/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-04
 * @tag  priorityQueue
 * @similar  373,347, 378
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 *
 * https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (40.96%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    108.4K
 * Total Submissions: 256.2K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
 * 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
 * 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
 *
 *
 *
 * 示例 1:
 * 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * 输出: [1,2],[1,4],[1,6]
 * 解释: 返回序列中的前 3 对数：
 * ⁠    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 *
 * 示例 2:
 * 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * 输出: [1,1],[1,1]
 * 解释: 返回序列中的前 2 对数：
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 *
 *
 *
 * 提示:
 * 1 <= nums1.length, nums2.length <= 10^5
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 和 nums2 均为 升序排列
 * 1 <= k <= 10^4
 * k <= nums1.length * nums2.length
 *
 *
 */

// @lc code=start
class Solution {
public:
    static bool lessCmp(pair<int, int>& v1, pair<int, int>& v2) {
        if ((v1.first + v1.second) < (v2.first + v2.second)) {
            return true;
        }
        return false;
    }

    //常规方法，没有利用num1和num2的有序性，TLE
    vector<vector<int>> kSmallestPairsTLE19_31(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&lessCmp) > maxHeap(lessCmp);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                maxHeap.push(make_pair(nums1[i], nums2[j]));
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            auto& pp = maxHeap.top();
            res.push_back(vector<int>{pp.first, pp.second});
            maxHeap.pop();
        }
        return res;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();

    /*
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        */


        auto greateCmp = [&nums1, &nums2](pair<int, int>& v1, pair<int, int>& v2) -> bool {
            //ERROR 搞错了 i j 和nums1 nums2的对应关系
            //if ((nums1[v1.first]+nums1[v1.second]) > (nums2[v2.first]+nums2[v2.second])) {
            if ((nums1[v1.first]+nums2[v1.second]) > (nums1[v2.first]+nums2[v2.second])) {
                return true;
            }
            return false;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(greateCmp)> minHeap(greateCmp);


        vector<vector<int>> res;

        int minL = min(len1, k);
        for (int r = 0; r < minL; r++) {
            minHeap.push(make_pair(r, 0));
        }

        while (!minHeap.empty()) {
            auto pp = minHeap.top();
            minHeap.pop();
            res.push_back(vector<int>{nums1[pp.first], nums2[pp.second]});
            if (res.size() >= k) {
                break;
            }
            if (pp.second + 1 < len2) {
                minHeap.push(make_pair(pp.first, pp.second+1));
            }
        }

        return res;
    }

};
// @lc code=end


/*
双指针...发现是错的...参考例子[1,2,3,15] 和[1,3,4,5]，指针得来回跑.


Time Limit Exceeded
19/31 cases passed (N/A)
Testcase
[1,2,3,4,5,6,7,,2'... 87797 more character
Expected Answer
[[1,1],[1,2],[2,1],[1,3],[2,2],[3,1],[1,4], ...

*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
