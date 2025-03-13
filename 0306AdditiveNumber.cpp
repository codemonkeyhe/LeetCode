/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-13
 * @tag backtracking
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 *
 * https://leetcode.cn/problems/additive-number/description/
 *
 * algorithms
 * Medium (37.60%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    57.6K
 * Total Submissions: 154K
 * Testcase Example:  '"112358"'
 *
 * 累加数 是一个字符串，组成它的数字可以形成累加序列。
 *
 * 一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。
 *
 * 给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。
 *
 * 说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 *
 *
 *
 * 示例 1：
 * 输入："112358"
 * 输出：true
 * 解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 *
 * 示例 2：
 * 输入："199100199"
 * 输出：true
 * 解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 *
 *
 *
 * 提示：
 * 1 <= num.length <= 35
 * num 仅由数字（0 - 9）组成
 *
 *
 *
 *
 * 进阶：你计划如何处理由过大的整数输入导致的溢出?
 *
 */

// @lc code=start
class SolutionOutOfRange {
public:
    bool isAdditiveNumber(string num) {
        int idx = 0;
        vector<int> path;
        vector<int> pathLen;
        bool res = false;
        if (num.size() < 3) {
            return false;
        }
        bt(num, idx, path, pathLen, res);
        return res;
    }


    void bt(string num, int idx, vector<int>& path, vector<int>& pathLen, bool& res) {
        if (idx == num.size() && path.size() >= 3) {
            res = true;
            return ;
        }

        //int sum = 0;
        for (int i = idx; i < num.size(); i++) {
            int ssLen = i - idx+1;
            string ss = num.substr(idx, ssLen);
           // int ci = num[i] - '0';
          //  sum = sum*10 + ci;
            if (ssLen > 1 && (num[idx] == '0'))  {
                continue;
            }
            int pl = pathLen.size();
            if (pl >= 2) {
                int maxLen = max(pathLen[pl - 2], pathLen[pl - 1]);
                if (ssLen > (maxLen + 1)) {
                    continue;
                }
            }
            long long sum = stoll(ss);
            int len = path.size();
            if (len >= 2) {
                if (( sum - path[len-2] ) !=  path[len-1] ) {
                     continue;
                }
            }
            path.push_back(sum);
            pathLen.push_back(ssLen);
           cout << "idx=" << idx << " i=" << i << " sum=" << sum << endl;
            bt(num, i+1, path, pathLen, res);
            path.pop_back();
            pathLen.pop_back();
        }

        return ;
    }
};

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int idx = 0;
        vector<string> path;
        bool res = false;
        if (num.size() < 3) {
            return false;
        }
        bt(num, idx, path,  res);
        return res;
    }


    void bt(string num, int idx, vector<string>& path,  bool& res) {
        if (idx == num.size() && path.size() >= 3) {
            res = true;
            return ;
        }

        //int sum = 0;
        for (int i = idx; i < num.size(); i++) {
            int ssLen = i - idx+1;
            string ss = num.substr(idx, ssLen);
            if (ssLen > 1 && (num[idx] == '0'))  {
                continue;
            }
            int len = path.size();
            if (len >= 2) {
                int maxLen = max(path[len-1].size(), path[len-2].size());
                if (ssLen > (maxLen+1)) {
                    continue;
                }
                if (stringAdd(path[len-1] , path[len-2] ) !=  ss ) {
                     continue;
                }
            }
            path.push_back(ss);
            bt(num, i+1, path, res);
            if (res == true) {
                return;
            }
            path.pop_back();
        }

        return ;
    }

    string stringAdd(string s1, string s2) {
        string res = "";
        int add = 0;
        int p2 = s2.size() -1;
        int p1 = s1.size() -1;
        while ((p1 >= 0) || (p2 >= 0)) {
            int cur =  add;
            if (p2 >= 0) {
                cur +=(s2[p2] - '0');
                p2--;
            }
            if (p1 >= 0 ) {
                cur += (s1[p1] - '0');
                p1--;
            }
            add = cur/10;
            cur = cur %10;
            res += char(cur+'0');
        }

        if (add == 1) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// @lc code=end

// 9223372036854775807


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


