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

??path=bt; ????????????C++11?????
Runtime: 16 ms, faster than 98.33% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 17.9 MB, less than 6.60% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
*/
    bool helper(TreeNode* root, TreeNode* son,  vector<TreeNode*> &bt, vector<TreeNode*> &path) {
        if (root == NULL)
            return false;
        bt.push_back(root);
        if (root == son) {
            //path = bt;
            path.assign(bt.begin(), bt.end());
            //???return?????bt???????????push_back?pop_back????
            //??bt???????????
            return true;
        }
        bool inLeft = helper(root->left, son, bt, path);
        if (!inLeft)
            helper(root->right, son, bt, path);
        bt.pop_back();
        return false;
    }

/*
TLE ??
??????
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
        //helper ??backtracking ???
        helper(root, son, bt, path);
        // helper2 ??DFS???? TLE
        //helper2(root, son, bt, path);
        return;
    }

/*
M1
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        rootToNode(root, p, pathP);
        rootToNode(root, q, pathQ);
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
??p??q??????????????
??P??q???????????p??q?????!!
??p??q?????????NULL
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        //????: if (root->val == p->val || root->val == q->val) {
        if (root == p || root == q) {
            return root;
        }
        //??root??????p??q??????leftRes???p??q
        //??root????????p??q??leftRes???p?q?LCA
        //??root???????p?????q??leftRes=NULL
        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);
        if (leftRes == NULL) { //????????p??q??????????
            return rightRes;
        }
        if (rightRes == NULL) { //??
            return leftRes;
        }
        if (leftRes && rightRes) { //???????p??q??????????????????
            return root;
        }
        //????????p q???NULL
        return NULL;
    }

/*
?????????
*/
    TreeNode* lowestCommonAncestorM3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        //??root??????p??q??leftRes???p??q?????NULL
        TreeNode* leftRes = lowestCommonAncestorM3(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestorM3(root->right, p, q);
        // if (leftRes == NULL) { //????????p??q??????????
        if (leftRes == NULL  ) {
            //??? rightRes == p || rightRes == q || rightRes==LCA(p,q)
            return rightRes;
        }
        if (rightRes == NULL) { //??
        // ??? (leftRes == p || leftRes == q || leftRes== LCA(p,q))
            return leftRes;
        }
        //if (leftRes && rightRes) { //???????p??q??????????????????
        if ((leftRes == p && rightRes == q) ||
            (leftRes == q && rightRes == p)) {
            return root;
        }
        //????????p q???NULL
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
M1 ????? [???N??]
 ??root_to_p???  O(N)
 ??root_to_q??? O(N)
 ?????????????????? O(N)


M2  ?????[TODO]
?????????????unordered_map<TreeNode*, TreeNode*>??? ???????
???hashmap??p?????????root??????set<TreeNode*> setPathP??
???hashmap??q???????????????setPathP??????????LCA


M3 Recursion
????? ??? ???????
???
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
????
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

????????,?????????
??root->val?p,q?val???????????root->left right?????????????
??root->val?p,q?val?????
?3???
p,q??root->left
p,q??root->right
p,q???root->left ???root->right????root?????

*/


