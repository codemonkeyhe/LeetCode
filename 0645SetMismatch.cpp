/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-23
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 *
 * https://leetcode.cn/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (39.09%)
 * Likes:    368
 * Dislikes: 0
 * Total Accepted:    120.1K
 * Total Submissions: 307.4K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且
 * 有一个数字重复 。
 *
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。
 *
 * 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,2,4]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 * 输入：nums = [1,1]
 * 输出：[1,2]
 *
 *
 * 提示：
 * 2
 * 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        int arr[10001] = {0};
        for (int i = 0; i < len; i++) {
            arr[nums[i]]+=1;
        }
        vector<int> res;
        int lost = 0;
        for (int i = 1; i <= len; i++) {
            if ((arr[i]) == 2 ) {
                res.push_back(i);
            } else if (arr[i] == 0) {
                lost = i;
            }
        }
        res.push_back(lost);
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


