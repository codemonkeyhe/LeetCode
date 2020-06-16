/**
 * @file
 * @brief  94-144-145-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-21
 */

/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
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
    void LRX(TreeNode* root, vector<int> &res) {
        if (root == NULL)
            return;
        LRX(root->left, res);
        LRX(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        int m = 6;
        switch (m) {
            case 0:
                LRX(root, res);
                break;
            case 1:
                preOrderXLRset(root, res);
                break;
            case 2:
                preOrderXRL(root, res);
                break;
            case 3:
                preOrderPre(root, res);
                break;
            case 4:
                preOrderNull(root, res);
                break;
            case 5:
                Morris(root, res);
                break;
            case 6:
                MorrisChangeTree(root, res);
                break;
        }
        return res;
    }

/*
Runtime: 4 ms, faster than 35.09% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
*/
    void preOrderXRL(TreeNode* root, vector<int>& res) {
        vector<int> tmp;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur != NULL) {
            while (cur != NULL) {
                tmp.push_back(cur->val);
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            cur = cur->left;
        }
        res.assign(tmp.rbegin(), tmp.rend());
    }

/*
Runtime: 4 ms, faster than 35.09% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.

//walked 存储LRX中的X，也就是当cur有right节点时，把cur存入set，等遍历完cur->right节点时，回到cur时，能够继续往上回退
walked虽然是set，本质上是存储了 LRX中R的后驱节点X，这样当回到X节点时，知道X已经遍历完了，方便进一步往父节点回退，
因此set可用一个pre来代替， 只要cur->right=pre，也说明R节点结束了，当前的cur是R的后继X节点。
*/
    void preOrderXLRset(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s;
        set<TreeNode*> walked;
        TreeNode* cur = root;
        while(!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if (cur->right!=NULL && !walked.count(cur)) {
                walked.insert(cur);
                cur = cur->right;
            } else {
                s.pop();
                res.push_back(cur->val);
                cur=NULL;
            }
        }
    }

/*
Runtime: 4 ms, faster than 35.65% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
*/
    void preOrderPre(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s;
        TreeNode* pre;
        TreeNode* cur = root;
        while(!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if (cur->right!=NULL && cur->right!=pre) {
                cur = cur->right;
            } else {
                s.pop();
                res.push_back(cur->val);
                pre = cur;
                cur=NULL;
            }
        }
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
*/
    void preOrderNull(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s;
        if (root == NULL) {
            return ;
        }
        s.push(root);
        TreeNode* cur;
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur!=NULL) {
                s.push(cur);
                s.push(NULL);
                if(cur->right!=NULL)
                    s.push(cur->right);
                if(cur->left!=NULL)
                    s.push(cur->left);
            } else {
                res.push_back(s.top()->val);
                s.pop();
            }
        }
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
*/
    void Morris(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root;
        TreeNode* pre;
        vector<int> tmp;
        while (cur != NULL) {
            if (cur->right == NULL) {
                tmp.push_back(cur->val);
                cur = cur->left;
            } else {
                pre = cur->right;
                while(pre->left!=NULL && pre->left != cur){
                    pre = pre->left;
                }
                if (pre->left == NULL) { // first time to visit left tree the rightmost leaf node
                    tmp.push_back(cur->val);
                    pre->left = cur;
                    cur = cur->right;
                } else {// second time to visit left tree the rightmost leaf node
                    pre->left = NULL;
                    cur = cur->left;
                }
            }
        }
        res.assign(tmp.rbegin(), tmp.rend());
    }

//Runtime: 4 ms, faster than 43.41% of C++ online submissions for Binary Tree Postorder Traversal.
//Memory Usage: 8.7 MB, less than 22.04% of C++ online submissions for Binary Tree Postorder Traversal.
    void MorrisChangeTree(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root;
        TreeNode* pre;
        deque<int> d;
        while (cur!=NULL) {
            d.push_front(cur->val);
            if (cur->right == NULL) {
                cur=cur->left;
            } else {
                pre = cur->right;
                while(pre->left != NULL) {
                    pre = pre->left;
                }
                pre->left = cur->left;
                cur->left = NULL;
                cur = cur->right;
            }
        }
        res.assign(d.begin(), d.end());
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
    auto v = s.postorderTraversal(root);
    for (auto e: v) {
        cout << e << " ";
    }

    return 0;
}


/*
M1 recursive, DFS
T=O(N)
S=O(lgN)

M2 DFS to iterate, use stack
T=O(N)
S=O(N)

M2.1
LRX 的遍历的逆序为 XRL
XLR为先序遍历，把先序遍历的R和L颠倒过来，就是XRL，再逆序，就是LRX

M2.2
LRX的难点在于 遍历完R节点后，不清楚当前节点是否是X，如果是X，则不需要继续压入X的left和right。
因此，如何区分R和X的边界，是切入点。
有三种方法
1.借助set去标记是否访问过LRX中的X。
2.存储pre指针，指向LRX遍历顺序里面cur节点的前驱，当cur->right=pre时，说明cur节点是已经访问过的父节点了。本质上和法1相同，只是把set换成pre指针而已。
3.在R和X之间压入特别的标记，例如nullptr [通用方法]
postorder=LRX 所以压栈顺序为 XRL ，但是在X之后，压入一个Null，栈顺序为 X，Null,R,L 因此遇到Null时，直接弹出X，无需再展开X的L和R。


M3 Morris Traversal (Threaded BinaryTree)
M3.1 Morris (unchanged Tree)
postOrder=LRX
preOrder=XLR
use preOrder-Morris method but switch left and right logic, turns XLR to XRL
and reverse XRL to LRX
Reverse( preOrderMorris(root)) = PostOrder

改进版


M3.2 Morris (Change Tree)
LRX = 逆序实现 XRL
M3.1的镜像版， 之前是按照右指针展开成链表，现在是按照左指针展开成链表
1) 先访问X，
2) 如果X的右节点==NULL，
    X=X->left
3) 否则
    然后把右子树中的最左孩子的left指针 指向 左子树
    X再指向右子树。

*/