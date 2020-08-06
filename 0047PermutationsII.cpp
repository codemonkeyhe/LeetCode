/**
 * @file
 * @brief  46-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-23
 * @tag DFS; backtracking
 */

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]

Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
 /*
 M1 错误的剪枝方法
 29 / 30 test cases passed.
             if (i>begin && (nums[i]==nums[begin] || nums[i]==nums[i-1]))
                 continue;
 错误case
 [-1,2,0,-1,1,0,1]
  有3对相同的元素，上面的剪枝只能保证2对相同元素时输出正确结果

  本质在于没有深刻理解swap操作
  例如初始序列
  1 1 2 2 3 3 4
  begin=0, i=6
  swap(0,6) = 4 1 2 2 3 3 1
  DFS begin=1, i=4
  swap(1,4) = 4 3 2 2 1 3 1
  DFS begin=2, i=2
  (4 3 2) 2 1 3 1
  从上面的序列开始用swap生成新的排列
  A) begin=3, i=3
  swap(3,3) = (4 3 2 2) 1 3 1
  B) begin=3, i=4
  swap(3,4) = (4 3 2 1) 2 3 1
  C) begin=3, i=5
  swap(3,5) = (4 3 2 3) 1 2 1
  D) begin=3, i=6
  swap(3,6) = (4 3 2 1) 1 3 2

分支(B)和分支(D)头部重合，尾部经过若干排列后，也必然重合。这就是BUG原因。
分支(D)应该被过滤掉的,但是根据前面的条件，
  D) begin=3, i=6
  未swap前的序列 (4 3 2) 2 1 3 1
  nums[i]=nums[6]=1
  nums[i-1]=nums[5]=3
  nums[begin]=nums[3]=2
  的确满足 if (i>begin && (nums[i]==nums[begin] || nums[i]==nums[i-1]))

之前sort想把相同元素排在一起，方便把相邻且相等的元素直接忽略，但是被多次swap后，这种相等且相邻的关系被破坏了
于是只要相同的元素错开了，就无法被剪枝

如何砍掉分支D？
查看上下文找规律
  D) begin=3, i=6
  (4 3 2) 2 1 3 1
  nums[i]=nums[6]=1
  与未swap前的序列 (4 3 2) 2 1 3 1 中的nums[4]=1相等，因此应该被剪枝。

法1 每次都要把nums[i]与[begin, end]范围元素比较，只要重复就跳过。
法2 当前层swap过的元素记录在册，放到hashset里面，重复的元素不再swap

 */

//Runtime: 8 ms, faster than 86.34% of C++ online submissions for Permutations II.
//Memory Usage: 8.5 MB, less than 87.32% of C++ online submissions for Permutations II.
void m1v1(vector<int>& nums, int begin, vector<vector<int>>& res) {
    if (begin == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); ++i) {
        // BUG if (i > begin && (nums[i] == nums[begin] || nums[i] == nums[i - 1])) continue;
        bool same = false;
        {  // filter
            for (int k = begin; k < i; ++k) {
                if (nums[i] == nums[k]) {
                    same = true;
                    break;
                }
            }
        }
        if (same)
            continue;
        swap(nums[i], nums[begin]);
        m1v1(nums, begin + 1, res);
        swap(nums[begin], nums[i]);
    }
}

//Runtime: 28 ms, faster than 30.97% of C++ online submissions for Permutations II.
//Memory Usage: 9.5 MB, less than 30.51% of C++ online submissions for Permutations II.
void m1v2(vector<int>& nums, int begin, vector<vector<int>>& res) {
    if (begin == nums.size()) {
        res.push_back(nums);
        return;
    }
    unordered_set<int> used;
    for (int i = begin; i < nums.size(); ++i) {
        if (used.count(nums[i]))
            continue;
        used.insert(nums[i]);
        swap(nums[i], nums[begin]);
        m1v2(nums, begin + 1, res);
        swap(nums[begin], nums[i]);
    }
}


// Runtime: 8 ms, faster than 82.96% of C++ online submissions for Permutations II.
// Memory Usage: 8.6 MB, less than 70.75% of C++ online submissions for Permutations II.
/*
BUG
剪枝的bug    if (i>0  && (nums[i] == nums[i-1]))
与046-m32 相比就多了2行剪枝而已
*/
void m2(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i])  //用过的禁止再用
            continue;
        if (i > 0 && !used[i - 1] && (nums[i] == nums[i - 1]))
            continue;
        used[i] = true;
        path.push_back(nums[i]);
        m2(nums, used, path, res);
        path.pop_back();
        used[i] = false;
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        //m3(nums, res);

        sort(nums.begin(), nums.end());
        m1v1(nums, 0,  res);

        //vector<int> path;
        //vector<bool> used(nums.size(), false);
        //m2(nums, used, path, res);

        return res;
    }

/*
Runtime: 4 ms, faster than 98.78% of C++ online submissions for Permutations II.
Memory Usage: 8.1 MB, less than 93.11% of C++ online submissions for Permutations II.
*/
    void m3(vector<int>& nums, vector<vector<int>>& res) {
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
    }


};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

}

int main() {

    // const int len = 3;
    // int nums[len] = {1,1,2};

    const int len = 7;
    int nums[len] = {1,1,2,2,3,3,4};
    vector<int> nu(nums, nums + len);
    Solution s;
    auto res = s.permuteUnique(nu);
    print2DVector(res);

    return 0;
}


/*
Tips
M1 递归+sort+swap
剪枝效率低

M2 递归+used

M3 sort+next_permutation


M1 ErrorCase
14 / 30 test cases passed.
Status: Wrong Answer
Submitted: 9 minutes ago
Input:
[2,2,1,1]
Output:
[[2,2,1,1],[2,1,2,1],[2,1,1,2],[2,1,1,2],[2,1,2,1],[1,2,2,1],[1,2,1,2],[1,1,2,2],[1,2,1,2],[1,2,2,1],[1,1,2,2]]
Expected:
[[1,1,2,2],[1,2,1,2],[1,2,2,1],[2,1,1,2],[2,1,2,1],[2,2,1,1]]

*/
