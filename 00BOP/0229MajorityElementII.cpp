/**
 * @file
 * @brief BOP 2.3
 * @author MonkeyHe
 * @version 1.0
 * @date 2020-04-02
 */


/*
Given an integer array of size n, find all elements that appear more than ? n/3 ? times.
Note: The algorithm should run in linear time and in O(1) space.

Example 1:
Input: [3,2,3]
Output: [3]

Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
    }
};

//Runtime: 8 ms, faster than 96.97% of C online submissions for Majority Element II.
//Memory Usage: 7.2 MB, less than 100.00% of C online submissions for Majority Element II.
// ?C????? ???? ????????????????C++??
// ?????? res?????????????????returnSize????
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int ma = 0;
    int mb = 0;
    int cnta=0;
    int cntb=0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == ma) {
            cnta++;
            continue;
        }
        if (nums[i] == mb) {
            cntb++;
            continue;
        }
        if (cnta == 0) {
            ma = nums[i];
            cnta = 1;
            continue;
        }
        if (cntb==0) {
            mb = nums[i];
            cntb = 1;
            continue;
        }
        // means cnta!=0 && cntb!=0 && nums[i] !=ma !=mb
        cnta--;
        cntb--;
    }
    int a = 0;
    int b = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (cnta && (nums[i] == ma)) {
            a++;
        } else if (cntb && (nums[i] == mb)) {
            b++;
        }
    }

    int* res = (int*)malloc(sizeof(int) *3);
    *returnSize = 0;
    if (a>numsSize/3) {
        res[(*returnSize)++] = ma;
    }
    if (b>numsSize/3) {
        res[(*returnSize)++] = mb;
    }
    return res;
}
   /* ???????
    *returnSize = 0;
    if (a>numsSize/3) {
        *returnSize +=1;
        a=1;
    } else {
        a=0;
    }
    if (b>numsSize/3) {
        *returnSize +=1;
        b=1;
    } else {
        b=0;
    }
    int *res = NULL;
    if (*returnSize) {
        res=(int*)malloc(sizeof(int)* (*returnSize));
        int i =0;
        if (a) {
            res[i++] = ma;
        }
        if (b) {
            res[i++] = mb;
        }
    }
    return res;
    */

int main() {
    const int len = 8;
    int nums[len] = {1, 2, 2, 3, 2, 1, 1, 3};
    //int nums[len] = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> nu(nums, nums + len);

    // c
    int rs=0;
    int* res = majorityElement(nums, len, &rs);
    for (int i = 0; i < rs; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);

    // cpp

    return 0;
}

/*
Tips similar 169
M0 map  unordered_map

M1 sort + walk

M2 Boyer-Moore Voting Algorithm
https://leetcode-cn.com/problems/majority-element-ii/solution/169ti-sheng-ji-ban-xiang-jie-zhu-xing-jie-shi-tong/



*/
