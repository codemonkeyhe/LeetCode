/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-22
 * @date 2025-03-12
 * @tag DFS; backtracking
 */

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <algorithm>

using namespace std;

class SolutionOld {
public:


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum II.
//Memory Usage: 10.6 MB, less than 86.48% of C++ online submissions for Combination Sum II.
/*
Skill
1. 元素不重复使用  把i+1传递给DFS
因为元素不能重复使用，因此用过的元素不能再用了，要i+1，而0039可重复使用，是传递i下去的
m1(cd, i+1, target - cd[i], path, res);

2.同层去重
2.1 排序是必须的，才能同层去重剪枝，如果不排序，则这里的剪枝是无效的
if (i>begin && cd[i]==cd[i-1])
一开始只写了 if ( cd[i]==cd[i-1])
结果 Exp1少了[1,1,6]，因为给过滤掉了, 而且当i==0时，有越界的风险。

2.2 理解i>begin
同一层尝试相同的元素是无意义的，会导致重复。所以，同一层选择元素时，要避免重复。
begin是当前target下尝试剩余元素列表的起点， 而i则是指向同一层级的不同元素，进行下一层的DFS。
i>begin 表示对当前层的起点元素不去重，当前层的第二个元素开始，检查是否与前一个元素相同，相同的话则去重。
如果是i>=begin，则cd[i-1]会有数组越界的风险。
*/

    void m1(vector<int>& cd, int begin, int target, vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < cd.size(); ++i) {
            if (target>=cd[i]) {
                //BUG if (cd[i]==cd[i-1])
                if (i>begin && cd[i]==cd[i-1])
                    continue;
                path.push_back(cd[i]);
                m1(cd, i+1, target - cd[i], path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>  res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        m1(candidates, 0,  target, path,  res);
        return res;
    }

};

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.43%)
 * Likes:    1658
 * Dislikes: 0
 * Total Accepted:    610.4K
 * Total Submissions: 1M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。 
 *
 *
 *
 * 示例 1:
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start
class Solution {
public:

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> >  res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int idx = 0;
        bt(candidates, target,  idx,  path, res);
        return  res;
    }

    void bt(vector<int>& nums, int target, int idx, vector<int>& path, vector<vector<int> >& res) {
        if (0 == target) {
            res.push_back(path);
            return ;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > target) {
                continue;
            }
            if ((i > idx) && (nums[i] == nums[i-1])) {
                continue;
            }
            path.push_back(nums[i]);
            bt(nums, target-nums[i],  i+1,   path, res);
            path.pop_back();
        }
        return;
    }

};
// @lc code=end



int main() {

    //const int len = 3;
    //int nums[len] = {2,3,5};

    const int len = 7;
    int nums[len] = {10,1,2,7,6,1,5};
    int target = 8;
    vector<int> nu(nums, nums + len);
    Solution s;
    auto res = s.combinationSum2(nu, target);
    print2DVector(res);
    return 0;
}


/*
Tips
0039  候选集无重复，每个元素可以多次使用，结果要去重
去重只考虑一种情况， 例如组合{2,3,5}和{2,5,3}算重复
sort是可选的，为了加速

0040  候选集有重复，每个元素只能只用1次，结果要去重
去重要考虑2种情况， 一种是同0039的组合结果要去重
一种是 不同位置的相同元素去重，   比如 {2-1st,3-2nd,2-3rd} 和 {3-2nd,2-3rd, 2-4th} 算作重复
因此必须要把元素先sort一遍，遇到相同的元素时，for循环跳过即可
sort是必须的，为了相邻去重

M1  递归+DFS+回溯

SKILL
同层去重
作者：jin-ai-yi
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/he-xin-kao-dian-tong-ceng-qu-zhong-by-jin-ai-yi/
无论是求组合/子集/排列，只要原数组中含有重复元素，通用一个去重方法：
1.先排序，使相同元素相邻；
2.在backtrack的for循环里：
if(i>start&&candidates[i]==candidates[i-1]) continue;

其中i>start一定要理解，i是当前考察的元素下标，start是本层最开始的那个元素的下标，我们的去重是要同层去重，
如果你只写candidates[i]==candidates[i-1]这一个判断条件，那么在dfs树的时候，身处不同层的相同元素的组合/排列也都生成不了
这一点一定要理解，同样考察“同层去重”的题目还有：90. 子集 II

同层去重的好题解有很多，比如这篇：
子集 I 到 子集 II 剪枝的思路

*/
