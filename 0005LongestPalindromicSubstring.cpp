/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-21
 * @tag  danamicProgramming
 * @similar   516, 647
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.35%)
 * Likes:    7676
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 5.1M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 *
 *
 * 示例 1：
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:


    string longestPalindromeMX(string s) {
        int len = s.size();

        // PASS
        memo = vector<vector<pair<int, int> > > (
            len, vector<pair<int, int>>(len, pair<int, int>(0, 0)));
        auto ss = longPalindromeV2(s, 0, len-1);
        return s.substr(ss.first, ss.second);


        //TLE
        //return longPalindrome(s, 0, len-1);


        // TLE
        // auto ss = longPalindromeV3(s, 0, len - 1);
        // return s.substr(ss.first, ss.second);

        //longPa(s, 0, len-1);
        //return maxAns;
    }

    unordered_map<int, string> cache;
    string longPalindrome(string& s, int left, int right) {
        if (left > right) {
            return "";
        }
        int key = left * 10000 + right;
        if (cache.count(key)) {
            return cache[key];
        }
        int i = left;
        int j = right;
        while ((i < j) && (s[i] == s[j])) {
            i++;
            j--;
        }
        if (i >= j) {
            string res = s.substr(left, right - left + 1);
            cache[key] = res;
            return res;
            //return s.substr(left, right - left + 1);
        }
        // s[i] != s[j]
        string sa = longPalindrome(s, left + 1, right);
        string sb = longPalindrome(s, left, right - 1);
        if (sa.size() > sb.size()) {
            cache[key] = sa;
            return sa;
        }
        cache[key] = sb;
        return sb;
    }

    //vector<vector<string> >  memo;  MEM LIMIT

    //换种cache 过了
    // Your runtime beats 5.02 % of cpp submissions
    vector<vector<pair<int, int> > >  memo;

    pair<int, int> longPalindromeV2(string& s, int left, int right) {
        if (left > right) {
            return  make_pair(-1, -1);
        }
        pair<int, int>& cres = memo[left][right];
        if (cres.first != 0) {
            return cres;
        }
        int i = left;
        int j = right;
        while ((i < j) && (s[i] == s[j])) {
            i++;
            j--;
        }
        if (i >= j) {
            //string res = s.substr(left, right - left + 1);
            cres = make_pair(left, right - left + 1);
            return cres;
            //return s.substr(left, right - left + 1);
        }
        // s[i] != s[j]
        auto sa = longPalindromeV2(s, left + 1, right);
        auto sb = longPalindromeV2(s, left, right - 1);
        if (sa.second > sb.second) {
            cres = sa;
        } else {
            cres = sb;
        }
        return cres;
    }



