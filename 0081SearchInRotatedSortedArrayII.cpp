/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-10
 * @tag
 * @similar
 */

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?


*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
       return bs(nums, 0, nums.size()-1, target);
    }

    /*
   [1,3]   2

[2,5,6,0,0,1,2]
3

[3,1,1]
3

Runtime: 4 ms, faster than 99.80% of C++ online submissions for Search in Rotated Sorted Array II.
Memory Usage: 14 MB, less than 65.91% of C++ online submissions for Search in Rotated Sorted Array II.
    */
    bool bs(vector<int>& nums, int begin, int end, int target) {
        int mid = 0;
        while (begin <= end) {
            mid = begin + ((end - begin) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[end] && nums[mid] == nums[begin]) {
                end--;
                begin++;
                continue;
            }
            //BUG if (nums[mid] < nums[end]) { //右边有序
            if (nums[mid] <= nums[end]) { //右边有序
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
        return false;
    }




};

bool search(int* nums, int numsSize, int target){

}


int main() {
    Solution s;
}


/*
Tips
和033比，多了元素重复，重复带来了什么问题?
mid=0+(3-0)/2 = 1
1 1 1 3  左右都有序
3 1 1 1 右有序
1 3 1 1 右有序
1 1 3 1  左有序
1 1 1 3 1 左有序  nums[mid] == nums[begin] == nums[end]
1 3 1 1 1 右有序  nums[mid] == nums[begin] == nums[end]
即if (nums[mid]<=nums[end]) 不一定得到 右区间有序

1 2 3 3 3 3 3
3 1 2 3 3 3 3  //nums[begin] == nums[mid] == nums[low]
3 3 1 2 3 3 3
3 3 3 1 2 3 3
3 3 3 3 1 2 3  //nums[begin] == nums[mid] == nums[low]
3 3 3 3 3 1 2
2 3 3 3 3 3 1

当nums[mid] == nums[end]时
在[mid+1, end]遍历，
    如果全部相等，并且不等于target，则去搜左边
    如果部分相等，说明左区间有序，则比较nums[mid] nums[begin] 和target的关系

M1  二分法
T= O(N)  Tavg=O(logN)
033解法
if (nums[mid]<nums[end]) //右区间有序
    if (tg>nums[mid] && tg<= nums[end]) go right
    else go left
else [if(nums[mid]>nums[end])] //左区间有序
    if (tg<nums[mid] && tg >= nums[begin]) go left
    else go right

081解法
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C%2B%2B-solution-(o(logn)-on-average-o(n)-worst-case)
把  nums[begin] == nums[mid] == nums[low] 拿出来特殊考虑 【这一点需要枚举大量例子才能意识到】
在比较nums[mid]!=target后， 遇到这种情况时，收缩区间，begin++  end--
然后剩余部分和033基本相同 只是把 < 改成了<=
if (nums[mid]<=nums[end]) //右区间有序
    if (tg>nums[mid] && tg<= nums[end]) go right
    else go left
else [if(nums[mid]>nums[end])] //左区间有序
    if (tg<nums[mid] && tg >= nums[begin]) go left
    else go right


1 1 1 2 3 3 3
3 1 1 1 2 3 3
3 3 1 1 1 2 3
3 3 3 1 1 1 2
2 3 3 3 1 1 1
1 2 3 3 3 1 1
1 1 2 3 3 3 1




M2

*/


