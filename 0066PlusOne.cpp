/**
 * @file 0066PlusOne.cpp
 * @brief 
 * @author MonkeyHe
 * @version  1.0
 * @date 2018-09-16
 */

/*
 
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
 
*/


#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     //m== 1说明是999的情况
    int m = 0;
        int size = digits.size();
        vector<int> res(size+1,0);
        res[size-1]=1;
    for (int i = size-1; i >=0 ; i--) {
        res[i] += digits[i];
        if (res[i] >= 10 ) {
            res[i] = res[i] -10;
            if (i == 0) {
                m = 1;
                break;
            } else {
                m = 0;
            }
            res[i-1] = 1;
        } 
    }
    if (m == 1) {
        for (int i = size; i >=1; i--) {
            res[i] = res[i-1];
        }
        res[0] =1;
    } else { //去掉末尾多余位
        res.pop_back();
    }
    return res;
}
    
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 思路1：例如999会有溢出危险,先逆序遍历，逆序存储结果，这样便成为 0001，然后再逆序一遍。O(2n)复杂度，2*n存储空间
 思路2：假设确定是三位数，那么则知道只有999才有可能溢出，因此只要判断是否是999即可，是的话返回1000，不是的话返回原来的值+1。依然是O(2n)，N存储空间 
 思路3：预设符号位，假如是三位数，那就申请size=4的数组，然后舍弃第一位。涉及到内存释放，会有内存泄漏。
 因为题目说了不存在前导0，即不存在099这种情况。

本题目采用思路2
 
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
      //m== 1说明是999的情况
    int m = 1;
    for (int i = digitsSize-1; i >= 0 ; i--) {
        if (digits[i] !=9) {
            m = 0;
            break;
        } 
    }
    
    int len = digitsSize+m;
    int* res = (int*)malloc(sizeof(int)*len);
    memset(res, 0, len*sizeof(int));
    int j = len -1;
    res[j] = 1;
    for (int i = digitsSize-1; i >= 0 ; i--) {
        res[j] += digits[i];
        if (res[j] >= 10) {
            res[j] = res[j] -10;
            res[j-1] = 1;
        }
        j--;
    }
    *returnSize = len;
    return res;
}



int main() {
    const int len = 4;
    int nums[len] = {4, 3, 2, 1};

    // c
    int res_len = 0;
    int *res = plusOne(nums, len, &res_len);
    for (size_t i = 0; i < (size_t)res_len; ++i) {
        printf("%d ", res[i]);
    }
    free(res);
    printf("\n");

    // cpp
    Solution s;
    vector<int> nu(nums, nums+len);   
    vector<int> re;
    re = s.plusOne(nu);
    for (size_t i = 0; i < re.size(); ++i) {
        cout << re[i] << " ";
    }
    cout << endl;

    return 0;
}



    
