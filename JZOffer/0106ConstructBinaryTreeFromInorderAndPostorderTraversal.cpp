/**
 * @file
 * @brief  P6-similar　　105-106-889 similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-14
 */

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PrintXLR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    PrintXLR(root->left);
    PrintXLR(root->right);
    return;
}

void PrintLXR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintLXR(root->left);
    cout << root->val << " ";
    PrintLXR(root->right);
    return;
}

class Solution {
public:


// Runtime: 24 ms, faster than 66.99% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage: 23.1 MB, less than 11.11% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
    TreeNode* buildBT(vector<int>& inorder, int b1, int e1, vector<int>& postorder, int b2, int e2) {
        if (b1 > e1 || b2 > e2) {
            return NULL;
        }
        TreeNode* cur = new TreeNode(postorder[e2]);
        int i = 0;
        for (i = b1; i <=e1; ++i) {
            if (inorder[i] == cur->val) {
                break;
            }
        }
        int leftSonLen = i-b1;
        int rightSonLen = e1-i;
        if (leftSonLen>0)
            cur->left = buildBT(inorder, b1, b1+leftSonLen-1, postorder, b2, b2+leftSonLen-1);
        if (rightSonLen>0)
            cur->right = buildBT(inorder, b1+leftSonLen+1, e1, postorder, b2+leftSonLen, e2-1);
        return cur;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildBT(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        /*
        int inPos = inorder.size()-1;
        int postPos = postorder.size()-1;
        int stop = INT_MIN;
        return buildM2(inorder,  postorder, inPos, postPos, stop);
        */
    }

// Runtime: 20 ms, faster than 80.07% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage: 23.2 MB, less than 11.11% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
    TreeNode* buildM2(vector<int>& inorder, vector<int>& postorder, int& inPos, int& postPos, int stop) {
        if (postPos < 0) {
            return NULL;
        }
        if (inorder[inPos] == stop) {
            inPos--;
            return NULL;
        }
        TreeNode* cur = new TreeNode(postorder[postPos]);
        postPos--;
        cur->right = buildM2(inorder, postorder,inPos, postPos,  cur->val);
        cur->left = buildM2(inorder, postorder, inPos, postPos, stop);
        return cur;
    }

};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){

}

int main() {

    int len = 5;
    int inorder[len] = {9,3,15,20,7};
    int postorder[len] = {9,15,7,20,3};

/*
    TreeNode* r1 = buildTree(inorder, len, postorder, len);
    PrintXLR(r1);
    cout << endl;
    */

    vector<int> post(postorder, postorder + len);
    vector<int> in(inorder, inorder + len);

    Solution s;
    TreeNode * r2 = s.buildTree(in, post);
    PrintLXR(r2);

    return 0;
}


/*
Tips
M1 逆序遍历PostOrder,末尾的元素就是根节点，再用根节点分割InOrder数组

M2 O(N)解法，不依赖Stack，不用HashMap的O(N)
参照105  stefan pochmann的O(N)解法 和  889 Lee215的O(N)解法
LXR  9 3 15 20 7
LRX  9 15 7 20 3

把LXR倒序遍历，相当于 RXL  7 20 15 3 9
把LRX倒序遍历，相当于 XRL  3 20 7 15 9

然后参照105的解法，基于XRL去构建树，并且告知孩子的stop位置。
为何要基于XRL去构建，因为倒序遍历LRX数组，就是XRL。

X节点的右孩子何时构建完毕？ 当遇到RXL中的X时，表示构建完成，所以右孩子的stoper就是X。

X节点的左孩子何时构建完毕？
解析同 0105
令X的父节点为P1，
若P1->right = X,则在RXL中遇到P1时， 表示X节点的左孩子构建完了。
若P1->left = X, 令X的最近祖先节点为PN，且满足Pn->right也是X的祖先节点。 则在RXL中遇到这个Pn时，表示X节点的左孩子构建完了。

总结成经验，X节点左孩子的stopper等于X节点的stopper



M3 借助Stack

*/