/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-15
 * @tag
 */

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode.cn/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (60.09%)
 * Likes:    4939
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * 
 * 说明：你不能倾斜容器。
 * 
 * 
 * 
 * 示例 1：
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49 
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2：
 * 输入：height = [1,1]
 * 输出：1
 * 
 * 提示：
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * 

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0;
        int j = len - 1;
        int maxA = -1;
        int h = 0;
        while(i<j) {
            int w = j-i;
            if (height[i] > height[j]) {
                h = height[j--];
            }  else {
                h = height[i++];
            }
            int a = h*w;
            if (maxA < a) {
                maxA = a;
            }
        }
        return maxA;
    }


};


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


