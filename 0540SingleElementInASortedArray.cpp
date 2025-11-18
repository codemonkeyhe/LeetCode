/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-18
 * @tag    binarySearch
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
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 *
 * https://leetcode.cn/problems//description/
 *
 * algorithms
 * Medium (60.28%)
 * Likes:    744
 * Dislikes: 0
 * Total Accepted:    155K
 * Total Submissions: 255.7K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 * 请你找出并返回只出现一次的那个数。
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 *
 *
 * 示例 2:
 * 输入: nums =  [3,3,7,7,10,11,11]
 * 输出: 10
 *
 *
 *
 *
 *
 *
 * 提示:
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicateM1(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res = res ^ nums[i];
        }
        return res;
    }

/*
BlueZone: [intMin, left]
RedZone: [right, intMax]
ToBinSplitZone: (left, right)


blueZone                     RedZone
                      res
01  23     偶数 奇数    偶    奇数  偶数
aa  bb  ... k   k      m    n     n

blueZone:  [intMin, left]
定义 [都是成对的区间]

01 2
33 4


5

*/

    bool isBlue(vector<int> &nums, int mid) {
        if (mid % 2 == 0) {
            if (mid+1 < nums.size() && nums[mid] == nums[mid + 1]) {
                return true;
            }
            return false;
        } else {
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                return true;
            }
            return false;
        }
    }

    int singleNonDuplicateM2(vector<int>& nums) {
        int nlen = nums.size();
        int left = -1;
        int right = nlen;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isBlue(nums, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[left + 1];
    }

/*
blueZone:  [intMin, left]
定义 [都是成对的区间]
*/
    bool isBlue2(vector<int> &nums, int mid) {
        if (mid % 2 == 0) {
            if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                return true;
            }
            return false;
        } else {
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                return true;
            }
            return false;
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        int nlen = nums.size();
        int left = 0;
        int right = nlen - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBlue2(nums, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];
    }



};
// @lc code=end

/*
1 ^ 1 = 0
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1

a^a = 0


   0 1 2 3 4 5 6 7 8
  [1,1,2,3,3,4,4,8,8]

   0 1 2 3 4   5  6
  [3,3,7,7,10,11,11]

                      res
01  23     偶数 奇数    偶    奇数  偶数
aa  bb  ... k   k      m    n     n

cond1和cond2是等价的
Cond1
if idx %2 == 0  && (nums[idx] == nums[idx+1])
    move LeftBoarder
    说明 res在 [idx+2, right]范围
Cond2
if idx %2 == 0  && (nums[idx] == nums[idx-1] )
    move rightBoarder
    说明 res在 [left, idx-2]范围

cond3和cond4是等价的
cond3
if idx %2 == 1  && (nums[idx] == nums[idx-1])
    move LeftBoarder
    说明 res在 [idx+1, right]范围
Cond4
if idx %2 == 1  && (nums[idx] == nums[idx+1] )
    move rightBoarder
    说明 res在 [left, idx-1]范围




*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
