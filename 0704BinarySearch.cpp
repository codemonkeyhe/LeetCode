/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-13
 * @tag  binarySearch
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
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 *
 * https://leetcode.cn/problems/binary-search/description/
 *
 * algorithms
 * Easy (55.39%)
 * Likes:    1737
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 * target，如果目标值存在返回下标，否则返回 -1。
 *
 *
 * 示例 1:
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 *
 *
 * 示例 2:
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 *
 *
 *
 *
 * 提示：
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int searchM1(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i <= j) {
            int mid =  i+(j-i)/2;
            if (target == nums[mid]) {
                return mid;
            }
            if (target > nums[mid]) {
                i = mid+1;
            } else {
                j = mid -1;
            }
        }
        return  -1;
    }

    // blue: <= target
    // red > target
    /*
    blueZone <=target
    redZone > target
           blue   red
    -1,0,3,5,9,   12

    */
    int searchM2(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i <= j) {//[1,2]
            int mid = i + (j - i) / 2;
            // left mid T right
            if (nums[mid] <= target) {
                i = mid + 1;
            } else {
            // left T mid  right
                j = mid - 1;
            }
        }
        if (i >= 1 && nums[i-1] == target) {
            return i-1;
        }
        return -1;
    }


    /*
    blueZone < target
    RedZone >= target
    */
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i <= j) {//[1,2]
            int mid = i + (j - i) / 2;
            // left mid T right
            if (nums[mid] < target) {
                i = mid + 1;
            } else {
            // left T mid  right
                j = mid - 1;
            }
        }
        /*
        if (i < nums.size() && nums[i] == target) {
            return i;
        }*/
        if (j+1 >=0 && j+1 < nums.size() && nums[j+1] == target) {
            return j+1;
        }
        return -1;
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


