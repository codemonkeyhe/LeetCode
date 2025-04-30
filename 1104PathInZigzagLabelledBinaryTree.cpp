/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-29
 * @tag  binaryTree,math
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
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 *
 * https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/description/
 *
 * algorithms
 * Medium (75.79%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 46.8K
 * Testcase Example:  '14'
 *
 * 在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。
 * 如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
 * 而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
 *
 *
 *
 * 给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。
 *
 *
 *
 * 示例 1：
 * 输入：label = 14
 * 输出：[1,3,4,14]
 *
 *
 * 示例 2：
 * 输入：label = 26
 * 输出：[1,2,6,10,26]
 *
 *
 *
 *
 * 提示：
 *
 * 1 <= label <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int dep = 1;
        int num = 1;
        int rowCnt = 1;
        while (label > num) {
            dep++;
            rowCnt = rowCnt << 1;
            num += rowCnt;
        }
        //cout << "num=" << num << " rrowCn=" << rowCnt << " dep=" << dep << endl;

        vector<int> path;
        if (dep%2==0) {
            label = getMirror(label, rowCnt, num);
        }

        while (dep > 0) {
            if (dep & 1) {  // ji  asc
                path.push_back(label);
                label = label >> 1;
            } else {  // ou desc
                // getMirro
                int mir = getMirror(label, rowCnt, num);
                path.push_back(mir);
                // ErrorCase label = mir/2;
                label = label >> 1;
            }
            dep--;
            num -= rowCnt;
            rowCnt = rowCnt >> 1;
        }

        reverse(path.begin(), path.end());
        return path;
    }

    int getMirror(int label, int rowCnt, int num) {
        int rightV = num - rowCnt + 1;
        int diff = num - label;
        int mir = rightV + diff;
        //return (1 << row - 1) + (1 << row) - 1 - label;
        return mir;
    }
};
// @lc code=end

/*
Wrong Answer
11/44 cases passed (N/A)
Testcase
26
Answer
[1,3,5,13,26]
Expected Answer
[1,2,6,10,26]
Stdout

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


