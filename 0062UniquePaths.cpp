/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-
 * @tag   dp
 * @similar  62, 63, 980
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (68.25%)
 * Likes:    2237
 * Dislikes: 0
 * Total Accepted:    995.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 示例 1：
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 示例 2：
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 *
 *
 * 示例 3：
 * 输入：m = 7, n = 3
 * 输出：28
 *
 *
 * 示例 4：
 * 输入：m = 3, n = 3
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    Solution(){}

    //不加CACHE TLE
    /*
Time Limit Exceeded
41/63 cases passed (N/A)
Testcase
51
9
Expected Answer
1916797311

    */

    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        int key = m * 100 + n;
        if (cache.count(key)) {
            return cache[key];
        }

        int res = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        cache[key] = res;
        return res;
    }

    // pair无法直接作为key，需要另外提供hash函数
    //unordered_map<pair<int, int>, int>  cache;
    unordered_map<int, int>  cache;


    int uniquePathsDP(int m, int n) {
       // return m1(m, n);
//        return m2(m, n);
        return m2v2(m, n);
    }

    int m2v2(int m, int n) {
        vector<int> vv(m, 0);
        for (int j = 0; j < m; ++j) {
            vv[j] = 1;
        }
        for (int i = 1; i < n; ++i){
            for (int j = 1; j < m; ++j) {
                vv[j] = vv[j] + vv[j-1];
            }
        }
        return vv[m-1];
    }

     /*
    f(m,n) = f(m-1,n)+f(m,n-1)
    像杨辉三角
    1 1 1
    1 2 3
    1 3 6
    */
    int m2(int m, int n) {
        vector<vector<int> > vv(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            vv[i][0] = 1;
        }
        for (int j = 0; j < m; ++j) {
            vv[0][j] = 1;
        }
        for (int i = 1; i < n; ++i){
            for (int j = 1; j < m; ++j) {
                vv[i][j] = vv[i-1][j] + vv[i][j-1];
            }
        }
        return vv[n-1][m-1];
    }


    int m1(int m, int n) {
        int data[200] = {};
        // 情况数 C(m-1+n-1, m-1) = (m+n-2)! / (m-1)!(n-1)!
        int up = m + n - 2;
        int down1 = m - 1;
        int down2 = n - 1;
        for (int i=1; i<=up; ++i) {
            data[i]++;
        }
        for (int i = 1; i <= down1; ++i) {
            data[i]--;
        }
        for (int i = 1; i <= down2; ++i) {
            data[i]--;
        }
        //对data进行拆分
        vector<int> numerator;    //分子
        vector<int> denominator;  //分母
        for (int i = 1; i <= up; ++i) {
            if (data[i] == 0) {  //不存在这个数
                continue;
            }
            if (data[i] > 0) {  // i是分子
                numerator.push_back(i);
            } else {  // i是分母
                denominator.push_back(i);
            }
        }
        //约分
        int prim[3] = {2, 3, 5};
        int count[6] = {};
        for (int j = 0; j < 3; ++j) {
            int p = prim[j];
            for (int i = 0; i < numerator.size(); ++i) {
                while (numerator[i] % p == 0) {
                    numerator[i] /= p;
                    count[p]++;
                }
            }
            for (int i = 0; i < denominator.size(); ++i) {
                while (denominator[i] % p == 0) {
                    denominator[i] /= p;
                    count[p]--;
                }
            }
        }
        unsigned long res=1;
        for (int i = 0; i < numerator.size(); ++i) {
            res = res*numerator[i];
        }
        for (int j = 0; j < 3; ++j) {
            int p = prim[j];
            while(count[p]>0){
                res = res * p;
                count[p]--;
            }
        }
        for (int i = 0; i < denominator.size(); ++i) {
            res = res/denominator[i];
        }
        for (int j = 0; j < 3; ++j) {
            int p = prim[j];
            while(count[p]<0){
                res = res / p;
                count[p]++;
            }
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


