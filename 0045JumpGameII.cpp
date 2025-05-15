/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-15
 * @tag  greedy
 * @similar  55, 1306
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.41%)
 * Likes:    2754
 * Dislikes: 0
 * Total Accepted:    902.6K
 * Total Submissions: 2M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 * 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j]  处:
 * 0 <= j <= nums[i] 
 * i + j < n
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 nums[n-1]
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> cache;


    int jumpSlow(vector<int>& nums) {
        return jumpDP(nums, 0);
    }

    // 从nums[idx]开始跳，跳到nums[LEN-1]的最小跳跃步数
    // Your runtime beats 5.01 % of cpp submissions
    int jumpDP(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }
        if (idx == nums.size() - 1) {
            return 0;
        }
        if (cache.count(idx)) {
            return cache[idx];
        }
        int cur = nums[idx];
        // ErrorCase int minJ = INT_MAX ;
        int minJ = INT_MAX - 10000 ;
        for (int i = 1; i <= cur; i++) {
            int step = jumpDP(nums, idx + i) + 1;
            minJ = min(minJ, step);
        }
        // if minJ == INT_MAX means can not jump
        cache[idx] = minJ;
        return minJ;
    }

    int jumpUgly(vector<int>& nums) {
        int pos = 0;
        int minStep = 0;
        int len = nums.size();
        if (len == 1) {
            return 0;
        }
        for (int i = 0;  i < len;) {
            int cur = nums[i];
            int nextJump = -1;
            int nextIdx = -1;
            for (int j = 1; j <= cur; j++) {
                if (i+j >= (len-1)) {
                    return minStep+1;
                }
                int s = i + j + nums[i + j];
                if (s > nextJump) {
                    nextJump = s;
                    nextIdx = i+j;
                }
            }
            i = nextIdx;
            minStep++;
            if (i == (len-1))  {
                break;
            }
        }
        return minStep;
    }


    int jump(vector<int>& nums) {
        int minStep = 0;
        int len = nums.size();
        int maxJump = 0;
        int i = 0;
        int reachMax = 0;
        for (; i < len; i++) {
            /*
            if (i > maxJump) { //题目保证可达
                break;
            }
            */
            if (i >= len - 1) {
                break;
            }
            int step = i + nums[i];
            maxJump = max(maxJump, step);
            if (i >= reachMax) {
                //cout << "i=" << i << " reachMax=" << reachMax << " oldStep=" << minStep << " maxJump=" << maxJump << endl;
                minStep++;
                reachMax = maxJump;
            }
        }
        return minStep;
    }

};
// @lc code=end

/*
Runtime Error
1/110 cases passed (N/A)
Error
Line 24: Char 46: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
Line 24: Char 46: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:33:46
Testcase
[2,3,0,1,4]
Expected Answer
2



2,3,1,1,4

逆向思考
4
W1 1,4
W2 3,1,1,4
W2最远，所以选择从3-4，而非1->4

正向
i=0 maxjump=2
if  jump=1   i=1 maxJump=1+3=4
if jump=2   i=2  maxJump=2+1=3
4>3 所以，greedy，选择 jump1跳到3


Runtime Error
2/110 cases passed (N/A)
Error
Line 1122: Char 34: runtime error: addition of unsigned offset to 0x502000000190 overflowed to 0x50200000018c (stl_vector.h)
Line 1122: Char 34: runtime error: addition of unsigned offset to 0x502000000190 overflowed to 0x50200000018c (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:34
Testcase
[0]
Expected Answer
0
Stdout
i=0 cur=0 nextIdx=-1


Wrong Answer
104/110 cases passed (N/A)
Testcase
[2,3,1]
Answer
2
Expected Answer
1
Stdout
i=0 cur=2 nextIdx=1


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


