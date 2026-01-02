/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2026-01-02
 * @tag  radixSort
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
 * @lc app=leetcode.cn id=2343 lang=cpp
 *
 * [2343] 裁剪数字后查询第 K 小的数字
 *
 * https://leetcode.cn/problems/query-kth-smallest-trimmed-number/description/
 *
 * algorithms
 * Medium (42.16%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 27K
 * Testcase Example:  '["102","473","251","814"]\n[[1,1],[2,3],[4,2],[1,2]]'
 *
 * 给你一个下标从 0 开始的字符串数组 nums ，其中每个字符串 长度相等 且只包含数字。
 *
 * 再给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [ki, trimi] 。对于每个 queries[i]
 * ，你需要：
 * 将 nums 中每个数字 裁剪 到剩下 最右边 trimi 个数位。
 * 在裁剪过后的数字中，找到 nums 中第 ki 小数字对应的 下标 。如果两个裁剪后数字一样大，那么下标 更小 的数字视为更小的数字。
 * 将 nums 中每个数字恢复到原本字符串。
 *
 *
 * 请你返回一个长度与 queries 相等的数组 answer，其中 answer[i]是第 i 次查询的结果。
 *
 * 提示：
 * 裁剪到剩下最右边 x 个数位的意思是不断删除最左边的数位，直到剩下 x 个数位。
 * nums 中的字符串可能会有前导 0 。
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
 * 输出：[2,2,1,0]
 * 解释：
 * 1. 裁剪到只剩 1 个数位后，nums = ["2","3","1","4"] 。最小的数字是 1 ，下标为 2 。
 * 2. 裁剪到剩 3 个数位后，nums 没有变化。第 2 小的数字是 251 ，下标为 2 。
 * 3. 裁剪到剩 2 个数位后，nums = ["02","73","51","14"] 。第 4 小的数字是 73 ，下标为 1 。
 * 4. 裁剪到剩 2 个数位后，最小数字是 2 ，下标为 0 。
 * ⁠  注意，裁剪后数字 "02" 值为 2 。
 *
 *
 * 示例 2：
 * 输入：nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
 * 输出：[3,0]
 * 解释：
 * 1. 裁剪到剩 1 个数位，nums = ["4","7","6","4"] 。第 2 小的数字是 4 ，下标为 3 。
 * ⁠  有两个 4 ，下标为 0 的 4 视为小于下标为 3 的 4 。
 * 2. 裁剪到剩 2 个数位，nums 不变。第二小的数字是 24 ，下标为 0 。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 100
 * 1 <= nums[i].length <= 100
 * nums[i] 只包含数字。
 * 所有 nums[i].length 的长度 相同 。
 * 1 <= queries.length <= 100
 * queries[i].length == 2
 * 1 <= ki <= nums.length
 * 1 <= trimi <= nums[0].length
 *
 *
 * 进阶：你能使用 基数排序算法 解决此问题吗？这种解法的复杂度又是多少？
 *
 */

// @lc code=start
class Solution {
public:
    // 可读性不好，纯粹为了存下标，牺牲了可读性
    vector<int> smallestTrimmedNumbersM1(vector<string>& nums, vector<vector<int>>& queries) {
        int width = nums[0].size();
        // 0: (trim=1)  1: (trim=2) 2:(trim=3)
        // 存储基数排序的过程
        vector<vector<int>> radixSortRes;
        int len = nums.size();
        vector<vector<int>> mr(10, vector<int>());
        int idx = width - 1;

        vector<int> tmp(len, 0); // 存储nums的下标
        for (int i = 0; i < len; i++) {
            tmp[i] = i;
        }

        while(idx >=0) {
            // map
            for (int i = 0; i < len; i++) {
                int ni = tmp[i];
                auto& num = nums[ni];
                auto& ch = num[idx];
                int ich = int(ch-'0');
                // change push num改成push 下标
                //mr[ich].push_back(num);
                mr[ich].push_back(ni);
            }
            // collect
            int k = 0;
            for (int j = 0; j < 10; j++) {
                for (auto& ni : mr[j]) {
                    tmp[k++] = ni;
                }
                mr[j].clear();
            }
            radixSortRes.push_back(tmp);
            idx--;
        }

        vector<int> ans;
        for (auto& qu : queries)  {
            int& k = qu[0]; // kth small  k starts from 1
            int& trim = qu[1];  // leftNumCnt,  trim: 1-width
            int ni = radixSortRes[trim-1][k-1];
            ans.push_back(ni);
        }
        return ans;
    }

    vector<int> smallestTrimmedNumbersWA250_251(vector<string>& nums, vector<vector<int>>& queries) {
        int width = nums[0].size();
        // 0: (trim=1)  1: (trim=2) 2:(trim=3)
        // 存储基数排序的过程
        vector<vector<int>> radixSortRes;
        int len = nums.size();
        // BUG 多个数值相同的数字，只取了最后1个下标
        unordered_map<string, int> sidx;
        for (int i = 0; i < nums.size(); i++) {
            sidx[nums[i]] = i;
        }
        vector<vector<string>> mr(10, vector<string>());
        vector<string> tmp(nums.begin(), nums.end());
        int idx = width-1;
        while (width-- > 0) {
            //cout << "idx=" << idx << " width=" << width << endl;
            // map
            for (int i = 0; i < len; i++) {
                auto& num = tmp[i];
                auto& ch = num[idx];
                int ich = int(ch-'0');
                mr[ich].push_back(num);
            }
            // collect
            int k = 0;
            for (int j = 0; j < 10; j++) {
                for (auto& num : mr[j]) {
                    tmp[k++] = num;
                }
                mr[j].clear();
            }
            vector<int> rec;
            for (auto& ss : tmp) {
                auto curI = sidx[ss];
                rec.push_back(curI);
            }
            radixSortRes.push_back(rec);
            idx--;
        }

        vector<int> ans;
        for (auto& qu : queries)  {
            int& k = qu[0]; // kth small  k starts from 1
            int& trim = qu[1];  // leftNumCnt,  trim: 1-width
            int ni = radixSortRes[trim-1][k-1];
            ans.push_back(ni);
        }
        return ans;
    }


    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int width = nums[0].size();
        // 0: (trim=1)  1: (trim=2) 2:(trim=3)
        // 存储基数排序的过程
        vector<vector<int>> radixSortRes;
        int len = nums.size();

        vector<vector<pair<int, string>>> mr(10, vector<pair<int, string>>());
        vector<pair<int, string> > tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp.push_back(make_pair(i, nums[i]));
        }

        int idx = width-1;
        while (width-- > 0) {
            // map
            for (int i = 0; i < len; i++) {
                auto& pa = tmp[i];
                auto& num = pa.second;
                auto& ch = num[idx];
                int ich = int(ch-'0');
                mr[ich].push_back(pa);
            }
            // collect
            int k = 0;
            for (int j = 0; j < 10; j++) {
                for (auto& pa : mr[j]) {
                    tmp[k++] = pa;
                }
                mr[j].clear();
            }
            vector<int> rec;
            for (auto& pa : tmp) {
                rec.push_back(pa.first);
            }
            radixSortRes.push_back(rec);
            idx--;
        }

        vector<int> ans;
        for (auto& qu : queries)  {
            int& k = qu[0]; // kth small  k starts from 1
            int& trim = qu[1];  // leftNumCnt,  trim: 1-width
            int ni = radixSortRes[trim-1][k-1];
            ans.push_back(ni);
        }
        return ans;
    }

};
// @lc code=end

/*
   0      1     2     3
 ["102","473","251","814"]

 1st idx=2 个
 251 102 473 814

 2st idx=1 十
 102  814  251 473

 3st idx=0 百
 102  251  473  814


Wrong Answer
250/251 cases passed (N/A)

0    1   2   3
111 111 111 111


0    1   2   3
11   11  11  11
kth=2 第2小的数字为11，下标是1

如果两个裁剪后数字一样大，那么下标 更小 的数字视为更小的数字。

query
1 1    kth=1 下标=0
2 2    kth=2 下标=1
3 3    kth=3 下标=3

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
