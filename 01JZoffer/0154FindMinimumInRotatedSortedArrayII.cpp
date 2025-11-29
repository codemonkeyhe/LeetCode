/**
 * @file
 * @brief 1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-11
 * @tag
 * @similar
 */

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0

Note:
This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 72.12% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
Memory Usage: 12.5 MB, less than 37.85% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
*/
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        while(l<r){
            mid  = l + ((r-l) >> 1);
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
                l++;
                r--;
                continue;
            }
            if (nums[mid] <= nums[r]) { //go left  nums[mid] maybe minVal
                r = mid;
            } else { //go right  nums[mid] > nums[r]
                l = mid+1;
            }
        }
        return nums[l];
    }

};

int findMin(int* nums, int numsSize){

}


int main() {
    Solution s;
}


/*
Tips
重复的元素带来的影响
1 2 2 2 2
2 1 2 2 2 //n[l] == n[mid] == n[r]
2 2 1 2 2
2 2 2 1 2 //n[l] == n[mid] == n[r]
2 2 2 2 1
mid=2 r=4  if(nums[2] < nums[4]) goLeft不成立
改成  if(nums[2] <= nums[4])  goLeft 也不成立
除非剔除  //n[l] == n[mid] == n[r]的情况  【借助了0081的经验】

2 2 2 2 3
3 2 2 2 2
2 3 2 2 2  //n[l] == n[mid] == n[r]
2 2 3 2 2
2 2 2 3 2  //n[l] == n[mid] == n[r]

T最坏情况为O(N)

153逻辑
if nums[mid] < nums[r]
    goLeft
    end = mid; //这里没有+1 是因为 nums[mid] 可能是最小值
else
    goRight
    begin = mid+1;  //这里加1是因为 nums[mid]>nums[r] 可知 nums[mid]必然不是最小值



M1

M2

*/


