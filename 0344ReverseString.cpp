/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag
 * @similar 541  345
 */

/*
Write a function that reverses a string. The input string is given as an array of characters char[].
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

Example 1:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 44 ms, faster than 91.64% of C++ online submissions for Reverse String.
Memory Usage: 23.5 MB, less than 20.75% of C++ online submissions for Reverse String.
*/
    void reverseString(vector<char>& s) {
        int j = s.size()-1;
        int i = 0;
        while(i<j) {
            swap(s[i++], s[j--]);
        }
    }

};

void reverseString(char* s, int sSize){

}


int main() {
    Solution s;
}


/*
Tips
M1 ???

M2 ??

*/

