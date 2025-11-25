/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-25
 * @tag    sort, heapSort
 * @similar  215, 1985
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1985 lang=cpp
 *
 * [1985] 找出数组中的第 K 大整数
 *
 * https://leetcode.cn/problems/find-the-kth-largest-integer-in-the-array/description/
 *
 * algorithms
 * Medium (42.62%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 36.7K
 * Testcase Example:  '["3","6","7","10"]\n4'
 *
 * 给你一个字符串数组 nums 和一个整数 k 。nums 中的每个字符串都表示一个不含前导零的整数。
 *
 * 返回 nums 中表示第 k 大整数的字符串。
 *
 * 注意：重复的数字在统计时会视为不同元素考虑。例如，如果 nums 是 ["1","2","2"]，那么 "2" 是最大的整数，"2"
 * 是第二大的整数，"1" 是第三大的整数。
 *
 *
 *
 * 示例 1：
 * 输入：nums = ["3","6","7","10"], k = 4
 * 输出："3"
 * 解释：
 * nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
 * 其中第 4 大整数是 "3"
 *
 *
 * 示例 2：
 * 输入：nums = ["2","21","12","1"], k = 3
 * 输出："2"
 * 解释：
 * nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
 * 其中第 3 大整数是 "2"
 *
 *
 * 示例 3：
 * 输入：nums = ["0","0"], k = 2
 * 输出："0"
 * 解释：
 * nums 中的数字按非递减顺序排列为 ["0","0"]
 * 其中第 2 大整数是 "0"
 *
 *
 *
 *
 * 提示：
 * 1 <= k <= nums.length <= 10^4
 * 1 <= nums[i].length <= 100
 * nums[i] 仅由数字组成
 * nums[i] 不含任何前导零
 *
 *
 */

// @lc code=start
class Solution {
public:
   // greater
   // T:下沉
   // Error string len maybe 100
    static bool cmpFn(string& a, string& b) {
        int ia = stoi(a);
        int ib = stoi(b);
        if (ia > ib) {
            return true;
        }
        return false;
    }

    static bool cmpFn2(string& a, string& b) {
        int lena = a.size();
        int lenb = b.size();
        if (lena > lenb) {
            return true;
        } else if (lena < lenb) {
            return false;
        }
        /* duplicated
        for (int i = 0; i < lena; i++) {
            if (a[i] > b[i]) {
                return true;
            } else if (a[i] < b[i]) {
                return false;
            }
        }
        return false;
        */
        return a > b;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        //dicOrder 10 < 3 < 6 < 7
     //ERROR   priority_queue<string, vector<string>, greater<string>> minHeap;
        // priority_queue<string, vector<string>, bool(*)(string&, string&)> minHeap(&cmpFn);
        //priority_queue<string, vector<string>, bool(*)(string&, string&)> minHeap(&cmpFn2);
        priority_queue<string, vector<string>, decltype(&cmpFn2)> minHeap(cmpFn2);
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
// @lc code=end

/*
Runtime Error
137/219 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::out_of_range'
terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
