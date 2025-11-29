/**
 * @file
 * @brief  P19
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-27;20250504
 * @similar 2415
 */

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3


But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Follow up: Solve it both recursively and iteratively.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>


using namespace std;

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (60.28%)
 * Likes:    2945
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }


    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && (r2 == NULL)) {
            return true;
        }
        if (r1 == NULL || (r2 == NULL)) {
            return false;
        }
        if (r1->val != r2->val) {
            return false;
        }
        return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }
};
// @lc code=end



class SolutionJZ {
public:
/*
InOrder as a full binary tree, a full binary tree is every node has 0 or 2 sons.
194 / 195 test cases passed.
Status: Wrong Answer
Input:
[5,4,1,null,1,null,4,2,null,2,null]
Output:
true
Expected:
false

*/
    void InOrder(TreeNode* root, vector<int> &v) {
        if (root->left==NULL && root->right==NULL) { //leaf node
            v.push_back(root->val);
            return;
        }
        if (root->left) {
            InOrder(root->left, v);
        } else {
            v.push_back(INT_MIN);
        }
        v.push_back(root->val);
        if (root->right) {
            InOrder(root->right, v);
        } else {
            v.push_back(INT_MIN);
        }
        return;
    }

    bool isSymmetricM1Bad(TreeNode* root) {
        if (root==NULL) {
            return true;
        }
        vector<int> v;
        InOrder(root, v);
        int i = 0;
        int j = v.size()-1;
        while (i<j) {
            if (v[i++]!=v[j--]) {
                return false;
            }
        }
        return true;
    }

/*
一击必杀
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.6 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
*/
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) {
            return true;
        }
        if (l == NULL || r == NULL) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }

    bool isSymmetricM2(TreeNode* root) {
        if (root==NULL) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isSymmetricM31(struct TreeNode* root) {
        queue<TreeNode*> q;
        if (root == NULL) {
            return true;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur != NULL) {
                    v.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                } else {
                    v.push_back(INT_MIN);
                }
            }
            int i = 0;
            int j = v.size() - 1;
            while (i < j) {
                if (v[i++] != v[j--]) {
                    return false;
                }
            }
        }
        return true;
    }

/*
Runtime: 12 ms, faster than 14.31% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.8 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
*/
    bool isSymmetricM32(struct TreeNode* root) {
        queue<TreeNode*> a;
        queue<TreeNode*> b;
        if (root == NULL) {
            return true;
        }
        a.push(root->left);
        b.push(root->right);
        while(!a.empty()) {
            if (b.empty()) {
                return false;
            }
            TreeNode* ca = a.front();
            a.pop();
            TreeNode* cb = b.front();
            b.pop();
            if (!ca && !cb) {
                continue;
            }
            if (ca == NULL || cb == NULL) {
                return false;
            }
            if (ca->val != cb->val) {
                return false;
            }
            a.push(ca->left);
            a.push(ca->right);
            b.push(cb->right);
            b.push(cb->left);
        }
        return true;
    }

/*
Runtime: 12 ms, faster than 14.31% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.8 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
*/
    bool isSymmetricM33(struct TreeNode* root) {
        queue<TreeNode*> a;
        if (root == NULL) {
            return true;
        }
        a.push(root->left);
        a.push(root->right);
        while(!a.empty()) {
            TreeNode* ca = a.front();
            a.pop();
            TreeNode* cb = a.front();
            a.pop();
            if (!ca && !cb) {
                continue;
            }
            if (ca == NULL || cb == NULL) {
                return false;
            }
            if (ca->val != cb->val) {
                return false;
            }
            a.push(ca->left);
            a.push(cb->right);
            a.push(ca->right);
            a.push(cb->left);
        }
        return true;
    }



};

bool isSymmetric(struct TreeNode* root){

}

int main() {
    //const int len = 6;
    //int nums[len] = {1,2,2,2,EMPTY_V,2};

    const int len = 11;
    int nums[len] = {5,4,1,EMPTY_V,1,EMPTY_V,4,2,EMPTY_V,2,EMPTY_V};
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    SolutionJZ s;
    cout << s.isSymmetricM33(root) << endl;

    return 0;
}


/*
Tips
M1 比较中序遍历的数组是否对称
 1.单纯的中序遍历无法确定，即使Null也要输出，用INT_MIN代替即可，也无法确定
    错误解法 见 isSymmetricM1Bad
    除非是一个满二叉树，要把最下层所有的NULL全部补齐，这样的话浪费太多空间，不划算。
 2.需要带上中序遍历的结构信息，例如深度或者左右孩子结构
例如下面的解法
https://leetcode.com/problems/symmetric-tree/discuss/33398/symmetric-tree-why-inorder-traversal-doesn't-work
https://leetcode.com/problems/symmetric-tree/discuss/33051/inorder-traversal-needs-to-encode-left-and-right-info
https://leetcode.com/problems/symmetric-tree/discuss/445256/a-simple-C%2B%2B-solution-using-in-order-traversal-(0-ms)

M2 递归 比较左右是否相等

M3 BFS+queue
M3.1 检查每一层是否回文
如何检查每层是否回文，用vector

M3.2 BFS+2个queue
  比较两个queue是否相等

M3.3 把3.2的2个queue合并成1个queue


*/