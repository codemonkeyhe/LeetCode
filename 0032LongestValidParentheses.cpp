/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-04
 * @tag dynamicProgramming,stack
 * @similar 20,22,32
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (37.98%)
 * Likes:    2710
 * Dislikes: 0
 * Total Accepted:    572.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 * 示例 1：
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 0 <= s.length <= 3 * 10^4
 * s[i] 为 '(' 或 ')'
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    int longestValidParenthesesM1V1(string s) {
        int len = s.size();
        vector<int> dp(len, 0);
        // dp[0] = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == '(') {
                dp[i] = 0;
                continue;
            }
            if (s[i - 1] == '(') {  // caseA
                int val = (i >= 2) ? dp[i - 2] : 0;
                dp[i] = val + 2;
                continue;
            }
            //caseB
            int L = dp[i-1];
            if ((i >= L + 1) && (s[i - L - 1] == '(')) {
                int val = (i >= L + 2) ? dp[i - L - 2] : 0;
                dp[i] = dp[i - 1] + 2 + val;
            }
        }
        auto it = max_element(dp.begin(), dp.end());
        return (it == dp.end()) ? 0: (*it);
    }


    //偏移量大法
    // dp[i] 偏移为 dp[i']  i'-2 = i = [0.. len-1]
    int longestValidParenthesesM1V2(string s) {
        int len = s.size();
        vector<int> dp(len + 2, 0);
        for (int i = 3; i <= len + 1; i++) { // here is i'
            if (s[i - 2] == '(') {
                //dp[i] = 0;
                continue;
            }
            if (s[i - 3] == '(') {  // caseA
                dp[i] = dp[i - 2] + 2;
                continue;
            }
            //caseB
            int L = dp[i-1];
            if ((i >= L + 3) && (s[i - L - 3] == '(')) {
                dp[i] = dp[i - 1] + 2 + dp[i - L - 2];
            }
        }
        auto it = max_element(dp.begin(), dp.end());
        return (it == dp.end()) ? 0: (*it);
    }


    int longestValidParenthesesM2(string s) {
        stack<int> st;
        int start = -1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            if (st.empty()) {
                start = i; //means s[i] is new split point
                continue;
            }
            // means match
            st.pop();
            int len = i - start;
            if (!st.empty()) {// top element is split point
                len = i - st.top();
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }


    int longestValidParenthesesM22(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            // s[i] == ')'
            // means match or pop the old split point
            st.pop();
            if (st.empty()) {
                //start = i; //means s[i] is new split point
                st.push(i);
                continue;
            }
            if (!st.empty()) {  // top element is split point
                int len = i - st.top();
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }



    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left < right) {
                left = 0;
                right = 0;
            } else if (left == right) {
                maxLen = max(maxLen, left * 2);
            }
        }

        left = 0;
        right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left > right) {
                left = 0;
                right = 0;
            } else if (left == right) {
                maxLen = max(maxLen, left * 2);
            }
            //cout << "i=" << i << " mm=" <<  maxLen << endl;
        }
        return maxLen;
    }

};
// @lc code=end

/*
)()())
dp[i][j]表示nums[i..j]的最长有效括号的长度
if (nums[j]=="(")  dp[i][j] = dp[i][j-1]
if (nums[j]==")")
   CaseA nums[j-1]=="("   dp[i][j] = dp[i][j-2] +2，意味着dp[i][j-2]必须以nums[j-2]结尾
   CaseB nums[j-1]==")"   nums[i... j-2] = .....)) 也必然存在一个最长有效括号，记做 dp[i][j-2]，
        dp[i][j-2]的最长有效括号不一定以nums[i]开头，可能是nums[k]开头， k>i，但是必须以nums[j-2]结尾，
        因此需要修正DP的定义，dp[i][j]不一定以nums[i]开头，必须以nums[j]结尾，换句话说，i没有必要存在了，dp[i][j] = dp[j]

dp[j]表示以nums[j]结尾的最长有效括号的长度
if (nums[j]=="(")  dp[j] = 0

if (nums[j]==")")
    CaseA nums[j-1]=="("   dp[j] = dp[j-2] +2

CaseB nums[j-1]==")"
形如        ....))
令dp[j-1]的长度为L，  nums[k...j-1]的最长有效括号的长度为L ，以nums[k]打头，nums[j-1]结尾， 长度j-1-k+1 = L  , j-k = L，有k=j-L
nums[k ... j-1]有效，意味着nums[k]和nums[j-1]配对，因此nums[k]=(
i.. k.. j-2 )) =  i.. (.. j-2))
    if (nums[k-1] == '('
    则有 i.. ((.. j-2))
    此时有 dp[j] = dp[j-1] +2 + dp[k-2], 其中dp[k-2]就是以nums[k-2]结尾的最长有效括号，可以和后面的连接起来，成为一个更大的有效括号
    dp[k-2]=dp[j-L-2] = dp[j-dp[j-1]-2]
    因此 ， dp[j] = dp[j-1] + 2 + dp[j-dp[j-1]-2]

Runtime Error
2/231 cases passed (N/A)
Error
Line 1082: Char 16: runtime error: reference binding to null pointer of type 'int' (stl_iterator.h)
Line 1082: Char 16: runtime error: reference binding to null pointer of type 'int' (stl_iterator.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_iterator.h:1091:16
Testcase
""
Expected Answer
0


Wrong Answer
199/231 cases passed (N/A)
Testcase
"()"
Answer
0
Expected Answer
2


Wrong Answer
217/231 cases passed (N/A)
Testcase
"(()())"
Answer
4
Expected Answer
6



Wrong Answer
102/231 cases passed (N/A)
Testcase
"()"
Answer
1
Expected Answer
2
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


