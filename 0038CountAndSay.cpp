/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-26
 * @tag
 */

/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"
Explanation: This is the base case.

Example 2:
Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 4 ms, faster than 88.07% of C++ online submissions for Count and Say.
Memory Usage: 6.2 MB, less than 97.33% of C++ online submissions for Count and Say.
*/
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string pre("1");
        string cur("");
        for (int i = 2; i <= n; ++i) {
            int num = 1;
            int j = 0;
            for (; j < pre.size() - 1; ++j) {
                if (pre[j] != pre[j+1]) {
                    cur += to_string(num) + pre[j];
                    num = 1;
                } else {
                    num++;
                }
            }
            cur += to_string(num) +  pre[j];
            pre = cur;
            cur = "";
        }
        return pre;
    }

};



char* countAndSay(int n){

}


int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
}


/*
Tips
M1

M2

*/


