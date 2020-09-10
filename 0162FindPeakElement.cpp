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
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.

Follow up: Your solution should be in logarithmic complexity.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 8 ms, faster than 85.90% of C++ online submissions for Find Peak Element.
Memory Usage: 8.8 MB, less than 96.62% of C++ online submissions for Find Peak Element.
mid+1 <=h 是多余的，可以去掉，仔细思考一下，就发现的确如此
*/
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        while(l<h) {
            // l <= mid < h
            int mid = l + ((h - l) >> 1);
            if (mid+1 <= h && nums[mid] <= nums[mid+1]) { //goR
                l = mid + 1;
            } else { //goL
                h = mid;
            }
        }
        return l;
    }

};

int findPeakElement(int* nums, int numsSize){

}


int main() {
    Solution s;
}


/*
Tips
遍历复杂度为O(N) 不符合题意
潜意识就是2分了，只有二分才能做到log(N)
另外，单调递增的数组的峰值就是最后一个元素，因为 nums[-1] = nums[n] = -∞.

M1

M2

*/


