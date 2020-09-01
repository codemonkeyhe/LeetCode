/**
 * @file 0027RemoveElement.cpp
 * @brief
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-17;2020-09-01
 */

/*

Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
    }

*/


#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // M1
    //Runtime: 4 ms, faster than 67.09% of C++ online submissions for Remove Element.
    //Memory Usage: 9.1 MB, less than 28.47% of C++ online submissions for Remove Element.
    int removeElementM1(vector<int>& nums, int val) {
        int len = 0;
        int nsize = nums.size();
        for (int i = 0; i < nsize; ++i) {
            if (nums[i] != val) {
                if (len != i) {
                    nums[len] = nums[i];
                }
                len++;
            }
        }
        return len;
    }

/*
swap时，依然可能把要删除的val swap到前面，因此不能i++
[3]　3
[3 3]  3

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
Memory Usage: 9.1 MB, less than 10.86% of C++ online submissions for Remove Element.
*/
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int k = len - 1;
        int i = 0;
        while (i <= k) {
            if (nums[i] == val) {
                nums[i] = nums[k];
                //不用 swap也可以
                //swap(nums[i], nums[k]);
                k--;
            } else {
                i++;
            }
        }
        return i;
    }
};


int removeElement(int* nums, int numsSize, int val) {
    int len = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            if (len != i) {
                nums[len] = nums[i];
            }
            len++;
        }
    }
    return len;
}


int main() {
    const int len = 9;
    int nums[len] = {0,4,4,0,4,4,4,0,2};
    const int val = 4;

    // c
    int res = removeElement(nums, len, val);
    printf("%d\n", res);

    // cpp
    Solution s;
    vector<int> nu;
    int re = s.removeElement(nu, val);
    cout << re << endl;
    for (size_t i = 0; i < nu.size(); i++) {
        cout << nu[i] << " ";
    }

    return 0;
}

/* Tips
M1 保持元素顺序 O(N)
把元素往前挪

M2 不用保持顺序
要删除的元素swap到末尾

*/

