/**
 * @file
 * @brief  P27-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-09
 */

/*
Given a binary tree, flatten it to a linked list in-place.
For example, given the following tree:
    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    TreeNode* pre;

//Runtime: 8 ms
//Memory Usage: 12.1 MB
    void flattenM11(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* r = root->right;
        if (pre) {
            pre->right = root;
            pre->left = NULL;
        }
        pre = root;
        flattenM11(root->left);
       // flatten(root->right);
        flattenM11(r);
    }

    //Runtime: 16 ms, faster than 11.63% of C++ online submissions for Flatten Binary Tree to Linked List.
    //Memory Usage: 12.1 MB, less than 39.48% of C++ online submissions for Flatten Binary Tree to Linked List.
    void m111(TreeNode* root, TreeNode** pre) {
        if (root == NULL) return;
        TreeNode* r = root->right;
        if (*pre) {
            (*pre)->right = root;
            (*pre)->left = NULL;
        }
        *pre = root;
        m111(root->left, pre);
        m111(r, pre);
    }

    void flatten(TreeNode* root) {
        TreeNode* pre = NULL;
        m111(root, &pre);
    }


//Runtime: 12 ms, faster than 11.63% of C++ online submissions for Flatten Binary Tree to Linked List.
//Memory Usage: 12.3 MB, less than 18.28% of C++ online submissions for Flatten Binary Tree to Linked List.
    void m12(TreeNode* root, TreeNode*& next) {
        if (!root) return;
        m12(root->right, next);
        m12(root->left, next);
        root->right = next;
        root->left = NULL;
        next = root;
    }


    void flattenM12(TreeNode* root) {
        TreeNode* next = NULL;
        m12(root, next);
    }

    //like 145   LRX => RLX
   //  Runtime: 8 ms, faster than 66.37% of C++ online submissions for Flatten Binary Tree to Linked List.
    // Memory Usage: 12.4 MB, less than 12.17% of C++ online submissions for Flatten Binary Tree to Linked List.
    void flattenM2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // bug  必须赋值为NULL，否则野指针容易出问题
        while(!s.empty() || cur != NULL) {
            while(cur!=NULL) {
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            if (cur->left == NULL || cur->left == pre) {
                s.pop();
                // visit cur begin
                cur->right = pre;
                cur->left = NULL;
                // visit cur end
                pre = cur;
                cur = NULL;
            } else {
                cur = cur->left;
            }
        }
    }
};

// M3 Morris
//Runtime: 4 ms, faster than 97.07% of C++ online submissions for Flatten Binary Tree to Linked List.
//Memory Usage: 12.2 MB, less than 33.86% of C++ online submissions for Flatten Binary Tree to Linked List.
void flatten(struct TreeNode* root) {
    struct TreeNode* cur = root;
    struct TreeNode* pre = NULL;
    while (cur != NULL) {
        if (cur->left == NULL) {
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right != NULL) {
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
            cur = cur->right;
        }
    }
}

int main() {

    Solution s;

    return 0;
}


/*
Tips
准确理解题意， 1.是BT不是BST 2.链表的顺序是XLR的顺序，并非按元素大小升序
即就地展开成链表，把right指针当做链表的next指针

M1 XLR
recursive+DFS
因为BT展开成链表的顺序就是XLR，因此很容易想到用PreOrder来遍历节点，同时修改每个节点的right指针，指向下一个要遍历的节点。
但是副作用是修改了right指针后，破坏了树结构，导致XLR递归中断。
此时有2种办法：
m11  副本法
比较直观
在right指针的指向被修改前，先备份一下，然后递归调用时不传递被修改后的right指针，而是传递修改之前的备份指针。

m12 经验法
这里需要一个思维转换，无法从数理逻辑去推导，而是经验。
链表顺序从头到尾是XLR，反过来，从尾到头就是RLX。用RLX去遍历的话，就能避免[按照XLR遍历修改right指针导致递归中断]的缺点

不管是m11,m12,都需要一个pre指针指向当前遍历节点的前一个节点，这样才能组成链表。
pre可以作为Solution的类成员，也可以作为函数参数去传递。前者的移植性不好，改成C代码麻烦。后者C代码也通用。
用作函数参数时，2个选择，二级指针去传递TreeNode** pre，或者传递指针的引用 TreeNode*& pre

M2 XLR
iterate+DFS+stack

M3 Morris
like 094

*/
