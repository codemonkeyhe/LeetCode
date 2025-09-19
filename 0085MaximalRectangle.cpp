/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-19
 * @tag  monotonicStack,matrix
 * @similar  84, 85
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode.cn/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (55.14%)
 * Likes:    1741
 * Dislikes: 0
 * Total Accepted:    217.6K
 * Total Submissions: 390K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 *
 *
 *
 * 示例 1：
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 *
 *
 * 示例 2：
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 * 示例 3：
 * 输入：matrix = [["1"]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * rows == matrix.length
 * cols == matrix[0].length
 * 1 <= row, cols <= 200
 * matrix[i][j] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> height(col, 0);
        int maxRec = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }
            int large = largestRectangleArea(height);
            maxRec = max(maxRec, large);
        }
        return maxRec;
    }

    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        vector<int> right(len, len);
        vector<int> left(len, -1);

        stack<int> st;
        for (int i = 0; i < len; i++) {
            int cur = heights[i];
            while(!st.empty() &&  heights[st.top()] > cur) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //st = stack<int>();
        while (!st.empty()) {
            st.pop();
        }

        for (int j = len - 1; j >= 0; j--) {
            int cur = heights[j];
            while(!st.empty() &&  heights[st.top()] > cur) {
                left[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        int large = 0;
        for (int i = 0; i < len; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            large = max(large, area);
        }
        return large;
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
