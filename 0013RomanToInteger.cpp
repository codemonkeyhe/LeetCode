/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-25
 * @tag
 */

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 24 ms, faster than 52.49% of C++ online submissions for Roman to Integer.
Memory Usage: 6.1 MB, less than 73.66% of C++ online submissions for Roman to Integer.
*/
    int romanToInt(string s) {
        int data[91] = {};
        data['I'] = 1;
        data['V'] = 5;
        data['X'] = 10;
        data['L'] = 50;
        data['C'] = 100;
        data['D'] = 500;
        data['M'] = 1000;
        int len = s.size();
        int res = data[s[len-1]];;
        int cur = len - 2;
        while (cur >= 0) {
            if (data[s[cur]] < data[s[cur+1]]) {
                res -= data[s[cur]];
            } else {
                res += data[s[cur]];
            }
            cur--;
        }
        return res;
    }

/*
Runtime: 12 ms, faster than 80.69% of C++ online submissions for Roman to Integer.
Memory Usage: 6 MB, less than 86.81% of C++ online submissions for Roman to Integer.
*/
    int romanToIntM1(string s) {
        int data[91] = {};
        data['I'] = 1;
        data['V'] = 5;
        data['X'] = 10;
        data['L'] = 50;
        data['C'] = 100;
        data['D'] = 500;
        data['M'] = 1000;
        int len = s.size();
        int cur = len-1;
        int res = 0;
        bool minus = false;
        while (cur >= 0) {
            if (minus)
                res -= data[s[cur]];
            else
                res += data[s[cur]];
            minus = false;
            if (cur == 0) {
                break;
            }
            switch(s[cur]){
                case 'V':  // 5
                    if (s[cur - 1] == 'I') {
                        minus = true;
                    }
                    break;
                case 'X': // 10
                    if (s[cur - 1] == 'I') {
                        minus = true;
                    }
                    break;
                case 'L':  // 50
                    if (s[cur - 1] == 'X') {
                        minus = true;
                    }
                    break;
                case 'C':  // 100
                    if (s[cur - 1] == 'X') {
                        minus = true;
                    }
                    break;
                case 'D':  // 500
                    if (s[cur - 1] == 'C') {
                        minus = true;
                    }
                    break;
                case 'M':  // 1000
                    if (s[cur - 1] == 'C') {
                        minus = true;
                    }
                    break;
                default:
                    break;
            }
            cur--;
        }
        return res;
    }


/*
Runtime: 12 ms, faster than 80.69% of C++ online submissions for Roman to Integer.
Memory Usage: 5.9 MB, less than 95.76% of C++ online submissions for Roman to Integer.
代码太罗嗦了，可以更加简化
*/
    int romanToIntFool(string s) {
        int data[91] = {};
        data['I'] = 1;
        data['V'] = 5;
        data['X'] = 10;
        data['L'] = 50;
        data['C'] = 100;
        data['D'] = 500;
        data['M'] = 1000;
        int len = s.size();
        int cur = len-1;
        int res = 0;
        bool minus = false;
        while (cur >= 1) {
            switch(s[cur]){
                case 'I':
                    if (minus) {
                        res-=1;
                    } else {
                        res+=1;
                    }
                    minus = false;
                    break;
                case 'V':  // 5
                    if (minus)
                        res -= 5;
                    else {
                        res += 5;
                    }
                    if (s[cur - 1] == 'I') {
                        minus = true;
                    } else {
                        minus = false;
                    }
                    break;
                case 'X': // 10
                    if (minus)
                        res -= 10;
                    else {
                        res += 10;
                    }
                    if (s[cur - 1] == 'I') {
                        minus = true;
                    } else {
                        minus = false;
                    }
                    break;
                case 'L':  // 50
                    if (minus)
                        res -= 50;
                    else {
                        res += 50;
                    }
                    if (s[cur - 1] == 'X') {
                        minus = true;
                    } else {
                        minus = false;
                    }
                    break;
                case 'C':  // 100
                    if (minus)
                        res -= 100;
                    else {
                        res +=  100;
                    }
                    if (s[cur - 1] == 'X') {
                        minus = true;
                    } else {
                        minus = false;
                    }
                    break;
                case 'D':  // 500
                    if (minus)
                        res -= 500;
                    else {
                        res += 500;
                    }
                    if (s[cur - 1] == 'C') {
                        minus = true;
                    } else {
                        minus = false;
                    }
                    break;
                case 'M':  // 1000
                    if (minus)
                        res -= 1000;
                    else {
                        res += 1000;
                    }
                    if (s[cur - 1] == 'C') {
                        minus = true;
                    } else {
                        minus = false;
                    }
                    break;
                default:
                    break;
            }
            cur--;
        }
        if (cur==0) {
            if (minus) {
                res -= data[s[cur]];
            } else {
                res += data[s[cur]];
            }
        }
        return res;
    }


};




int main() {
    Solution s;
    //string str = "IXC";
    //string str = "IXCM";
    string str = "MCMXCIV";
    cout << s.romanToInt(str) << endl;
}


/*
Tips
映射关系的存储
A-Z  65-90
a-z  97-122
0-9  48-57

unordered_map<char, int> //  'X' -> 10
int data[91];  //  [X] ->10

陷阱
1 左结合还是右结合，这里默认右结合优先
"IXC"   89
XC=90 再减去I为89
IXC = I(XC) = 100-10-1=89
而非 (IX)C =100-(10-1) = 100-9-91

IXCM=IX(CM)=I[X (CM)] = 1000-100-10-1= 889

因此得从右往左遍历

2 IIX  10
I+IX = 1+9=10
即前缀用减法 只能是左边的第一个字符，不能链式调用下去

M1 模拟法
1 2   3    4   5  6   7    8     9   10   11
I II III   IV  V  VI  VII  VIII  IX   X   XI

M2 规律法
当小值在大值的左边，则减小值，如 IV=5-1=4;
当小值在大值的右边，则加小值，如 VI=5+1=6;
最末位的一个字符永远适用于加法
https://leetcode.com/problems/roman-to-integer/discuss/6547/Clean-O(n)-c%2B%2B-solution
https://leetcode.com/problems/roman-to-integer/discuss/6509/7ms-solution-in-Java.-easy-to-understand

*/


