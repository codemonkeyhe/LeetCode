/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-18
 * @tag greedy, hashtable
 * @similar  56, 763
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.97%)
 * Likes:    1302
 * Dislikes: 0
 * Total Accepted:    361.5K
 * Total Submissions: 460K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串 "ababcc" 能够被分为 ["abab",
 * "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 *
 * 返回一个表示每个字符串片段的长度的列表。
 *
 *
 * 示例 1：
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
 *
 * 示例 2：
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabelsM1(string s) {
        int n = s.size();
        vector<int> left(27, -1);
        vector<int> right(27, -1);
        map<int,int> idx2ch; // first occur idx 2 ch
        for (int i = 0; i < n; i++) {
            int cur = int(s[i] - 'a');
            if (left[cur] == -1) { // first
                left[cur] = i;
                right[cur] = i;
                idx2ch[i] = cur;
            } else { // not first, then mark last
                right[cur] = i;
            }
        }
        // 按照区间左端点排序
        vector<pair<int, int>> ranges;
        for (auto&[idx, ch]: idx2ch) { // from small to big
            auto pa = make_pair(left[ch], right[ch]);
            ranges.push_back(pa);
        }

        // merge range
        vector<pair<int, int>> merge;
        int preLeft = ranges[0].first;
        int preRight =  ranges[0].second;
        for (int i = 1; i < ranges.size(); i++) {
            auto& pa = ranges[i];
            if (pa.first < preRight) { //  overlop
                // overlop ,extend right point , left point already keep asc
                preRight = max(preRight, pa.second);
                continue;
            }
            // not overlop
            merge.push_back(make_pair(preLeft, preRight));  // pre range
            preLeft = pa.first;
            preRight = pa.second;
        }
        // the last range
        merge.push_back(make_pair(preLeft, preRight));

        vector<int> res;
        for (auto& pa : merge) {
            res.push_back(pa.second - pa.first + 1);
        }
        return res;
    }


    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> right(27, -1);
        for (int i = 0; i < n; i++) {
            int cur = int(s[i] - 'a');
            right[cur] = i;
        }

        vector<int> res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            int cur = int(s[i] - 'a');
            end = max(end, right[cur]);
            if (end == i) { // find one partion
                res.push_back(end - start + 1);
                start = i + 1;
                end = 0;
            }
        }
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


