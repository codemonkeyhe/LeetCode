/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-10
 * @tag  binarySearch;
 * @similar  81
 */

/*
Given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You should search for target in nums and if you found return its index, otherwise return -1.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1


Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
testcase
[1,3]  target=3

[4,5,6,7,0,1,2]
0

Runtime: 8 ms, faster than 68.56% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11.2 MB, less than 73.96% of C++ online submissions for Search in Rotated Sorted Array.

        while (begin <= end) {  <= 是为了当begin==end时，再最后计算一次，是否满足要求
*/

    int bs(vector<int>& nums, int begin, int end, int target) {
        int mid = 0;
        while (begin <= end) {
            mid = begin + ((end - begin) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < nums[end]) { //右边有序
                if (target > nums[mid] && target <= nums[end]) { //go right
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else { //左边有序
                if (target < nums[mid] && target >= nums[begin]) { //go left
                    end = mid - 1;
                }  else {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
       return bs(nums, 0, nums.size()-1, target);
    }

};

int search(int* nums, int numsSize, int target){

}


int main() {
    Solution s;
}


/*
Tips
数字唯一
M0 暴力法 O(N)

M1 二分法
二分法有Recursion和Iteration 两种实现，
优先使用Iteration
 思维陷阱 单纯和nums[mid]比较 无法得出结果
 target > nums[mid]　goRight??
 [5,6,7,0,1,2,4]  target= 5  goLeft
 mid=3 nums[mid] = 0

 target < nums[mid]　goLeft??
 [4,5,6,7,0,1,2]  target=2　 goRight
 mid=3 nums[mid] = 7

错误思路
if tg >n[mid]
    if tg <= n[end] go right
    else go left
if tg <n[mid]
   if tg >= n[begin] go left
   else go right
例如
 1,2,4,5,6,7,0  tg=6,7  应该goRight
按照上面逻辑 就会goLeft

错误思路2  确定左右区间有序后，不能只和 nums[mid]比较
if (nums[mid]<nums[end]) //右区间有序
    if (tg>nums[mid]) go right
    else go left
else [if(nums[mid]>nums[end])] //左区间有序
    if (tg<nums[mid]) go left
    else go right

首先把nums[mid]和nums[end]或者nums[begin]去比较 确定是否左或者右区间的单调性!!!
 0,1,2,4,5,6,7
 7,0,1,2,4,5,6
 6,7,0,1,2,4,5
 5,6,7,0,1,2,4
 4,5,6,7,0,1,2
 2,4,5,6,7,0,1  tg=7
 1,2,4,5,6,7,0  tg=6,7
if (nums[mid]<nums[end]) //右区间有序
    if (tg>nums[mid] && tg<= nums[end]) go right
    else go left
else [if(nums[mid]>nums[end])] //左区间有序
    if (tg<nums[mid] && tg >= nums[begin]) go left
    else go right


M2 数组法
下标对应nums[i], value对应nums[i]的i
数字范围大小有限
-10^4 <= nums[i] <= 10^4

*/


