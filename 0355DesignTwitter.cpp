/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-01
 * @tag  design, hashMap
 * @similar
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 *
 * https://leetcode.cn/problems/design-twitter/description/
 *
 * algorithms
 * Medium (41.21%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    50.9K
 * Total Submissions: 122.6K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 10 条推文。
 *
 * 实现 Twitter 类：
 * Twitter() 初始化简易版推特对象
 * void postTweet(int userId, int tweetId) 根据给定的 tweetId 和 userId
 * 创建一条新推文。每次调用此函数都会使用一个不同的 tweetId 。
 * List<Integer> getNewsFeed(int userId) 检索当前用户新闻推送中最近  10 条推文的 ID
 * 。新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 按照时间顺序由最近到最远排序 。
 * void follow(int followerId, int followeeId) ID 为 followerId 的用户开始关注 ID 为
 * followeeId 的用户。
 * void unfollow(int followerId, int followeeId) ID 为 followerId 的用户不再关注 ID 为
 * followeeId 的用户。
 *
 *
 *
 *
 * 示例：
 * 输入
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * 输出
 * [null, null, [5], null, null, [6, 5], null, [5]]
 *
 * 解释
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
 * twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
 * twitter.follow(1, 2);    // 用户 1 关注了用户 2
 * twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
 * twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文
 * id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
 * twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
 * twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1
 * 已经不再关注用户 2
 *
 *
 *
 * 提示：
 * 1 <= userId, followerId, followeeId <= 500
 * 0 <= tweetId <= 10^4
 * 所有推特的 ID 都互不相同
 * postTweet、getNewsFeed、follow 和 unfollow 方法最多调用 3 * 10^4 次
 * 用户不能关注自己
 *
 *
 */

// @lc code=start
class Twitter {
public:
    Twitter() {
        timeid = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetTime[tweetId] = timeid++;
        user2tweet[userId].push_back(tweetId);
    }

    /*
    K路归并
    1 两两合并
    2 优先队列，下标数组
    3 递归-

    */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<vector<int>> alltw;
        auto& selfT = user2tweet[userId];
        if (selfT.size() > 0) {
            alltw.push_back(selfT);
        }
        auto &followees = users[userId];
        for (auto& fid: followees) {
            auto& tweets = user2tweet[fid];
            if (tweets.size() > 0) {
                alltw.push_back(tweets);
            }
        }

        int k = alltw.size();
        if (k == 0) {
            return ans;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >>  maxHeap;
        for (int i = 0; i < k; i++) {
            vector<int>& cur = alltw[i];
            for (int j = cur.size() - 1; j >= 0; j--) {
                int& timeid = tweetTime[cur[j]];
                maxHeap.push(make_pair(timeid, cur[j]));
                if (j < int(cur.size() - 10)) { // enough
                // ERROR TYPE WTF
                //if (j < cur.size() - 10) { // enough
                    break;
                }
            }
        }

        while(!maxHeap.empty()) {
            if (ans.size() >= 10) {
                break;
            }
            auto& topPa = maxHeap.top();
            ans.push_back(topPa.second);
            maxHeap.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        users[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }


    unordered_map<int, unordered_set<int> > users;
    unordered_map<int, vector<int> > user2tweet;
    unordered_map<int, int> tweetTime;
    int timeid;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end


/*
Wrong Answer
14/18 cases passed (N/A)
Testcase
["Twitter","postTweet","postTweet","getNewsFeed"]
[[],[1,5],[1,3],[1]]
Answer
[null,null,null,[3]]
Expected Answer
[null,null,null,[3,5]]

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
