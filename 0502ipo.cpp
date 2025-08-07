/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-07
 * @tag  greedy, sort
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
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 *
 * https://leetcode.cn/problems/ipo/description/
 *
 * algorithms
 * Hard (45.31%)
 * Likes:    359
 * Dislikes: 0
 * Total Accepted:    61.7K
 * Total Submissions: 132.5K
 * Testcase Example:  '2\n0\n[1,2,3]\n[0,1,1]'
 *
 * 假设 力扣（LeetCode）即将开始 IPO 。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。
 * 由于资源有限，它只能在 IPO 之前完成最多 k 个不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。
 *
 * 给你 n 个项目。对于每个项目 i ，它都有一个纯利润 profits[i] ，和启动该项目需要的最小资本 capital[i] 。
 *
 * 最初，你的资本为 w 。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。
 *
 * 总而言之，从给定项目中选择 最多 k 个不同项目的列表，以 最大化最终资本 ，并输出最终可获得的最多资本。
 *
 * 答案保证在 32 位有符号整数范围内。
 *
 *
 *
 * 示例 1：
 * 输入：k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
 * 输出：4
 * 解释：
 * 由于你的初始资本为 0，你仅可以从 0 号项目开始。
 * 在完成后，你将获得 1 的利润，你的总资本将变为 1。
 * 此时你可以选择开始 1 号或 2 号项目。
 * 由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
 * 因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
 *
 *
 * 示例 2：
 * 输入：k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
 * 输出：6
 *
 *
 *
 *
 * 提示：
 * 1 <= k <= 10^5
 * 0 <= w <= 10^9
 * n == profits.length
 * n == capital.length
 * 1 <= n <= 10^5
 * 0 <= profits[i] <= 10^4
 * 0 <= capital[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapitalTLE32_40(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int> > vc;
        int len = capital.size();
        for (int i = 0; i < len; i++) {
            vc.push_back(make_pair(capital[i], profits[i]));
        }
        sort(vc.begin(), vc.end());

        int cnt = 0;
        int total = w;
        int idx = 0;
        //unordered_set<int> hs;
        vector<int> used(len, 0);
        while(cnt++ < k) {
            int maxv = 0;
            for (int i = 0; i < len; i++) {
                if (vc[i].first > w) {
                    break;
                }
                //if (vc[i].second > maxv && (hs.count(i) == 0)) {
                if (vc[i].second > maxv && (used[i] == 0)) {
                    maxv = vc[i].second;
                    idx = i;
                }
            }
            total += maxv;
            w += maxv;
           // cout << " use=" << idx << " profit=" << maxv << " cap=" << vc[idx].first << endl;
            //hs.insert(idx); //used
            used[idx] = 1;
        }
        return total;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int> > vc;
        int len = capital.size();
        for (int i = 0; i < len; i++) {
            vc.push_back(make_pair(capital[i], profits[i]));
        }
        sort(vc.begin(), vc.end());

        int cnt = 0;
        int total = w;
        int idx = 0;
        int i = 0;
        priority_queue<int, vector<int>, less<int> > maxHeap;
        while(cnt++ < k) {
            for (; i < len; i++) {
                if (vc[i].first > total) {
                    break;
                }
                maxHeap.push(vc[i].second);
            }
            if (maxHeap.empty()) {
                break;
            }
            total += maxHeap.top();
            maxHeap.pop();
        }
        return total;
    }

};


// @lc code=end

/*
Wrong Answer
10/40 cases passed (N/A)
Testcase
1
2
[1,2,3]
[1,1,2]
Answer
3
Expected Answer
5
Stdout
 use=2 profit=3 cap=2

Time Limit Exceeded
32/40 cases passed (N/A)
Testcase
100000
' +
  '100000
' +
  '[100...
Expected Answer
1000100000


Runtime Error
3/40 cases passed (N/A)
Error
Line 1082: Char 16: runtime error: reference binding to null pointer of type 'const int' (stl_iterator.h)
Line 1082: Char 16: runtime error: reference binding to null pointer of type 'const int' (stl_iterator.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_iterator.h:1091:16
Testcase
1
0
[1,2,3]
[1,1,2]
Expected Answer
0


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
