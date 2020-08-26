/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-26
 * @tag
 */

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:
Input: "Hello World"
Output: 5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 4 ms, faster than 91.90% of C++ online submissions for Length of Last Word.
Memory Usage: 6.6 MB, less than 40.72% of C++ online submissions for Length of Last Word.
*/
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        int j = s.size() - 1;
        //filter right space
        while (j >= 0 && s[j] == ' ') {
            j--;
        }
        if (j < 0) { // all space
            return 0;
        }
        int end = j;
        j--;
        while (j >= 0 && s[j] != ' ') {
            j--;
        }
        return end - j;
    }

};

int lengthOfLastWord(char* s) {


}

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


