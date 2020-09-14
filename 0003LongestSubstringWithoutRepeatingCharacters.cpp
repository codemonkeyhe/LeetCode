/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-13
 * @tag
 * @similar
 */

/*
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
/*
Runtime: 40 ms, faster than 56.19% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 10.9 MB, less than 31.15% of C++ online submissions for Longest Substring Without Repeating Characters.
不用每次right++时都要更新maxLen
*/
    int lengthOfLongestSubstringFool(string s) {
        unordered_set<char> hs;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (left < n && right < n) {
            if (!hs.count(s[right])) {
                hs.insert(s[right]);
                right++;
                int len = right - left;
                if (len > maxLen) {
                    maxLen = len;
                }
            } else { //right指向的字符其中一个字符重复
                hs.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }

    // 当right指向的字符其中一个字符重复时，窗口左界右移1位
    /*
    ErrorCase " "
    Expect 1
Runtime: 52 ms, faster than 43.90% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 10.8 MB, less than 32.35% of C++ online submissions for Longest Substring Without Repeating Characters.
    M1
    */
    int lengthOfLongestSubstringM1(string s) {
        unordered_set<char> hs;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (left < n) {
            while (right < n && !hs.count(s[right])) {
                hs.insert(s[right]);
                right++;
            }
            //遇到重复字符  或者 right==n
            int len = right - left;
            if (len > maxLen) {
                maxLen = len;
            }
            hs.erase(s[left]);
            left++;
        }
        return maxLen;
    }



    /*
    M2
    用迭代器非常麻烦
Runtime: 28 ms, faster than 73.05% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.6 MB, less than 53.06% of C++ online submissions for Longest Substring Without Repeating Characters.
    */
    int lengthOfLongestSubstringM2(string s) {
        unordered_map<int, int> hm;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (left < n && right < n) {
            int lastSamePos = 0;
            while (right < n) {
                auto  it = hm.find(s[right]);
                if (it == hm.end() ) {
                    hm.insert(make_pair(s[right], right));
                    right++;
                    continue;
                }
                //存在重复字符
                if (it->second >= left) {  //在left开始范围内重复
                    lastSamePos = it->second;
                    //修改重复字符的位置为最新的位置
                    it->second = right;
                    break;
                } else {  //虽然重复，但是不在left开始范围，是之前历史重复字符，相当于重新覆盖插入
                    it->second = right;
                    right++;
                    continue;
                }
            }
            //right == n(lastSamePos==0)  or find same s[right] (lastSamePos==it->second)
            int len = right - left;
            if (len > maxLen)
                maxLen = len;
            left = lastSamePos + 1;
            right++;
        }
        return maxLen;
    }

/*
Runtime: 36 ms, faster than 60.31% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.7 MB, less than 44.60% of C++ online submissions for Longest Substring Without Repeating Characters.
还是比较啰嗦，需要干掉lastSamePos
*/
    int lengthOfLongestSubstringM21(string s) {
        unordered_map<int, int> hm;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (left < n && right < n) {
            int lastSamePos = 0;
            while (right < n) {
                auto it = hm.find(s[right]);
                if (it != hm.end() && (it->second >= left)) {
                    lastSamePos = it->second;
                    it->second = right;
                    break;
                }
                hm[s[right]] = right;
                right++;
           }
            //right == n(lastSamePos==0)  or find same s[right] (lastSamePos==it->second)
           maxLen = max(maxLen, right - left);
           left = lastSamePos + 1;
           right++;
        }
        return maxLen;
    }

/*
Runtime: 36 ms, faster than 60.31% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.5 MB, less than 58.04% of C++ online submissions for Longest Substring Without Repeating Characters.
1. 砍掉了啰嗦的迭代器
2. 没有刻意区分一定要在right++时才更新maxLen,这样其实降低了实现难度
*/
    int lengthOfLongestSubstringM22(string s) {
        unordered_map<int, int> hm;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (left < n && right < n) {
            auto it = hm.find(s[right]);
            if (it != hm.end() && (it->second >= left)) {
                left = it->second + 1;
                it->second = right;
                right++;
            } else {  //找不到该字符 或者 该字符的pos < left
                hm[s[right]] = right;
                right++;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }



/*
Runtime: 28 ms, faster than 73.05% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.5 MB, less than 58.76% of C++ online submissions for Longest Substring Without Repeating Characters.
M22 再优化，
参照
https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1729/11-line-simple-Java-solution-O(n)-with-explanation
*/

   int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> hm;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (right < n) {
            auto it = hm.find(s[right]);
            if (it != hm.end() && (it->second >= left)) {
                left = it->second + 1;
            }
            hm[s[right]] = right;
            right++;
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }


    /*
Runtime: 4 ms, faster than 99.93% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 7.5 MB, less than 81.62% of C++ online submissions for Longest Substring Without Repeating Characters.
    M3
    相比M23 基本一毛一样  只是把hashmap换成vector而已
    */
    int lengthOfLongestSubstring(string s) {
        vector<int> hm(128,-1);
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxLen = 0;
        while (right < n) {
            auto it = hm[s[right]];
            if (it != -1 && (it >= left)) {
                left = it + 1;
            }
            hm[s[right]] = right;
            right++;
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }


};

int lengthOfLongestSubstring(char * s){

}


int main() {
    Solution s;
    // string str = "abcabcbb";
    // string str = "tmmzuxt";
    string str = "aabaab!bb";
    auto res = s.lengthOfLongestSubstring(str);
    cout << res << endl;
}


/*
Tips
M1 滑动窗口+ hashset去重
每次向右遇到不重复的字符，加入hashset。如果字符存在于hashset，说明是重复字符，则记录长度.
然后左界向右移动一个字符，从hashset删除这个字符。
abcabcbb
L  R
当R->a与hashset重复时，记录长度为3。此时不需要立刻把L指向重复的字符a，因为后面L会经过a的。
L右移动1位指向b，在重新开始移动窗口右界R。
L代表和以s[L]打头的最长无重复子串

M2 滑动窗口+ hashmap去重


M3 使用128或者256的数组 以及 vector<int> 去重
因为 ascii码的字符一般是 8bit，256种足够覆盖

总结
1. 用hashmap好过hashset，大部分滑动窗口都是用hashmap
2. 小心左右越界，举一些右窗口直接扩张到终点的例子
3. 更新maxLen时，不要在乎性能，这样不容易出错
4. 1层循环优于2层循环，方便理解

*/


