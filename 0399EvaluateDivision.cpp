/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-11
 * @tag bfs,floyd, shortestPath
 * @similar   399, 1334
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode.cn/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (58.56%)
 * Likes:    1180
 * Dislikes: 0
 * Total Accepted:    121.4K
 * Total Submissions: 205.5K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0
 * 替代这个答案。
 *
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。
 *
 *
 *
 * 示例 1：
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 注意：x 是未定义的 => -1.0
 *
 * 示例 2：
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 *
 *
 * 示例 3：
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 *
 *
 *
 *
 * 提示：
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 *
 *
 */

// @lc code=start
class Solution {
public:

    // M1
    vector<double> calcEquationBFS(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        int total = len * 2;

        int idx = 0;
        unordered_map<string, int> n2i;
        vector<vector<double>> ma(total, vector<double>(total, 0.0L));
        for (int i = 0; i < len; i++) {
            auto& eq = equations[i];
            double val = values[i];
            if (n2i.count(eq[0]) == 0) {
                n2i[eq[0]] = idx++;
            }
            if (n2i.count(eq[1]) == 0) {
                n2i[eq[1]] = idx++;
            }
            int from = n2i[eq[0]];
            int to = n2i[eq[1]];
            ma[from][to] = val;
            ma[to][from] = 1.0L / val;
        }

        vector<double> res;
        for (auto& que: queries) {
            if (n2i.count(que[0]) == 0 || (n2i.count(que[1]) == 0)) {
                res.push_back(-1.0L);
                continue;
            }
            int from = n2i[que[0]];
            int to = n2i[que[1]];
            double vv = getPath(ma, from, to);
            res.push_back(vv);
        }

        return res;
    }


    //bfs
    double getPath(vector<vector<double>>& ma, int from, int to) {
        if (from == to) {
            return 1.0L;
        }
        double val = ma[from][to];
        if (val != 0.0L) {
            return val;
        }
        queue<pair<int, double>> que;
        unordered_set<int> used;
        que.push(make_pair(from, 1.0L));
        used.insert(from);
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();

                auto neis = ma[cur.first];
                for (int j = 0; j < neis.size(); j++) {
                    if (neis[j] == 0.0L) {
                        continue;
                    }
                    if (used.count(j)) {
                        continue;
                    }
                    used.insert(j);
                    double pathRes = cur.second * neis[j];
                    if (j == to) {
                        return pathRes;
                    }
                    que.push(make_pair(j, pathRes));
                }
            }
        }
        return -1.0L;
    }

    //M2 floyd
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        int total = len * 2;

        int idx = 0;
        unordered_map<string, int> n2i;
        vector<vector<double>> ma(total, vector<double>(total, 0.0L));
        for (int i = 0; i < len; i++) {
            auto& eq = equations[i];
            double val = values[i];
            if (n2i.count(eq[0]) == 0) {
                n2i[eq[0]] = idx++;
            }
            if (n2i.count(eq[1]) == 0) {
                n2i[eq[1]] = idx++;
            }
            int from = n2i[eq[0]];
            int to = n2i[eq[1]];
            ma[from][to] = val;
            ma[to][from] = 1.0L / val;
        }

        for (int k = 0; k < idx; k++) { // 中介 k
            ma[k][k] = 1.0L;
            for (int i = 0; i < idx; i++) {
                for (int j = 0; j < idx; j++) {
                    if (ma[i][k] > 0 && ma[k][j] > 0) {
                        ma[i][j] = ma[i][k] * ma[k][j];
                    }
                }
            }
        }

        vector<double> res;
        for (auto& que: queries) {
            if (n2i.count(que[0]) == 0 || (n2i.count(que[1]) == 0)) {
                res.push_back(-1.0L);
                continue;
            }
            int from = n2i[que[0]];
            int to = n2i[que[1]];
            double vv = ma[from][to];
            if (vv == 0.0L) {
                res.push_back(-1.0L);
            } else {
                res.push_back(vv);
            }
        }
        return res;
    }

    bool aboutEqual(double a, double b) {
        static double epsilon = 1e-5;
        return fabs(a - b) <= epsilon;
    }

};
// @lc code=end

/*
Wrong Answer
0/29 cases passed (N/A)
Testcase
[["a","b"],["b","c"]]
' +
  '[2.0,3.0]
' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Answer
[6.00000,0.00000,-1.00000,1.00000,-1.00000]
Expected Answer
[6.0,0.5,-1.0,1.0,-1.0]



Time Limit Exceeded
8/29 cases passed (N/A)
Testcase
[["a","b"],["c","d"]]
[1.0,1.0]
[["a","c"],["b","d"],["b","a"],["d","c"]]
Expected Answer
[-1.00000,-1.00000,1.00000,1.00000]
a->b->a->b 死循环 需要used


M2 floyd
Wrong Answer
28/29 cases passed (N/A)
Testcase
[["b","a"],["c","b"],["d","c"],["e","d"],["f","e"],["g","f"],["h","g"],["i","h"],["j","i"],["k","j"],["k","l"],["l","m"],["m","n"],["n","o"],["o","p"],["p","q"],["q","r"],["r","s"],["s","t"],["t","u"]]
' +
  '[1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05,1e-05]
' +
  '[["a","u"]]
Answer
[0.99994]
Expected Answer
[1.0]
*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
