/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag
 * @similar 344
 */

/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 16 ms, faster than 71.80% of C++ online submissions for Reverse String II.
Memory Usage: 7.2 MB, less than 96.50% of C++ online submissions for Reverse String II.
*/
    string reverseStr(string s, int k) {
        int n = s.size() - 1;
        int i = 0;
        int j = i + k;
        int left = 0;
        int right = 0;
        while (i <= n) {
            left = i;
            right = j - 1;
            if (right > n) {
                right = n;
            }
            while (left < right) {
                swap(s[left++], s[right--]);
            }
            i += 2 * k;
            j = i + k;
        }
        return s;
    }
};

char * reverseStr(char * s, int k){

}



int main() {
    Solution s;
}

/*
Tips
M1

M2

*/