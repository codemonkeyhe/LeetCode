/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-20
 * @tag slidingWindow,priorityQueue,monotinicQueue
 * @similar  76, 209, 239
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (48.92%)
 * Likes:    3152
 * Dislikes: 0
 * Total Accepted:    874.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindowTLE46(vector<int>& nums, int k) {
        int len = nums.size();
        queue<int> que;
        int i = 0;
        int j = 0;

        int rcnt = len - k + 1;
        vector<int> res;

        // first k
        for (j = 0; j < k; j++) {
            int& cur = nums[j];
            if (que.empty() || (cur > que.back())) {
                que.push(cur);
            }
        }
        res.push_back(que.back());

        while(j < len) {
            // each step i++; then j++
            int out = nums[i++];
            if (out == que.front()) {
                que.pop();
            }
            if (que.empty()) { // from i ,build k
                j = i;
                while (j < i + k) {
                    int& cur = nums[j];
                    if (que.empty() || (cur > que.back())) {
                        que.push(cur);
                    }
                    j++;
                }
                res.push_back(que.back());
                continue;
            }

            int& cur = nums[j];
            if (que.empty() || (cur > que.back())) {
                que.push(cur);
            }
            res.push_back(que.back());
            j++;
        }
        return res;
    }

    vector<int> maxSlidingWindowM1(vector<int>& nums, int k) {
        int len = nums.size();
        deque<int> que;
        vector<int> res;
        for (int i = 0; i < len; i++) {
            int& cur = nums[i];
            while(!que.empty() && (cur >= nums[que.back()])) {
                que.pop_back();
            }
            que.push_back(i);

            if (i - que.front() >= k) {
                que.pop_front();
            }
            if (i >= k-1) {
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }

        vector<int> res;
        res.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));

            // window size  [i-k+1, i]
            int winLeft = i-k;
            while (pq.top().second <= winLeft) {
                pq.pop();
            }

            res.push_back(pq.top().first);
        }
        return res;
    }

};
// @lc code=end

/*
Wrong Answer
20/51 cases passed (N/A)
Testcase
[1,-1]
1
Answer
[1,1]
Expected Answer
[1,-1]


Wrong Answer
22/51 cases passed (N/A)
Testcase
[7,2,4]
2
Answer
[7,7]
Expected Answer
[7,4]


Wrong Answer
20/51 cases passed (N/A)
Testcase
[1,3,1,2,0,5]
3
Answer
[3,3,0,5]
Expected Answer
[3,3,2,5]


Time Limit Exceeded
46/51 cases passed (N/A)
Testcase
[10000,9999,9998,9997,9996,9995,9994,9993,'... 528926 more character

Expected Answer
[10000,9999,9998,9997,9996,9995,9994,15,14,13,12,11]

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


