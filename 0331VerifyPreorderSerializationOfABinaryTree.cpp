/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-27
 * @tag  binaryTree,stack
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 *
 * https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (49.33%)
 * Likes:    538
 * Dislikes: 0
 * Total Accepted:    82.3K
 * Total Submissions: 165.6K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * 序列化二叉树的一种方法是使用 前序遍历 。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如
 * #。
 *
 *
 *
 * 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
 * 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
 * 保证 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
 * 你可以认为输入格式总是有效的
 * 例如它永远不会包含两个连续的逗号，比如 "1,,3" 。
 *
 *
 * 注意：不允许重建树。
 *
 *
 *
 * 示例 1:
 * 输入: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * 输出: true
 *
 * 示例 2:
 * 输入: preorder = "1,#"
 * 输出: false
 *
 *
 * 示例 3:
 * 输入: preorder = "9,#,#,1"
 * 输出: false
 *
 *
 *
 *
 * 提示:
 * 1 <= preorder.length <= 10^4
 * preorder 由以逗号 “，” 分隔的 [0,100] 范围内的整数和 “#” 组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> strSplitBy2(string str, char delimiter) {
        size_t pos = 0;
        size_t prev = 0;
        vector<string> res;
        while ((pos = str.find(delimiter, pos)) != string::npos) {
            res.push_back(str.substr(prev, pos - prev));
            pos++;
            prev = pos;
        }
        res.push_back(str.substr(prev));
        return res;
    }

    const string nullStr  = "#";

    bool isValidSerializationM1(string preorder) {
        if (preorder == "#") {
            return true;
        }
        vector<string> nodes = strSplitBy2(preorder, ',');
        vector<string> st;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] != nullStr) {
                st.push_back(nodes[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                string& last = st.back();
                if (last !=  nullStr) {
                    // first #
                    st.push_back(nullStr);
                    continue;
                } else {
                    if (st.size() <2) {
                        return false;
                    }
                    st.pop_back(); // first is #
                    st.pop_back();
                    st.push_back(nullStr);
                }
            }
            int stLen = st.size();
            while ((st.size() >= 3) && (st.back() == nullStr) && (st[stLen-2] == nullStr)) {
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.push_back(nullStr);
                stLen = st.size();
            }
        }
        if ((st.size() == 1) && (st.back() == nullStr)) {
            return true;
        }
        return false;
    }

    bool isValidSerializationM11(string preorder) {
        if (preorder == "#") {
            return true;
        }
        vector<string> nodes = strSplitBy2(preorder, ',');
        vector<string> st;
        int stLen = st.size();
        for (int i = 0; i < nodes.size(); i++) {
            st.push_back(nodes[i]);
            stLen = st.size();
            while ((st.size() >= 3) && (st.back() == nullStr) &&
                   (st[stLen - 2] == nullStr) && (st[stLen-3] != nullStr) ) {
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.push_back(nullStr);
                stLen = st.size();
            }
        }
        if ((st.size() == 1) && (st.back() == nullStr)) {
            return true;
        }
        return false;
    }

    bool isValidSerialization(string preorder) {
        if (preorder == "#") {
            return true;
        }
        vector<string> nodes = strSplitBy2(preorder, ',');
        vector<string> st;
        int nCnt = 0;
        int notNull = 0;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == nullStr) {
                nCnt++;
            } else {
                notNull++;
            }
            if (nCnt > notNull && (i < nodes.size() - 1)) {
                return false;
            }
        }
        if (nCnt == (notNull + 1)) {
            return true;
        }
        return false;
    }
};
// @lc code=end

/*
M1 stack
M2 计算入度出度
M3  NullSize = notNullSize +1



Trick: stack取 第二高的元素不方便，用vector当stack好一点
stack.push  = vector.push_back
stack.top    = vector.back
stack.pop    = vector.pop_back




 * 输入: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"


stack1
9 3 4## 1## 2 # 6##
9 3 4## 1## 2 # #
9 3 4## 1## #
9 3 4## #   #
9 3 #   #   #
9  #   #
#


stack2
9 3 4 #  next = # , pop (4, #) push(#)
9 3 #
9 3 # 1 #   next = # , pop (1, #) push(#)
9 3 # #      top is ##   pop (3##)  push (#)
9 #
9 # 2 # 6 #     next = # , pop (6, #) push(#)
9 # 2 # #        top is ##   pop (2##)  push (#)
9 # #      top is 9##   pop (9##)  push (#)
#        finally, stack.size=1 and top=#


Wrong Answer
8/152 cases passed (N/A)
Testcase
"1,#,#,#,#"
Answer
true
Expected Answer
false



Wrong Answer
9/152 cases passed (N/A)
Testcase
"#"
Answer
false
Expected Answer
true

Wrong Answer
52/152 cases passed (N/A)
Testcase
"9,#,93,#,9,9,#,#,#"
Answer
false
Expected Answer
true


Wrong Answer
70/152 cases passed (N/A)
Testcase
"9,#,9,19,19,19,#,9,#,#,9,#,#,#,9,29,#,#,#"
Answer
false
Expected Answer
true

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


