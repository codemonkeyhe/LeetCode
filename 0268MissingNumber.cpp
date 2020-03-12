/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-12
 */

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned long sum = 0;
        size_t len = nums.size();
        for (size_t i = 0; i < len; ++i) {
            sum = sum + (unsigned long)nums[i];
        }
        return  (1+len) * len /2 - sum;
    }

};

int missingNumber(int* nums, int numsSize){
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        res = res ^ (i+1) ^ nums[i];
    }
    return res;
}



int main() {
    const int len = 9;
    int nums[len] = {9,6,4,2,3,5,7,0,1};
    vector<int> nu(nums, nums+len);
    auto r1 = missingNumber(nums, len);
    printf("%d\n", r1);

    Solution s;
    auto r2 = s.missingNumber(nu);
    cout << r2 << endl;

    return 0;
}


/*
Tips
因为空间限制，不能用hash_map
M1  数字移动到对应的下标上 O(N)
    再次遍历数组，下标和数字没对应上的就是缺失的

M2 bit位  2^32-1 bit 空间太大

M3 求和公式,这我都没想到....
 Sum=(A1+AN)*N/2 如果只缺了某个元素，全部减掉一遍

M4 XOR
   A XOR  A = 0
   0 XOR A = A
   A^A^B^B^C = C
   也就是把下标和数字全部XOR一边，成双成对的都会消失，剩下那个单独的就是缺失的数字


https://leetcode.com/problems/missing-number/discuss/69786/3-different-ideas%3A-XOR-SUM-Binary-Search.-Java-code

*/