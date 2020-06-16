/**
 * @file
 * @brief  94-144-145-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-19
 */

/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/
    void LXR(TreeNode* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        LXR(root->left, res);
        res.push_back(root->val);
        LXR(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        int m = 4;
        switch (m) {
            case 0:
                LXR(root, res);
                break;
            case 1:
                InOrderSet(root, res);
                break;
            case 2:
                InOrderM2(root, res);
                break;
            case 3:
                InOrderM25(root, res);
                break;
            case 4:
                Morris(root, res);
                break;
            case 5:
                MorrisChangeTree(root, res);
                break;
        }
        return res;
    }

 //LXR 本质是DFS DFS可用stack改成迭代

/*
Runtime: 4 ms, faster than 28.84% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.

use set is a fool method
*/
    void InOrderSet(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> s;
        //BUG set<int> walked;  if two node has same value
        set<TreeNode*> walked;
        if (root==NULL){
            return;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            if (cur->left!=NULL) {
                if (!walked.count(cur->left)) {
                    s.push(cur->left);
                    continue;
                }
            }
            s.pop();
            res.push_back(cur->val);
            walked.insert(cur);
            if (cur->right != NULL) {
                s.push(cur->right);
            }
        }
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/

    void InOrderM2(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }

    //set 通用版
    void InOrderM25(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> s;
        set<TreeNode*> walked;
        if(root == NULL) {
            return ;
        }
        s.push(root);
        TreeNode* cur;
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            if (!walked.count(cur)) {
                // FILO(XRL) = LRX  = post
                s.push(cur);
                walked.insert(cur);
                if (cur->right != NULL) {
                    s.push(cur->right);
                }
                // FILO(RXL) = LXR  = in
                //s.push(cur);
                //walked.insert(cur);
                if (cur->left != NULL) {
                    s.push(cur->left);
                }
                // FILO(RLX) = XLR  = pre
                //s.push(cur);
                //walked.insert(cur);
            } else {
                res.push_back(cur->val);
            }
        }
    }

    vector<int> inorderTraversalM3(TreeNode* root) {
        vector<int> res;
        return res;
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/
    void Morris(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root;
        TreeNode* pre;
        while (cur != NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right!=NULL && pre->right != cur){
                    pre = pre->right;
                }
                if (pre->right == NULL) {  // first time to visit left tree the rightmost leaf node, pre points leaf node
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/
    void MorrisChangeTree(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root;
        TreeNode* pre;
        while (cur != NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right!=NULL){
                    pre = pre->right;
                }
                pre->right = cur;
                TreeNode* curOld = cur;
                cur = cur->left;
                // change tree
                curOld->left = NULL;
            }
        }
    }

};


const int EMPTY_V = 0x80000000;
TreeNode* buildBinaryTree(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    vector<TreeNode*> data;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == EMPTY_V) {
            data.push_back(NULL);
        } else {
            TreeNode* p = new TreeNode(nums[i]);
            data.push_back(p);
        }
    }
    int len = data.size();
    for (int i = 0; i < len; ++i) {
        TreeNode* node = data[i];
        if (node == NULL) {
            continue;
        }
        int leftPos = 2 * i + 1;
        int rightPos = leftPos + 1;
        if (leftPos < len) {
            node->left = data[leftPos];
        }
        if (rightPos < len) {
            node->right = data[rightPos];
        }
    }
    return data[0];
}

int main() {

    const int len = 7;
    int nums[len] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    Solution s;
    auto v = s.inorderTraversal(root);
    for (auto e: v) {
        cout << e << " ";
    }

    return 0;
}


/*
Tips

M1 recursive, DFS
T=O(N)
S=O(lgN)

M2 DFS to iterate, use stack
T=O(N)
S=O(N)

M2.5 iterate + stack , use null as visited mark,  this is a common solusion for LXR,XLR, LRX
(N) means null mark
LXR = LX(N)R
XLR = X(N)LR
LRX = LRX(N)
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/wan-quan-mo-fang-di-gui-bu-bian-yi-xing-miao-sha-q/
但是这种方法对于LXR和XLR来说有点多余，太多冗余的nullptr入栈了，不推荐

M3 Morris Traversal (Threaded BinaryTree)
基于线索二叉树
https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/148939/CPP-Morris-Traversal
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/dong-hua-yan-shi-94-er-cha-shu-de-zhong-xu-bian-li/


有两种Morris Traversal, 一种会改变树结构，即官方的答案，另外一种中途会改变树结构，但是最后会复原整棵树，见最后。
https://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion

https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode/
本方法中，我们使用一种新的数据结构：线索二叉树。方法如下：
Step 1: 将当前节点current初始化为根节点
Step 2: While current不为空，
若current没有左子节点
    a. 将current添加到输出
    b. 进入右子树，亦即, current = current.right
否则
    a. 在current的左子树中，令current成为最右侧节点的右子节点
    b. 进入左子树，current = current.left [把current设为调整后的树的树根]
举例而言:
          1
        /   \
       2     3
      / \   /
     4   5 6

首先，1 是根节点，所以将 current 初始化为 1。1 有左子节点 2，current 的左子树是
         2
        / \
       4   5
在此左子树中最右侧的节点是 5，于是将 current(1) 作为 5 的右子节点。
令 current = cuurent.left (current = 2)。 [current=1  current->left=2,  执行了此句后,current指向了2 ]
现在二叉树的形状为:
         2
        / \
       4   5
            \
             1
              \
               3
              /
             6

对于 current(2)，其左子节点为4，我们可以继续上述过程
        4
         \
          2
           \
            5
             \
              1
               \
                3
               /
              6

由于 4 没有左子节点，添加 4 为输出，接着依次添加 2, 5, 1, 3 。节点 3 有左子节点 6，故重复以上过程。
最终的结果是 [4,2,5,1,6,3]。
*/

/*
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
https://leetcode.wang/leetCode-94-Binary-Tree-Inorder-Traversal.html
Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.
1. Initialize current as root
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left

Although the tree is modified through the traversal, it is reverted back to its original shape after the completion.
Although the tree is modified through the traversal, it is reverted back to its original shape after the completion.
Although the tree is modified through the traversal, it is reverted back to its original shape after the completion.

#include <stdio.h>
#include <stdlib.h>

// A binary tree tNode has data, a pointer to left child and a pointer to right child
struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};

// Function to traverse the binary tree without recursion and without stack
void MorrisTraversal(struct tNode* root)
{
    struct tNode *current, *pre;
    if (root == NULL)
        return;
    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            // Find the inorder predecessor of current
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            // Make current as the right child of its inorder predecessor
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
            // Revert the changes made in the 'if' part to restore the original tree i.e.,
             //   fix the right child of predecessor
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            } // End of if condition pre->right == NULL
        } // End of if condition current->left == NULL
    } // End of while
}

// UTILITY FUNCTIONS
// Helper function that allocates a new tNode with the given data and NULL left and right pointers.
struct tNode* newtNode(int data)
{
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Driver program to test above functions
int main()
{

     Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
    struct tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    MorrisTraversal(root);

    return 0;
}


*/

