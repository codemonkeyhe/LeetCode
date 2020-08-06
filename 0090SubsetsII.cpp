/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-06
 */

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        m1(nums, res);
        return res;
    }

//Runtime: 12 ms, faster than 30.04% of C++ online submissions for Subsets II.
//Memory Usage: 7.9 MB, less than 59.09% of C++ online submissions for Subsets II.
    void m1(vector<int>& nums,  vector<vector<int>>& res) {
        if (nums.size() == 0)
            return;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());  // insert empty set
        int lastSetSize = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int fixSize = res.size();
            int begin = 0;
            if (i>0 && nums[i] == nums[i-1]) {
                //添加的元素和之前相同
                begin = lastSetSize;
            }
            for (int j = begin; j < fixSize; ++j) {
                vector<int>& v = res[j];
                vector<int> new_v(v.begin(), v.end());
                new_v.push_back(nums[i]);
                res.push_back(new_v);
            }
            lastSetSize = fixSize;
        }
    }

};


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

}


int main() {
    const int len = 4;
    int nums[len] = {1, 2, 2, 2};
    vector<int> nu(nums, nums + len);
    Solution s;
    auto res = s.subsetsWithDup(nu);
    print2DVector(res);

    return 0;
}


/*
Tips
M1 构造法 同0078
只是要把元素先排序，相同的元素添加时，要区分界限，添加元素时不再需要拷贝整个全集了，而是拷贝上一次的增量

M2

*/
