/**
 * @file
 * @brief  112-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-08
 */

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
Note: A leaf is a node with no children.

Example:
Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

//Runtime: 4 ms, faster than 76.66% of C++ online submissions for Sum Root to Leaf Numbers.
//Memory Usage: 12.6 MB, less than 28.85% of C++ online submissions for Sum Root to Leaf Numbers.

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
//Memory Usage: 12.5 MB, less than 47.54% of C++ online submissions for Sum Root to Leaf Numbers.

    void m1(TreeNode* root, int &sum, int &total) {
        if (root == NULL) {
            return;
        }
        sum=sum*10+root->val;
        if (!root->left && !root->right) {
            total+=sum;
        } else {
            m1(root->left, sum, total);
            m1(root->right, sum, total);
        }
        sum=sum/10; //回溯 状态重置
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int total = 0;
        //m1(root, sum, total);
        m2(root, sum, total);
        return total;
    }

//Runtime: 8 ms, faster than 24.96% of C++ online submissions for Sum Root to Leaf Numbers.
//Memory Usage: 12.4 MB, less than 58.15% of C++ online submissions for Sum Root to Leaf Numbers.
    void m2(TreeNode* root, int sum, int &total) {
        if (root == NULL) {
            return;
        }
        sum=sum*10+root->val;
        if (!root->left && !root->right) {
            total+=sum;
            return;
        }
        m2(root->left, sum, total);
        m2(root->right, sum, total);
    }


};

int sumNumbers(struct TreeNode* root){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1 Recursive DFS
回溯, int &sum 需要状态重置,和0113类似
113之所以回溯是因为拷贝vector<int>性能不好，所以要修改vector<int>的路径状态

M2 Recursive DFS
无回溯 int sum, 无须重置，

M3 DFS+stack
stack<TreeNode*, int> s;
int记录pathSum

M4 BFS+queue
queue<TreeNode*, int> s;
int记录pathSum

*/
