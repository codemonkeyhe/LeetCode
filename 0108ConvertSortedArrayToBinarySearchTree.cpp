/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-27
 * @tag
 * @similar 109
 */

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

/*
Runtime: 20 ms, faster than 66.52% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 20.6 MB, less than 76.36% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
*/
    TreeNode* buildBST(vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        int mid = (begin + end) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, begin, mid-1);
        root->right = buildBST(nums, mid+1, end);
        return root;
    }

};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

}

int main() {
    Solution s;
}

/*
Tips
M1 DFS  LXR
skill
总是选择中间位置左边的数字作为根节点
int mid = (begin + end) >> 1;
总是选择中间位置右边的数字作为根节点
int mid = (begin + end+1) >> 1;
选择任意一个中间位置数字作为根节点
int mid = (left + right + rand() % 2) / 2;

M2

*/
