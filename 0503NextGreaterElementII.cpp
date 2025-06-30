/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-28
 * @tag  stack,monotonicStack,hashMap
 * @similar  496,503,556,739
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode.cn/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (67.46%)
 * Likes:    1056
 * Dislikes: 0
 * Total Accepted:    308.2K
 * Total Submissions: 447.8K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
 * 下一个更大元素 。
 * 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1
 * 。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [1,2,1] 1 2 1
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数；
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 *
 *
 * 示例 2:
 * 输入: nums = [1,2,3,4,3]
 * 输出: [2,3,4,-1,4]
 *
 *
 *
 *
 * 提示:
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElementsV1(vector<int>& nums) {
        int len = nums.size();
        nums.resize(len*2);
        for (int i = 0; i < len; i++) {
            nums[i+len] = nums[i];
        }
        stack<int> st;
        int i = 0;
        unordered_map<int, int> n2n;
        while (i < 2 * len) {
            int& cur = nums[i];
            while (!st.empty() && cur > nums[st.top()]) {
                n2n[st.top()] = cur;
                st.pop();
            }
            // cur <= st.top()
            st.push(i);
            i++;
        }
        vector<int> res;
        for (int i = 0; i < len; i++) {
            if (n2n.count(i)) {
                res.push_back(n2n[i]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }

     vector<int> nextGreaterElementsV2(vector<int>& nums) {
        int len = nums.size();
        nums.resize(len*2);
        for (int i = 0; i < len; i++) {
            nums[i+len] = nums[i];
        }
        stack<int> st;
        int i = 0;
        vector<int> res(len, -1);
        while (i < 2 * len) {
            int& cur = nums[i];
            while (!st.empty() && cur > nums[st.top()]) {
                if (st.top() < len) {
                    res[st.top()] = cur;
                }
                st.pop();
            }
            // cur <= st.top()
            st.push(i);
            i++;
        }
        return res;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        stack<int> st;
        int i = 0;
        vector<int> res(len, -1);
        while (i < 2 * len) {
            int ri = i%len;
            int& cur = nums[ri];
            while (!st.empty() && cur > nums[st.top()]) {
                res[st.top()] = cur;
                st.pop();
            }
            // cur <= st.top()
            st.push(ri);
            i++;
        }
        return res;
    }
};
// @lc code=end


/*
Wrong Answer
59/223 cases passed (N/A)
Testcase
[1,2,3,4,5]
Answer
[2,3,4,-1,-1]
Expected Answer
[2,3,4,5,-1]


[1,2,3,4,5] 1 2 3 4


[1,2,3,2,5]


Wrong Answer
133/223 cases passed (N/A)
Testcase
[5,4,3,2,1]
Answer
[-1,-1,-1,-1,5]
Expected Answer
[-1,5,5,5,5]

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


