/**
 * @file
 * @brief 112-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-08
 */

/*
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.

Example:
Input:
   1
 /   \
2     3
 \
  5
Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:

//Runtime: 4 ms, faster than 82.38% of C++ online submissions for Binary Tree Paths.
//Memory Usage: 14 MB, less than 23.85% of C++ online submissions for Binary Tree Paths.
    void m1(TreeNode* root, string path, vector<string> &res) {
        if (root==NULL) {
            return ;
        }
        path+=to_string(root->val)+"->";
        if (!root->left && !root->right) {
            //去掉末尾的->
            res.push_back(string(path.begin(), path.end()-2));
            return;
        }
        m1(root->left, path, res);
        m1(root->right, path, res);
    }

    vector<string> binaryTreePathsM1(TreeNode* root) {
        vector<string> res;
        m1(root, "", res);
        return res;
    }

//Runtime: 8 ms, faster than 29.21% of C++ online submissions for Binary Tree Paths.
//Memory Usage: 11.8 MB, less than 64.77% of C++ online submissions for Binary Tree Paths.
    vector<string> binaryTreePathsM2(TreeNode* root) {
        vector<string> res;
        //stack<TreeNode*> s;
        vector<TreeNode*> s;  //把vector当stack，方便遍历
        TreeNode* cur = root;
        TreeNode* pre;
        while(!s.empty() || cur!=NULL)  {
            while (cur!=NULL)  {
                s.push_back(cur);
                cur=cur->left;
            }
            cur = s.back();
            if (cur->right != NULL && cur->right != pre) {
                cur = cur->right;
            } else {
                if (!cur->left && !cur->right) { // leaf
                    string path;
                    for (int i = 0; i < s.size(); i++) {
                        path+= to_string(s[i]->val) + "->";
                    }
                    res.push_back(string(path.begin(), path.end()-2));
                }
                s.pop_back();
                pre = cur;
                cur = NULL;
            }
        }
        return res;
    }

//Runtime: 8 ms, faster than 29.21% of C++ online submissions for Binary Tree Paths.
//Memory Usage: 12.4 MB, less than 61.08% of C++ online submissions for Binary Tree Paths.
    vector<string> binaryTreePathsM3(TreeNode* root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        queue<pair<TreeNode*, string> > q;
        q.push(make_pair(root, ""));
        while (!q.empty()){
            int size = q.size();
            while(size--) {
                TreeNode* cur = q.front().first;
                string path = q.front().second;
                q.pop();
                if (!cur->left && !cur->right) {  //leaf
                    res.push_back(path+to_string(cur->val));
                    continue;
                }
                path +=to_string(cur->val)+"->";
                if (cur->left)
                    q.push(make_pair(cur->left, path));
                if (cur->right)
                    q.push(make_pair(cur->right, path));
            }
        }
        return res;
    }

};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1 Recursive DFS
答案是要显示路径 ->  而叶子节点末尾时没有-> 因此要区别对待
M11 只有非叶子节点才需要加->，叶子节点不需要这个后缀
M12 所有节点都加-> 在加入到最终结果res时，忽略掉末尾的->

M2 DFS+stack
stack<TreeNode*>

M3 BFS+queue
queue<TreeNode*, string> q;

*/
