/**
 * @file 0035SearchInsertPosition.cpp
 * @brief
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-16
 */

/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for (i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == target) {
                break;
            } else if (nums[i] < target ) {
                continue;
            } else {
                break;
            }
        }
        return i;
    }
};

//M2
//Runtime: 4 ms, faster than 90.40% of C online submissions for Search Insert Position.
//Memory Usage: 5.6 MB, less than 88.89% of C online submissions for Search Insert Position.
int searchInsert(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize-1;
    int mid = 0;
    while(l<=r) {
        mid = l + (r-l)/2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target){
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return l;
}


int main() {
    const int len = 4;
    int nums[len] = {1, 3, 5, 6};
    int target = 5;

    // c
    int res = searchInsert(nums, len, target);
    printf("%d\n", res);

    // cpp
    Solution s;
    vector<int> nu(nums, nums+len);
    int re = s.searchInsert(nu, target);
    cout << re << endl;

    return 0;
}


/*
Tips
M1 暴力法
Runtime: 9 ms

M2 二分法

*/