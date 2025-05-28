/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-28
 * @tag  dynamicProgramming
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
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode.cn/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (44.87%)
 * Likes:    1108
 * Dislikes: 0
 * Total Accepted:    185.8K
 * Total Submissions: 404.7K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
 * 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
 *
 *
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 +
 * ...
 * 注意：a + b 意味着字符串 a 和 b 连接。
 *
 *
 *
 * 示例 1：
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：s1 = "", s2 = "", s3 = ""
 * 输出：true
 *
 *
 *
 *
 * 提示：
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1、s2、和 s3 都由小写英文字母组成
 *
 *
 *
 *
 * 进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它?
 *
 */

// @lc code=start
class Solution {
public:
    bool isInterleaveM1(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l1 + l2 != l3) {
            return false;
        }
        //return cacheBT(s1, s2, s3, l1 - 1, l2 - 1, l3 - 1);
        return cacheBTV2(s1, s2, s3, l1 - 1, l2 - 1);
    }

    unordered_map<int, bool> cache;

    bool cacheBT(string& s1, string& s2, string& s3, int i, int j, int k) {
       // cout << " i=" << i << " j=" << j << " k=" << k << endl;
        if (k < 0)  {
            if (i < 0 && j < 0) {
                return true;
            } else {
                return false;
            }
        }
        // k >= 0
        if (j < 0) {
            return (s1.substr(0, i + 1) == s3.substr(0, k + 1));
        }
        if (i < 0) {
            return (s2.substr(0, j + 1) == s3.substr(0, k + 1));
        }
        // i >=0 && j >= 0 && k >= 0
        if (i + j + 2 != k + 1) { // len is not match
            return false;
        }

        int key = i * 1000 + j;
        //int key = i * 100000 + j * 1000 + k;
        if (cache.count(key)) {
            return cache[key];
        }
        bool& res = cache[key];

        if ((s3[k] != s1[i]) && (s3[k] != s2[j])) {
            cache[key] = false;
            return false;
        }

        if ((s3[k] == s1[i]) && (s3[k] == s2[j])) {
            res = cacheBT(s1, s2, s3, i - 1, j, k - 1) ||
                   cacheBT(s1, s2, s3, i, j - 1, k - 1);
            return res;
        }

        if (s3[k] == s1[i]) {
            res = cacheBT(s1, s2, s3, i - 1, j, k - 1);
            return res;
        }

        if (s3[k] == s2[j]) {
            res =  cacheBT(s1, s2, s3, i, j - 1, k - 1);
            return res;
        }
        res = false;
        return false;
    }

    // 不需要k k可以由i和j推导出来
    // dfs(i, j) 表示 s1[0...i] 和  s2[0...j] 能否交错形成 s3[0...i+j+1]
    bool cacheBTV2(string& s1, string& s2, string& s3, int i, int j) {
       // cout << " i=" << i << " j=" << j << " k=" << k << endl;
       if (i < 0 && j < 0) {
           return true;
       }
       int k = i + j + 1;

        // i >=0 && j >= 0 && k >= 0
        int key = i * 1000 + j;
        //int key = i * 100000 + j * 1000 + k;
        if (cache.count(key)) {
            return cache[key];
        }
        // default val is false
        bool& res = cache[key];
        if (i >= 0 && (s3[k] == s1[i])) {
            res = cacheBTV2(s1, s2, s3, i - 1, j);
        }
        if (j >= 0 && (s3[k] == s2[j])) {
            res = res || cacheBTV2(s1, s2, s3, i, j - 1);
        }
        return res;
    }

    //dp[i][j] = condition1 || condition2
    // condition1 = dp[i-1][j] && (s3[k] == s1[i])
    //condition2  = dp[i][j-1] && (s3[k] == s2[j])
    // dp整体偏移+1，否则初始值不好算
    // dp[i'][j']   i' = i+1; j'=j+1
    // i(i'-1) - [0, l1-1] j(j'-1)-[0, l2-1]
    // dp[i'][j'] 表示 s1[0...i] 和  s2[0...j] 能否交错形成 s3[0...i+j+1]
    // old answer=dp[l1-1][l2-1] ，偏移后 answer = dp[l1][l2]
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l1 + l2 != l3) {
            return false;
        }
        vector<vector<bool> > dp(l1 + 1, vector<bool>(l2 + 1, false));

        // key step
        dp[0][0] = true;

        for (int i = 0; i <= l1; i++) { //这里的i是i'
            for (int j = 0; j <= l2; j++) { //j'
                // old k =  i+1 +j + 1 -1 = i+j+1
                // here k = i+j+1 = i'-1 + j' -1 + 1 = i' +j' -1
                if (i == 0 && j == 0) {
                    continue;
                }
                int k = i + j - 1;
                int res = false;
                if (i > 0 && (s3[k] == s1[i - 1])) {
                    res = dp[i - 1][j];
                }
                if (j > 0 && (s3[k] == s2[j - 1])) {
                    res =  res || dp[i][j-1];
                }
                dp[i][j] = res;
                //cout << "i=" << i << " j= " << j << " dp=" << dp[i][j] << endl;
            }
        }
        return dp[l1][l2];
    }

        /*
        s1 a  i=0
        s2 b  j=0
        s3 ba  k=1
        s3 ca  k=1
        */


};
// @lc code=end

/*
Time Limit Exceeded
102/106 cases passed (N/A)
Testcase
"aaaaaaaaaaaaaaaaaaaaaaaaaaa"
' +
  '"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
' +
  '"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
Expected Answer
false

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


