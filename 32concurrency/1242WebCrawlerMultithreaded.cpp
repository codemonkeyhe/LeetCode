/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-28
 * @tag  mutithread
 * @similar  1236, 1242, 1188
 */

/*
给你一个初始地址 startUrl 和一个 HTML 解析器接口 HtmlParser，请你实现一个 多线程的网页爬虫，用于获取与 startUrl 有 相同主机名 的所有链接。
以 任意 顺序返回爬虫获取的路径。

爬虫应该遵循：
1 从 startUrl 开始
2 调用 HtmlParser.getUrls(url) 从指定网页路径获得的所有路径。
3 不要抓取相同的链接两次。
4 仅浏览与 startUrl 相同主机名 的链接。


例如主机名是 example.org 。简单起见，你可以假设所有链接都采用 http 协议，并且没有指定 端口号。举个例子，链接 http://leetcode.com/problems 和链接 http://leetcode.com/contest 属于同一个 主机名， 而 http://example.org/test 与 http://example.com/abc 并不属于同一个 主机名。

HtmlParser 的接口定义如下：
interface HtmlParser {
  // Return a list of all urls from a webpage of given url.
  // This is a blocking call, that means it will do HTTP request and return when this request is finished.
  public List<String> getUrls(String url);
}
注意一点，getUrls(String url) 模拟执行一个HTTP的请求。 你可以将它当做一个阻塞式的方法，直到请求结束。 getUrls(String url) 保证会在 15ms 内返回所有的路径。 单线程的方案会超过时间限制，你能用多线程方案做的更好吗？

对于问题所需的功能，下面提供了两个例子。为了方便自定义测试，你可以声明三个变量 urls，edges 和 startUrl。但要注意你只能在代码中访问 startUrl，并不能直接访问 urls 和 edges。





示例 1：
输入：
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
输出：[
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]

示例 2：
输入：
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com"
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = "http://news.google.com"
输出：["http://news.google.com"]
解释：startUrl 链接与其他页面不共享一个主机名。


提示：

1 <= urls.length <= 1000
1 <= urls[i].length <= 300
startUrl 是 urls 中的一个。
主机名的长度必须为 1 到 63 个字符（包括点 . 在内），只能包含从 “a” 到 “z” 的 ASCII 字母和 “0” 到 “9” 的数字，以及中划线 “-”。
主机名开头和结尾不能是中划线 “-”。
参考资料：https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames
你可以假设路径都是不重复的。


拓展问题：
假设我们要要抓取 10000 个节点和 10 亿个路径。并且在每个节点部署相同的的软件。软件可以发现所有的节点。我们必须尽可能减少机器之间的通讯，并确保每个节点负载均衡。你将如何设计这个网页爬虫？
如果有一个节点发生故障不工作该怎么办？
如何确认爬虫任务已经完成？

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

 class HtmlParser {
   public:
     vector<string> getUrls(string url) {
        return  vector<string>();
     }
 };

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class SolutionTLE18_20 {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        curHost = getHost(startUrl);
        vector<string>  res;
        que.push(startUrl);
        walked.insert(startUrl);
        res.push_back(startUrl);

        while(!que.empty()) {
            auto cur = que.front();
            que.pop();
            auto urls = htmlParser.getUrls(cur);
            for (auto &url : urls) {
                if (walked.count(url)) {
                    continue;
                }
                if (url.find(curHost) == string::npos) {
                //if (getHost(url) != curHost) {
                   continue;
                }
                que.push(url);
                walked.insert(url);
                res.push_back(url);
            }

        }
        return res;
    }


    string getHost(string& url) {
        auto pos = url.find("//", 0);
        if (pos == string::npos) {
            return "NOTFOUND";
        }
        auto beginPos = pos+2;
        auto p2 = url.find('/', pos+2);
        if (p2 == string::npos) {
            return "NOTFOUND";
        }
        int len = p2 - beginPos;
        return url.substr(beginPos, len);
    }

    string curHost;
    queue<string> que;
    unordered_set<string> walked;
};

class Solution {
public:

    class QueTask {
        public:
         QueTask(string& host) {
            curHost = host;
         }

          atomic<int> activeCnt{0};
          atomic<bool> done{false};

          string curHost;
          queue<string> que;
          std::mutex queMu;
          condition_variable cv; // for queMu

          unordered_set<string> walked;
          std::mutex walkedMu;
    };

    void Worker(int tid, QueTask* qt, HtmlParser* parser) {
        while(true) {
            unique_lock<mutex> lk(qt->queMu);
            while (qt->que.size() == 0 && qt->done == false) {
                qt->cv.wait(lk);
            }

            if (qt->que.size() == 0 && qt->done == true) { // end thread
                break;
            }

            if (qt->que.size() == 0) {
                continue;
            }
            string url = qt->que.front();
            qt->que.pop();
            lk.unlock();

            qt->activeCnt++;
            auto urlList = parser->getUrls(url);
            vector<string> validUrl;
            for (auto u: urlList) {
                if (getHost(u) != qt->curHost) {
                   continue;
                }

                {
                    unique_lock<mutex> lk3(qt->walkedMu);
                    if(qt->walked.count(u) == 0) { //
                        qt->walked.insert(u);
                        validUrl.push_back(u);
                    }
                    lk3.unlock();
                }
            }

            if (validUrl.size() > 0) {
                unique_lock<mutex> lk2(qt->queMu);
                for (auto vu : validUrl) {
                    qt->que.push(vu);
                }
                lk2.unlock();
                qt->cv.notify_all();
            }

            qt->activeCnt--;
        }
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        auto host = getHost(startUrl);
        QueTask qt(host);
        qt.que.push(startUrl);
        qt.walked.insert(startUrl);

        vector<thread> threads;
        int threadNums = 4;
        for (int i = 0; i < threadNums; i++) {
           // BUG std::thread t(&Solution::Worker, this, i, std::ref(qt), std::ref(htmlParser));
            //BUG: threads.push_back(t); thread can not copy
            std::thread t(&Solution::Worker, this, i, &qt, &htmlParser);
            threads.push_back(std::move(t));
        }

        {
            //monitorProgress(qt);
            unique_lock<mutex> lk(qt.queMu);
            while(!qt.que.empty() || qt.activeCnt > 0) {
                qt.cv.wait_for(lk, chrono::milliseconds(10));
            }
            lk.unlock();
        }

        qt.done = true;
        qt.cv.notify_all();

        for (auto& t : threads) {
            t.join();
        }

        vector<string>  res(qt.walked.begin(), qt.walked.end());
        return res;
    }

    void monitorProgress(QueTask& qt) {
        unique_lock<mutex> lock(qt.queMu);
        while (!qt.que.empty() || qt.activeCnt > 0) {
            qt.cv.wait_for(lock, chrono::milliseconds(10));
        }
    }

    // BUG  当url=http://news.google.com ,应该返回 news.google.com
    // 花了1hour找多线程的BUG，其实是GetHost的BUG
    string getHostERROR(string& url) {
        auto pos = url.find("//", 0);
        if (pos == string::npos) {
            return "NOTFOUND";
        }
        auto beginPos = pos+2;
        auto p2 = url.find('/', pos+2);
        if (p2 == string::npos) {
            return "NOTFOUND";
        }
        int len = p2 - beginPos;
        return url.substr(beginPos, len);
    }

    string getHost(string& url) {
        auto pos = url.find("//", 0);
        if (pos == string::npos) {
            return "NOTFOUND";
        }
        auto beginPos = pos+2;
        auto p2 = url.find('/', pos+2);
        if (p2 == string::npos) {
            return url.substr(beginPos);
        }
        int len = p2 - beginPos;
        return url.substr(beginPos, len);
    }

};

int main() {
}


/*
Tips
M1 单线程 TLE

M2 多线程+ 单个queue+2个mutex
每个线程即使生产者，也是消费者
消费： 从queue拿一个url ，调用 HtmlParser的getUrls
生产： 把过滤后的结果写会queue
queue需要mutex保护，4个线程同时竞争
中心化的unordered_set<string>需要mutex2保护

M3 多线程+多个queue
消费：多个queue, url按尾号%4，分到4个queue，每个线程从一个queue拿url，这个queue也需要锁
生产：先按host过滤，过滤后的结果写回全局queue，全局queue由主线程进行中心化去重，再url%4分到4个queue

中心化去重，还是需要一把中心锁



*/
