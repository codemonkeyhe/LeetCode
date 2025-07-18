/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-17
 * @tag hashmap,slidingWindow
 * @similar 30, 242, 438
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (39.03%)
 * Likes:    1101
 * Dislikes: 0
 * Total Accepted:    201.5K
 * Total Submissions: 516.7K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
 * s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
 *
 *
 * 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"，
 * "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
 * 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 * 输入：s = "barfoothefoobarman", words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
 * 子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
 * 子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
 * 输出顺序无关紧要。返回 [9,0] 也是可以的。
 *
 *
 * 示例 2：
 * 输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * 输出：[]
 * 解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
 * s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
 * 所以我们返回一个空数组。
 *
 *
 * 示例 3：
 * 输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * 输出：[6,9,12]
 * 解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
 * 子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
 * 子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
 * 子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] 和 s 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Your runtime beats 5.01 % of cpp submissions
    // M1V1
    vector<int> findSubstringM1v1(string s, vector<string>& words) {
        vector<int> res;
        int wc = words.size();
        int sl = words[0].size();
        int len = wc * sl;
        int slen = s.size();
        if (slen < len) {
            return res;
        }
        unordered_map<string, int > w2idx;
        for (int i = 0; i < wc; i++) {
            w2idx[words[i]]++;
        }
        for (int i = 0; i <= slen-len; i++) {
            bool diff = false;
            unordered_map<string, int > hm;
            for (int j = i; j < i+len; j += sl) {
                string cur = s.substr(j, sl);
                if (w2idx.count(cur) == 0) {
                    diff = true;
                    break;
                }
                hm[cur]++;
                /*
                // 加了下面的比较 反而TLE
                if (hm[cur] > w2idx[cur]) {
                    diff = true;
                    break;
                }
                */
            }
            if (diff == false && (hm == w2idx)) {
                res.push_back(i);
            }
        }
        return res;
    }


    // M1V2
    // Your runtime beats 5.01 % of cpp submissions
    vector<int> findSubstringM1v2(string s, vector<string> &words) {
        vector<int> res;
        int wc = words.size();
        int sl = words[0].size();
        int len = wc * sl;
        int slen = s.size();
        if (slen < len) {
            return res;
        }
        unordered_map<string, int > w2idx;
        for (int i = 0; i < wc; i++) {
            w2idx[words[i]]++;
        }

        unordered_map<int, string> idx;
        for (int i = 0; i <= slen-sl; i++) {
            string cur = s.substr(i, sl);
            if (w2idx.count(cur) == 0) {
                continue;
            }
            idx[i] = cur;
        }

        for (int i = 0; i <= slen-len; i++) {
            bool diff = false;
            unordered_map<string, int > hm;
            for (int j = i; j < i+len; j += sl) {
                if (idx.count(j) == 0) {
                    diff = true;
                    break;
                }
                hm[idx[j]]++;
            }
            if (diff == false && (hm == w2idx)) {
                res.push_back(i);
            }
        }
        return res;
    }

    // M2 slidingWindow  需要比较两个hashmap
    vector<int> findSubstringM2V1(string s, vector<string>& words) {
        vector<int> res;
        int wc = words.size();
        int sl = words[0].size();
        int len = wc * sl;
        int slen = s.size();
        if (slen < len) {
            return res;
        }
        unordered_map<string, int > w2idx;
        for (int i = 0; i < wc; i++) {
            w2idx[words[i]]++;
        }
        for (int i = 0; i < sl; i++) {
            unordered_map<string, int > hm;
            //1 init window
            int cnt = 0;
            for (int j = i; j <= slen-sl; j += sl) {
                string cur = s.substr(j, sl);
                hm[cur]++;
                cnt++;
                if (cnt >= wc) {
                    break;
                }
            }
            // cnt == wc
            if (hm == w2idx) {
                res.push_back(i);
            }
            // 2 begin slide
            for (int j = i; j <= slen-len; j += sl) {
                string left = s.substr(j, sl);
                string right = s.substr(j + len, sl);
                hm[left]--;
                hm[right]++;

                if (hm[left]==0) {
                    hm.erase(left);
                }
                if (hm[right]==0) {
                    hm.erase(right);
                }
                //cout << "i=" << i << " j=" << j << "left=" << left << " right=" << right << endl;
                if (hm == w2idx) { //hashmap有干扰项，需要删除次数为0的结点
                    res.push_back(j+sl);
                }
            }
        }
        return res;
    }


    // 官解  基于DIFF  不需要比较hashmap，需要删除空元素
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wc = words.size();
        int sl = words[0].size();
        int len = wc * sl;
        int slen = s.size();
        if (slen < len) {
            return res;
        }
        unordered_map<string, int > w2idx;
        for (int i = 0; i < wc; i++) {
            w2idx[words[i]]--;
        }
        for (int i = 0; i < sl; i++) {
            unordered_map<string, int > diff(w2idx);
            //1 init window
            for (int c = 0; c < wc; c++) {
                string cur = s.substr(i + c * sl, sl);
                diff[cur]++;
                if (diff[cur] == 0) {
                    diff.erase(cur);
                }
            }
            // cnt == wc
            if (diff.empty()) {
                res.push_back(i);
            }
            // 2 begin slide
            for (int j = i; j <= slen-len; j += sl) {
                string left = s.substr(j, sl);
                string right = s.substr(j + len, sl);
                diff[left]--;
                diff[right]++;
                if (diff[left]==0) {
                    diff.erase(left);
                }
                if (diff[right]==0) {
                    diff.erase(right);
                }

               //cout << "i=" << i << " j=" << j << "left=" << left << " right=" << right << endl;
                if (diff.empty()) {
                    res.push_back(j+sl);
                }
            }
        }
        return res;
    }


    // M4 不需要比较hashmap，也不需要删除hashmap为0的元素
    // 仿 LC438 写法
    vector<int> findSubstringM4(string s, vector<string> &words) {
        vector<int> res;
        int wc = words.size();
        int sl = words[0].size();
        int len = wc * sl;
        int slen = s.size();
        if (slen < len) {
            return res;
        }

        unordered_map<string, int > w2idx;
        for (int i = 0; i < wc; i++) {
            w2idx[words[i]]--;
        }
        for (int i = 0; i < sl; i++) {
            unordered_map<string, int > diff(w2idx);
            //1 init window
            for (int c = 0; c < wc; c++) {
                string cur = s.substr(i + c * sl, sl);
                diff[cur]++;
            }
            // cnt == wc
            int wordDiff = 0;
            for (auto& [w, c]: diff) {
                if (c != 0) {
                    wordDiff++;
                }
            }
            if (wordDiff == 0) {
                res.push_back(i);
            }

            // 2 begin slide
            for (int j = i; j <= slen-len; j += sl) {
                string left = s.substr(j, sl);
                string right = s.substr(j + len, sl);
                if (diff[left] == 0) {
                    wordDiff++;
                } else if (diff[left] == 1) {
                    wordDiff--;
                }
                diff[left]--;

                if (diff[right] == 0) {
                    wordDiff++;
                } else if (diff[right] == -1) {
                    wordDiff--;
                }
                diff[right]++;

               //cout << "i=" << i << " j=" << j << "left=" << left << " right=" << right << endl;
                if (wordDiff == 0) {
                    res.push_back(j+sl);
                }
            }
        }
        return res;
    }
};
// @lc code=end


/*
Wrong Answer
98/182 cases passed (N/A)
Testcase
"barfoofoobarthefoobarman"
["bar","foo","the"]
Answer
[9,12,15]
Expected Answer
[6,9,12]

Wrong Answer
116/182 cases passed (N/A)
Testcase
"wordgoodgoodgoodbestword"
["word","good","best","good"]
Answer
[]
Expected Answer
[8]

Wrong Answer
146/182 cases passed (N/A)
Testcase
"aaaaaaaaaaaaaa"
["aa","aa"]
Answer
[0,2,4,6,8,10,0,3,5,7,9]
Expected Answer
[0,1,2,3,4,5,6,7,8,9,10]



M5 2个hashmap
使用一个 overload当作DIFF变量 难以理解
https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solutions/3691292/30-ci-ding-chang-hua-dong-chuang-kou-pyt-5vgx/?envType=problem-list-v2&envId=sliding-window


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


