/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-30
 * @tag array; OneShot
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 *
 * https://leetcode.cn/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (54.68%)
 * Likes:    384
 * Dislikes: 0
 * Total Accepted:    163.3K
 * Total Submissions: 298.5K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个  无重复元素 的 有序 整数数组 nums 。
 *
 * 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于
 * nums 的数字 x 。
 *
 * 列表中的每个区间范围 [a,b] 应该按如下格式输出：
 *
 *
 * "a->b" ，如果 a != b
 * "a" ，如果 a == b
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [0,1,2,4,5,7]
 * 输出：["0->2","4->5","7"]
 * 解释：区间范围是：
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 *
 *
 * 示例 2：
 * 输入：nums = [0,2,3,4,6,8,9]
 * 输出：["0","2->4","6","8->9"]
 * 解释：区间范围是：
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 *
 *
 *
 * 提示：
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * nums 中的所有值都 互不相同
 * nums 按升序排列
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int i = 0;
        while (i < nums.size()) {
            int j = i;
            while ((j < nums.size()-1) && (nums[j])+1 == nums[j+1]) {
                j++;
            }
            if (i == j) {
                res.push_back(std::to_string(nums[i]));
            } else {
                std::stringstream ss;
                ss << nums[i] << "->" << nums[j];
                res.push_back(ss.str());
            }
            i = j+1;
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


