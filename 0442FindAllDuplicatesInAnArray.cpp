/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-01
 * @tag   array, hashTable
 * @similar  442, 448
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (75.15%)
 * Likes:    775
 * Dislikes: 0
 * Total Accepted:    126K
 * Total Submissions: 167.6K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现
 * 两次 的整数，并以数组形式返回。
 *
 * 你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 * 输入：nums = [1,1,2]
 * 输出：[1]
 *
 *
 * 示例 3：
 * 输入：nums = [1]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * nums 中的每个元素出现 一次 或 两次
 *
 *
 */

// @lc code=start
class Solution {
public:
    // brutal
    vector<int> findDuplicatesM1(vector<int>& nums) {
        int lenn = nums.size();
        vector<int> tmp(lenn + 1, 0);
        for (int i = 0; i < lenn; i++) {
            int val = nums[i];
            tmp[val]++;
        }
        vector<int> res;
        for (int i = 0; i <= lenn; i++) {
            if (tmp[i] == 2) {
                res.push_back(i);
            }
        }
        return res;
    }


    vector<int> findDuplicates(vector<int>& nums) {
        int lenn  = nums.size();
        for (int i = 0; i < lenn; i++) {
            int cur = nums[i];
            int wantPos = cur - 1;
            while(cur != nums[wantPos]) {
                swap(nums[i], nums[wantPos]);
                cur = nums[i];
                wantPos = cur - 1;
            }
        }

        vector<int> res;
        for (int i = 0; i < lenn; i++) {
            if (nums[i] != (i + 1)) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end

/*
 [4,3,2,7,8,2,3,1]


num[i]= i+1
0 1 2 3 4 5 6 7
1 2 3 4 0 0 7 8
  2 3


 [4,3,2,7,8,2,3,1]
 [7,3,2,4,8,2,3,1]

 [7,3,2,4,8,2,3,1]
 [3,3,2,4,8,2,7,1]


 [3,3,2,4,8,2,7,1]
 [2,3,3,4,8,2,7,1]


 [2,3,3,4,8,2,7,1]
 [3,2,3,4,8,2,7,1]

 [0,2,-1,4,8,2,7,1]
 [0,2,-1,4,1,2,7,8]

 [0,2,-1,4,1,2,7,8]
 [1,2,-1,4,0,2,7,8]

 [1,2,-1,4,0,2,7,8]
 [1,-1,-1,4,0,0,7,8]

V2
i = 0, swap many times
 [4,3,2,7,8,2,3,1]
 [7,3,2,4,8,2,3,1]
 [3,3,2,4,8,2,7,1]
 [2,3,3,4,8,2,7,1]
 [3,2,3,4,8,2,7,1]
nextStep
i = 1, nums[1] == nums[ nums[1]-1] , continue
i = 2, nums[2] == nums[ nums[2]-1] , continue
i = 3, nums[3] == nums[ nums[3]-1] , continue
i = 4,  nums[4] = 8 , swaps
 [3,2,3,4,8,2,7,1]
 [3,2,3,4,1,2,7,8]
 [1,2,3,4,3,2,7,8]

i = 5, nums[5] == nums[ nums[5]-1] , continue
i = 6, continue
i = 7, continue
final: those nums at pos but  pos != num-1
 [1,2,3,4,3,2,7,8]





Wrong Answer
8/29 cases passed (N/A)
Testcase
[10,2,5,10,9,1,1,4,3,7]
Answer
[10,1,4]
Expected Answer
[10,1]





*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
