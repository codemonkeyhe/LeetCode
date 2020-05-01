/**
 * @file 0053MaximumSubarray.cpp
 * @brief  最大子段和
 * @author MonkeyHe
 * @version 2.0
 * @date 2018-09-17
 * @date 2020-03-06
 *
 */

/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle. 微妙

 */

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

//#define INT_MAX 0x7fffffff
//#define INT_MIN 0x80000000

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int m = 1;
        int maxSum = 0;
        switch (m) {
            case 1:
                maxSum=M1(nums);
            break;
            case 3:
                //maxSum=M3V1(nums);
                //maxSum=M3V2(nums);
                //maxSum=M3V3(nums);
            break;
            case 4:
                maxSum=M4(nums);
            break;
        }
        return maxSum;
    }


    // M1 暴力法 O(N^3) => O(N^2)
    int M1(vector<int>& nums) {
        int maxSum = 0x80000000;
        int sum = 0;
        size_t len = nums.size();
        for (size_t i = 0; i < len; i++) {
            sum = 0;
            for (size_t j = i; j < len; j++) {
                sum+= nums[j];
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }

    // M3 动态规划 O(N)
    // M3V1 Space O(N)*2
    int M3V1(vector<int>& nums) {
        size_t len = nums.size();
        vector<int> start(len,0);
        vector<int> all(len,0);
        start[len-1] = nums[len-1];
        all[len-1] = nums[len-1];
        for (int i = len-2; i>=0; i--) {
            start[i] = max( nums[i], nums[i]+start[i+1]);
            all[i] = max(start[i], all[i+1]);
        }
        return all[0];
    }

    // M3V2 Space O(1)
    int M3V2(vector<int>& nums) {
        size_t len = nums.size();
        int start = nums[len-1];
        int all = nums[len-1];
        for (int i = len-2; i>=0; i--) {
            start = max( nums[i], nums[i]+start);
            all = max(start, all);
        }
        return all;
    }

    // M3V2 换种写法
    int M3V3(vector<int>& nums) {
        size_t len = nums.size();
        int start = nums[len-1];
        int all = nums[len-1];
        for (int i = len-2; i>=0; i--) {
            if (start < 0) {
                start = 0;
            }
            start += nums[i];
            if (start > all) {
                all = start;
            }
        }
        return all;
    }


    // M4 规律法 O(N)
    int M4(vector<int>& nums) {
        int curSum = 0;
        int maxSum = 0x80000000;
        for (size_t i = 0; i < nums.size(); ++i)  {
            if (curSum <= 0) {
                curSum = nums[i];
            } else {
                curSum += nums[i];
            }
            if (curSum > maxSum) {
                maxSum = curSum;
            }
        }
        return maxSum;
    }
};


int getMaxCenter(int *nums, int pos, int left, int right);
int maxSubSum(int *nums, int left, int right);

// M2 分治法 O(N*logN)
int maxSubArray(int *nums, int numsSize)
{
    return maxSubSum(nums, 0, numsSize-1);
}


int maxSubSum(int *nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    int pos = (right+left)/2;
    int sumLeft = maxSubSum(nums, left, pos);
    int sumRight = maxSubSum(nums, pos+1, right);
    int sumCenter = getMaxCenter(nums, pos, left, right);
    int maxSum = -1000;
    if (sumLeft < sumRight) {
        maxSum = sumRight;
    } else {
        maxSum = sumLeft;
    }
    if (maxSum < sumCenter) {
        maxSum = sumCenter;
    }
    return maxSum;
}

int getMaxCenter(int *nums, int pos, int left, int right) {
    int sum = 0;
    int maxLeft = -1000;
    int maxRight = -1000;
    for (int i = pos; i >= left; i--) {
        sum += nums[i];
        if (sum > maxLeft) {
            maxLeft = sum;
        }
    }
    sum = 0;
    for (int j = pos+1; j <= right; j++) {
        sum += nums[j];
        if (sum > maxRight) {
             maxRight =sum;
        }
    }
    return maxLeft+maxRight;
}

int main()
{
    const int len = 9;
    int nums[len] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nu(nums, nums + len);

    // c
    cout <<"HI"<<endl;
    int res = maxSubArray(nums, len);
    printf("C: %d\n", res);
    cout <<"HI2"<<endl;

    // cpp
    Solution s;
    int re = s.maxSubArray(nu);
    cout << "CPP: " << re << endl;
    return 0;
}






/*
Tips:
编程之美 2.14
M1 暴力法 O(N^3) => O(N^2)
M2 分治法 O(N*logN)
    MaxSum(A[0..N]):
        Case1 =MaxLeftSum(A[0..N/2-1])
        Case2 =MaxRightSum(A[N/2 .. N])
        Case3 =MaxCenterSum(A[i..N/2-1.N/2..k])

M3 动态规划 O(N)
    MaxSum[0..N]  = max { A[0],  A[0]+ Start[1], MaxSum[1..N]}, Start[1] = 以A[1]打头的最大和
    ...
    MaxSum[n-1, N] = max { A[n-1], A[n-1] + start[n], MaxSum[n..n]}
    其中Start[n] = A[n] , MaxSum[n..n] = A[n]


M4 规律法 O(N) 和 动态规划很相似
    M4 规律法原理
    假设数组为 A[1...N]
      令最大连续子数组和 MaxSum = A[i...k]
       则 必有  A[i-1] <= 0
                A[i-1] + A[i-2] <= 0
                A[i-1] ...  A[0] <= 0
       即 必有 以i-1结尾向A0延伸的子数组 之和 <=0 ， 即 Sum[k...i-1] <= 0 且 0<=k <i
       因此从左开始遍历数组，但凡遇到 Sum[k...i-1]　<=0的，直接舍弃，则i为潜在的MaxSum的左边界。
       左边界找到了，因此往右遍历，尝试每一个右边界，把每次新加进来的右边界节点求和，与MaxSum比较。
*/