/*

DP定义很关键
CommonError
DP[i][j] 为s.substr(i, j-i+1)的最长回文子串的长度 这是错误的


unodered_map作为cache行不通  TLE
Time Limit Exceeded
123/142 cases passed (N/A)
Testcase
"qbmhukucteihghldwdobtvgwwnhflpceiwhbkmvxavmqxedfndegztlpjptpdowwavemasyrjxxnhldnloyizyxgqlhejsdylvkpdzllrzoywfkcamhljminikvwwvqlerdilrdgzifojjlgeayprejhaequyhcohoeonagsmfrqhfzllobwjhxdxzadwxiglvzwiqyzlnamqqsastxlojpcsleohgtcuzzrvwzqugyimaqtorkafyebrgmrfmczwiexdzcokbqymnzigifbqzvfzjcjuugdmvegnvkgbmdowpacyspszvgdapklrhlhcmwkwwqatfswmxyfnxkepdotnvwndjrcclvewomyniaefhhcqkefkyovqxyswqpnysafnydbiuanqphfhfbfovxuezlovokrsocdqrqfzbqhntjafzfjisexcdlnjbhwrvnyabjbshqsxnaxhvtmqlfgdumtpeqzyuvmbkvmmdtywquydontkugdayjqewcgtyajofmbpdmykqobcxgqivmpzmhhcqiyleqitojrrsknhwepoxawpsxcbtsvagybnghqnlpcxlnshihcjdjxxjjwyplnemojhodksckmqdvnzewhzzuswzctnlyvyttuhlreynuternbqonlsfuchxtsyhqlvifcxerzqepthwqrsftaquzuxwcmjjulvjrkatlfqshpyjsbaqwawgpabkkjrtchqmriykbdsxwnkpaktrvmxjtfhwpzmieuqevlodtroiulzgbocrtiuvpywtcxvajkpfmaqckgrcmofkxynjxgvxqvkmhdbvumdaprijkjxxvpqnxakiavuwnifvyfolwlekptxbnctjijppickuqhguvtoqfgepcufbiysfljgmfepwyaxusvnsratn"
Expected Answer
"vwwv"

*/
    unordered_map<int, pair<int, int>> cache2;
    pair<int, int> longPalindromeV3(string& s, int left, int right) {
        if (left > right) {
            return make_pair(-1, -1);
        }
        int key = left * 10000 + right;
        if (cache2.count(key)) {
            return cache2[key];
        }
        int i = left;
        int j = right;
        while ((i < j) && (s[i] == s[j])) {
            i++;
            j--;
        }
        if (i >= j) {
            //string res = s.substr(left, right - left + 1);
            auto res = make_pair(left, right - left + 1);
            cache2[key] = res;
            return res;
            //return s.substr(left, right - left + 1);
        }
        // s[i] != s[j]
        auto sa = longPalindromeV3(s, left + 1, right);
        auto sb = longPalindromeV3(s, left, right - 1);
        if (sa.second > sb.second) {
            cache2[key] = sa;
            return sa;
        }
        cache2[key] = sb;
        return sb;
    }



    int maxLen = 0;
    string maxAns = "";
    void longPa(string& s, int left, int right) {
        if (left > right) {
            return;
        }
        int key = left * 10000 + right;
        int i = left;
        int j = right;
        while ((i < j) && (s[i] == s[j])) {
            i++;
            j--;
        }
        if (i >= j) {
            int plen = right - left + 1;
            if (plen > maxLen) {
                maxLen = plen;
                maxAns = s.substr(left, plen);
            }
            return;
        }
        // s[i] != s[j]
        longPa(s, left + 1, right);
        longPa(s, left, right - 1);
    }

    string longestPalindromeM3(string s) {
         int len = s.size();
         for (int i = 0; i < len; i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
         }
         return s.substr(start, maxLen1);
    }


    int maxLen1 = 0;
    int start = 0;
    void expand(string& s, int i , int j) {
        int len = s.size();
        while ((i >= 0 && j < len) && (s[i] == s[j])) {
            i--;
            j++;
        }
        // i == -1 || j == len
        //i [i+1, j-1] j
        int curlen = j - i - 1;
        if (curlen > maxLen1) {
            maxLen1 = curlen;
            start = i + 1;
        }
    }

    //中心扩展法
    string longestPalindromeM4(string s) {
         int len = s.size();
         int begin = 0;
         int slen = 0;
         for (int i = 0; i < len; i++) {
            auto r1 = expandV2(s, i, i);
            auto r2 = expandV2(s, i, i + 1);
            if (r1.second > slen)  {
                begin = r1.first;
                slen = r1.second;
            }
            if (r2.second > slen)  {
                begin = r2.first;
                slen = r2.second;
            }
         }
         return s.substr(begin, slen);
    }


    pair<int, int> expandV2(string& s, int i , int j) {
        int len = s.size();
        while ((i >= 0 && j < len) && (s[i] == s[j])) {
            i--;
            j++;
        }
        // i == -1 || j == len
        //i [i+1, j-1] j
        //int curlen = j - i - 1;
        return make_pair(i + 1, j - i - 1);
    }



    string longestPalindromeM5(string s) {
        int n = s.size();
        //dp[i][j]=1 means s.substr(i, j-i+1) is a palindrome
        vector<vector<int> > dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        int maxLen = 1;
        int maxIdx = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                    continue;
                }
                // s[i] == s[j]
                if (i + 1 >= j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] == 1) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        maxIdx = i;
                    }
                }
            }
        }
        return s.substr(maxIdx, maxLen);
    }


    string longestPalindrome(string s) {
        int n = s.size();
        //dp[i][j]=1 means s.substr(i, j-i+1) is a palindrome
        vector<vector<int> > dp(n, vector<int>(n, -1));
        int maxLen = 1;
        int maxIdx = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                    continue;
                }
                // s[i] == s[j]
                if (i + 1 >= j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] == 1) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        maxIdx = i;
                    }
                }
            }
        }
        return s.substr(maxIdx, maxLen);
    }
};
// @lc code=end

/*
 * 输入：s = "babad"

 babad

 b!=d
 delete b or d
 answer = max(abad   baba)

 abad
 a!=d
 delete a or delete d
 answer=max(bad aba) = aba

 baba
 b!=a
 answer=max(aba, bab)

不加cache
Time Limit Exceeded
44/142 cases passed (N/A)
Testcase
"babaddtattarrattatddetartrateedredividerb"
Expected Answer
"ddtattarrattatdd"



加了cache
Time Limit Exceeded
107/142 cases passed (N/A)
Testcase
"cmmrracelnclsbtdmuxtfiyahrvxuwreyorosyqapfpnsntommsujibzwhgugwtvxsdsltiiyymiofbslwbwevmjrsbbssicnxptvwmsmiifypoujftxylpyvirfueagprfyyydxeiftathaygmolkcwoaavmdmjsuwoibtuqoewaexihispsshwnsurjopdwttlzyqdbkypvjsbuidsdnpgklhwfnqdvlffcysnxeywvwvblatmxbflnuykhfhjptenhcxqinomlwalvlezefqybpuepbnymzlruuirpiatqgjgcnfmrlzshauoxuoqopcikogfwpssjdeplytcapmujyvgtfmmolnuadpwblgmcaututcrwsqrlpaaqobjfnhudmsulztbdkxpfejavastxejtpbqfftdtcdhvtpbzfuqcwkxtldtjycreimiujtxudtmokcoebhodbkgkgxjzrgyuqhozqtidltodlkziyofdeszwiobkwesdijxbbagguxvofvtphqxgvidqfkljufgubjmjllxoanbizwtedykwmneaosopynzlzvrlqcmyaahdcagfatlhwtgqxsyxwjhexfiplwtrtydjzrsysrcwszlntwrpgfedhgjzhztffqnjotlfudvczwfkhuwmdzcqgrmfttwaxocohtuscdxwfvhcymjpkqexusdaccw"
Expected Answer
"rsysr"


Wrong Answer
67/142 cases passed (N/A)
Testcase
"cbbd"
Answer
""
Expected Answer
"bb"
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


