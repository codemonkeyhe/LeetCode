/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-17
 * @tag
 */

/*
 
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <set>

using namespace std;

/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.48%)
 * Likes:    902
 * Dislikes: 0
 * Total Accepted:    557.3K
 * Total Submissions: 748K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 
 * 
 * 
 * 示例 1：
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 * 
 * 
 * 提示：
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 既然用set去重，还不如直接用set求交集 
    // O(m*n)
    vector<int> intersectionM1(vector<int>& nums1, vector<int>& nums2) {
        set<int> dup;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    if (dup.count(nums1[i]) == 0) {
                        res.push_back(nums1[i]);
                        dup.insert(nums1[i]);
                    }
                    break;
                }
            }
        }
        return res;
    }

    // 用hash_map 的次数来去重
    // O(m) + O(n)
    vector<int> intersectionM2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int ,int> dup;
        vector<int> res;
        for (auto& num : nums1 ) {
            dup.insert(make_pair(num, 1));
        }
        for (auto& n2 : nums2) {
            if (dup[n2] == 1) {
                res.push_back(n2);
                dup[n2] = 0;
            }
        }
        return res;
    }


// small table join big table
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size() * 6) {
            return  intersection(nums2, nums1);
        }
        unordered_map<int ,int> dup;
        vector<int> res;
        for (auto& num : nums1 ) {
            dup.insert(make_pair(num, 1));
        }
        for (auto& n2 : nums2) {
            if (dup[n2] == 1) {
                res.push_back(n2);
                dup[n2] = 0;
            }
        }
        return res;
    }


};
// @lc code=end



int main() {
    Solution s;
    vector<int> v1({4,9,5});
    vector<int> v2({9,4,9,8,4});
    auto res = s.intersection(v1, v2);
    printVector(res, "res:");
}


/*
Tips
M1

M2

*/


