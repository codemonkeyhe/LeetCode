/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-25
 */

/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input:

           1
         /   \
        3     2
       / \     \
      5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:
Input:

          1
         /
        3
       / \
      5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:
Input:

          1
         / \
        3   2
       /
      5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

Example 4:
Input:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    // Fool Method ,  Time Limit Exceeded
    // 使用null作为占位符太蠢了，应该发挥下标的作用.
    int widthOfBinaryTreeFool(TreeNode* root) {
        queue<TreeNode*> q;
        if (root==NULL) {
            return 0;
        }
        q.push(root);
        int max = 1;
        int width = 0;
        int stopper = 0;
        while(!q.empty()){
            int size = q.size();
            int leftPos = -1;
            int rightPos = -1;
            int limit = 2*stopper+1;
            for (int i = 0; i < size ; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur==NULL){
                    if (i<=limit) {
                        q.push(NULL);
                        q.push(NULL);
                    }
                } else {
                    if (leftPos==-1) {
                        leftPos = i;
                    } else {
                        rightPos = i;
                    }
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            stopper = leftPos;
            if (rightPos != -1) {
                stopper = rightPos;
                width = rightPos - leftPos+1;
                if (width > max) {
                    max = width;
                }
            }
            if (leftPos == -1) {// cur level no border node
                return max;
            }
        }
        return max;
    }




/*
Runtime: 8 ms, faster than 65.08% of C++ online submissions for Maximum Width of Binary Tree.
Memory Usage: 15.8 MB, less than 33.33% of C++ online submissions for Maximum Width of Binary Tree.

2*pos error
runtime error: signed integer overflow: 2 * 2147483647 cannot be represented in type 'int' (solution.cpp)
*/

    int widthOfBinaryTreeBFS(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long> > q;
        q.push(make_pair(root, 0));
        unsigned long max = 0;
        unsigned long size = 0;
        while(!q.empty()) {
            size = q.size();
            unsigned long width = q.back().second  - q.front().second + 1;
            if (width > max) {
                max = width;
            }
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q.front().first;
                unsigned long pos = q.front().second;
                q.pop();
                if (cur->left) {
                    q.push(make_pair(cur->left, 2*pos));
                }
                if (cur->right) {
                    q.push(make_pair(cur->right, 2*pos+1));
                }
            }
        }
        return max;
    }

/*
Runtime: 8 ms, faster than 65.08% of C++ online submissions for Maximum Width of Binary Tree.
Memory Usage: 16 MB, less than 33.33% of C++ online submissions for Maximum Width of Binary Tree.
*/
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        vector<int> v;
        int maxWidth = 1;
        DFS(root, 0, 0, v, maxWidth);
        return maxWidth;
    }

    void DFS(TreeNode* root, int level, unsigned long pos, vector<int> &v, int &maxWidth) {
        if (v.size()<=level) {
            v.push_back(pos); //leftPos
        } else {
            int width = pos - v[level]+1;
            if (width > maxWidth) {
                maxWidth = width;
            }
        }
        if (root->left) {
            DFS(root->left, level+1, 2*pos, v, maxWidth);
        }
        if (root->right) {
            DFS(root->right, level+1, 2*pos+1, v, maxWidth);
        }
    }
};



int main() {

    const int len = 8;
    int nums[len] = {1, 3, 2, 5, 3, EMPTY_V, 9, 6};
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    Solution s;
    auto v = s.widthOfBinaryTree(root);
    cout << v << endl;


    return 0;
}


/*
Tips

M1 DFS

M2 BFS

TestCase
error test case, not a tree.
[0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,]

*/