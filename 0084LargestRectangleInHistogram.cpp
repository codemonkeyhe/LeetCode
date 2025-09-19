/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-14
 * @tag  stack,monotonicStack
 * @similar 84, 496, 503, 739
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (45.76%)
 * Likes:    2942
 * Dislikes: 0
 * Total Accepted:    536.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 * 1 <= heights.length <=105
 * 0 <= heights[i] <= 104
 *
 *
 */


/*
V1:
寻找右侧第一个比自己小的元素
fromLeftToRight:  意味着stack里面都是left元素，越底部越left, 当前元素是最right的元素
monotonicStack: bottom->top: small -> big
如果栈顶大于当前元素，则出栈，并记录   栈顶的右侧第一个比自己小的元素就是当前元素
栈里面保存的是左侧元素，当前元素就是右侧元素

寻找左侧第一个比自己小的元素
fromRightToLeft
monotonicStack: bottom->top: small -> big
如果栈顶大于当前元素，则出栈，并记录   栈顶的左侧比自己小的元素就是当前元素
栈里面保存的是右侧元素，当前元素就是左侧元素

V2:
寻找右侧第一个比自己小的元素
fromRightToLeft
monotonicStack: bottom->top: small -> big
如果栈顶大于等于当前元素，则出栈
然后栈顶的元素必然小于当前元素，[整个栈也小于当前元素]
栈里面保存的是右侧元素，当前元素就是左侧元素
因此，当前元素右侧比自己小的元素就是栈顶

寻找左侧第一个比自己小的元素
fromLeftToRight:
monotonicStack: bottom->top: small -> big
如果栈顶大于等于当前元素，则出栈
然后栈顶的元素必然小于当前元素，[整个栈也小于当前元素]
栈里面保存的是左侧元素，当前元素就是右侧元素
因此，当前元素左侧比自己小的元素就是栈顶

结论：
1 不管是寻找左侧/右侧的较小/较大元素，遍历顺序无关，从左往右遍历和从右往左遍历都可以
2 对于寻较小的元素，单调栈的单调性是固定的，即 bottom->top: small -> big
3 对于寻较大的元素，单调栈的单调性是固定的，即 bottom->top: big -> small (LC496)

V3
把V1和V2合并起来

V1
寻找右侧比自己小的元素
fromLeftToRight:
monotonicStack: bottom->top: small -> big

V2
寻找左侧比自己小的元素
fromLeftToRight:
monotonicStack: bottom->top: small -> big


*/


// @lc code=start
class Solution {
public:

    int largestRectangleAreaV1(vector<int>& heights) {
        int len = heights.size();
        vector<int> right(len, len);
        vector<int> left(len, -1);


        stack<int> st;
        int i = 0;
        for (; i < len; i++) {
            int cur = heights[i];
            while(!st.empty() && heights[st.top()] > cur) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        /*
        while(!st.empty()) {
            right[st.top()] = i;
            st.pop();
        }*/

        st = stack<int>();
        int j = len-1;
        for (; j >= 0; j--) {
            int cur = heights[j];
            while(!st.empty() && heights[st.top()] > cur) {
                left[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        /*
        while(!st.empty()) {
            left[st.top()] = j;
            st.pop();
        }*/

        int maxArea = 0;
        for (int i = 0; i < len; i++) {
            int width = (right[i] - left[i] -  1);
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    // V2
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> right(len, len);
        vector<int> left(len, -1);


        stack<int> st;
        int j = len-1;
        for (; j >= 0; j--) {
            int cur = heights[j];
            while(!st.empty() && heights[st.top()] >= cur) {
                st.pop();
            }
            if (!st.empty()) {
                right[j] = st.top();
            }
            st.push(j);
        }


        st = stack<int>();
        int i = 0;
        for (; i < len; i++) {
            int cur = heights[i];
            while(!st.empty() && heights[st.top()] >= cur) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }


        int maxArea = 0;
        for (int i = 0; i < len; i++) {
            int width = (right[i] - left[i] -  1);
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    // TLE 90-99
    int largestRectangleAreaM2TLE(vector<int>& heights) {
        int maxArea = 0;
        int len = heights.size();
        for (int left = 0; left < len; left++) {
            int h = heights[left];
            for (int right = left; right < len; right++) {
                int w = (right - left + 1);
                h = min(h, heights[right]);
                int area = w * h;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }

};
// @lc code=end

/*
M1 固定高，拓展宽
V1
V2
V3

M2 枚举宽


Wrong Answer
68/99 cases passed (N/A)
Testcase
[1]
Answer
0
Expected Answer
1


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


