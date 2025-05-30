/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-12, 20250523
 * @tag   dynamicProgramming
 * @similar  300, 1143
 */

/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>

using namespace std;


/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Medium (62.86%)
 * Likes:    3677
 * Dislikes: 0
 * Total Accepted:    661.6K
 * Total Submissions: 1M
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:

/*

dp[i][j] 表示 word1[0-i] 和word2[0-j]的minDistance
ans=dp[l1-1][l2-1]
偏移1位，则
dp[i+1][j+1] 表示 word1[0~i] 和word2[0~j]的minDistance
dp[i][j] 表示 word1[0~i-1] 和word2[0~j-1]的minDistance
ans=dp[l1][l2]
*/

    int minDistanceM1(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int> > dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i <= l1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= l2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                // dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
        return dp[l1][l2];
    }


    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
    //    vector<vector<int> > dp(l1 + 1, vector<int>(l2 + 1, 0));
        memo = vector<vector<int> >(l1, vector<int>(l2, -1));
        return cacheBT(word1, word2, l1-1, l2-1);
    }

    vector<vector<int> > memo;
    int cacheBT(string& word1, string& word2, int i, int j) {
        if (i < 0) {
            return j+1; //del word2[0,j]
        }
        if (j < 0) {
            return i+1;
        }
        int& cres = memo[i][j];
        if (cres != -1) {
            return cres;
        }

        if (word1[i] == word2[j]) {
            int res = cacheBT(word1, word2, i-1, j-1);
            cres = res;
            return res;
        }

        int res = min({
            cacheBT(word1, word2, i-1, j),  // delOP
            cacheBT(word1, word2, i-1, j-1), // replace
            cacheBT(word1, word2, i, j-1) // addOp
        }) + 1;
        cres = res;
        return res;
    }

};
// @lc code=end

/*
min(op1, op2)
min({op1, op2, op3}) // C++ 11 新方法



dp[i][j] 表示 word1[0-i] 和word2[0-j]的minDistance

if (w1[i] == w2[j])
dp[i][j] = dp[i-1][j-1]


if (w1[i] != w2[j])
dp[i][j] == min(
    delOP: dp[i-1][j]  ，
    replaceOP: dp[i-1][j-1],
    addOP: dp[i][j-1]
    ) + 1


关键点：
if (w1[i] != w2[j])
执行AddOP，必然会在W1末尾插入一个w2[j]的字符
相当于
dp[i][j] = dp[i+1][j]
又因为此时 w1[i+1] = w2[j] ,
因此   dp[i+1][j] = dp[i][j-1]
所以 有 dp[i][j] = dp[i][j-1]


不加Cache
Time Limit Exceeded
26/1147 cases passed (N/A)
Testcase
"dinitrophenylhydrazine"
"benzalphenylhydrazone"
Expected Answer
7



*/


class SolutionOld {
public:
    int minDistance(string word1, string word2) {
        return dis(word1, 0, word1.size()-1, word2, 0, word2.size()-1);
    }

    // Time Limit Exceeded
    int dis(const string &word1, int w1b, int w1e, const string &word2,
                int w2b, int w2e) {
        if (w1b > w1e) {      // w1=""
            if (w2b > w2e) {  // w2 = ""
                return 0;
            } else {
                return w2e - w2b + 1;
            }
        }
        if (w2b > w2e) {      // w2 = ""
            if (w1b > w1e) {  // w1=""
                return 0;
            } else {
                return w1e - w1b + 1;
            }
        }
        if (word1[w1b] == word2[w2b]) {
            return dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);
        }
        // remove  w1[0] // insert w1[0] before w2[0]
        int d1 = dis(word1, w1b + 1, w1e, word2, w2b, w2e);
        // remove  w2[0] // insert w2[0] before w1[0]
        int d2 = dis(word1, w1b, w1e, word2, w2b + 1, w2e);
        // repace  char  at w1[0] = w2[0]
        int d3 = dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);
        return min(min(d1, d2), d3) + 1;
    }


};

