/**
 * @file
 * @brief 类似鸽巢原理，关键点在于 如何利用数组就地hash
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-14
 * @tag hashmap,tricky
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
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (44.36%)
 * Likes:    2093
 * Dislikes: 0
 * Total Accepted:    380.4K
 * Total Submissions: 856.2K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,0]
 * 输出：3
 * 解释：范围 [1,2] 中的数字都在数组中。
 *
 * 示例 2：
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 解释：1 在数组中，但 2 没有。
 *
 * 示例 3：
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 解释：最小的正数 1 没有出现。
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Time: O(n)  Space: O(n)
    int firstMissingPositiveM1(vector<int>& nums) {
        unordered_set<int> hs;
        int minV = INT_MAX;
        int maxV = 0;
        for (auto& num: nums) {
            if (num <= 0) {
                continue;
            }
            hs.insert(num);
            minV = min(minV, num);
            maxV = max(maxV, num);
        }

        if (minV != 1) {
            return 1;
        }

        int i = 1;
        for (; i <= maxV; i++) {
            if (hs.count(i)) {
                continue;
            }
            break;
        }
        return i;
    }


    int firstMissingPositive(vector<int>& nums) {
        int minV = INT_MAX;
        int len = nums.size();
        for (auto& num: nums) {
            if (num <= 0) {
                num = len + 1;
            } else {
                minV = min(minV, num);
            }
        }

        if (minV != 1) {
            return 1;
        }

        /*
        // Error Thought:  [3,4,-1,1]
        if ((maxV - minV) == len - 1) { // [1,2,3]
            return len + 1;
        }
        */

        // ans = [1, len+1]
        // use idx , idx=0  means ans =idx+1 = 0+1 = 1
        // use idx , idx=len-1  means ans =idx+1 = len
        for (int i = 0; i < len; i++) {
            int cur = abs(nums[i]);
            //if (cur > len+1) { // not ans, skip
            if (cur > len) {  // not ans, skip
                continue;
            }
            // may be ans, set mark on array
            int idx = cur-1;
            nums[idx] = -abs(nums[idx]);
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0) {
                continue;
            }
            return i+1;
        }
        return len + 1;
    }

};
// @lc code=end

/*
Runtime Error
60/178 cases passed (N/A)
Error
Line 21: Char 25: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
Line 21: Char 25: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:30:25
Testcase
[1,2,3,10,2147483647,9]
Expected Answer
4


KEY
实际上，对于一个长度为 N 的数组，其中没有出现的最小正整数只能在 [1,N+1] 中。这是因为如果 [1,N] 都出现了，那么答案是 N+1，否则答案是 [1,N] 中没有出现的最小正整数。这样一来，我们将所有在 [1,N] 范围内的数放入哈希表，也可以得到最终的答案。而给定的数组恰好长度为 N，这让我们有了一种将数组设计成哈希表的思路：

作者：力扣官方题解
链接：https://leetcode.cn/problems/first-missing-positive/solutions/304743/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/
来源：力扣（LeetCode）


Wrong Answer
11/178 cases passed (N/A)
Testcase
[3,4,-1,1]
Answer
5
Expected Answer
2

*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


