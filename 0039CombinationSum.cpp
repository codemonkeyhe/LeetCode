/**
 * @file
 * @brief   similar 40 46 47  78  90
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-22
 * @tag
 */

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
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

//Runtime: 8 ms, faster than 87.85% of C++ online submissions for Combination Sum.
//Memory Usage: 10.9 MB, less than 77.41% of C++ online submissions for Combination Sum.
// 较为冗余，剪枝思路不好，是从去重的思路演变而来的，把偏序性引入进去来去除 重复的组合数
    void m11(vector<int>& cd, int target, vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        int newtg = 0;
        for (int i = 0; i < cd.size(); i++) {
            newtg =  target-cd[i];
            if (newtg >= 0) {
                //通过 偏序性来去重
                if (!path.empty() && cd[i] < path.back()) {
                    continue;
                }
                path.push_back(cd[i]);
                m11(cd, newtg, path, res);
                path.pop_back();
            }
        }
    }

/*
// 剪枝思路OK  画图体会begin 和i的转换关系
// i用来遍历同一层级的路径选择，那么用过cd[i]之后，到下一层递归时，只需要从cd[i]的坐标i开始遍历即可，无需从0开始
例如
i=0 begin=0  path=2, 从[2,3,6,7] 遍历每个元素去DFS，下一层函数依旧从 [2,3,6,7] 选取元素
i=1 begin=1时, path=3, 只需要从[3,6,7]去遍历，无需考虑i=0的元素2， 因为上一层已经试过了 path=[2,3, ..]的所有情况
i=2 begin=2时, path=6,依次只需要考虑[6,7]开始的元素，path=[6,2, ..]和[6,3, ..]的分支已经由前面2打头的和3打头的分支遍历过了
*/

//没有sort的性能
    //Runtime: 8 ms, faster than 87.85% of C++ online submissions for Combination Sum.
//Memory Usage: 10.7 MB, less than 90.48% of C++ online submissions for Combination Sum.
//经过sort加速的性能
//Runtime: 4 ms, faster than 98.79% of C++ online submissions for Combination Sum.
//Memory Usage: 10.6 MB, less than 91.37% of C++ online submissions for Combination Sum.
    void m12(vector<int>& cd, int begin, int target, vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < cd.size(); i++) {
            if (target >= cd[i]) {
                path.push_back(cd[i]);
                m12(cd, i, target-cd[i], path, res);
                path.pop_back();
            }
        }
   }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>  res;
        vector<int> path;
        //sort为了提速搜索时提速， 删掉sort一样通过
       // sort(candidates.begin(), candidates.end());
        //m11(candidates, target, path,  res);
        m12(candidates, 0,  target, path,  res);
        return res;
    }

};



int main() {
    const int len = 3;
    int nums[len] = {2,5,3};
    int target = 8;
    vector<int> nu(nums, nums + len);
    Solution s;
    auto res = s.combinationSum(nu, target);
    print2DVector(res);
    return 0;
}


/*
Tips
M1 递归
sort为了提速搜索时提速， 删掉sort一样通过
组合去重的Skill
M11 利用元素的偏序性
例如 组合 {3,5} 和 {5,3} 要去重，只需要保证组合间的元素按升序排列即可，因此构造path时，检查path是否满足升序
M12 利用递归的遍历起始元素begin来去重
这个画上分支图就理解了

T不确定，有2种观点
https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
T=O(2^N)
For time complexity, we should not consider the if-else return condition, because we want the worse case.
So we should consider two things. 1. number of the candidates 2. how we reach the nodes.

E.g. candidates = [1, 2, 3]. And we only have two choices take or not take = how we reach the nodes.
graph: (sorry consider ___ as whitespace)
candidate______________"" ("") ( X= not take, O = take)
____________________ /__ \
1__________________X_____O( 1)
__________________ /__ \ ___ /__ \
2________________X__O___X___O ( 2, 12)
________________ /_ \ / \ / \ _ / ___ \
3______________X__OX_OXOX O(3, 23, 13, 123)
The Os are the node that we created.
So that is why 2^n. The 2 is "take" or "not take".

T=O(N^target)
Time complexity is O(N^target) where N is a length of candidates array.
Space complexity is O(target).
This is worst case and without any optimization, like moving position forward and sorting to stop early.
Just assuming that each recursive step we go over all existing candidates, so base N.
And go as deep as target in our recursive calls (if candidates are close to 1), so power of target.
You can mention that this is worst case and optimizations can make time complexity a little better, for interview I think this should be enough.

M2 DP  TODO
https://leetcode-cn.com/problems/combination-sum/solution/chao-qiang-gifzhu-ni-shi-yong-dong-tai-gui-hua-qiu/
https://leetcode.com/problems/combination-sum/discuss/16656/Dynamic-Programming-Solution
https://leetcode.wang/leetCode-39-Combination-Sum.html

MN 通用回溯方法
https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
https://leetcode-cn.com/problems/combination-sum/solution/xue-yi-tao-zou-tian-xia-hui-su-suan-fa-by-powcai/




类似题目还有:
39. 组合总和
40. 组合总和 II
46. 全排列
47. 全排列 II
78. 子集
90. 子集 II


https://leetcode.com/problems/subsets/
https://leetcode.com/problems/subsets-ii/
https://leetcode.com/problems/permutations/
https://leetcode.com/problems/permutations-ii/
https://leetcode.com/problems/combination-sum/
https://leetcode.com/problems/combination-sum-ii/
https://leetcode.com/problems/palindrome-partitioning/


*/
