/**
 * @file 0026RemoveDuplicatesFromSortedArray.cpp
 * @brief
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-17
 */

/*

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

*/

/*
思路1 最简单 遍历n个元素，把重复的元素放到末尾，每次需要m次移动。复杂度 0(n^2)
             直到下一个元素比当前元素小，则停止遍历

思路2 因为不需要在乎数组的原样保存，参见discuss答案
      k指向有序数组首部, 从头开始遍历，忽略重复的，遇到不重复的添加到k++处

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int len = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }
    int len = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i-1]) {
            nums[len++] = nums[i];
        }
    }
    return len;
}


int main() {
    const int len = 10;
    int nums[len] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // c
    int res = removeDuplicates(nums, len);
    printf("%d\n", res);

    // cpp
    Solution s;
    vector<int> nu;
    int re = s.removeDuplicates(nu);
    cout << re << endl;

    return 0;
}


