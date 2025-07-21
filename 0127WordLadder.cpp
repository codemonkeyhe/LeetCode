/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-21
 * @tag bfs,hashTable
 * @similar  126, 127, 433, 2452
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode.cn/problems/word-ladder/description/
 *
 * algorithms
 * Hard (48.79%)
 * Likes:    1474
 * Dislikes: 0
 * Total Accepted:    251.4K
 * Total Submissions: 504.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 字典 wordList 中从单词 beginWord 到 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 ->
 * s2 -> ... -> sk：
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列
 * 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
 *
 *
 * 示例 1：
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 *
 *
 * 示例 2：
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * 输出：0
 * 解释：endWord "cog" 不在字典中，所以无法进行转换。
 *
 *
 *
 * 提示：
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord、endWord 和 wordList[i] 由小写英文字母组成
 * beginWord != endWord
 * wordList 中的所有字符串 互不相同
 *
 *
 */

// @lc code=start
class Solution {
public:

/*
51/51 cases passed (2138 ms)
Your runtime beats 5.02 % of cpp submissions
Your memory usage beats 4.95 % of cpp submissions (277.5 MB)
*/
    int ladderLengthM1V1(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> w2m;
        unordered_map<string, vector<string>> m2w;
        unordered_map<string, vector<string> > wg;

        for (auto& word: wordList) {
            for (int i = 0; i < word.size(); i++) {
                string w2 = word;
                w2[i] = '*';
                w2m[word].push_back(w2);
                m2w[w2].push_back(word);
            }
        }

        if(w2m.count(endWord) == 0) {
            return 0;
        }

        for (auto &[word, mids]: w2m) {
            vector<string> neis;
            for (auto& mid: mids) {
                auto& likewords = m2w[mid];
                for (auto& lw: likewords) {
                    if (lw != word) {
                        neis.push_back(lw);
                    }
                }
            }
            wg[word] = neis;
        }


        int minPath = 10001;
        for (int i = 0; i < beginWord.size(); i++) {
            string w2 = beginWord;
            w2[i] = '*';
            auto& likewords = m2w[w2];
            if (likewords.size() == 0) {
                continue;
            }
            for (auto& lw: likewords) {
                int path = findPathInWordGraph(lw, endWord, wg);
                minPath = min(minPath, path);
            }
        }
        if (minPath > 10000) { // no valid path
            return 0;
        }
        return minPath+1;
    }

    /*
    优化了对beginWord的处理
    51/51 cases passed (419 ms)
    Your runtime beats 27.03 % of cpp submissions
    */
    int ladderLengthM1V2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> w2m;
        unordered_map<string, vector<string>> m2w;
        unordered_map<string, vector<string> > wg;

        wordList.push_back(beginWord);
        for (auto& word: wordList) {
            for (int i = 0; i < word.size(); i++) {
                string w2 = word;
                w2[i] = '*';
                w2m[word].push_back(w2);
                m2w[w2].push_back(word);
            }
        }

        if(w2m.count(endWord) == 0) {
            return 0;
        }

        for (auto &[word, mids]: w2m) {
            vector<string> neis;
            for (auto& mid: mids) {
                auto& likewords = m2w[mid];
                for (auto& lw: likewords) {
                    if (lw != word) {
                        neis.push_back(lw);
                    }
                }
            }
            wg[word] = neis;
        }

        int path = findPathInWordGraph(beginWord, endWord, wg);
        if (path > 10000) { // no valid path
            return 0;
        }
        return path;
    }

/*
M1V3
string 映射成 int
51/51 cases passed (239 ms)
Your runtime beats 32.53 % of cpp submissions
*/
    int ladderLengthM1V3(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> w2m;
        unordered_map<string, vector<string>> m2w;
        //unordered_map<string, vector<string> > wg;
        unordered_map<int, vector<int> > wg;

        wordList.push_back(beginWord);
        for (auto& word: wordList) {
            for (int i = 0; i < word.size(); i++) {
                string w2 = word;
                w2[i] = '*';
                w2m[word].push_back(w2);
                m2w[w2].push_back(word);
            }
        }

        if(w2m.count(endWord) == 0) {
            return 0;
        }

        int idx = 0;
        unordered_map<string, int> w2id;
        w2id[beginWord] = idx++;
        for (auto& word: wordList) {
            w2id[word] = idx++;
        }

        for (auto &[word, mids]: w2m) {
            int curID = w2id[word];
            vector<int> neis;
            for (auto& mid: mids) {
                auto& likewords = m2w[mid];
                for (auto& lw: likewords) {
                    if (lw != word) {
                        neis.push_back(w2id[lw]);
                    }
                }
            }
            wg[curID] = neis;
        }

        int path = findPathInWordGraphV2(w2id[beginWord], w2id[endWord], wg);
        if (path > 10000) { // no valid path
            return 0;
        }
        return path;
    }


    int findPathInWordGraph(string bw, string ew,  unordered_map<string, vector<string>> & wordGraph) {
        unordered_set<string> visited;
        queue<string> que;
        que.push(bw);
        visited.insert(bw);

        int step = 0;
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();
                //visited.insert(cur);
                if (cur == ew) {
                    // 节点数目等于边数加1
                    return step+1;
                }
                if (wordGraph.count(cur) == 0) { // not valid path
                    return 10002;
                }
                auto &neis = wordGraph[cur];
                for (auto& nei: neis) {
                    if (visited.count(nei) == 0) {
                        que.push(nei);
                        visited.insert(cur);
                    }
                }
            }
            step++;
        }
        return 10003;
    }


    int findPathInWordGraphV2(int bw, int ew,  unordered_map<int, vector<int>> & wordGraph) {
        unordered_set<int> visited;
        queue<int> que;
        que.push(bw);
        visited.insert(bw);

        int step = 0;
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();
                //visited.insert(cur);
                if (cur == ew) {
                    // 节点数目等于边数加1
                    return step+1;
                }
                if (wordGraph.count(cur) == 0) { // not valid path
                    return 10002;
                }
                auto &neis = wordGraph[cur];
                for (auto& nei: neis) {
                    if (visited.count(nei) == 0) {
                        que.push(nei);
                        visited.insert(cur);
                    }
                }
            }
            step++;
        }
        return 10003;
    }

    // M2
    /*
   51/51 cases passed (95 ms)
Your runtime beats 72.51 % of cpp submissions
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if (wordset.count(endWord) == 0) {
            return 0;
        }
        queue<string> que;
        unordered_set<string> visited;
        que.push(beginWord);
        visited.insert(beginWord);
        int step = 0;
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();
                auto neis = getSimilar(cur, wordset);
                for (auto& nei: neis) {
                    if (nei == endWord) {
                        // step+1是边数， 顶点数=边数+1
                        return step+2;
                    }
                    if (visited.count(nei) == 0) {
                        que.push(nei);
                        visited.insert(nei);
                    }
                }
            }
            step++;
        }
        return 0;
    }

    vector<string> getSimilar(string& cur, unordered_set<string>& wordset) {
        vector<string> res;
        for (auto& ch: cur) {
            char old = ch;
            for (char i = 'a'; i <= 'z'; i++) {
                if (i == old) {
                    continue;
                }
                ch = i;
                if (wordset.count(cur)) {
                    res.push_back(cur); // copy change word
                }
            }
            ch = old; // restore
        }
        return res;
    }


};
// @lc code=end


/*
M1 先建立图，再BFS
M2 就地BFS，暴力穷举可变单词

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


