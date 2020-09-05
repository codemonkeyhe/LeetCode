/**
 * @file
 * @brief   1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-05
 * @tag  BFS;
 * @similar 559 589 590
 */

/*
Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).


Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
/*
Runtime: 76 ms, faster than 19.04% of C++ online submissions for N-ary Tree Level Order Traversal.
Memory Usage: 11.7 MB, less than 81.33% of C++ online submissions for N-ary Tree Level Order Traversal.
*/
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> v;
            while (n-- > 0) {
                Node* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                const vector<Node*> &children = cur->children;
                for(int i = 0; i< children.size(); ++i) {
                    q.push(children[i]);
                }
            }
            res.push_back(v);
        }
        return res;
    }

};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {

}


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


