/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-09
 */

/*
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (size_t k = 0; k < nums.size(); ++k) {
            size_t i = k + 1;
            size_t j = nums.size() - 1;
            int target = -nums[k];
            while (i < j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    res.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    // filter the same data from left
                    while (i < j && nums[i] == nums[i + 1]) {
                        ++i;
                    }
                    // filter the same data from right
                    while (i < j && nums[j] == nums[j - 1]) {
                        --j;
                    }
                    ++i;
                    --j;
                    continue;
                } else if (sum < target) {
                    ++i;
                } else {
                    --j;
                }
            }
            // filter the same target
            while (k + 1 < nums.size() && nums[k] == nums[k + 1]) {
                ++k;
            }
        }
        return res;
    }
};

static int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // stable_sort(nums, nums+numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    int** res = (int**)malloc(numsSize*numsSize* sizeof(int*));
    int size = 0;
    for (int k = 0; k < numsSize; ++k) {
        int left = k + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[k] + nums[left] + nums[right];
            if (sum == 0) {
                res[size] = (int*)calloc(3, sizeof(int));
                res[size][0] = nums[k];
                res[size][1] = nums[left];
                res[size][2] = nums[right];
                while (left < right && nums[left] == res[size][1]) {
                    ++left;
                }
                while (left < right && nums[right] == res[size][2]) {
                    --right;
                }
                size++;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
        while (k + 1 < numsSize && (nums[k] == nums[k + 1])) {
            ++k;
        }
    }
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i <size; ++i) {
        (*returnColumnSizes)[i] = 3;
    }
    return res;
}

int main() {
    const int len = 6;
    int nums[len] = {-1, 0, 1, 2, -1, -4};
    vector<int> nu(nums, nums + len);

    int rs = 0;
    int* rcs;
    auto res = threeSum(nums, len, &rs, &rcs);
    for (int i = 0; i < rs; ++i) {
        for (int j = 0; j < rcs[i]; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);
    free(rcs);
    cout << "--------" << endl;
    Solution s;
    auto result = s.threeSum(nu);
    for (size_t i = 0; i < result.size(); i++) {
        const auto& rowi = result[i];
        for (size_t j = 0; j < rowi.size(); j++) {
            cout << rowi[j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Tips
https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments
1 如何避免计算重复数据
i=k+1
2 避免结果集重复。
   当找到一组解时，把同样大小的数据过滤掉。因为数组已经排序了，过滤非常容易。

3 C的实现如何精准分配内存？
https://leetcode.com/problems/3sum/discuss/142616/clean-C-solution
每次都realloc
https://leetcode.com/problems/3sum/discuss/7755/Share-my-23ms-C-solutions
只有空间耗尽时，才realloc

或者一次性分配4048个指针
https://leetcode.com/problems/3sum/discuss/7673/My-28ms-C-version
int** _3m = (int**)calloc(4048,sizeof(int*));

4048不够用
分配了 int** res = (int**)malloc(numsSize*numsSize * sizeof(int*));够用，但是花了30.1MB

C的排序用 qsort
qsort(nums, numsSize, sizeof(int), cmpfunc);


*/