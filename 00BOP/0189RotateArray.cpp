/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-31
 */

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // M2 反转 分割 再反转
    // Runtime: 16 ms, faster than 81.48% of C++ online submissions for Rotate
    // Array. Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Rotate Array.
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if (k == 0) {
            return;
        }
        int tmp = 0;
        int last = 0;
        // reverse nums
        for (size_t i = 0; i < len / 2; ++i) {
            tmp = nums[i];
            last = len - 1 - i;
            nums[i] = nums[last];
            nums[last] = tmp;
        }
        // reverse nums[0, k-1]
        for (size_t i = 0; i < k / 2; ++i) {
            tmp = nums[i];
            last = k - 1 - i;
            nums[i] = nums[last];
            nums[last] = tmp;
        }
        // reverse nums[k, len-1]
        for (size_t i = k; i < (len + k) / 2; ++i) {
            tmp = nums[i];
            last = len + k - i - 1;
            nums[i] = nums[last];
            nums[last] = tmp;
        }
    }
};


// M3 就地置换
// Runtime: 12 ms, faster than 90.84% of C online submissions for Rotate Array.
// Memory Usage: 7.4 MB, less than 100.00% of C online submissions for Rotate Array.
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return;
    }
     k = k % numsSize;
     if (k == 0) {
         return;
     }
    int p = numsSize-k;
    int cur = nums[p];
    int curPos = p;
    int newPos = 0;
    int begin = p;
    int tmp = 0;
    int cnt = 0;
    while (cnt<=numsSize) {
        newPos = (curPos+k)%numsSize;
        //newPos = (p+k)%numsSize;
        //swap(newPos, curPos)
        tmp = nums[newPos];
        nums[newPos] = cur;
        cur = tmp;
        curPos = newPos;
        cnt++;
        if (curPos == begin) {
            if (cnt == numsSize) {
                break;
            } else {
                curPos = curPos+1;
                cur = nums[curPos];
                begin = curPos;
            }
        }
    }
}

int main() {
    int len = 6;
    int nums[len] = {1, 2, 3, 4, 5, 6};
    int k = 2;
    vector<int> nu(nums, nums + len);
    rotate(nums, len, k);
    for (int i = 0; i < len; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    Solution s;
    s.rotate(nu, k);
    for (auto v : nu) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}

/*
Tips
M1 额外申请一个数组
违背了题意

M2 反转 分割 再反转


M3 就地置换
https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode/



*/