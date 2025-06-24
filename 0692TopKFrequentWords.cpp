/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-23
 * @tag  sort,quickSelect,heapSort,minHeap
 * @similar 215, 347, 692
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 *
 * https://leetcode.cn/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (56.11%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    132.4K
 * Total Submissions: 234.2K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * 给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。
 *
 * 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序。
 *
 *
 *
 * 示例 1：
 * 输入: words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * 输出: ["i", "love"]
 * 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
 * ⁠   注意，按字母顺序 "i" 在 "love" 之前。
 *
 *
 * 示例 2：
 * 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
 * k = 4
 * 输出: ["the", "is", "sunny", "day"]
 * 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
 * ⁠   出现次数依次为 4, 3, 2 和 1 次。
 *
 *
 *
 *
 * 注意：
 * 1 <= words.length <= 500
 * 1 <= words[i] <= 10
 * words[i] 由小写英文字母组成。
 * k 的取值范围是 [1, 不同 words[i] 的数量]
 *
 *
 * 进阶：尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
 *
 */

// @lc code=start
class Solution {
public:
    bool isBig(pair<int, string>& a ,pair<int, string>& b) {
        if (a.first > b.first) {
            return true;
        }
        if (a.first == b.first && (a.second < b.second)) {
            return true;
        }
        return false;
    }


    //maxHeap
    void heapAdjust(vector<pair<int, string> >& nodes, int i, int len) {
        auto top = nodes[i];
        int cur = i;
        int ch = 2 * cur + 1;
        while(ch < len) {
            if (ch + 1 < len && isBig(nodes[ch + 1], nodes[ch])) {
                ch++;
            }
            if (isBig(top, nodes[ch])) { // no need to adjust
                break;
            }
            nodes[cur] = nodes[ch];
            cur = ch;
            ch = 2 * cur + 1;
        }
        nodes[cur] = top;
    }


    vector<string> topKFrequentM1(vector<string>& words, int k) {
        unordered_map<string, int> wc;
        for (auto& w: words) {
            wc[w]++;
        }

        vector<pair<int, string> > nodes;
        for (auto& [w, c]: wc)  {
            nodes.push_back(make_pair(c, w));
        }

        // buildMaxHeap
        int n = nodes.size();
        int last = n / 2 - 1;
        for (int i = last; i >= 0; i--) {
            heapAdjust(nodes, i, n);
        }
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(nodes[0].second);
            swap(nodes[0], nodes[--n]);
            heapAdjust(nodes, 0, n);
        }
        return res;
    }


    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wc;
        for (auto& w: words) {
            wc[w]++;
        }

        vector<pair<int, string> > nodes;
        for (auto& [w, c]: wc)  {
            nodes.push_back(make_pair(c, w));
        }

        // minHeap should use greater  a > b return true
        auto cmpFn = [](pair<int, string>& a, pair<int, string>& b) -> bool {
            if (a.first > b.first) {
                return true;
            }
            if (a.first == b.first && (a.second < b.second)) {
                return true;
            }
            return false;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmpFn)>
            minHeap;

        for (auto& [w, c]: wc)  {
            minHeap.push(make_pair(c, w));
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // res可以先扩容，再逆序赋值
        vector<string> res;
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        // 小根队，需要reverse
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


