/**
 * @file
 * @brief  BOP 2.16
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-04-11
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

class Solution {
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
    Solution s;
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