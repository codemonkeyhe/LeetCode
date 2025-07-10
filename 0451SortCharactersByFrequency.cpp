/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-10
 * @tag hashMap,bucketSort
 * @similar 1636
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 *
 * https://leetcode.cn/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (72.14%)
 * Likes:    513
 * Dislikes: 0
 * Total Accepted:    137.9K
 * Total Submissions: 191.2K
 * Testcase Example:  '"tree"'
 *
 * 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
 *
 * 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
 *
 *
 *
 * 示例 1:
 * 输入: s = "tree"
 * 输出: "eert"
 * 解释: 'e'出现两次，'r'和't'都只出现一次。
 * 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
 *
 *
 * 示例 2:
 * 输入: s = "cccaaa"
 * 输出: "cccaaa"
 * 解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
 * 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
 *
 *
 * 示例 3:
 * 输入: s = "Aabb"
 * 输出: "bbAa"
 * 解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
 * 注意'A'和'a'被认为是两种不同的字符。
 *
 *
 *
 *
 * 提示:
 * 1 <= s.length <= 5 * 10^5
 * s 由大小写英文字母和数字组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    string frequencySortM1(string s) {
        unordered_map<char, int> chcnt;
        for (auto& ch: s) {
            chcnt[ch]++;
        }
        map<int, string> cntss;
        for (auto& [ch, cnt]: chcnt) {
            int k = cnt;
            string tmp = "";
            while (k-- > 0) {
                tmp += ch;
            }
            cntss[cnt] += tmp;
        }
        string res = "";
        for (auto it = cntss.rbegin(); it != cntss.rend(); it++) {
            res += it->second;
        }
        return res;
    }

    string frequencySort(string s) {
        unordered_map<char, int> chcnt;
        int maxCnt = 0;
        for (auto& ch: s) {
            chcnt[ch]++;
            if (chcnt[ch] > maxCnt) {
                maxCnt = chcnt[ch];
            }
        }
        vector<string> bucket(maxCnt+1, "");
        for (auto& [ch, cnt]: chcnt) {
            int k = cnt;
            string tmp = "";
            while (k-- > 0) {
                tmp += ch;
            }
            bucket[cnt] += tmp;
        }
        string res = "";
        for (int i = maxCnt; i >=0; i--) {
            string& ss = bucket[i];
            if (ss != "") {
                res += ss;
            }
        }
        return res;
    }


};
// @lc code=end

/*
Wrong Answer
10/33 cases passed (N/A)
Testcase
"raaeaedere"
Answer
"daaaeeeerr"
Expected Answer
"eeeeaaarrd"
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


