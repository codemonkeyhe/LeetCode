/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-14
 */

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            res = res^ nums[i];
        }
        return res;
    }

};

int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        res ^= nums[i];
    }
    return res;
}

int main() {
    int len = 5;
    int nums[len] = {4,1,2,1,2};
    vector<int> nu(nums, nums+len);
    printf("%d\n", singleNumber(nums, len));

    Solution s;
    cout << s.singleNumber(nu) << endl;

    return 0;
}



/*
Tips
M1 XOR
等同于 0268
XOR满足交换律和结合律
A^A=A  A^0=0
A^A^B^B^C = C
*/