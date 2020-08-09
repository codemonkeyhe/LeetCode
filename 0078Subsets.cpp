/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-06
 * @tag backtracking
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
        m3(nums, res);

        //m1(nums, res);

        // vector<int> path;
        // m2(nums, 0, path, res);

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

//Runtime: 4 ms, faster than 73.12% of C++ online submissions for Subsets.
//Memory Usage: 7.1 MB, less than 73.96% of C++ online submissions for Subsets.
    void m2(vector<int>& nums, int begin, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = begin; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            m2(nums, i+1, path, res);
            path.pop_back();
        }
    }

//Runtime: 4 ms, faster than 72.71% of C++ online submissions for Subsets.
//Memory Usage: 7.1 MB, less than 85.10% of C++ online submissions for Subsets.
    void m3(vector<int>& nums,  vector<vector<int>>& res) {
        int len = nums.size();
        int total = 1 << len;  // 2^len
        int cur = 0;
        for (int i = 0; i < total; ++i) {
            cur = i;
            vector<int> subset;
            for (int j = 0; j < len; ++j) {
                if (cur&0x01) {
                    subset.push_back(nums[j]);
                }
                cur >>= 1;
            }
            res.push_back(subset);
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
M1 构造法-循环版  来自CCI
S(n)为n个元素的组合的集合
把S(n-1)的所有组合全部复制一遍，在每个组合里加入a[n]，即可得到S(n)
即 S(n) = S(n-1) + { ComIn_S(n-1), a[n]}


M2 构造法-回溯版

M3 二进制转换法
3个元素的子集数量为2^3=8
N个元素的子集数量为2^N
因为构造子集时，每个元素可以选择加入或者不加入，总共有N个元素，所以是2^N

把加入当做二进制1，不加入当做二进制0
3个元素的子集对应3个bit位,如下所示
000 空集
001 a
010 b
100 c
101 {a,c}
111 {a,b,c}
生成二进制bit序列，再把序列转为子集即可

*/
