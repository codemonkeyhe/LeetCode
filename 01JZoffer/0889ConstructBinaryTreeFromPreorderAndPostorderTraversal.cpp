/**
 * @file
 * @brief   P6-Similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-05
 */

/*
Return any binary tree that matches the given preorder and postorder traversals.
Values in the traversals pre and post are distinct positive integers.

Example 1:
Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Note:
1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

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
Solution() {
    preIndex=0;
    posIndex=0;
    i = 0;
}

~Solution() {

}


//Runtime: 20 ms, faster than 17.13% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
//Memory Usage: 22.3 MB, less than 16.67% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

//Runtime: 4 ms, faster than 99.30% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
//Memory Usage: 22.1 MB, less than 16.67% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
    TreeNode* constructTree(vector<int>& pre, int b1, int e1, vector<int>& post, int b2, int e2) {
        if (b1==e1 || b2 == e2)  { //pre or post is empty
            return NULL;
        }
        int cur = pre[b1];
        TreeNode* root = new TreeNode(cur);
        if(b1+1 == e1) { //only one element
            // change root->left==NULL to return root, then time cost from 20ms to 4ms.
            //root->left == NULL;
            return root;
        }
        int leftSonSize = 0;
        int leftSon = pre[b1 + 1];
        int i = 0;
        for (i = b2; i < e2; ++i) {
            if (post[i] == leftSon) {
                break;
            }
        }
        leftSonSize = i - b2 + 1;
        if (leftSonSize != 0) {
            root->left = constructTree(pre, b1 + 1, b1 + 1+leftSonSize , post, b2, b2+leftSonSize);
        }
        int rightSonSize = e2 - b2 - leftSonSize;
        if (rightSonSize != 0) {
            root->right = constructTree(pre, b1 +1+ leftSonSize, e1, post,  b2+leftSonSize, e2 - 1);
        }
        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex = 0, postIndex = 0;
        return constructFromPrePostLee215(pre, preIndex, post, postIndex);
        //return constructTree(pre, 0, pre.size(), post, 0, post.size());
    }


//Runtime: 8 ms, faster than 94.91% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
//Memory Usage: 21.9 MB, less than 16.67% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
    TreeNode* constructFromPrePostLee215(vector<int>& pre, int &preIndex, vector<int>& post, int &postIndex) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[postIndex])
            root->left = constructFromPrePostLee215(pre, preIndex, post, postIndex);
        if (root->val != post[postIndex])
            root->right = constructFromPrePostLee215(pre, preIndex, post, postIndex);
        postIndex++;
        return root;
    }

/*
Lee215 O(N)
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)
    int preIndex = 0, posIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[posIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[posIndex])
            root->right = constructFromPrePost(pre, post);
        posIndex++;
        return root;
    }
*/

    int preIndex;
    int posIndex;
    int i;

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post, string msg) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        i++;
        cout << "i=" << i << " preIndex=" << preIndex << " postIndex=" << posIndex << " root.val=" << root->val
        << " msg=" << msg << endl;
        string father = "fa="+std::to_string(root->val);
        if (root->val != post[posIndex])
            root->left = constructFromPrePost(pre, post, father+" left");
        else {
            cout << "i=" << i << " preIndex=" << preIndex << " postIndex=" << posIndex
            << " root.val=" << root->val << " no need to left" << endl;
        }
        if (root->val != post[posIndex])
            root->right = constructFromPrePost(pre, post, father+" right");
        else {
            cout << "i=" << i << " preIndex=" << preIndex << " postIndex=" << posIndex
            << " root.val=" << root->val << " no need to right" << endl;
        }
        cout << "i=" << i << " preIndex=" << preIndex << " postIndex=" << posIndex << " root.val=" << root->val << " LR DONE"
        << endl;
        posIndex++;
        return root;
    }

};


struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){

}

int main() {
   int len = 7;
   int pre[len] = {1,2,4,5,3,6,7};
   int post[len] = {4,5,2,6,7,3,1};


    /*
    int len = 3;
    int pre[len] = {1,2,3};
    int post[len] = {3,2,1};
   */

    vector<int> preo(pre, pre + len);
    vector<int> posto(post, post + len);

    Solution s;
    //TreeNode * r2 = s.constructFromPrePost(preo, posto, "first");
    TreeNode * r2 = s.constructFromPrePost(preo, posto);
    PrintLXR(r2);
    // 1 2 4 5 3 6 7
    return 0;
}


/*
Tips
M1 递归
以pre[0]为根，pre[1]则是pre[0]的左子树的根节点
在post里寻找pre[1],找到的话，则找到了左子树的数量。然后递归处理同样的问题即可。
XLR pre   1 [2 4 5] [3 6 7]
LRX post  [4 5 2 ] [6 7 3] 1
T=O(N^2)

    1
   / \
  2   3
 / \ / \
4  5 6  7

LXR　in   [452] 1 [673]


M2 O(N)解法
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)


M3 寻父节点法
遍历pre，对于每一个cur=pre[i],在post里寻找cur的位置，从此位置向右搜索 父节点，
只要找到第一个父节点，便把cur优先放入父节点的左孩子，如果左孩子已有了，则作为右孩子
https://www.youtube.com/watch?v=5lWJpTEnyow


Que
Q1 如何证明答案不唯一？
   容易举例子证明

full binary tree  和 数据结构C语言版的 满二叉树 定义不同
A full binary tree is a tree in which every node has either 0 or 2 children.
https://www.techiedelight.com/construct-full-binary-tree-from-preorder-postorder-sequence/
https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
It is not possible to construct a general Binary Tree from preorder and postorder traversals (See this).
But if know that the Binary Tree is Full, we can construct the tree without ambiguity.

pre=XLR
post=LRX
从pre和post只能确定X和LR的关系，无法进一步区分L和R之间的位置关系。所以不唯一。
如果一个节点只有一个子节点时，这个节点是左子节点或者是右子节点,造成了答案不唯一。
例如 pre=GIH post=HIG
G是根，IH可以是G的左子树，也可以是G的右子树。

    G
   / \
  I   I
 /   /
H   H

如果加上full binary tree的限制，则IH必须是G的左子树，因此避免了二义性


Q2 不唯一的答案有多少种？


*/