/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-23
 * @tag DFS; backtracking
 */

/*
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]

Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
    //Memory Usage: 7.5 MB, less than 87.68% of C++ online submissions for Permutations.
    void m1(vector<int>& nums, int begin,  vector<vector<int>> &res) {
        if (begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            m1(nums, begin+1, res);
            swap(nums[i], nums[begin]);
        }
    }


//Runtime: 4 ms, faster than 86.71% of C++ online submissions for Permutations.
//Memory Usage: 7.5 MB, less than 85.85% of C++ online submissions for Permutations.
    /*
    复杂了，不需要考虑情况总数，next_premutation会自动考虑
           do {
                result.emplace_back(nums);
            } while (next_permutation(nums.begin(), nums.end()));
    */
    void m2(vector<int>& nums, vector<vector<int>>& res) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        int total = 1;
        for (int i = 1; i <= n; i++) {
            total = total*i;
        }
        while(total-->0) {
            res.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        };
    }

//Runtime: 4 ms, faster than 86.71% of C++ online submissions for Permutations.
//Memory Usage: 8.4 MB, less than 19.77% of C++ online submissions for Permutations.
    void m31(vector<int>& nums, set<int> &used,  vector<int> &path, vector<vector<int>> &res) {
        if (used.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used.count(nums[i])) {
                path.push_back(nums[i]);
                used.insert(nums[i]);
                m31(nums, used, path, res);
                used.erase(nums[i]);
                path.pop_back();
            }
        }
    }

//Runtime: 4 ms, faster than 86.71% of C++ online submissions for Permutations.
//Memory Usage: 7.6 MB, less than 68.33% of C++ online submissions for Permutations.
    void m32(vector<int>& nums, vector<bool> &used,  vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            m32(nums, used, path, res);
            used[i] = false;
            path.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        //m1(nums, 0,  res);
        //m2(nums, res);

        vector<int> path;
        //set<int> used;
        //m31(nums, used, path, res);

        vector<bool> used(nums.size(), false);
        m32(nums, used, path, res);

        return res;
    }

};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

}


int main() {

    const int len = 3;
    int nums[len] = {1,2,3};
    vector<int> nu(nums, nums + len);
    Solution s;
    auto res = s.permute(nu);
    print2DVector(res);

    return 0;
}


/*
Tips
M1 递归+swap
初始数组 [1,2,3]
按照全排列的定义去构造。总共有3个坑XXX,每个X放入一个数字，第一个X有3种选择，第二个X有2种选择。
情况总数 P(3,3)=3!=6
先选第一个元素,选这个操作就是swap(0,0)，把选中的元素放到数组前面，没选中的元素先丢到数组末尾
(1) 2 3  -> (1 2) 3 -> (1 2 3)
(1) 2 3  -> (1 3) 2 -> (1 3 2)
再选第二个元素, swap(0,1)
(2) 1 3  -> (2 1) 3 -> (2 1 3)
(2) 1 3  -> (2 3) 1 -> (2 3 1)
再选第三个元素, swap(0,2)
(3) 2 1  -> (3 2) 1 -> (3 2 1)
(3) 2 1  -> (3 1) 2 -> (3 1 2)
swap方法缺点：
1. 全排列不能按照字段序生成，例如先生成(3 2 1)，最后生成(3 1 2)
2. 需要改变原数组
3. 当全排列有重复元素时，会有问题。参见0047

M2 参照0031
先sort
依次生成NextPermutation
需要生成An:n次 = n!次

M3 全排列定义法
需要标记这个元素是否使用过，用过的无法使用
M31 用一个set<int>来标记元素是否使用过, 用过的元素加入到set,使用过的元素在下一层递归时不可以再选
M32 用一个vector<bool>来标记元素是否使用过,用过的元素的下标加入到vector,使用过的元素在下一层递归时不可以再选
M32方案最好


Skill
0040可以把i+1传递给下一层的DFS，实现用过了的元素不再使用，
0046无法这么做，因为0040的结果是组合，最终结果的元素和位置无关。
而0046是要生成全排列，是和位置有关系的，DFS时每次都要从位置0开始，例如[1,2,3]
当前层选i=1，即元素2时，下一层DFS的元素要么是1(i=0) 要么是3(i=2)，无法从i+1=1+1=2开始选择。
*/
