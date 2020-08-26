/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-26
 * @tag
 */

/*
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.
Memory Usage: 6.3 MB, less than 91.53% of C++ online submissions for Add Binary.
*/
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        int i = a.size()-1;
        int j = b.size()-1;
        string res;
        int cur = 0;
        int add = 0;
        while (i >= 0 || j >= 0) {
            cur = add + (i >= 0 ? (a[i] - '0') : 0) + (j >= 0 ? (b[j] - '0') : 0);
            add = cur / 2;
            i--;
            j--;
            res += (char)(cur % 2 + '0');
        }
        // 容易遗漏下面这行
        if (add) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }

};

char* addBinary(char* a, char* b) {}

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


