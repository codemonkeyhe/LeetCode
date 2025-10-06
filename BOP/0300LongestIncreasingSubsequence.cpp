/**
 * @file
 * @brief  BOP 2.16
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-04-11,2025-05-23
 * @tag dynamicProgramming,binarySearch+greedy
 * @similar 72, 300, 354, 673, 1143, 1964
 */

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (55.79%)
 * Likes:    3988
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 *
 *
 * 示例 1：
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 *
 * 示例 2：
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 *
 * 示例 3：
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 *
 *
 */

// @lc code=start
class Solution {
public:

    int lengthOfLISM1(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);

        for (int i = 0; i < len; i++) {
            int maxLIS = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                // nums[i] > nums[j]
                maxLIS = max(maxLIS, dp[j]);
            }
            dp[i] = maxLIS+1;
        }

        /*
        int maxV = 1;
        for (int i = 0; i < len; i++) {
            if (dp[i] >  maxV) {
                maxV = dp[i];
            }
        }
        */
       int maxV = *max_element(dp.begin(), dp.end());

        return maxV;
    }


    int lengthOfLISM2(vector<int>& nums) {
        int len = nums.size();
        int res = 1;
        memo = vector<int>(len, -1);
        for (int i = 0; i < len; i++) {
            res = max(res, cacheBT(nums, i));
        }
        // ErrorCase return cacheBT(nums, len-1);
        return res;
    }

    vector<int> memo;
    int cacheBT(vector<int>& nums, int i) {
        if (memo[i] != -1) {
            return memo[i];
        }

        int maxLIS = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] >= nums[i]) {
                continue;
            }
            int v = cacheBT(nums, j) + 1;
            maxLIS  = max(maxLIS, v);
        }
        memo[i] = maxLIS;
        return maxLIS;
    }

    int lengthOfLISM3(vector<int>& nums) {
        int len = nums.size();
        vector<int> d(len, 0);
        d[0] = nums[0];
        int dl = 1;
        for (int i = 1; i < len; i++) {
            int& cur = nums[i];
            int j = 0;
            for (; j < dl; j++) {
                if (d[j] >= cur) {
                    break;
                }
            }
            d[j] = cur;
            if (j == dl) {
                dl++;
            }
        }
        return dl;
    }


    // greedy
    // d[i]  表示 定义 长为 i+1 的上升子序列的末尾元素的最小值。
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> d;
        for (int i = 0; i < len; i++) {
            int& cur = nums[i];
            int idx = lower_bound(d.begin(), d.end(), cur) - d.begin();
            if (idx == d.size()) {
                d.push_back(cur);
            } else {
                d[idx] = cur;
            }
        }
        return d.size();
    }
};
// @lc code=end

/*
dp[i] 表示以nums[i] 结尾的 LIS的length
dp[i] = max(dp[j]) + 1 , nums[j]  < nums[i] 且  0 <=j < i



Time Limit Exceeded
22/55 cases passed (N/A)
Testcase
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,...207,2208,2209,2210,2211,2212,2213,2214,2215,2216,2217,2218,2219,2220,2221,2'... 1394 more character
Expected Answer
2500
*/

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class SolutionOld {
public:

    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        int max = 0;
        for (int i = 0; i < len; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] &&  dp[j]+1 > dp[i]) {
                    dp[i] =  dp[j] +1;
                }
            }
            if (dp[i] > max)  {
                max=dp[i];
            }
        }
        return max;
    }

    int lengthOfLISM2(vector<int>& nums) {
        int len = nums.size();
        if (len==0) {
            return 0;
        }
        vector<int> tail(len, 0);
        int idx = 0;
        tail[idx] =  nums[0];
        for (int i = 1; i < len; ++i) {
            if (nums[i] > tail[idx]) {
                tail[++idx] = nums[i];
            } else if (nums[i] == tail[idx]){
                continue;
            } else {
                int low = 0;
                int high = idx;
                while(low<high) {
                    int mid = (low+high)/2;
                    if (tail[mid] < nums[i]) {
                        low = mid+1;
                    } else {
                        high = mid;
                    }
                }
                tail[low] = nums[i];
            }
        }
        return idx+1;
    }

};



int main() {
    int len = 8;
    int nums[len] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nu(nums, nums + len);
    SolutionOld s;
    cout << s.lengthOfLISM2(nu) << endl;

    return 0;
}

/*
Tips

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
首先，需要对「子序列」和「子串」这两个概念进行区分；
子序列（subsequence）
子序列并不要求连续，例如：序列 [4, 6, 5] 是 [1, 2, 4, 3, 7, 6, 5] 的一个子序列。
子串（substring、subarray）
子串一定是连续的，

其次，题目中的「上升」的意思是「严格上升」，[1, 2, 2, 3] 都不能算作「上升子序列」；

第三，子序列中元素的相对顺序很重要。
它们必须保持在原始数组中的相对顺序。


M0 暴力法

M1 动态规划
//Runtime: 160 ms, faster than 5.13% of C++ online submissions for Longest Increasing Subsequence.
//Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Longest Increasing Subsequence.

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
定义 dp[i]为考虑前 i个元素，以第 i个数字结尾的最长上升子序列的长度，注意 nums[i] 必须被选取。
我们从小到大计算 dp[] 数组的值，在计算 dp[i]之前，我们已经计算出 dp[0…i−1] 的值，则状态转移方程为：
dp[i] = max(dp[j]) + 1, 其中  0 <= j < i , 且num[j]<num[i]

即考虑往 dp[0…i−1] 中最长的上升子序列后面再加一个 nums[i]。由于 dp[j] 代表 nums[0…j] 中以 nums[j] 结尾的最长上升子序列，所以如果能从 dp[j] 这个状态转移过来，那么 nums[i] 必然要大于 nums[j]，才能将 nums[i] 放在 nums[j] 后面以形成更长的上升子序列。

最后，整个数组的最长上升子序列即所有 dp[i] 中的最大值。
LIS_length= max(dp[i]), 其中 0 <= i < n
​
按照BOP的解析，把上面2个方程合并为1个。
LIS[i+1] = max(1, LIS[k]+1) ,   for any k<=i 满足 array[i+1]>array[k]
即如果 array[i+1]>array[k]，那么第i+1个元素可以接在LIS[k]长的子序列后面构成一个更长的子序列。
LIS[i]即以第i个元素结尾的最长递增子序列的长度



M2 贪心+二分查找
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Longest Increasing Subsequence.
tail[i] 表示长度为 i+1 的所有上升子序列的结尾元素的最小值。
证明tail的单调递增性
只需要维护状态数组 tail 的定义，它的长度就是最长上升子序列的长度。
https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/


*/