/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-22
 * @tag BinaryTree
 * @similar 449
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (59.19%)
 * Likes:    1272
 * Dislikes: 0
 * Total Accepted:    256.1K
 * Total Submissions: 429.8K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 *
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 *
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 *
 *
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 * 树中结点数在范围 [0, 10^4] 内
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CodecBFS {
public:

    const char elemSP = ',';
    const char lineSP = '|';
    const char nullS = '#';

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        string res = "";
        queue<TreeNode*> qe;
        qe.push(root);
        while(!qe.empty()) {
            int cnt = qe.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode* cur =  qe.front();
                qe.pop();
                if (cur) {
                    res += to_string(cur->val) + elemSP;

                    // NULL 也入队
                    qe.push(cur->left);
                    qe.push(cur->right);
                } else {
                    res += "#,";
                }
            }
            res+=lineSP;
        }
        return res;
    }

    void GetNodeFromLine(string& data, vector<TreeNode*>& line) {
        int i = 0;
        int j = 0;
        TreeNode* nx = NULL;
        while (j < data.size()) {
            if (data[j] == nullS) {
                line.push_back(nx);
                i = j + 2;
                j++;
            } else if (data[j] == elemSP) {
                string ss = data.substr(i, j - i);
                line.push_back(new TreeNode(stoi(ss)));
                i = j + 1;
            }
            j++;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return NULL;
        }

        // 可以用qe实现
        vector<vector<TreeNode*> > nodes;

        int i = 0;
        int j = 0;
        while(j < data.size()) {
             if (data[j] == lineSP) {
                vector<TreeNode*> line;
                auto curLine =  data.substr(i, j-i);
                GetNodeFromLine(curLine, line);
                nodes.push_back(line);
                i = j+1;
            }
            j++;
        }

        for (int i = 0; i < nodes.size()-1; i++) {
            vector<TreeNode*> cur = nodes[i];
            vector<TreeNode*> nextL = nodes[i+1];
            int idx = 0;
            for (int k = 0; k < cur.size(); k++) {
                if (cur[k] == NULL) {
                    continue;
                }
                int leftSon = 2*idx;
                cur[k]->left = nextL[leftSon];
                cur[k]->right = nextL[leftSon+1];
                idx++;
            }
        }
        return nodes[0][0];
    }
};



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL) {
            return res;
        }
        ser(root, res);
        return res;
    }

    void ser(TreeNode* root, string& res) {
        if (root == NULL) {
            res+="#,";
            return;
        }
        res = res + to_string(root->val) + ",";
        ser(root->left, res);
        ser(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return NULL;
        }

        //cout << "data=" << data << endl;
        vector<string> nodes = getNodes(data);
        int idx = 0;
        auto root = buildBT(nodes, idx);
        return root;
    }

    vector<string> getNodes(string& data) {
        vector<string> res;
        int i=0;
        int j=0;
        while(j < data.size()) {
            if (data[j] == '#') {
                res.push_back("#");
                i = j+2;
                j++;
            } else if (data[j] == ',') {
                string ss = data.substr(i, j-i);
                res.push_back(ss);
                i = j+1;
            }
            j++;
        }
        return res;
    }


    TreeNode* buildBT(vector<string>& data, int& idx) {
        if (idx >= data.size()) {
            return NULL;
        }
        if (data[idx] == "#")  {
            // 易错点
            idx++;
            return NULL;
        }
        int val = stoi(data[idx]);
        TreeNode* root = new TreeNode(val);
        idx++;
        root->left = buildBT(data, idx);
        root->right = buildBT(data, idx);
        return root;
    }

};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