int minDistance(char *word1, char *word2) {
    int m=strlen(word1);
    int n=strlen(word2);
    int d[m+1][n+1];
    int i=0; int j = 0;
    for (i = 0; i <= m; ++i) {
        for (j = 0; j <= n;++j) {
            if (i == 0) {
                d[i][j] = j;
            } else if (j == 0){
                d[i][j] = i;
            } else if  (word1[i-1] == word2[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                int md = d[i-1][j] > d[i][j-1] ? d[i][j-1] : d[i-1][j];
                d[i][j] = (md>d[i-1][j-1]? d[i-1][j-1] : md) +1;
            }
        }
    }
    /*
    for (i = 0; i <= m; ++i) {
        for (j = 0; j <= n;++j) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    */
    return d[m][n];
}

int main() {
    string w1 = "intention";
    string w2 = "execution";
//    w1 = "horse";
//    w2 = "ros";
    printf("%d\n", minDistance((char*)w1.c_str(), (char*)w2.c_str()));
    // w1 = "dinitrophenylhydrazine";
    // w2 = "acetylphenylhydrazine";
 //   Solution s;
  //  cout << s.minDistance(w1, w2) << endl;
    return 0;
}


/*
Tips
M1 递归【BOP官方解法】
Error TLE
    指数级别增长
可以用 缓存方案，避免重复计算

M2 把递归转成DP

if w1[0] = w2[0]
     return dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);
else
    // remove  w1[0] // insert w1[0] before w2[0]
    int d1 = dis(word1, w1b + 1, w1e, word2, w2b, w2e);
    // remove  w2[0] // insert w2[0] before w1[0]
    int d2 = dis(word1, w1b, w1e, word2, w2b + 1, w2e);
    // repace  char  at w1[0] = w2[0]
    int d3 = dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);
    return min(d1, f2, d3)+1;

得出递推方程
d(w1, 0, n, w2, 0, m)  =  d(w1, 1, n, w2, 1, m);   if w1[0] == w2[0]
d(w1, 0, n, w2, 0, m)  =  min[ d(w1, 1, n, w2, 0, m), d(w1, 0, n, w2, 1, m), d(w1, 1, n, w2, 1, m)] +1 ;   if w1[0] != w2[0]

把上述递推方程反向简化,从尾部开始往头部修改，
令 d(i,j) = d(w1,0,i, w2,0,j) , i=len(w1)-1，令j=len(w2)-1 ,i和j为w1和w2的下标指针
d(i, j) = d(i-1,j-1)    if (w[i] == w[j])
d(i, j) = min( d(i-1, j), d(i, j-1), d(i-1, j-1)) +1,   if (w[i] != w[j])

d(0, j) = d(w1, 0, 0, w2, 0, j) = d(w1[0..0] , w2[0..j] )
d(i, 0) = d(w1[0..i], w2[0..0] )
d(0, 0) = d(w1[0..0], w2[0..0] )

这样会引入负数，而且w1[0..0]=w1[0],无法表示空串''

因此换种写法
令 d(m,n) = d(w1,0,m, w2,0,n)  = d( w1[0:m), w2[0:n) ), 只是 m=len(w1), n=len(w2), m和为 数组最后1个元素的下一个节点。
这样 w[0:1) =w[0]
这样 w[0:0) =""

前提 i<=m, j<=n
d(i, j) = d(i-1,j-1)    if (w[i-1] == w[j-1])
d(i, j) = min( d(i-1, j), d(i, j-1), d(i-1, j-1)) +1,   if (w[i-1] != w[j-1])

d(0, j) = d(w1, 0, 0, w2, 0, j) = d(w1[0..0) , w2[0..j) ) = d("",  w2[0..j)) = j;
d(0, 0) = d(w1[0..0), w2[0..0) ) = 0

最后画一个i,j求解 的二维数组出来，可以看出 DP依赖路径，因此可以 用 for i for j 遍历二维数组的方式去依次求解。

https://leetcode.com/problems/edit-distance/discuss/530858/C-easy-solution-Dynamic-programming
https://leetcode.com/problems/edit-distance/discuss/528282/DP-C%2B%2B


*/