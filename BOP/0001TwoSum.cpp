/**
 * @file 0001TwoSum.cpp
 * @brief 
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-16
 */

/*
 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/


#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int size = nums.size();
    for (int i =0; i< size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;

}
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* res = (int*)malloc(sizeof(int)*2);
    for (int i =0; i< numsSize-1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}


int main() {
    const int len = 4;
    int nums[len] = {2, 7, 11, 15};
    int target = 9;

    // c
    int *res = twoSum(nums, len, target);
    for (size_t i = 0; i < sizeof(res)/sizeof(int); ++i) {
        printf("%d ", res[i]);
    }
    free(res);
    printf("\n");

    // cpp
    Solution s;
    vector<int> nu(nums, nums+len);   
    vector<int> re;
    re = s.twoSum(nu, target);
    for (size_t i = 0; i < re.size(); ++i) {
        cout << re[i] << " ";
    }
    cout << endl;

    return 0;
}

