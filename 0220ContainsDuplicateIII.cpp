/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-05
 * @tag  bucket, slidingWindow
 * @similar  217, 219, 220
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 *
 * https://leetcode.cn/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Hard (30.58%)
 * Likes:    773
 * Dislikes: 0
 * Total Accepted:    112.4K
 * Total Submissions: 357.6K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * 给你一个整数数组 nums 和两个整数 indexDiff 和 valueDiff 。
 *
 * 找出满足下述条件的下标对 (i, j)：
 *
 *
 * i != j,
 * abs(i - j) <= indexDiff
 * abs(nums[i] - nums[j]) <= valueDiff
 *
 *
 * 如果存在，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
 * 输出：true
 * 解释：可以找出 (i, j) = (0, 3) 。
 * 满足下述 3 个条件：
 * i != j --> 0 != 3
 * abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
 * abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
 *
 *
 * 示例 2：
 * 输入：nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
 * 输出：false
 * 解释：尝试所有可能的下标对 (i, j) ，均无法满足这 3 个条件，因此返回 false 。
 *
 *
 *
 *
 * 提示：
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 1 <= indexDiff <= nums.length
 * 0 <= valueDiff <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int getID(int x, long w) {
        //return x < 0 ? (x + 1ll) / w - 1 : x / w;
        // ERROR return (x + 10^9) / (w);
        return (x + 1000000000) / (w);
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> bucket; // bucketID->num
        int k = indexDiff;
        int len = nums.size();
        //int winSize = k + 1;
        int width = valueDiff + 1;
        for (int i = 0; i < len; i++) { // win  [i-k-1]  [i-k  i]  winSize = i-(i-k) +1 = k+1
            if (i >= k + 1) {
                //      int idx = nums[i - k - 1] / width;
                int idx = getID(nums[i - k - 1], width);
                bucket.erase(idx);
            }
            int bid = getID(nums[i], width);
            //int bid = nums[i] / width;
            if (bucket.count(bid)) {
                return true;
            }
            if (bucket.count(bid-1) && abs(bucket[bid-1] - nums[i]) <= valueDiff) {
                return true;
            }

            if (bucket.count(bid+1) && abs(bucket[bid+1] - nums[i]) <= valueDiff) {
                return true;
            }
            bucket[bid] = nums[i];
        }
        return false;
    }
};
// @lc code=end


/*

Wrong Answer
49/56 cases passed (N/A)
Testcase
[1,5,9,1,5,9]
2
3
Answer
true
Expected Answer
false


输入
nums = [-3,3]
indexDiff = 2
valueDiff = 4

添加到测试用例
标准输出
i=0num=-3 bid=0
i=1num=3 bid=0
TTT  num=3 bid=0
输出
true
预期结果
false


很多小伙伴对getID有点迷惑,就是为什么取负数,如w=10, 因为非负数是0-9，10-19, 20-29...这种一组，而负数是-1~-10, -11~-20...这些是一组，如果-1~-10直接除以10，会被分到两组中，而不是-1这一组，所以先+1变成-0 ~ -9,与正数一致，再除以10，最后减1，正好是-1这一组，其它组也是同理

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
