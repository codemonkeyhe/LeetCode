/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-14
 */

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void RootFirstPrint(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    RootFirstPrint(root->left);
    RootFirstPrint(root->right);
    return;
}

class Solution {
   public:
    TreeNode* build(vector<int>& pre, int p1, int p2, vector<int>& in, int i1, int i2) {
        if (p1 >=p2 || i1>=i2) {
            return NULL;
        }
        int r = pre[p1];
        TreeNode *p = new TreeNode(r);
        int idx = -1;
        for (int i = i1; i < i2; ++i) {
            if (in[i] == r) {
                idx = i;
                break;
            }
        }
        int dis = idx -i1;
        if (idx != -1){
            p->left = build(pre, p1+1, p1+1+dis, in, i1, idx);
            p->right = build(pre, p1+1+dis, p2, in, idx+1, i2);
        }
        return p;
    }

/*
Runtime: 28 ms, faster than 34.42% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 21.4 MB, less than 23.81% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
*/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder,
                           int inorderSize) {

                           }

int main() {
    int len = 5;
    int preorder[len] = {3,9,20,15,7};
    int inorder[len] = {9,3,15,20,7};

    vector<int> pre(preorder, preorder + len);
    vector<int> in(inorder, inorder + len);

    Solution s;
    TreeNode * r2 = s.buildTree(pre, in);
    RootFirstPrint(r2);
    return 0;
}


/*
Tips
M1 递归
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34557/My-neat-C%2B%2B-solution
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/340504/C%2B%2B-simple-recursive-(%2B-detail-explanation)
从preorder寻找根节点X，然后在inorder寻找根节点X位置，砍成左右两个子树。
分割后的左子树的数目=L1, 那么preorder里面在节点X后面L1个元素都属于左子树的preorder

因为 preorder = XLR
inorder = LXR, 当在inorder里面找到X后， 左子树leftT的数组长度 L1=len(L)　右子树rightT的数组长度R1=len(R)
那么在preorder数组里面， 必有  preorder[X+1, X+1+L1)必为leftT的preorder， preorder[X+1+L1, X+L2)比为rightT的preorder

M2 M1递归的基础上优化 find过程
    每次遍历太耗时了， 用 unorder_map把find变成O(1)

M3 用Stack来解决
    TODO


*/