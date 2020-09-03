/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-03
 * @tag
 * @similar  2 415
 */

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
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
Ascii
'0' - 48
'a' - 97
'A' - 65

Runtime: 8 ms, faster than 87.15% of C++ online submissions for Multiply Strings.
Memory Usage: 6.7 MB, less than 50.13% of C++ online submissions for Multiply Strings.
*/
    string multiplyFool(string num1, string num2) {
        if (num1 == "0" || num2 == "0")  return "0";
        int n = num1.size() + num2.size();
        string res(n, '0');
        for (int i = 0; i < num1.size(); ++i) {
            num1[i] -= '0';
        }
        for (int i = 0; i < num2.size(); ++i) {
            num2[i] -= '0';
        }
        int k = 0;
        int kk = 0;
        int p = 0;
        int cur = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            const int& out = (int)num1[i];
            kk = k;
            for (int j = num2.size() - 1; j >= 0; --j) {
                p = out * (int)num2[j];
                //BUG res[kk] += p % 10;
                //忽略了 res[kk]自身产生的进位了
                cur = res[kk] - '0' + p % 10;
                if (cur >= 10) {
                    res[kk] = cur % 10 + '0';
                    res[kk + 1] += cur / 10;
                } else {
                    res[kk] = (cur + '0');
                }
                if (p >= 10) {
                    res[kk + 1] += p / 10;
                }
                kk++;
            }
            k++;
        }
        // 删掉多余的字符
        int i = res.size() - 1;
        while (res[i] == '0') {
            i--;
        }
        res = res.substr(0, i + 1);
        //不需要把res变为字符串,因为res的初始每个字符就是'0'了
        reverse(res.begin(), res.end());
        return res;
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Multiply Strings.
Memory Usage: 6.5 MB, less than 78.30% of C++ online submissions for Multiply Strings.
*/
   string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")  return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1 + n2, '0');
        int k = 0;
        int kk = 0;
        for (int i = n1 - 1; i >= 0; --i, k++) {
            const int& out = (int)(num1[i] - '0');
            kk = k;
            int cur = 0;
            int carry = 0;
            for (int j = n2 - 1; j >= 0; --j) {
                cur = (res[kk] - '0') + out * (int)(num2[j] - '0') + carry;
                res[kk] = (cur % 10 + '0');
                carry = cur / 10;
                kk++;
            }
            if (carry) {
                res[kk] += carry;
                kk++;
            }
        }
        // 删掉多余的字符
        res = res.substr(0, kk);
        //不需要把res变为字符串,因为res的初始每个字符就是'0'了
        reverse(res.begin(), res.end());
        return res;
    }

};


char * multiply(char * num1, char * num2){

}


int main() {

    string tt = "0123456789";
    for (int i = 0; i < tt.size(); ++i) {
        tt[i] -= '0';
    }
    cout << tt << endl; //乱码
    cout << "---" << endl;
    for (int i = 0; i < tt.size(); ++i) {
        cout << (int)tt[i] << endl;
    }
    Solution s;
}


/*
Tips
M1 模拟法
写得太罗嗦了
没有找到i j  和 kk的关系
如果找到i j kk的关系，则不用逆置res。

https://leetcode.com/problems/multiply-strings/discuss/17646/Brief-C%2B%2B-solution-using-only-strings-and-without-reversal
//精简版
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        for (int i = 0; i < m + n; i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return "0";
    }

M2

*/


