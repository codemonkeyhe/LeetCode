/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-17
 * @tag  math,randomized,reservoirSampling
 * @similar   382, 394, 398, 470
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 *
 * https://leetcode.cn/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (68.88%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    62.9K
 * Total Submissions: 91.9K
 * Testcase Example:  '["Solution","pick","pick","pick"]\n[[[1,2,3,3,3]],[3],[1],[3]]'
 *
 * 给你一个可能含有 重复元素 的整数数组 nums ，请你随机输出给定的目标数字 target 的索引。你可以假设给定的数字一定存在于数组中。
 *
 * 实现 Solution 类：
 * Solution(int[] nums) 用数组 nums 初始化对象。
 * int pick(int target) 从 nums 中选出一个满足 nums[i] == target 的随机索引 i
 * 。如果存在多个有效的索引，则每个索引的返回概率应当相等。
 *
 *
 *
 *
 * 示例：
 * 输入
 * ["Solution", "pick", "pick", "pick"]
 * [[[1, 2, 3, 3, 3]], [3], [1], [3]]
 * 输出
 * [null, 4, 0, 2]
 *
 * 解释
 * Solution solution = new Solution([1, 2, 3, 3, 3]);
 * solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
 * solution.pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
 * solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * target 是 nums 中的一个整数
 * 最多调用 pick 函数 10^4 次
 *
 *
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution1 {
public:
    Solution1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            //data.push_back(nums[i]);
            v2i[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& vv = v2i[target];
        if (vv.size() == 1) {
            return vv[0];
        }
        return vv[rand() % vv.size()];
    }

    //vector<int> data;
    unordered_map<int, vector<int> > v2i;
};


//TLE 15-17, but OK
class Solution {
public:
    Solution(vector<int>& nums): data(nums) {
    }

    int pick(int target) {
        int sameCnt = 0;
        int idx = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == target) {
                sameCnt++;
                if (rand() % sameCnt == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }

    vector<int>& data;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
