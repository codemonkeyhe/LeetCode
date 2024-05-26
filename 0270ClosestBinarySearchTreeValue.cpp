/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-26
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=270 lang=cpp
 *
 * [270] 最接近的二叉搜索树值
 *
 * https://leetcode.cn/problems/closest-binary-search-tree-value/description/
 *
 * algorithms
 * Easy (53.09%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    21.2K
 * Total Submissions: 40K
 * Testcase Example:  '[4,2,5,1,3]\n3.714286'
 *
 * 给你二叉搜索树的根节点 root 和一个目标值 target ，请在该二叉搜索树中找到最接近目标值 target
 * 的数值。如果有多个答案，返回最小的那个。
 *
 *
 * 示例 1：
 * 输入：root = [4,2,5,1,3], target = 3.714286
 * 输出：4
 *
 *
 * 示例 2：
 * 输入：root = [1], target = 4.428571
 * 输出：1
 *
 * 提示：
 * 树中节点的数目在范围 [1, 10^4] 内
 * 0 <= Node.val <= 10^9
 * -10^9 <= target <= 10^9
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
    // M1
    int closestValueM1(TreeNode* root, double target) {
        vector<int> arr;
        LXR(root, arr);

        int i = 0;
        int len = arr.size();
        for (; i < len;i++) {
            if (arr[i] >= target) {
                break;
            }
        }
        if (i== len) {
            return arr[len-1];
        }
        double dis1 = double(arr[i])-target;
        if (i == 0) {
            return arr[0];
        }
        double dis2 = target - double(arr[i-1]);
        if (dis2 <= dis1) {
            return arr[i-1];
        }
        return arr[i];
    }


    void LXR(TreeNode* root, vector<int> &arr) {
        if (root == NULL) {
            return ;
        }
        LXR(root->left, arr);
        arr.push_back(root->val);
        LXR(root->right, arr);
        return;
    }


    int closestValue(TreeNode* root, double target) {
        if (root == NULL) {
            return 0;
        }
        double minDis = 100000.0;
        int minVal = 0;
        DFS(root, target, minDis, minVal);
        return minVal;
    }


    void DFS(TreeNode* root, double target, double& minDis, int& minVal) {
        if (root == NULL) {
            return;
        }
        DFS(root->left, target, minDis, minVal);
        double dis  = abs(root->val - target);
        if (dis < minDis) {
            minVal = root->val;
            minDis = dis;
        }
        DFS(root->right, target, minDis, minVal);
        return;
    }
};
// @lc code=end

/*
M1 中序遍历成有序数组，再遍历比较最接近的

M2 DFS
相当于中序遍历时，一边遍历一边比较



*/


int main() {
    Solution s;
}


