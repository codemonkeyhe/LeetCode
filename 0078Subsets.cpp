/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-06
 * @tag
 */

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        m1(nums, res);
        return res;
    }

    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
    // Memory Usage: 7.1 MB, less than 80.39% of C++ online submissions for Subsets.
    void m1(vector<int>& nums,  vector<vector<int>>& res) {
        if (nums.size() == 0)
            return;
        res.push_back(vector<int>());  // insert empty set
        for (int i = 0; i < nums.size(); ++i) {
            int fixSize = res.size();
            for (int j = 0; j < fixSize; ++j) {
                vector<int>& v = res[j];
                vector<int> new_v(v.begin(), v.end());
                new_v.push_back(nums[i]);
                res.push_back(new_v);
            }
        }
    }

};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {}

int main() {
    const int len = 3;
    int nums[len] = {1, 2, 3};
    vector<int> nu(nums, nums + len);
    Solution s;
    auto res = s.subsets(nu);
    print2DVector(res);

    return 0;
}

/*
Tips
M1 构造法  来自CCI
S(n)为n个元素的组合的集合
把S(n-1)的所有组合全部复制一遍，在每个组合里加入a[n]，即可得到S(n)
即 S(n) = S(n-1) + { ComIn_S(n-1), a[n]}


M2

*/
