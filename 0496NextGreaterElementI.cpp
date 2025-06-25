/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-25
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
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 *
 * https://leetcode.cn/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (71.97%)
 * Likes:    1177
 * Dislikes: 0
 * Total Accepted:    322.2K
 * Total Submissions: 447.6K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
 * 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
 * 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定
 * nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
 *
 * 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 *
 *
 *
 * 示例 1：
 * 输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出：[-1,3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * - 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
 * - 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 *
 * 示例 2：
 * 输入：nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出：[3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
 * - 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * nums1和nums2中所有整数 互不相同
 * nums1 中的所有整数同样出现在 nums2 中
 *
 *
 *
 *
 * 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
 *
 */

// @lc code=start
class Solution {
public:
    //M1: walk order : left to right , monotonic stack, bottom -> top : big -> small
    vector<int> nextGreaterElementM1(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        stack<int> st;

        unordered_map<int, int> n2b;
        int i = 0;
        while(i < len2) {
            int& cur = nums2[i];
            while(!st.empty() && (cur > st.top())) { // 互不相同
                n2b[st.top()] = cur;
                st.pop();
            }
            st.push(cur);
            i++;
        }

        while(!st.empty()) {
            n2b[st.top()] = -1;
            st.pop();
        }

        for (auto& val: nums1) {
            res.push_back(n2b[val]);
        }

        return res;
    }

    //M2: walk order :  right to left , monotonic stack, bottom -> top : big -> small
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        stack<int> st;

        unordered_map<int, int> n2b;
        int i = len2 - 1;
        while(i >= 0) {
            int& cur = nums2[i];
            while(!st.empty() && (cur > st.top())) { // 互不相同
                st.pop();
            }
            if (!st.empty()) {
                n2b[cur] = st.top();
            } else {
                n2b[cur] = -1;
            }
            st.push(cur);
            i--;
        }

        for (auto& val: nums1) {
            res.push_back(n2b[val]);
        }

        return res;
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


