/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2022-06-26
 * @tag
 * @similar
 */

/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9
Output: True


Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
Output: False
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    bool findTarget2(TreeNode* root, int k) {
        vector<int> res;
        LXR(root, res);
        int i = 0;
        int j = res.size() - 1;
        while (i < j) {
            int sum = res[i] + res[j];
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }

    void LXR(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        LXR(root->left, res);
        res.push_back(root->val);
        LXR(root->right, res);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hm;
      //  return LXR2(root, hm, k);
         return DFS(root, hm, k);
    }

    // 太繁琐了
    bool LXR2(TreeNode* root, unordered_set<int>& hm, int k) {
        if (root == NULL) {
            return false;
        }

        auto r1 = LXR2(root->left, hm, k);
        if (r1) {
            return true;
        }
        int target = k - root->val;
        auto it = hm.find(target);
        if (it != hm.end()) {
            return true;
        }
        hm.insert(root->val);
        auto r2 = LXR2(root->right, hm, k);
        if (r2) {
            return true;
        }
        return false;
    }

    bool DFS(TreeNode* root, unordered_set<int>& hm, int k) {
        if (root == NULL) {
            return false;
        }
        if (hm.count(k - root->val)) {
            return true;
        }
        hm.insert(root->val);
        return  DFS(root->left, hm, k) || DFS(root->right, hm, k);
    }

};

bool findTarget(struct TreeNode* root, int k) {}

int main() {
    Solution s;
    vector<int> data = {5, 3, 6, 2, 4, EMPTY_V, 7};
   // vector<int> data = {2,1,3};
    TreeNode* root = buildBinaryTree(data);
    int target = 9;
    auto res = s.findTarget(root, target);
    cout << res << endl;
}

/*
Tips
M1 中序遍历+双指针
Runtime: 53 ms, faster than 68.48% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 36.8 MB, less than 62.66% of C++ online submissions for Two Sum IV - Input is a BST.

M2 中序遍历+hash表
Runtime: 111 ms, faster than 5.90% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 39.4 MB, less than 14.45% of C++ online submissions for Two Sum IV - Input is a BST.

M3 DFS+hash
Runtime: 115 ms, faster than 5.24% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 39 MB, less than 18.81% of C++ online submissions for Two Sum IV - Input is a BST.

*/
