/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-05
 * @tag  slidingWindow
 * @similar 3,209,713
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (50.72%)
 * Likes:    854
 * Dislikes: 0
 * Total Accepted:    147.8K
 * Total Submissions: 279.1K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 *
 *
 * 示例 1：
 * 输入：nums = [10,5,2,6], k = 100
 * 输出：8
 * 解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3], k = 0
 * 输出：0
 *
 *
 *
 * 提示: 
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int res = 0;
        int le = 0;
        int ri = 0;
        int len  = nums.size();
        int prod = 1;
        while(ri < len) {
            prod *= nums[ri];
            while (prod >= k) {
                prod /= nums[le];
                le++;
            }
            //prod < k
            res += ri - le + 1;
            ri++;
        }
        return res;
    }
};
// @lc code=end

/*
10,5,2,6

left++ when product >=k
right++ when product <k

k=100                   res
10      P<k  right++    1
10 5    P<k   right++   1+2
10 5 2  P=k    left++
5 2     P<k     right++  1+2+2
5 2 6   <k     right++    1+2+2+3
5 2 6 X < k   right->X    END res=8
2 6   no need to walk
6 no need to walk


i   j
以j结尾的小于k的subArray的数目
1 2 3  < k
1 2 3
2 3
3
num = j-i+1


Runtime Error
1/98 cases passed (N/A)
Testcase
[1,2,3]
0
Expected Answer
0

Wrong Answer
96/98 cases passed (N/A)
Testcase
[1,1,1]
1
Answer
-6
Expected Answer
0
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


