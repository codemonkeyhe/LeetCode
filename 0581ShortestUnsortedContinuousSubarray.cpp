/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-19
 * @tag  twoPointer
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
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (42.19%)
 * Likes:    1235
 * Dislikes: 0
 * Total Accepted:    227.8K
 * Total Submissions: 530.2K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 *
 * 请你找出符合题意的 最短 子数组，并输出它的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [2,6,4,8,10,9,15]
 * 输出：5
 * 解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3,4]
 * 输出：0
 *
 *
 * 示例 3：
 * 输入：nums = [1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^5
 *
 *
 *
 *
 * 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> data(nums.begin(), nums.end());
        sort(data.begin(), data.end());
        int i = 0;
        while (i < nums.size() && data[i] == nums[i]) {
            i++;
        }
        if (i == nums.size()) {
            return 0;
        }
        int j = nums.size()-1;
        while (j >=0 && data[j] == nums[j]) {
            j--;
        }
        int res = j - i + 1;
        return res;
    }
};
// @lc code=end

/*
输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。


2

Wrong Answer
285/307 cases passed (N/A)
Testcase
[1,2,3,4]
Answer
-4
Expected Answer
0


MaxLeft             MinRight
左段有序   中段无序   右段有序
中段里面的最小值 比 左段里面的最大值 还要大 即中段里面的所有值都比它大
中段里面的最大值 比  右段里面的最小值 还要小 即中段里面的所有值都比它小


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
