/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-25
 * @tag
 */

/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Constraints:
haystack and needle consist only of lowercase English characters.

惯用语
looking for a needle in a haystack  大海捞针
hay 干草
haystack 干草垛
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 16 ms, faster than 12.21% of C++ online submissions for Implement strStr().
Memory Usage: 6.9 MB, less than 58.91% of C++ online submissions for Implement strStr().
*/
    int strStrM1Fool(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        if (nlen == 0) {
            return 0;
        }
        if (hlen < nlen) {
            return -1;
        }
        for (int i = 0; i <= hlen-nlen; ++i) {
        //BUG TLE for (int i = 0; i < hlen; ++i) {
            if (haystack[i] == needle[0]) {
                int n = i + 1;
                int j = 1;
                while (j < nlen && n < hlen) {
                    if (haystack[n] != needle[j]) {
                        break;
                    }
                    n++;
                    j++;
                }
                if (j == nlen) {
                    return i;
                }
            }
        }
        return -1;
    }

/*
暴力法-普通实现
Runtime: 8 ms, faster than 67.62% of C++ online submissions for Implement strStr().
Memory Usage: 6.7 MB, less than 87.53% of C++ online submissions for Implement strStr().
*/
    int strStrM11(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        if (nlen == 0) {
            return 0;
        }
        if (hlen < nlen) {
            return -1;
        }
        for (int i = 0; i <= hlen - nlen; ++i) {
            int j = 0;
            for (j = 0; j < nlen; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == nlen) {
                return i;
            }
        }
        return -1;
    }

/*
暴力法-类KMP实现
Runtime: 4 ms, faster than 99.07% of C++ online submissions for Implement strStr().
Memory Usage: 7 MB, less than 44.65% of C++ online submissions for Implement strStr().
*/
    int strStrM1(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        int i = 0;
        int j = 0;
        while(i < hlen && j < nlen) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else { // i j回退
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == nlen) {
            return i - j;
        }
        return -1;
    }

/*
KMP

*/
/*
void GetNext(char* p,int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1) {
		if (k == -1 || p[j] == p[k]) {
			++k;
			++j;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}
*/

    void DFANext(const string& pat, int* next) {
        int pLen = pat.size();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < pLen - 1) {
            if (k == -1 || pat[j] == pat[k]) {
                ++j;
                ++k;
                if (pat[j] != pat[k])
                    next[j] = k;
                else
                    next[j] = next[k];
            } else {
                k = next[k];
            }
        }
    }


/*
Runtime: 4 ms, faster than 99.07% of C++ online submissions for Implement strStr().
Memory Usage: 7.1 MB, less than 25.45% of C++ online submissions for Implement strStr().
*/
    int strStrM2(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        int i = 0;
        int j = 0;
        int* next = new int[nlen];
        DFANext(needle, next);
        while (i < hlen && j < nlen) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        delete[] next;
        if (j == nlen) {
            return i - j;
        }
        return -1;
    }

};

int strStr(char* haystack, char* needle) {}

int main() {
    Solution s;
}


/*
Tips

M1 暴力法
Time Limit Exceeded
O((M-N)*N)
M为haystack长度 N为needle长度
写复杂了
https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP


M2 KMP
https://blog.csdn.net/v_JULY_v/article/details/7041827

M3 BM(Boyer-Moore)
http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html

M4 RK(Rabin-Karp)
[TODO]

M5 Sunday
https://leetcode-cn.com/problems/implement-strstr/solution/python3-sundayjie-fa-9996-by-tes/



*/


