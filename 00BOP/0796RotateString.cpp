/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-04-01
 */

/*
We are given two strings, A and B.
A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false

Note:
A and B will have length at most 100.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
       if (A.size() != B.size()) {
            return false;
        }
        string str=A+A;
        if (str.find(B) != string::npos) {
            return true;
        }
        return false;
    }

    bool rotateString2(string A, string B) {
        int len = A.size();
        if (len != B.size()) {
            return false;
        }
        if (len == 0) {
            return true;
        }
        string rotate = "";
        for (int i = 0; i < len; ++i) {
            rotate = A.substr(len - i, i) + A.substr(0, len - i);
            if (rotate == B) {
                return true;
            }
        }
        return false;
    }
};

bool rotateString(char* A, char* B) {}

int main() {
    string sa("abcde");
    string sb("cdeab");

    Solution s;
    cout << s.rotateString(sa, sb) << endl;
    return 0;
}

/*
Tips
M1 (A+A).find(B)
 return A.size() == B.size() && (A + A).find(B) != string::npos;

M2 暴力法

M3 KMP 留给 0028

*/