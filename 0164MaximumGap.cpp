/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-09
 * @tag  sort,radixSort,bucketSort
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
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode.cn/problems/maximum-gap/description/
 *
 * algorithms
 * Medium (59.95%)
 * Likes:    645
 * Dislikes: 0
 * Total Accepted:    107.6K
 * Total Submissions: 180.4K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。
 *
 * 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 *
 * 示例 2:
 * 输入: nums = [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 *
 *
 *
 * 提示:
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 *
 *
 */



// @lc code=start
class Solution {
public:

    void RadixSort(vector<int>& a) {
        int n = a.size();
        int maxVal = *max_element(a.begin(), a.end());
        int width = 0;
        while (maxVal > 0) {
            maxVal = maxVal / 10;
            width++;
        }
        int radix = 0;
        long m = 1;
        vector<vector<int> > v(10, vector<int>());
        while (width-- > 0) {
            // 分配
            for (int i = 0; i < n; i++) {
                radix = (a[i] / m) % 10;
                v[radix].push_back(a[i]);
            }
            // 收集
            int j = 0;
            for (int i = 0; i < 10; i++) {
                vector<int>& li = v[i];
                for (auto& val : li) {
                    a[j++] = val;
                }
                li.clear();
            }
            m *= 10;
        }
    }

    void RadixSortV2(vector<int>& a) {
        int n = a.size();
        int maxVal = *max_element(a.begin(), a.end());
        int width = 0;
        while (maxVal > 0) {
            maxVal = maxVal / 10;
            width++;
        }
        int radix = 0;
        long m = 1;
        vector<int> buf(n, 0);
        while (width-- > 0) {
            vector<int> v(10, 0);
            for (int i = 0; i < n; i++) {
                radix = (a[i] / m) % 10;
                v[radix]++;
            }
            for (int i = 1; i <10; i++) {
                v[i] += v[i-1];
            }

            for (int i = n - 1; i >= 0; i--) {
                radix = (a[i] / m) % 10;
                int& order = v[radix];
                buf[order - 1] = a[i];
                order--;
            }
            a = buf;
           // copy(buf.begin(), buf.end(), a.begin());
            m *= 10;
        }
    }

    int maximumGap(vector<int>& nums) {
        RadixSortV2(nums);
        int maxDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i - 1];
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};
// @lc code=end


/*
Wrong Answer
12/44 cases passed (N/A)
Testcase
[3,1]
Answer
0
Expected Answer
2


[15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740]
2901




官解：
计算排序名次的前缀和
然后倒着遍历nums[i]，从名次前缀和中认领位置，填入buf数组
倒序便利是为了保证稳定性


demo如下
[15252,16764,27963,7817]

ERROR LOG 正序遍历
 round=1
 15252 27963 16764 7817
 round=10 【不符合预期， 16764和27963乱序 】
 7817 15252 16764 27963
 round=100
 15252 16764 7817 27963
 round=1000 【不符合预期】
 15252 16764 27963 7817
 round=10000   【不符合预期】
 7817 16764 15252 27963
 7817 16764 15252 27963


例如cnt[6]=4
前缀和累加后，表示 尾号<=6的有4个
十分位来看，
16764和27963尾号都是6，
但是在个位排序结果后， 27963在 16764 的前面，因此，10分位排序后，要保持这种顺序，不应该打乱。
因此应该倒着遍历，最后一个6基数的数字，应该排在末尾。保证了基数相同时的稳定性。


OK LOG 倒序遍历
 round=1
 15252 27963 16764 7817
 round=10 【符合预期】
 7817 15252 27963 16764
 round=100
 15252 16764 7817 27963
 round=1000
 15252 16764 7817 27963
 round=10000
 7817 15252 16764 27963
 7817 15252 16764 27963
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


