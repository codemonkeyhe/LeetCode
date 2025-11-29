/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-27
 */

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
/*
https://leetcode.com/submissions/detail/316432138/
Runtime: 12 ms, faster than 93.34% of C++ online submissions for Single Number III.
Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Single Number III.
*/
 vector<int> singleNumber(vector<int>& nums) {
     int bitDiff = 0;
     for (size_t i = 0; i < nums.size(); ++i) {
         bitDiff ^= nums[i];
     }
     int idx = 0;
     for (; idx < 32; ++idx) {
         if ((bitDiff >> idx) & 0x01) {
             break;
         }
     }
     int a = 0;
     int b = 0;
     for (size_t i = 0; i < nums.size(); ++i) {
         if ((nums[i] >> idx) & 0x01) {
             a ^= nums[i];
         } else {
             b ^= nums[i];
         }
     }
     vector<int> res(2, 0);
     res[0] = a;
     res[1] = b;
     return res;
    }

};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){

}


int main() {
    int len = 6;
    int nums[len] = {1,2,1,3,2,5};
    vector<int> nu(nums, nums+len);
    int rS = 0;
    auto r1 = singleNumber(nums, len, &rS);
    for (int i = 0; i < rS; ++i) {
        printf("%d ", r1[i]);
    }
    cout << "------" << endl;
    Solution s;
    auto r2 = s.singleNumber(nu);
    for (auto v : r2) {
        cout << v << " ";
    }
    return 0;
}

/*
Tips
A^A^B^B^C^D=C^D
分割成
A^A^C=C
B^B^D=D
如何把唯一的C和D分到两个组里面，通过C和D上同一个bit的位置的差异，来把C和D分到2个组。
C^D的结果正是C和D的比特位的diff
bit_diff=C^D

https://leetcode-cn.com/problems/single-number-iii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-5-8/
假如我们要找的数字是 a 和 b，一开始我们得到 diff = a ^ b。然后通过异或我们分别求出了 a 和 b 。
其实如果我们知道了 a，b 的话可以通过一次异或就能得到，b = diff ^ a 。
作者：windliang

技巧2 只保留a最低位的1
法1 new_a=a&(-a)
法2 new_a=(a&(a-1)) ^a
法3 new_a=a&(~(a-1))

*/
