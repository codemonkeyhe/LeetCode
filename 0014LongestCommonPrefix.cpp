/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-25
 * @tag
 */

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 8 ms, faster than 74.37% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.5 MB, less than 23.61% of C++ online submissions for Longest Common Prefix
*/
    string longestCommonPrefixM1(vector<string>& strs) {
        string res("");
        if (strs.size() == 0)
            return res;
        res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            string& cur = strs[i];
            while (j < cur.length() && j < res.length()) {
                if (cur[j] != res[j]) {
                    break;
                }
                j++;
            }
            res = cur.substr(0, j);
        }
        return res;
    }

/*
Runtime: 8 ms, faster than 74.37% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.2 MB, less than 80.63% of C++ online submissions for Longest Common Prefix.
*/
    string longestCommonPrefix(vector<string>& strs) {
        string res("");
        if (strs.size() == 0)
            return res;
        int minLen = INT_MAX;
        for (int i =0; i < strs.size(); ++i) {
            if (strs[i].length() < minLen) {
                minLen = strs[i].length();
            }
        }
        for (int j = 0; j < minLen; j++) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][j] != strs[i - 1][j]) {
                    return res;
                }
            }
            res += strs[0][j];
        }
        return res;
    }

};


char * longestCommonPrefix(char ** strs, int strsSize){

}

int main() {

    Solution s;
}


/*
Tips
M1 暴力法
两两比较
O(N*M)
M为每个string的平均宽度

M2 垂直遍历
flower
flow
flight
先遍历得到f 再遍历得到l
O(N*Min)
Min是所有strs中长度最短的字符串的长度

M3 tired树
没必要

*/


