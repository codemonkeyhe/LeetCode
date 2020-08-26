/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-26
 * @tag
 * @similar 67 2
 */

/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
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
Runtime: 8 ms, faster than 82.54% of C++ online submissions for Add Strings.
Memory Usage: 6.6 MB, less than 96.77% of C++ online submissions for Add Strings.
*/
    string addStrings(string num1, string num2) {
        if (num1.empty())
            return num2;
        if (num2.empty())
            return num1;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res;
        int carry = 0;
        int cur = 0;
        while(i>=0 || j>=0) {
            cur = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
            carry = cur / 10;
            cur = cur % 10;
            res += (cur + '0');
            i--;
            j--;
        }
        if (carry) {
            res += (carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }


    string minusStrings(const string& A, const string& B) {
        if (A==B) {
            return "0";
        }
        string res;
        //+: 1  -:0
        int sign = 0;
        if (A.size() == B.size()) {
            sign = A > B;
        } else {
            sign = A.size() > B.size();
        }
        const string& maxS = sign ? A : B;
        const string& minS = sign ? B : A;
        // 必有 i>=j
        int i = maxS.size() - 1;
        int j = minS.size() - 1;
        int borrow = 0;
        int cur = 0;
        //maxS - minS
        while (i >= 0 || j >= 0) {
            int curI = (i >= 0) ? maxS[i] - '0' : 0;
            int curJ = (j >= 0) ? minS[j] - '0' : 0;
            cur = curI + borrow - curJ;
            if (cur < 0) {
                cur += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }
            j--;
            i--;
            res += (cur + '0');
        }
        int k = res.size()-1;
        while (k >= 0 && res[k] == '0') {
            k--;
        }
        res = res.substr(0, k + 1);
        if (sign == 0) {
            res += '-';
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string minusStrings2(const string& A, const string& B) {
        string res;
        //+: 1  -:0
        int sign = 0;
        if (A.size() == B.size()) {
            sign = A >= B;
        } else {
            sign = A.size() > B.size();
        }
        const string& maxS = sign ? A : B;
        const string& minS = sign ? B : A;
        // 必有 i>=j
        int i = maxS.size() - 1;
        int j = minS.size() - 1;
        int borrow = 0;
        int cur = 0;
        //maxS - minS
        while (i >= 0 || j >= 0) {
            int curI = (i >= 0) ? maxS[i] : '0';
            int curJ = (j >= 0) ? minS[j] : '0';
            cur = curI + borrow - curJ;
            if (cur < 0) {
                cur += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }
            j--;
            i--;
            res += (cur + '0');
        }
        //移除结果的前导0
        int k = res.size()-1;
        while (k >= 0 && res[k] == '0') {
            k--;
        }
        if (k == -1) {  // means A==B
            res = '0';
        } else {
            res = res.substr(0, k + 1);
        }
        if (sign == 0) {
            res += '-';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


char * addStrings(char * num1, char * num2){

}

// 负数得另外处理
void TestOrder() {
    vector<string> v;
    v.push_back("123");
    v.push_back("-1");
    v.push_back("9");
    v.push_back("63");
    v.push_back("0");
    v.push_back("900");
    v.push_back("111");
    v.push_back("321");
    v.push_back("333");
    v.push_back("3333");
    v.push_back("12");
    v.push_back("1240");
    v.push_back("440");
    v.push_back("99");
    v.push_back("199");
    v.push_back("639");
    sort(v.begin(), v.end());
    // 字典序  111 12 123 1240 199 321 333 3333 440 639 99
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;

    // 数值序  12 99 111 123 199 321 333 440 639 1240 3333
    // 不支持负数
    sort(v.begin(), v.end(), [](string& a, string& b) {
        if (a.size() == b.size()) {
            return a < b;
        } else {
            return a.size() < b.size();
        }
    });
    for (auto s : v) {
        cout << s << " ";
    }
}

int main() {
    string num1 = "1000000";
    string num2 = "9090";
    Solution s;
    //cout << s.addStrings(num1, num2) << endl;
    cout << s.minusStrings(num1, num2) << endl;
    cout << s.minusStrings2(num1, num2) << endl;

    TestOrder();
}



/*
Tips
M1

M2

*/

