/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-18
 * @tag    hashmap;twoPointers
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
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 *
 * https://leetcode.cn/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (46.19%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 152.9K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。
 * k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] - nums[j]| == k
 *
 *
 * 注意，|val| 表示 val 的绝对值。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [3, 1, 4, 1, 5], k = 2
 * 输出：2
 * 解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
 * 尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1, 2, 3, 4, 5], k = 1
 * 输出：4
 * 解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
 *
 *
 * 示例 3：
 * 输入：nums = [1, 3, 1, 5, 4], k = 0
 * 输出：1
 * 解释：数组中只有一个 0-diff 数对，(1, 1) 。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^4
 * -10^7 <= nums[i] <= 10^7
 * 0 <= k <= 10^7
 *
 *
 */

// @lc code=start
class Solution {
public:
    // works but stupid
    int findPairsM1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        unordered_map<int, int> val2idx;
        int nlen = nums.size();
        int sameCnt = 0;
        int sameDiff = 0;
        for (int i = 0; i < nlen; i++) {
            while (i < nlen - 1 && nums[i] == nums[i + 1]) {
                sameCnt++;
                i++;
            }
            if (sameCnt > 0) {
                sameDiff++;
                sameCnt = 0;
            }
            auto& cur = nums[i];
            int want1 = cur - k;
            //int want2 = cur + k;
            if (val2idx.count(want1) == 1) {
                cnt++;
            }
            val2idx[cur] = i;
        }
        if (k == 0) {
            return sameDiff;
        }
        return cnt;
    }

    // 先构造map，再使用map
    int findPairsM2(vector<int>& nums, int k) {
        unordered_map<int, int> val2cnt;
        for (auto &num : nums) {
            val2cnt[num]++;
        }
        if (k == 0) {
            int sameCnt = 0;
            for (auto &[v, cnt] : val2cnt) {
                if (cnt > 1) {
                    sameCnt++;
                }
            }
            return sameCnt;
        }
        int res = 0;
        for (auto &[val, cnt] : val2cnt) {
            int want1 = val - k;
            //int want2 = val + k; //
            if (val2cnt.count(want1)) {
                res++;
            }
            /*
            if (val2cnt.count(want2)) {
                res++;
            }
            */
        }
        return res;
    }

    // 当(1,3)满足k=2时，3放入res记录结果，利用set去重
    // 当(3,5)满足k=2时，5放入res记录结果，利用set去重
    // M3
    int findPairsM3(vector<int> &nums, int k) {
        unordered_set<int> res;
        unordered_map<int, int> val2cnt;
        //int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto &val = nums[i];
            //delete 3lines below still work
            if (res.count(val) == 1) { // duplicate
                continue;
            }
            int want1 = val - k;
            int want2 = val + k;
            // exist(val-k, val)  mark val
            if (val2cnt.count(want1) == 1) {
         //       cnt++;
                res.insert(val);
            }
            // exist(val, val+k) mark val+k
            if (val2cnt.count(want2) == 1) {
          //      cnt++;
                res.insert(want2);
            }
            val2cnt[val] = i;
        }
        return res.size();
    }


    // sort + twoPointers
    // 1 1 3 4 5
    // >k move left
    // <k move right
    // == k findOne, then move left
    int findPairs(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int nlen = nums.size();
        int i = 0;
        int j = i+1;
        int cnt = 0;
        while (i < nlen && j < nlen) {
            int diff =  nums[j] - nums[i];
            if (diff == k) {
                cnt++;
                while (i < nlen-1 && nums[i] == nums[i + 1]) {
                    i++;
                }
                i++; // one more step
                j = i + 1;
                continue;
            }
            if (diff > k) {
                i++;
                j = i + 1;
            } else {
                j++;
            }
        }
        return cnt;
    }
};
// @lc code=end

/*
Wrong Answer
38/60 cases passed (N/A)
Testcase
[1,2,4,4,3,3,0,9,2,3]
3
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
