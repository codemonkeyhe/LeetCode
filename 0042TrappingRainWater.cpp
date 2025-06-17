/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-17
 * @tag stack, monotonicStack, twoPointers
 * @similar 42, 496, 739
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (63.39%)
 * Likes:    5123
 * Dislikes: 0
 * Total Accepted:    935K
 * Total Submissions: 1.5M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 示例 1：
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 *
 * 示例 2：
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:

    // 前后缀单调数组
    int trapM1(vector<int>& height) {
        int n = height.size();
        vector<int> leftHe(n, 0);
        int maxV = 0;
        for (int i = 0; i < n; i++) {
            maxV = max(maxV, height[i]);
            leftHe[i] = maxV;
        }

        vector<int> rightHe(n, 0);
        maxV = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxV = max(maxV, height[i]);
            rightHe[i] = maxV;
        }

        int waterSum = 0;
        for (int i = 0; i < n; i++) {
            int water = min(leftHe[i], rightHe[i]) - height[i];
            waterSum += water;
        }
        return waterSum;
    }


    // monotonic stack
    int trapM2(vector<int>& height) {
        int n = height.size();
        vector<int> st;
        int i = 0;
        int waterSum = 0;
        while(i < n) {
            int cur = height[i];
            // st.noEmpty and cur > st.back()
            while (!st.empty() && cur > height[st.back()]) {
                int bottom = st.back();
                st.pop_back();
                if (st.empty()) { // no left wall
                    break;
                }
                int left = st.back();
                int h = min(height[left], cur) - height[bottom];
                int w = i - left - 1;
                waterSum += h * w;
            }

            //if (st.empty() || cur <= height[st.back()]) {
            st.push_back(i); // push cur to stack
            i++;
        }
        return waterSum;
    }

    // M1的优化版，
    int trap(vector<int>& height) {
        int n = height.size();
        int waterSum = 0;
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax) {
                waterSum += leftMax - height[left];
                left++;
            } else {
                waterSum += rightMax - height[right];
                right--;
            }
        }
        return waterSum;
    }

};
// @lc code=end


/*
TwoPointers
解题思路
相信有很多小伙伴和我一样看了官方题解的双指针解法后依然一脸懵逼, 我在看了评论区大佬的讨论与说明后恍然大悟, 现在做一点总结记录, 以方便自己日后回看.

要点 1
对于某一个位置i, 我们能否接这个位置上的雨水, 取决于i左右两侧的最大值(leftMax, rightMax)是否比height[i]大. 只有当i左右两侧的最大值都比height[i]大时, 才能接i上的雨水, 数量为min(leftMax, rightMax) - height[i];
这里得出结论, 限制当前位置接雨水的条件是其左右两侧最大值中的较小值min(leftMax, rightMax).

要点 2
对于i和j两个指针, i从左向右移动, j从右向左移动, 对于指针i来说, leftMax是真实可信的, 因为leftMax的值是i一步一个脚印走出来的, 但是rightMax是不真实不可信的, 因为i不知道从height[i]到height[j]之间是否有其他的数大于rightMax; 同样,对于j来说rightMax是真实可信的, leftMax值是不真实不可信的.
这里得出结论:
对于左指针i, 它右侧的真实的最大值 >= rightMax,
对于右指针j, 它左侧的真实的最大值 >= leftMax.

要点 3
基于要点 1, 我们知道对于一个位置来说影响它接水的应该是左右两侧最大值中的较小值, 也就是min(leftMax, rightMax),
而基于要点 2, 我们知道左指针右侧的真实最大值会大于等于rightMax,
所以, 当出现leftMax < rightMax的时候, 左指针的位置是否能接雨水就已经确定了, 同样, 当出现leftMax >= rightMax的时候, 右指针的位置是否能接雨水就已经确定了, 所以, 可以写出下面的代码了.
另外关于代码中的循环条件while (i < j), 今天我再看时有了些疑问, 为什么不是while (i <= j)也能通过. 我又仔细想了下, 并做了些试验, 结果发现最后当i == j的时候, 它们指向的一定是数组中最大的那个数, 这个最大的数是不能接到雨水的.

作者：Lafiteee
链接：https://leetcode.cn/problems/trapping-rain-water/solutions/1502995/shuang-zhi-zhen-by-lafiteee-aay8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


