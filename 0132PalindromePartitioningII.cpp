/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-16
 * @tag     backtracing,dynamicProgramming
 * @similar   131, 132
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode.cn/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (49.81%)
 * Likes:    840
 * Dislikes: 0
 * Total Accepted:    115K
 * Total Submissions: 225.3K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。
 *
 * 返回符合要求的 最少分割次数 。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：s = "aab"
 * 输出：1
 * 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 *
 *
 * 示例 2：
 * 输入：s = "a"
 * 输出：0
 *
 *
 * 示例 3：
 * 输入：s = "ab"
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 2000
 * s 仅由小写英文字母组成
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:

    int minCnt = 3000;

    vector<vector<int>> pa;
    vector<int> idxCnt;

    // M1 DFS BT
    int minCutM1(string s) {

        int len = s.size();
        idxCnt = vector<int>(len, 3000);

        buildPa(s);
        //TLE 24/37
        //vector<string> path;
        //bt2(s, 0, path);

        //   //TLE 24/37
        bt3(s, 0, 0);
        return minCnt-1;
    }


    void buildPa(string& s) {
        int len = s.size();
        pa = vector<vector<int>>(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <=i; j++) {
                pa[i][j] = 1;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (s[i] != s[j]) {
                    continue;
                }
                pa[i][j] = pa[i + 1][j - 1];
            }
        }
    }


    void bt2(string& s, int idx, vector<string>& path) {
        if (idx == s.size()) {
            if (path.size() < minCnt) {
                minCnt = path.size();
            }
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (!pa[idx][i]) {
                continue;
            }
            int ssLen = i - idx + 1;
            string ss = s.substr(idx, ssLen);
            path.push_back(ss);
            bt2(s, i+1, path);
            path.pop_back();
        }
        return;
    }


    void bt3(string& s, int idx, int curLen) {
        if (idx == s.size()) {
            if (curLen < minCnt) {
                minCnt = curLen;
            }
            return;
        }
        if (curLen > minCnt) { //剪枝效果不大
            return;
        }
        if (curLen < idxCnt[idx]) { //剪枝效果好
            idxCnt[idx] = curLen;
        } else {
            return;
        }
       // for (int i = idx; i < s.size(); i++) {
        for (int i = s.size() - 1; i >= idx; i--) {
            if (!pa[idx][i]) {
                continue;
            }
            bt3(s, i+1, curLen+1);
        }
        return;
    }

    int minCut(string s) {
        buildPa(s);

        int len = s.size();
        vector<int> dp(len, 5000);
        dp[0] = 0;

        for (int i = 0; i < len; i++) {
            if (pa[0][i]) { // coreStep
                dp[i] = 0;
                continue;
            }
            int minCnt = INT_MAX/2;
            for (int j = 0; j < i; j++) {
                if (pa[j+1][i]) { // means dp[i] = dp[j] +1
                    if (dp[j] < minCnt) {
                        minCnt = dp[j];
                    }
                }
            }
            dp[i] = minCnt + 1;
        }

        return dp[len-1];
    }
};
// @lc code=end

/*
DFSV1
Time Limit Exceeded
24/37 cases passed (N/A)
Testcase
"ababababababababababababcbabababababababababababa"
Expected Answer
0

加上减枝
Time Limit Exceeded
26/37 cases passed (N/A)
Testcase
"apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp"
Expected Answer
452


Time Limit Exceeded
27/37 cases passed (N/A)
Testcase
"adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece"
Expected Answer
273


把    if (curLen <= idxCnt[idx])  改成 if (curLen < idxCnt[idx])
Time Limit Exceeded
32/37 cases passed (N/A)
Testcase
"fiefhgdcdcgfeibggchibffahiededbbegegdfibdbfdadfbdbceaadeceeefiheibahgececggaehbdcgebaigfacifhdbecbebfhiefchaaheiichgdbheacfbhfiaffaecicbegdgeiaiccghggdfggbebdaefcagihbdhhigdgbghbahhhdagbdaefeccfiaifffcfehfcdiiieibadcedibbedgfegibefagfccahfcbegdfdhhdgfhgbchiaieehdgdabhidhfeecgfiibediiafacagigbhchcdhbaigdcedggehhgdhedaebchcafcdehcffdiagcafcgiidhdhedgaaegdchibhdaegdfdaiiidcihifbfidechicighbcbgibadbabieaafgeagfhebfaheaeeibagdfhadifafghbfihehgcgggffgbfccgafigieadfehieafaehaggeeaaaehggffccddchibegfhdfafhadgeieggiigacbfgcagigbhbhefcadafhafdiegahbhccidbeeagcgebehheebfaechceefdiafgeddhdfcadfdafbhiifigcbddahbabbeedidhaieagheihhgffbfbiacgdaifbedaegbhigghfeiahcdieghhdabdggfcgbafgibiifdeefcbegcfcdihaeacihgdchihdadifeifdgecbchgdgdcifedacfddhhbcagaicbebbiadgbddcbagbafeadhddaeebdgdebafabghcabdhdgieiahggddigefddccfccibifgbfcdccghgceigdfdbghdihechfabhbacifgbiiiihcgifhdbhfcaiefhccibebcahidachfabicbdabibiachahggffiibbgchbidfbbhfcicfafgcagaaadbacddfiigdiiffhbbehaaacidggfbhgeaghigihggfcdcidbfccahhgaffiibbhidhdacacdfebedbiacaidaachegffaiiegeabfdgdcgdacfcfhdcbfiaaifgfaciacfghagceaaebhhibbieehhcbiggabefbeigcbhbcidbfhfcgdddgdffghidbbbfbdhcgabaagddcebaechbbiegeiggbabdhgghciheabdibefdfghbfbfebidhicdhbeghebeddgfdfhefebiiebdchifbcbahaddhbfafbbcebiigadhgcfbebgbebhfddgdeehhgdegaeedfadegfeihcgeefbbagbbacbgggciehdhiggcgaaicceeaefgcehfhfdciaghcbbgdihbhecfbgffefhgiefgeiggcebgaacefidghdfdhiabgibchdicdehahbibeddegfciaeaffgbefbbeihbafbagagedgbdadfdggfeaebaidchgdbcifhahgfdcehbahhdggcdggceiabhhafghegfdiegbcadgaecdcdddfhicabdfhbdiiceiegiedecdifhbhhfhgdbhibbdgafhgdcheefdhifgddchadbdggiidhbhegbdfdidhhfbehibiaacdfbiagcbheabaaebfeaeafbgigiefeaeheabifgcfibiddadicheahgbfhbhddaheghddceedigddhchecaghdegigbegcbfgbggdgbbigegffhcfcbbebdchffhddbfhhfgegggibhafiebcfgeaeehgdgbccbfghagfdbdfcbcigbigaccecfehcffahiafgabfcaefbghccieehhhiighcfeabffggfchfdgcfhadgidabdceediefdccceidcfbfiiaidechhbhdccccaigeegcaicabbifigcghcefaafaefd"
Expected Answer
1345


把
for (int i = idx; i < s.size(); i++)
改成
for (int i = s.size() - 1; i >= idx; i--)
过了

Accepted
37/37 cases passed (123 ms)
Your runtime beats 13.79 % of cpp submissions
Your memory usage beats 17.73 % of cpp submissions (61.5 MB)

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
