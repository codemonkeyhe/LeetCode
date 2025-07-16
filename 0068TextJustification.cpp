/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-15
 * @tag  simulaton
 * @similar  1592
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode.cn/problems/text-justification/description/
 *
 * algorithms
 * Hard (53.89%)
 * Likes:    472
 * Dislikes: 0
 * Total Accepted:    107.8K
 * Total Submissions: 191.1K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth
 * 个字符。
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 *
 * 注意:
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 *
 *
 *
 *
 * 示例 1:
 * 输入: words = ["This", "is", "an", "example", "of", "text", "justification."],
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 *
 * 示例 2:
 * 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 *
 *
 * 示例 3:
 * 输入:words =
 * ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth
 * = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 *
 *
 *
 *
 * 提示:
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] 由小写英文字母和符号组成
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cnt = 0;
        int last = 0;
        int i = 0;
        for (; i < words.size(); i++) {
            string& w = words[i];
            if (cnt + w.size() > maxWidth) { // a new line
                // collect words[last..i-1] to new lien
                auto line = makeNewLine(words, last, i-1, maxWidth);
                res.push_back(line);
                last = i;
                cnt = 0;
            }
            cnt += w.size() +1;
        }
        // the last line
        // i == words.size()
        string lastline = "";
        for (int k = last; k < i; k++) {
            lastline += words[k] + " ";
        }
        lastline.resize(maxWidth, ' ');
        res.push_back(lastline);
        return res;
    }


    string makeNewLine(vector<string>& words, int begin, int end, int width) {
        string line = "";
        int wc = end - begin + 1;
        if (wc == 1) { //左对齐
            line += words[begin];
            line.resize(width, ' ');
           // line += makeSpace(width - words[begin].size());
            return line;
        }
        int spaceCnt = width;
        for (int i = begin; i <= end; i++) {
            spaceCnt -= words[i].size();
        }
        int avgSpace = spaceCnt/(wc-1);
        int extra = spaceCnt - avgSpace * (wc - 1);
        for (int i = begin; i < begin + extra; i++) {
            line += words[i] + makeSpace(avgSpace+1);
        }
        for (int i = begin+extra; i <= end; i++ ) {
            line += words[i] + makeSpace(avgSpace);
        }
        line.resize(width, ' ');
        /*  等价写法
        if (line.size() > width) { //砍掉多余的空格
            line.resize(width);
        } else {
            int needCnt = width - line.size();
            line += makeSpace(needCnt);
        }
        */
        return line;
    }

    //可以用resize函数来代替
    // return string(num, ' ');
    string makeSpace(int num) {
        string ss = "";
        while (num-- > 0) {
            ss += " ";
        }
        return ss;
    }
};
// @lc code=end

/*
Wrong Answer
10/29 cases passed (N/A)
Testcase
["This", "is", "an", "example", "of", "text", "justification."]
16
Answer
["This    is    an","example of text ","justification.  "]
Expected Answer
["This    is    an","example  of text","justification.  "]



Wrong Answer
17/29 cases passed (N/A)
Testcase
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
' +
  '20
Answer
["Science   is what we","understand      well","enough to explain to","a   computer. Art is","everything  else  we","do                  "]
Expected Answer
["Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  "]


5 Space spilt into  3 slots
Error 3 1 1
Science   is what we
Want 2 2 1
Science  is  what we

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


