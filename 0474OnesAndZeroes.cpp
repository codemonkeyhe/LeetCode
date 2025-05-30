/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-30
 * @tag dynamicProgramming,0-1 bagpack
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
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (66.14%)
 * Likes:    1242
 * Dislikes: 0
 * Total Accepted:    263.9K
 * Total Submissions: 392.4K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 *
 *
 *
 *
 * 示例 1：
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1
 * ，大于 n 的值 3 。
 *
 *
 * 示例 2：
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 *
 *
 *
 *
 * 提示：
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 <= m, n <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<pair<int, int> > cnt01;

    int findMaxFormDFS(vector<string>& strs, int m, int n) {
        int len = strs.size();
        for (auto& str: strs) {
            auto pa = count01(str);
            cnt01.push_back(pa);
        }

        return cacheBT(strs, m, n, len-1);
    }

    pair<int, int> count01(string& str) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (auto& c: str) {
            if (c == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        return make_pair(cnt0, cnt1);
    }

    unordered_map<int, int> cache;
    int cacheBT(vector<string>& strs, int m, int n, int i) {
        if (i < 0) {
            return 0;
        }

        int key = m * 100000 + n * 1000 + i;
        if (cache.count(key)) {
            return cache[key];
        }

        int v1 = cacheBT(strs, m, n, i - 1);

        int cnt0 = 0;
        int cnt1 = 0;
        tie(cnt0, cnt1) = cnt01[i];
        int v2 = INT_MIN;
        if (m >= cnt0 && n >= cnt1) {
            v2 = cacheBT(strs, m - cnt0, n - cnt1, i - 1) + 1;
        }

        int val = max(v1, v2);
        //cout << "i=" << i << "m=" << m << " n=" << n << " v1=" << v1 << " v2="  << v2 << " val=" << val << endl;
        cache[key] = val;
        return val;
    }

    //dp的i偏移
    // dp[i']  i'-1=i = [0, len-1]
    // oldAnswer dp[len-1][m][n]
    // afteroffset d[len][m][n]
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        for (auto& str: strs) {
            auto pa = count01(str);
            cnt01.push_back(pa);
        }
        vector<vector<vector<int> > > dp(
            len+1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        int cnt0 = 0;
        int cnt1 = 0;

        for (int i = 1; i <= len; i++) {//遍历物品
            //string& cur = strs[i];
            tie(cnt0, cnt1) = cnt01[i - 1];

            for (int j = 0; j <= m; j++) {     // cnt0 //遍历背包
                for (int k = 0; k <= n; k++) { // cnt1
                    int v1 = dp[i - 1][j][k];
                    int v2 =  INT_MIN;
                    if (j >= cnt0 && (k >= cnt1)) {//背包放得下才放
                        v2 = dp[i - 1][j - cnt0][k - cnt1] + 1;
                    }
                    dp[i][j][k] = max(v1, v2);
                }
            }
        }

        return dp[len][m][n];
    }
};
// @lc code=end


/*
依然是01背包
背包从容量变成 m0n1
物品就是str[i]中的0和1

dp[i]表示从strs[0..i]中选取的最大子集的长度，且该子集满足<=m0n1的要求

dp[i]=dp[i-1],  不选strs[i]，放不下
dp[i]=dp[i-1]+1， 选strs[i]，背包放得下，容量变成了 m0n1- strs[i]的01数目


dp[i][m0n1]=dp[i-1][m0n1],  不选strs[i]，放不下
dp[i][m0n1]=dp[i-1][m0n1- strs[i]的01数]+1， 选strs[i]，背包放得下，容量变成了 m0n1- strs[i]的01数目
求最大值，所以
dp[i][m0n1]= max(
    dp[i-1][m0n1],
    dp[i-1][m0n1- strs[i]的01数]+1)

Wrong Answer
12/77 cases passed (N/A)
Testcase
["10","0","1"]
1
1
Answer
3
Expected Answer
2


Time Limit Exceeded
27/77 cases passed (N/A)
Testcase
["11","11","0","0","10","1","1","0","11","1","0","111","11111000","0","11","000","1","1","0","00","1","101","001","000","0","00","0011","0","10000"]
' +
  '90
' +
  '66
Expected Answer
29

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


