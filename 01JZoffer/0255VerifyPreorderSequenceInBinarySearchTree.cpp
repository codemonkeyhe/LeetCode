/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-27
 */

/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Consider the following binary search tree:
     5
    / \
   2   6
  / \
 1   3

Example 1:
Input: [5,2,6,1,3]
Output: false

Example 2:
Input: [5,2,1,3,6]
Output: true

Follow up:
Could you do it using only constant space complexity?
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

    bool XLR(vector<int>& preorder, int l, int r) {
        if (l == r) {
            return true;
        }
        int root = preorder[l];
        int i = 0;
        for (i = l+1; i<=r; ++i) { // find L & R tree border
            if (preorder[i] > root) {
                // means right subtree  root node =i
                break;
            }
        }
        for (int k = i; k <= r; ++k) {
            if (preorder[k] < root) { // right tree invalid
                return false;
            }
        }
        bool left = true;
        // i == l+1 means no left subtree
        if (i>l+1)  {
            left =  XLR(preorder, l+1, i-1);
        }
        bool right = true;
        // i > r(i=r+1) means no right subtree
        if (i<=r) {
            right = XLR(preorder, i, r);
        }
        return left && right;
    }

    bool XLR2(vector<int>& preorder, int l, int r) {
        if (l >= r) {
            return true;
        }
        int root = preorder[l];
        int i = 0;
        for (i = l+1; i<=r; ++i) { // find L & R tree border
            if (preorder[i] > root) {
                // means right subtree  root node =i
                break;
            }
        }
        for (int k = i; k <= r; ++k) {
            if (preorder[k] < root) { // right tree invalid
                return false;
            }
        }
        // i == l+1 means no left subtree
        // i > r(i=r+1) means no right subtree
        return XLR2(preorder, l+1, i-1) && XLR2(preorder, i, r);
    }



    bool verifyPreorder(vector<int>& preorder) {
        return XLR2(preorder, 0, preorder.size()-1);
    }

};



int main() {
  //  const int len = 5;
 //   int nums[len] = {5,2,6,1,3};
    //int nums[len] = {5,2,1,3,6};
    const int len = 4;
   int nums[len] = {5,7,6,8}; //no left tree


    vector<int> nu(nums, nums + len);

    Solution s;
    cout << s.verifyPreorder(nu) << endl;

    return 0;
}


/*
Tips
M1 根据大小寻找LR边界，然后递归
陷阱 左子树不存在或者右子树不存在导致的边界问题

M2

*/
