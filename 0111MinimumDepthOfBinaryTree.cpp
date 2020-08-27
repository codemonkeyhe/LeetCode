/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-25
 * @similar 104 110
 */

/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;


class Solution {
public:

/*
Runtime: 8 ms, faster than 98.08% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 19.8 MB, less than 69.05% of C++ online submissions for Minimum Depth of Binary Tree.
*/
    int depthMin(TreeNode* root, int level) {
        if (!root->left && !root->right) {
            return level;
        }
        int left = INT_MAX;
        if (root->left)
            left = depthMin(root->left, level+1);
        int right = INT_MAX;
        if (root->right)
            right = depthMin(root->right, level+1);
        return  (left <= right ? left : right);
    }

/*
Runtime: 12 ms, faster than 82.47% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 19.7 MB, less than 83.33% of C++ online submissions for Minimum Depth of Binary Tree.
*/
    int depthMinV2(TreeNode* root) {
        if (root == NULL) {
            return  0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int left = INT_MAX;
        if (root->left)
            left = depthMinV2(root->left);
        int right = INT_MAX;
        if (root->right)
            right = depthMinV2(root->right);
        return  (left <= right ? left : right) + 1;
    }

    int minDepth(TreeNode* root) {
        if (root== NULL) {
            return 0;
        }
    //    return depthMin(root, 1);
        //return depthMinV2(root);
        //return depthMinV2(root);
        //return DFS(root);
        //return DFSV2(root);
        //return BFS(root);
        return BFSV2(root);
    }

/*
Runtime: 16 ms, faster than 50.61% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 20 MB, less than 47.62% of C++ online submissions for Minimum Depth of Binary Tree.
*/
    int DFS(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre;
        int d=0;
        int min=INT_MAX;
        while(!s.empty() || cur != NULL) {
            while(cur!=NULL) {
                s.push(cur);
                cur=cur->left;
                d++;
            }
            cur = s.top();
            if (cur->left == NULL && cur->right==NULL) {  // only leaf node need to update min
                if (d < min) {
                    min = d;
                }
            }
            if (cur->right == NULL || cur->right == pre) {
                s.pop();
                d--;
                pre = cur;
                cur = NULL;
            } else {
                cur = cur->right;
            }
        }
        return min;
    }

/*
Runtime: 16 ms, faster than 50.61% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 19.8 MB, less than 69.05% of C++ online submissions for Minimum Depth of Binary Tree.
*/
    int DFSV2(TreeNode* root) {
        stack<pair<TreeNode*, int> > s;
        if(!root) {
            return 0;
        }
        s.push(make_pair(root, 1));
        int min = INT_MAX;
        while(!s.empty()) {
            pair<TreeNode*, int> cp = s.top();
            s.pop();
            TreeNode* cur = cp.first;
            int depth = cp.second;
            if (!cur->left && !cur->right && depth < min) {
                min = depth;
            }
            if (cur->left) {
                s.push(make_pair(cur->left, depth+1));
            }
            if (cur->right) {
                s.push(make_pair(cur->right, depth+1));
            }
        }
        return min;
    }

/*
Runtime: 16 ms, faster than 50.61% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 20 MB, less than 50.00% of C++ online submissions for Minimum Depth of Binary Tree.
*/
    int BFS(TreeNode* root) {
        queue< pair<TreeNode*, int> > q;
        if (root == NULL) {
            return 0;
        }
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<TreeNode*, int> cp = q.front();
                q.pop();
                TreeNode* cur = cp.first;
                int depth = cp.second;
                if (!cur->left && !cur->right) {
                    return depth;
                }
                if (cur->left)
                    q.push(make_pair(cur->left, depth+1));
                if (cur->right)
                    q.push(make_pair(cur->right, depth+1));
            }
        }
        return 0;
    }

/*
Runtime: 8 ms, faster than 98.08% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 20.1 MB, less than 47.62% of C++ online submissions for Minimum Depth of Binary Tree.
*/
    int BFSV2(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        int depth=0;
        while(!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) {//in level traversal , find the first leaf node
                    return depth;
                }
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return 0;
    }

};



int main() {

    const int len = 7;
    int nums[len] = {1, 2, 3, EMPTY_V, EMPTY_V, 6, 7};
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    Solution s;
    auto v = s.minDepth(root);
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
    pure queue, return the depth of the first leaf node when walk by level


深度优先搜索方法的缺陷是所有节点都必须访问到，以保证能够找到最小深度。因此复杂度是 O(N)O(N) 。
一个优化的方法是利用广度优先搜索，我们按照树的层去迭代，第一个访问到的叶子就是最小深度的节点，这样就不用遍历所有的节点了。
作者：LeetCode
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-de-zui-xiao-shen-du-by-leetcode/


4ms sample code
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
*/

