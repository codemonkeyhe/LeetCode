/**
 * @file
 * @brief  113-similar  CCI4.9
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-07; 2025-03-17
 */

/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class SolutionOld {
public:
//Runtime: 24 ms, faster than 67.34% of C++ online submissions for Path Sum III.
//Memory Usage: 15.6 MB, less than 68.32% of C++ online submissions for Path Sum III.
    void m1(TreeNode* root, int sum, int &res) {
        if (root == NULL) {
            return;
        }
        sum -= root->val;
        if (sum == 0) {
            res++;
        }
        m1(root->left, sum, res);
        m1(root->right, sum, res);
    }


    void XLR(TreeNode* root, int sum, int &res) {
        if (root==NULL){
            return;
        }
        m1(root, sum, res);
        XLR(root->left, sum, res);
        XLR(root->right, sum, res);
    }

    int pathSumM1(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        int res = 0;
        XLR(root, sum, res);
        return res;
    }

//Runtime: 24 ms, faster than 67.34% of C++ online submissions for Path Sum III.
//Memory Usage: 16.1 MB, less than 35.58% of C++ online submissions for Path Sum III.

    void m2(TreeNode* root, int sum, vector<int> &path, int &res) {
        if (root==NULL) return ;
        path.push_back(root->val);
        int total = 0;
        for (int i = path.size()-1; i >= 0; i--) {
            total += path[i];
            if (total==sum) {
                res++;
            }
        }
        m2(root->left, sum, path, res);
        m2(root->right, sum, path, res);
        path.pop_back();
    }

    int pathSumM2(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        int res = 0;
        vector<int> path;
        m2(root, sum, path, res);
        return res;
    }

};

/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (47.75%)
 * Likes:    2016
 * Dislikes: 0
 * Total Accepted:    399.5K
 * Total Submissions: 839.9K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 *
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 *
 *
 * 示例 1：
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 *
 *
 * 示例 2：
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 *
 *
 *
 *
 * 提示:
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9  
 * -1000  
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        vector<int> path;
        unordered_map<long long, int> sumToCnt;
        sumToCnt[0] = 1;
        long long sum = 0;
        bt(root, targetSum,  sumToCnt, sum, res);
        return res;
    }

    // Notice: sum要用long long, 对count函数不要误解了，返回值只有0 和1，而非计数
    //  sumToCnt[sum]++要放到前缀和之后，因为target可能为0,如果先插入hashmap，则任意节点的前缀和减去0 依然为本身。
    // sumToCnt[0] =1 因为前缀和要包括根节点
    void bt(TreeNode* root, int target,  unordered_map<long long, int>& sumToCnt,  long long sum, int& res) {
        if (root == NULL) {
            return;
        }

        sum = sum + root->val;
        long long preS = sum - target;
        if ( (sumToCnt[preS] > 0)) {
            res +=  sumToCnt[preS];
        //    cout << "sum=" << sum << " val=" << root->val << " preS=" << preS << " res=" << res <<  endl;
        }
        sumToCnt[sum]++;
        bt(root->left, target,  sumToCnt, sum, res);
        bt(root->right, target, sumToCnt, sum, res);
        sumToCnt[sum]--;
        return;
    }

};
// @lc code=end



int pathSum(struct TreeNode* root, int sum){

}

int main() {

    Solution s;

    return 0;
}


/*

Tips
M1  递归DFS
 路径简化为从根节点出发，到每个节点的路径，得到解法F1
    然后DFS遍历树的每个节点，调用F1
    这样耗时太高 T=O(N) * O(N)　= O(N^2)


M2 Backtracking
本质就是回溯，记录所有的路径和path，然后暴力遍历path
把M1的两步合为一步,则需要把路径信息存到vector里面

M3 HashMap的O(N)解法
核心原理
tree looks like:  R--..--A--..--B
SumPath(A,B) = SumPath(R, B) - SumPath(R, A) = PreSum(B) - PreSum(A)
use map<int, int> to store <PreSum, Count>




修改树结构 不推荐
https://leetcode.com/problems/path-sum-iii/discuss/91888/18ms-Fast-One-Pass-C%2B%2B-Solution

不修改树结构
https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method
For instance : in one path we have 1,2,-1,-1,2, then the prefix sum will be: 1, 3, 2, 1, 3,
let's say we want to find target sum is 2, then we will have 4 ways : {2}-2rd, {1,2,-1}, {2,-1,-1,2} and {2}-5th

Explanatio:
https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method/96424
This is an excellent idea and took me some time to figure out the logic behind.
Hope my comment below could help some folks better understand this solution.

1 The prefix stores the sum from the root to the current node in the recursion
2 The map stores <prefix sum, frequency> pairs before getting to the current node. We can imagine a path from the root to the current node. The sum from any node in the middle of the path to the current node = the difference between the sum from the root to the current node and the prefix sum of the node in the middle.
3 We are looking for some consecutive nodes that sum up to the given target value, which means the difference discussed in 2. should equal to the target value. In addition, we need to know how many differences are equal to the target value.
4 Here comes the map. The map stores the frequency of all possible sum in the path to the current node. If the difference between the current sum and the target value exists in the map, there must exist a node in the middle of the path, such that from this node to the current node, the sum is equal to the target value.
5 Note that there might be multiple nodes in the middle that satisfy what is discussed in 4. The frequency in the map is used to help with this.
6 Therefore, in each recursion, the map stores all information we need to calculate the number of ranges that sum up to target. Note that each range starts from a middle node, ended by the current node.
7 To get the total number of path count, we add up the number of valid paths ended by EACH node in the tree.
8 Each recursion returns the total count of valid paths in the subtree rooted at the current node. And this sum can be divided into three parts:
- the total number of valid paths in the subtree rooted at the current node's left child
- the total number of valid paths in the subtree rooted at the current node's right child
- the number of valid paths ended by the current node

The interesting part of this solution is that the prefix is counted from the top(root) to the bottom(leaves), and the result of total count is calculated from the bottom to the top :D

The code below takes 16 ms which is super fast.

public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        return findPathSum(root, 0, sum, map);
    }
    private int findPathSum(TreeNode curr, int sum, int target, Map<Integer, Integer> map) {
        if (curr == null) {
            return 0;
        }
        // update the prefix sum by adding the current val
        sum += curr.val;
        // get the number of valid path, ended by the current node
        int numPathToCurr = map.getOrDefault(sum-target, 0);
        // update the map with the current sum, so the map is good to be passed to the next recursion
        map.put(sum, map.getOrDefault(sum, 0) + 1);
        // add the 3 parts discussed in 8. together
        int res = numPathToCurr + findPathSum(curr.left, sum, target, map)
                                               + findPathSum(curr.right, sum, target, map);
       // restore the map, as the recursion goes from the bottom to the top
        map.put(sum, map.get(sum) - 1);
        return res;
    }

*/
