/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-16
 * @tag stack, monotonicStack
 * @similar 42, 496, 739
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.75%)
 * Likes:    1974
 * Dislikes: 0
 * Total Accepted:    759.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 *
 *
 *
 * 示例 1:
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 *
 *
 * 示例 2:
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 *
 *
 * 示例 3:
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 *
 *
 *
 * 提示：
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperaturesUgly(vector<int>& temper) {
        int len =  temper.size();
        vector<pair<int, int> > st; // tem -> idx

        st.push_back(make_pair(temper[0], 0));
        int i = 1;

        vector<int> res(len, 0);
        while (i < len) {
            int& cur = temper[i];
            if (st.empty()) {
                st.push_back(make_pair(cur, i));
                i++;
                continue;
            }

            auto pa = st.back();
            if (cur <= pa.first) {
                st.push_back(make_pair(cur, i));
                i++;
                continue;
            }

            while (cur > pa.first) {
               int dis = i - pa.second;
               res[pa.second] = dis;
               st.pop_back();
               if (st.empty()) {
                   break;
               }
               pa = st.back();
            }
            st.push_back(make_pair(cur, i));
            i++;
            continue;
        }

        for (auto& [tmp, idx] : st) {
            res[idx] = 0;
        }
        return res;
    }


    // code tidy
    vector<int> dailyTemperaturesTidy1(vector<int>& temper) {
        int len =  temper.size();
        vector<pair<int, int> > st; // tem -> idx

        int i = 0;
        vector<int> res(len, 0);
        while (i < len) {
            int& cur = temper[i];
            // cur >= st.top()
            while (!st.empty() && (cur > st.back().first)) {
                auto& pa = st.back();
                res[pa.second] = i - pa.second;
                st.pop_back();
            }

            // if is duplicate , when exit while ,must meet if condition
            if (st.empty() || (cur <= st.back().first)) {
                st.push_back(make_pair(cur, i));
                i++;
            }
        }

        // below is duplicate, because default value is zero
        for (auto& [tmp, idx] : st) {
            res[idx] = 0;
        }
        return res;
    }

    // code tidy2

    // 可以只存下标，回源到 temper来 查温度
    vector<int> dailyTemperatures(vector<int>& temper) {
        int len =  temper.size();
        vector<pair<int, int> > st; // tem -> idx
        int i = 0;
        vector<int> res(len, 0);
        while (i < len) {
            int& cur = temper[i];
            // cur >= st.top()
            while (!st.empty() && (cur > st.back().first)) {
                auto& pa = st.back();
                res[pa.second] = i - pa.second;
                st.pop_back();
            }

            st.push_back(make_pair(cur, i));
            i++;
        }
        return res;
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


