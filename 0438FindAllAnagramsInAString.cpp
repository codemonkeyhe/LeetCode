/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-23
 * @tag hashmap,slidingWindow
 * @similar 30, 242, 438, 567
 * @trick diffArray
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.54%)
 * Likes:    1423
 * Dislikes: 0
 * Total Accepted:    419K
 * Total Submissions: 783.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:

    //  暴力法
    vector<int> findAnagramsM1(string s, string p) {
        int lenp = p.size();
        vector<int> res;
        int limit =  (s.size()-lenp);
        for (int i = 0; i <= limit; i++) {
            auto ss = s.substr(i, lenp);
            if (isMatch(ss, p)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isMatch(string s, string p) {
        int arr[27] = {0};
        for (int i = 0; i < p.size(); i++) {
            int c = p[i]  - 'a';
            arr[c] +=1;
        }
        for (int i = 0; i < s.size(); i++) {
            int c = s[i]  - 'a';
            arr[c] -=1;
        }
        for (int i = 0; i <= 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }



    // 滑动窗口
    // 用arr[26]较为繁琐，还是vector<int> arr(26) 更加方便，可以省略 isArrMatch函数
    vector<int> findAnagramsM2(string s, string p) {
        int lenp = p.size();
        vector<int> res;
        if (s.size() < lenp) {
            return res;
        }

        int arrp[26] = {0};
        for (int i = 0; i < p.size(); i++) {
            int c = p[i]  - 'a';
            arrp[c] +=1;
        }

        int arrs[26] = {0};
        for (int i = 0; i < lenp; i++) {
            int c = s[i]  - 'a';
            arrs[c] +=1;
        }

        // ERROR ： 比较的是数组地址 ，而不是内容 ，可以用 std::equal
        // if (arrs == arrp) {
        if (isArrMatch(arrp, arrs)) {
            res.push_back(0);
        }

        int limit = s.size() - lenp;
        for (int i = 1; i <= limit; i++) {
            int c = s[i-1] - 'a';
            arrs[c] -=1;
            int nc = s[i-1+lenp] - 'a';
            arrs[nc] +=1;
            if (isArrMatch(arrs, arrp))  {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isArrMatch(int arrs[],  int arrp[]) {
        for (int i = 0; i <26; i++) {
            if (arrp[i] !=  arrs[i]) {
                return false;
            }
        }
        return true;
    }



    vector<int> findAnagrams(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<int> res;
        if (lens < lenp) {
            return res;
        }
        vector<int> diff(26, 0);
        for (auto& ch: p) {
            diff[ch-'a']++;
        }

        for (int i = 0; i < lenp; i++) {
            diff[s[i]-'a']--;
        }

        int chDiff = 0;
        for (int i = 0; i < 26; i++) {
            if (diff[i] != 0) {
                chDiff++;
            }
        }

        if (chDiff == 0) {
            res.push_back(0);
        }

        // begin slide window
        for (int i = 0; i < lens - lenp; i++ ) {
            // s[i] out of window, and s[i+lenp] into window
            int left = s[i]-'a';
            int oldl = diff[left];
            // 因为Diff=P-S ，当S中少了1个字符时，相当于P比S多了1个这样的字符
            // 注意DIFF的方向性
            diff[left]++;
            if (oldl == 0) { // 0 -> -1
                chDiff++;
            } else if (diff[left] == 0) { // 1 -> 0
                chDiff--;
            }

            int right = s[i+lenp] - 'a';
            int oldr = diff[right];
            diff[right]--;
            if (oldr == 0) { // 0 -> 1
                chDiff++;
            } else if (diff[right] == 0) { // -1 -> 0
                chDiff--;
            }
            if (chDiff == 0) {
                res.push_back(i+1);
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



/*

Wrong Answer
56/65 cases passed (N/A)
Testcase
"abaacbabc"
"abc"
Answer
[]
Expected Answer
[3,4,6]


思路：
用hashmap1记录p的字符计数，用hashmap2记录s的同等大小的子串的字符计数，
如果 hashmap1 == hashmap2，则该子串则是一个 字母异位词


核心点：
两个hashmap的比较相当于isArrMatch函数，需要O(N)， 如何优化 hashmap1 == hashmap2?

引入DIFF的概念，相当于 git diff

vector<int> diff(26, 0);

diff[ch] = strP.cnt[ch] - strS.windowSubstr.cnt[ch]
令diff[ch]  = N , 有3种情况：
Case1: N>0 ，说明 字符串p比s的窗口子串多N个ch
Case2: N=0 ，说明 字符串p和s的窗口子串拥有相当数量的ch
Case3: N<0 ，说明 字符串p和s的窗口子串少abs(N)个ch

这样用一个diff数组来代替两个hashmap

当 字符串p和s的窗口子串互为 字母异位词时，
此时 vector<int> diff(26, 0);的所有 字符的diff都应该为0，即 diff[0 .. 25] = 0
依然要遍历diff数组，依然是O(26)
因此，需要对diff进一步优化， 引入  chDiff 来表明不同字符的差异

chDiff == diff[0..25]里面值不为0的数量

例如
diff = { "a": 1, "b": -1}  chDiff=2，
diff = { "a": 100, "b": -30, "c":0 }  chDiff=2，
表示p和s有2个字符的差异，不管差异字符的具体差多少个数

当 字符串p和s的窗口子串互为 字母异位词时，必有 chDiff=0， 对应 diff[0 .. 25] = 0
相当于省略了 O(26)的diff数组检查

需要动态维护chDiff，每次修改diff时，都要维护chDiff，一旦chDiff==0，表示找到一种答案

因为chDiff和差异字符的数量无关系，只需要关注差异字符的增多和增少。因此，需要关注diff[ch]在-1，0，1之间的变化
diff[ch] from -1 to 0
表示 之前 p比s的窗口子串少了1个ch，现在 p和s有相同数量的ch，因此，chDiff=chDiff-1;
diff[ch] from 0 to -1
表示 之前 p和s有相同数量的ch    现在  p比s的窗口子串少了1个ch，因此，chDiff=chDiff+1;

diff[ch] from 1 to 0
表示 之前 p比s的窗口子串多了1个ch，现在 p和s有相同数量的ch，因此，chDiff=chDiff-1;
diff[ch] from 0 to 1
表示 之前 p和s有相同数量的ch    现在  p比s的窗口子串多了1个ch，因此，chDiff=chDiff+1;

总结
diff[ch] from {-1, 1} to 0
    chDiff=chDiff-1;
diff[ch] from 0  to {-1. 1}
    chDiff=chDiff+1;




*/