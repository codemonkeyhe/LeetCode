/**
 * @file
 * @brief  JZ-P39
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-25
 * @tag
 * @similar 111 110
 */

/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 62.23% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.8 MB, less than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
*/
    int depthMax(TreeNode* root, int level) {
        if (root==NULL) {
            return level;
        }
        int left = depthMax(root->left, level+1);
        int right = depthMax(root->right, level+1);
        return  (left < right ? right : left);
    }

/*
Runtime: 12 ms, faster than 62.23% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19 MB, less than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
*/
    int depthMaxV2(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = depthMaxV2(root->left);
        int right = depthMaxV2(root->right);
        return (left<right? right : left) +1;
    }

    int maxDepth(TreeNode* root) {
        //return depthMax(root, 0);
        //return depthMaxV2(root);
        //return DFS(root);
        //return BFS(root);
        return BFSV2(root);
    }

/*
Runtime: 8 ms, faster than 93.00% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19.1 MB, less than 98.90% of C++ online submissions for Maximum Depth of Binary Tree.
使用stack模拟真实的根到叶的路径，容易编写出错。最好还是用 stack<pair<TreeNode*, Depth> >，方便编写
借鉴了 LXR 树的遍历的迭代写法
*/
    int DFS(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre;
        int i = 0;
        int max = 0;
        while(!s.empty() || cur !=NULL) {
            while(cur!=NULL) {
                s.push(cur);
                cur = cur->left;
                i++;
            }
            if (i>max) {
                max = i;
            }
            cur = s.top();
            if (cur->right==NULL || cur->right == pre) {
                s.pop();
                i--;
                pre = cur;
                cur = NULL;
            } else {
                cur = cur->right;
            }
        }
        return max;
    }

/*
Runtime: 4 ms, faster than 99.50% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19 MB, less than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
使用nullptr作为每一层的标记，相当于换行符，这样做比较蠢
*/

    int BFS(TreeNode* root) {
        queue<TreeNode*> q;
        if (root!=NULL) {
            q.push(nullptr);
            q.push(root);
        } else {
            return 0;
        }
        TreeNode* cur;
        int max = -1;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur!= NULL) {
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            } else {
                max++;
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
        }
        return max;
    }

/*
Runtime: 8 ms, faster than 93.00% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19.3 MB, less than 79.12% of C++ online submissions for Maximum Depth of Binary Tree.
*/

    int BFSV2(TreeNode* root) {
        queue<TreeNode*> q;
        if (root!=NULL) {
            q.push(root);
        }
        TreeNode* cur;
        int max = 0;
        while(!q.empty()) {
            int size = q.size();
            max++;
            for (int i = 0; i < size; ++i) {
                cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return max;
    }



};


int main() {

    const int len = 7;
    int nums[len] = {1, 2, 3, EMPTY_V, 5, 6, 7};
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    Solution s;
    auto v = s.maxDepth(root);
    cout << v << endl;

    return 0;
}

/*
Tips
M1 recursive

M2 iterate stack DFS
M2.1  stack element  is pair<TreeNode*, Depth>
    easy to write
M2.2 pure stack, stack element is TreeNode*
    use stack to record the path from root to leaf node and calcute the length of the path
    just like 094 InOrderTraversal

M3 iterate queue BFS
M3.1
    just like 102 LevelOrderTraversal
    use nullptr to seperate next level
M3.2
    pure queue, calc batch size

*/
