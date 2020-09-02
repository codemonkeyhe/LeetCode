/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag  DP
 * @similar
 */

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "common.h"

using namespace std;

class Solution {
public:
/*
M3
Exp
1.从左往右的DP 不如从右往左的DP方便
2.状态压缩后，可以避免dp[-1]=1的尴尬
3.边界情况 例如dp[0] dp[-1]的考虑

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
Memory Usage: 6.4 MB, less than 37.75% of C++ online submissions for Decode Ways.
*/
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        if (s[0] == '0') {
            return 0;
        }
        dp[0] = 1;
        // dp[-1] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    // dp[i] = dp[i - 2];
                    dp[i] = i >= 2 ? dp[i - 2] : 1;
                } else {
                    dp[i] = 0;
                }
            } else {
                dp[i] = dp[i - 1];
                if (i >= 1) {
                    if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
                        // dp[i] += dp[i - 2];
                        dp[i] += i >= 2 ? dp[i - 2] : 1;
                    }
                }
            }
        }
        return dp[n - 1];
    }

    /*
    TLE
   "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253"
    */
    int helper(const string &s, int begin, unordered_set<string> &hm) {
        if (begin >= s.length()) {
            return 1;
        }
        //取第一个字符,如果是'0'，则跳过
        int res = 0;
        if (s[begin] != '0') {
            res += helper(s, begin + 1, hm);
        }
        if (begin + 2 <= s.length()) {
        //取前二个字符
            string s2 = s.substr(begin, 2);
            unordered_set<string>::iterator it = hm.find(s2);
            if (it != hm.end()) {
                res += helper(s, begin + 2, hm);
            }
        }
        return res;
    }



    int numDecodingsM1(string s) {
        if (s.empty())
            return 0;
        unordered_set<string> hm;
        for (int i = 1; i <= 26; ++i) {
            hm.insert(to_string(i));
        }
        unordered_map<string, int> cache;
        return helper(s, 0, hm, cache);
    }

/*
Runtime: 32 ms, faster than 5.19% of C++ online submissions for Decode Ways.
Memory Usage: 17 MB, less than 5.01% of C++ online submissions for Decode Ways.
*/
    int helper(const string &s, int begin, unordered_set<string> &hm,  unordered_map<string, int> &cache) {
        string substr = s.substr(begin, -1);
        auto ip = cache.find(substr);
        if (ip != cache.end()) {
            return ip->second;
        }
        if (begin >= s.length()) {
            return 1;
        }
        //取第一个字符,如果是'0'，则跳过
        int res = 0;
        if (s[begin] != '0') {
            res += helper(s, begin + 1, hm, cache);
        }
        if (begin + 2 <= s.length()) {
        //取前二个字符
            string s2 = s.substr(begin, 2);
            unordered_set<string>::iterator it = hm.find(s2);
            if (it != hm.end()) {
                res += helper(s, begin + 2, hm, cache);
            }
        }
        cache.insert(make_pair(substr, res));
        return res;
    }

};

int numDecodings(char * s){

}


int main() {

    Solution s;

    return 0;
}

/*
Tips
M1 DFS [TLE]
f(226) = [2]f(26) + [22]f(6) = 2+1=3
f(26) = [2]f(6)+[26]f(0) = 1+1=2
f(6) = [6]f(0)= 1
f(62) = [6]f(2) = 1
f(662) = [6]f(62)  = [66]f(2)  = 1
f(262) = [2]f(62) + [26]f(2) = 1+1=2
f(12) = [1]f(2) + [12] = 1+1 = 2;
f(202) = [2]f(02) + [20]f(2) = 0 +1=1

M1.5 DFS+Cache

DFS写复杂了,其实不需要用hash_map，但是Cache的思路是对的,cache的存储结构太笨了
参见
https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
Recursion
Runtime: 1988 ms, faster than 5.19% of C++ online submissions for Decode Ways.
Memory Usage: 6.2 MB, less than 87.79% of C++ online submissions for Decode Ways.
    int numDecodings(string s) {
        return s.empty() ? 0: numDecodings(0,s);
    }
    int numDecodings(int p, string& s) {
        int n = s.size();
        if(p == n) return 1; //剩余字符串为空，说明找到1种解法了
        if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
        //'0'只能配合左边的'1'或者'2'使用，结合称谓10或者20，因此遇到单独打头的0,说明这种方案不可行，直接return 0
        int res = numDecodings(p+1,s);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) //做了剪枝 如果是3,4..打头，必然不可能以双字符解码
            res += numDecodings(p+2,s);
        return res;
    }

Recursion+Memory
vector<int> mem下标idx对应着 s.substr(idx,-1)的子串，即以字符s[idx]打头的子串，值存储对应的种类数目
Runtime: 4 ms, faster than 63.80% of C++ online submissions for Decode Ways.
Memory Usage: 6.5 MB, less than 24.58% of C++ online submissions for Decode Ways.

    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n+1,-1); //注意是n+1 下标从0..n，因为i的范围就是从0..n
        mem[n]=1; //相当于 if(p==n) return 1;因为下标i==s.length()时，表示所有字符都已解码完毕
        return s.empty()? 0 : num(0,s,mem);
    }

    int num(int i, string &s, vector<int> &mem) {
        if(mem[i]>-1) return mem[i];
        if(s[i]=='0') return mem[i] = 0;
        int res = num(i+1,s,mem);
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7'))
            res+=num(i+2,s,mem);
        return mem[i] = res; //相当于 mem[i]=res; return res;
    }


M2 DP
DP本质其实就是M1.5的 Recursion+Memory的迭代写法
Recursion的本质是从左往右解码，改成迭代后，相当于递归的返回栈，因此是从右往左来迭代字符串
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1); //与前面的mem含义是相同的，dp[idx]即以s[idx]打头的字符的解码情况数
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') dp[i]=0;
            else {
                dp[i] = dp[i+1]; //即s[i]单独解码的情况
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7'))
                    dp[i]+=dp[i+2];  //即s[i]和s[i+1]合并解码的情况
            }
        }
        return s.empty()? 0 : dp[0];
    }

M2.5 DP状态压缩
    pp相当于dp_i_2
    p相当于dp_i_1
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;  //dp_i_2 = dp_i_1
            p = cur;  // dp_i_1 = cur
        }
        return s.empty()? 0 : p;
    }

M3 DP
M2的dp[i] 是以 s[i]打头的解码情况数，即s[i:n-1]的情况数目。i从n-1到0去迭代
如果s[i]可以单独解码,即s[i]!='0' dp[i] = dp[i+1]
如果s[i]还可以和s[i+1]联合解码，则dp[i]=dp[i+1]+dp[i+2];
边界情况
dp[n-1] = s[n-1:n-1] 即一个字符的情况数，如果是'0',则是0，否则是1
dp[n] = s[n:n-1]=1,即空串，所有字符成功解码，代表1种情况

M3的dp[i]定义为 以s[0..i]的情况数,i从0到n-1去迭代
dp[i+1] = dp[i]，　即s[i+1]!='0' 可以单独解码
dp[i+1] = 0,  即s[i+1]='0',但是又必须单独解码的情况;
dp[i+1] = dp[i-1], 即s[i+1]='0',但是联合解码成功的情况;
dp[i+1] = dp[i-1] 即s[i+1]和s[i]联合解码
因此 dp[i+1] = dp[i] + dp[i-1] ;即 s[i+1]可单独解码，又可以和s[i]联合解码

dp[0] 即s[0]的情况数，if s[0] ='0'则dp[0]=0 否则dp[0] =1


*/
