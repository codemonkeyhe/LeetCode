/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-27
 * @tag
 * @similar  9
 */

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 8 ms, faster than 99.31% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.2 MB, less than 91.17% of C++ online submissions for Valid Palindrome.
*/
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        // 小写统一变大写
        // A-65 a-97
        int valI = 0;
        int valJ = 0;
        while(i<j){
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {

            } else if (s[i] >= '0' && s[i] <= '9') {

            } else {
                i++;
                continue;
            }
            if (s[j] >= 'a' && s[j] <= 'z') {
                s[j] -= 32;
            } else if (s[j] >= 'A' && s[j] <= 'Z') {
            } else if (s[j] >= '0' && s[j] <= '9') {
            } else {
                j--;
                continue;
            }
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

};

bool isPalindrome(char * s){

}

int main() {
    Solution s;
}


/*
alphanumeric  既有字母又有数字  不是单纯的大小写字母  坑了

Tips
M1 首尾比较，用isalnum函数...
https://leetcode-cn.com/problems/valid-palindrome/solution/yan-zheng-hui-wen-chuan-by-leetcode-solution/
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }



M2 过滤非法字符，全部转为小写，放到另外一个字符
再reverse后比较两个字符串是否相等....

*/


