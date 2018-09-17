/**
 * @file 0053MaximumSubarray.cpp
 * @brief 
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-17
 */

/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 */

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};

int maxSubArray(int* nums, int numsSize) {
    
}



int main() {
    const int len = 9;
    int nums[len] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nu(nums, nums+len);   

    // c
    int res = maxSubArray(nums, len);
    printf("%d\n", res);

    // cpp
    Solution s;
    int re = s.maxSubArray(nu);
    cout << re << endl;
    return 0;
}





