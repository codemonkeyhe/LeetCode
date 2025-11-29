/**
 * @file 0167TwoSum2.cpp
 * @brief 
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-16
 */

/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 
 */

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* @brief 两端夹逼定理
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int h = 0;
        int t = numbers.size()-1;
        vector<int> res;
        while (h < t) {
            int s = numbers[h] + numbers[t];
            if (s == target) {
                res.push_back(h+1);
                res.push_back(t+1);
                break;
            } else if (s < target) {
                h++;
            } else {
                t--;
            }
        }
        return res;
    }
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int h = 0;
    int t = numbersSize - 1;
    int* res = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    while (h < t) {
        int s = numbers[h] + numbers[t];
        if (s == target) {
            res[0] = h+1;
            res[1] = t+1;
            break;
        } else if (s < target) {
            h++;
        } else {
            t--;
        }
    }
    return res;
}



int main() {
    const int len = 4;
    int nums[len] = {2, 7, 11, 15};
    int target = 9;

    // c
    int res_len = 0;
    int *res = twoSum(nums, len, target, &res_len);
    for (size_t i = 0; i < (size_t)res_len; ++i) {
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



