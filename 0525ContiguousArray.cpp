/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-16
 * @tag      hashtable,prefixsum
 * @similar  523, 525
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 *
 * https://leetcode.cn/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (54.57%)
 * Likes:    811
 * Dislikes: 0
 * Total Accepted:    96K
 * Total Submissions: 172.9K
 * Testcase Example:  '[0,1]'
 *
 * 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [0,1]
 * 输出：2
 * 说明：[0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
 *
 * 示例 2：
 * 输入：nums = [0,1,0]
 * 输出：2
 * 说明：[0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
 *
 * 示例 3：
 * 输入：nums = [0,1,1,1,1,1,0,0,0]
 * 输出：6
 * 解释：[1,1,1,0,0,0] 是具有相同数量 0 和 1 的最长连续子数组。
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1
 *
 *
 */

// @lc code=start
class Solution {
public:


    // 误解题意，不需要0和1的连续
    int findMaxLengthError(vector<int>& nums) {
        int nlen = nums.size();
        vector<int> presum(nlen+1, 0);
        for (int i = 0; i < nlen; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        int maxLen = 0;
        for (int i = 0; i < nlen; i++) {
            for (int j = i+1; j < nlen; j++) {
                int len = j - i + 1;
                if (len % 2 == 1) {
                    continue;
                }
                int mid = (i + j) / 2;
                // sum[i..j] == len/2  and sum[i..mid] == 0 or sum[i..mid] == len/2
                int sumij = presum[j + 1] - presum[i];
                int sumMid = presum[mid + 1] - presum[i];
                if (sumij == len/2 && (sumMid == 0 || sumMid == len/2)) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }

    // TLE
    int findMaxLengthTLE33_565(vector<int>& nums) {
        int nlen = nums.size();
        vector<int> presum(nlen+1, 0);
        for (int i = 0; i < nlen; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        int maxLen = 0;
        for (int i = 0; i < nlen; i++) {
            for (int j = i+1; j < nlen; j++) {
                int len = j - i + 1;
                if (len % 2 == 1) {
                    continue;
                }
                int sumij = presum[j + 1] - presum[i];
                if (sumij == len/2) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }

    int findMaxLength(vector<int>& nums) {
        int nlen = nums.size();
        for (auto& num : nums) {
            if (num == 0) {
                num = -1;
            }
        }

        vector<int> presum(nlen+1, 0);
        for (int i = 0; i < nlen; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        unordered_map<int, int> ps2idx;
        int maxLen = 0;
        for (int i = 0; i < presum.size(); i++) {
            int ps = presum[i];
            if (ps2idx.count(ps) == 1) {
                // means ps[i] - ps[k] = 0
                //  clen = i  - k
                //  k = ps2idx[ps]
                int clen = i - ps2idx[ps];
                maxLen = max(maxLen, clen);
            } else {
                ps2idx[ps] = i;
            }
        }
        return maxLen;
    }



};
// @lc code=end

/*
    3456     4567
    0110     1100

    // nums[i..j] == 11110000 or 00001111
    // len = j-i+1 and len%2== 0  mid = (i+j)/2
    // means sum[i..j] == len/2
    //means  sum[i..mid] == len/2 and sum[mid..j] = 0
    //means  sum[i..mid] == 0 and sum[mid..j] = len/2

   sum[i..j] = preSum[j+1] - preSum[i]


Wrong Answer
9/565 cases passed (N/A)
Testcase
[0,1,0,1]
Answer
2
Expected Answer
4


Time Limit Exceeded
33/565 cases passed (N/A)
Testcase
[0,1,1
Expected Answer
21560


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
