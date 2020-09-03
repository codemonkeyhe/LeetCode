/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag   Recursion;BT;
 * @similar  235
 */

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).€
Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

/*
Runtime: 24 ms, faster than 66.85% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 17.9 MB, less than 6.25% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

使用path=bt; 缩短耗时
Runtime: 16 ms, faster than 98.33% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 17.9 MB, less than 6.60% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
*/
    //程序退出时bt不干净，因为push_back和pop_back不对称
    bool helper(TreeNode* root, TreeNode* son,  vector<TreeNode*> &bt, vector<TreeNode*> &path) {
        if (root == NULL)
            return false;
        bt.push_back(root);
        if (root == son) {
            path = bt;
            // path.assign(bt.begin(), bt.end());
            return true;
        }
        bool inLeft = helper(root->left, son, bt, path);
        if (!inLeft)
            helper(root->right, son, bt, path);
        bt.pop_back();
        return false;
    }

    //Runtime: 24 ms, faster than 66.85% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//Memory Usage: 18.7 MB, less than 5.01% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
    // 程序退出时，bt是空的，干净的
    bool helper3(TreeNode* root, TreeNode* son,  vector<TreeNode*> &bt, vector<TreeNode*> &path) {
        if (root == NULL)
            return false;
        if (root == son) {
            path = bt;
            path.push_back(son); //把自己也加入进去
            return true;
        }
        bt.push_back(root);
        bool inLeft = helper3(root->left, son, bt, path);
        if (!inLeft)
            helper3(root->right, son, bt, path);
        bt.pop_back();
        return false;
    }


/*
TLE 超时
拷贝开销太大
*/
    bool helper2(TreeNode* root, TreeNode* son,  vector<TreeNode*> bt, vector<TreeNode*> &path) {
        if (root == NULL)
            return false;
        bt.push_back(root);
        if (root == son) {
            path = bt;
            return true;
        }
        return helper2(root->left, son, bt, path) || helper2(root->right, son, bt, path);
    }

    void rootToNode(TreeNode* root, TreeNode* son,  vector<TreeNode*> &path) {
        vector<TreeNode*> bt;
        //helper ?基于backtracking
        //helper(root, son, bt, path);
        helper3(root, son, bt, path);
        // helper2 基于DFS  TLE
        //helper2(root, son, bt, path);
        return;
    }

/*
M1
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        vector<TreeNode*> bt;
        helper3(root, p, bt, pathP);
        helper3(root, q, bt, pathQ);
        //rootToNode(root, p, pathP);
        //rootToNode(root, q, pathQ);
        int i = 0;
        for(; i < pathQ.size() && i < pathP.size(); i++) {
            if (pathQ[i] != pathP[i]) {
                break;
            }
        }
        if (i == 0)
            return NULL;
        return pathQ[i - 1];
    }


/*
M3
Runtime: 20 ms, faster than 89.38% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 14.5 MB, less than 35.39% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
如果p和q都在树里面，则返回LCA(p,q)
如果p和q两者只有1个都在树里，则返回q或者q
如果p和q都不在树里面，返回
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        //等价写法 if (root->val == p->val || root->val == q->val) {
        if (root == p || root == q) {
            return root;
        }
        //p和q都在左子树，则leftRes=LCA(p,q)
        //p和q只有1个在左子树，则leftRes=p或q
        //p和q都不在左子树，则leftRes=NULL
        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);
        if (leftRes == NULL) { //意味着左子树不存在p或者q节点
            return rightRes;
        }
        if (rightRes == NULL) { //
            return leftRes;
        }
        if (leftRes && rightRes) { //p和q一个在左子树 一个在右子树
            return root;
        }
        return NULL;
    }

/*
等价写法 加深理解
*/
    TreeNode* lowestCommonAncestorM3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode* leftRes = lowestCommonAncestorM3(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestorM3(root->right, p, q);
        if (leftRes == NULL  ) {
            //意味着 rightRes == p || rightRes == q || rightRes==LCA(p,q)
            return rightRes;
        }
        if (rightRes == NULL) { //
        // 意味着 (leftRes == p || leftRes == q || leftRes== LCA(p,q))
            return leftRes;
        }
        //if (leftRes && rightRes) {
        if ((leftRes == p && rightRes == q) ||
            (leftRes == q && rightRes == p)) {
            return root;
        }
        return NULL;
    }


};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

}


int main() {
    Solution s;
}


/*
Tips
M1 公共路径法
 root_to_p  O(N)
 root_to_q O(N)
 寻找两条路径的公共前缀 O(N)


M2  寻父节点法[TODO]
子父关系映射 unordered_map<TreeNode*, TreeNode*> hashmap;
在hashmap寻找p，路径存入set<TreeNode*> setPathP
在hashmap寻找q, 对比setPathP可得LCA


M3 Recursion
浓缩版
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/c-jing-dian-di-gui-si-lu-fei-chang-hao-li-jie-shi-/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || root==p || root==q){ return root; }
    auto left=lowestCommonAncestor(root->left,p,q);
    auto right=lowestCommonAncestor(root->right,p,q);
    if(!left) return right;
    if(!right) return left;
    return root;
}


*/


