#ifndef  __MATHS_H__
#define  __MATHS_H__

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


//// #################  GCD
// https://oi-wiki.org/math/number-theory/gcd/
// LeetCode 1979
// 辗转相除法
// gcd(x,y)=gcd(y,x mod y)
// x和y的大小关系不重要
int gcd(int x, int y) {
    if (x == 0) {
        return y;
    }
    return gcd(y % x, x);
}


// 不可以%0，因此要保护y
int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}


// 辗转相除法 迭代版本
int gcd(int x, int y) {
    int tmp = 0;
    while (y > 0) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}






//// #################  Prime
/*
质数（英文名：Prime number）又称素数，是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
https://oi-wiki.org/math/number-theory/sieve/

LeetCode204
*/

    bool isPrime(int n ) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }



// trick: j = i*i, not 2i ,2i is ok but slowly
    vector<bool> makePrime(int n) {
        vector<bool> pt(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            if (!pt[i]) {
                continue;
            }
            if ((long long)i * i > n) // prevent overflow
                continue;
            for (int j = i * i; j <= n; j += i) {
                pt[j] = false;
            }
        }
        return pt;
    }




//// ################# MOD
/*
 a%b = a - (a/b)*b

C 语言
-10 % 3 = ==>> -10 - (-3*3) = -1
-10/3 =-3.3 == -3

10/-3 =-3.3 == -3
10 % -3 ==>> 10 - (-3*-3) = 1


计算机程序设计语言中，不同语言对 % 的具体实现也不同:
    C&Java 语言中, % 是求余运算
    Python 语言中, % 是模取预算
计算机程序设计语言中，不同语言对 /(整除) 的具体实现也不同:
    C&Java 语言中, 整除是向零取整
    Python 语言中, 整除是向下取整




-1 0对任何数取模等于0
0%123=0
0%-123=0


0 任何数对1取模为0
a%1 == 0 ，

1 不可以对0取模
 a%0的行为是未定义的


2 可以对负数取模，但是不决定结果为负
即a%-3的符号由a来决定

在C++中，负数的取模运算有其特定的规则。根据C99标准，取模运算结果的正负由左操作数（被除数）的正负决定。如果左操作数是正数，那么取模运算的结果是非负数；如果左操作数是负数，那么取模运算的结果是负数或0。这意味着，取模运算的结果的符号与右操作数（除数）无关


在这个例子中，无论除数是正是负，结果的符号都与被除数相同。
cout << 5 % 2 << endl; // 输出 1
cout << 5 % -2 << endl; // 输出 1
cout << -5 % 2 << endl; // 输出 -1
cout << -5 % -2 << endl;// 输出 -1


3 负数可以取模
语言环境不同，“%”所代表的意义也不一样。
在C++和Java中，“%”代表的是“取余”，
而在Python中，“%”代表的是“取模”。
注意，“取余”和“取模”并不一样，因此不能像答主那样在不同的环境下测试对负数取模后的答案。实质上只是你在C++和Java中进行了“取余”运算，而在Python和计算器中进行了“取模”运算。

对正数进行取余和取模两种运算，其结果是相同的。而对于负数，取余和取模的结果则是不相同的


C++（G++ 编译）：cout << (-7) % 3; // 输出 -1
Java（1.6）： System.out.println((-7) % 3); // 输出 -1
Python 2.6：>>> (-7) % 3 // 输出 2
百度计算器：(-7) mod 3 = 2
Google 计算器：(-7) mod 3 = 2

C++（G++ 编译）： cout << 7 % (-3); // 输出 1
Java（1.6）： System.out.println(7 % (-3)); // 输出 1
Python 2.6：>>> 输出 -2
百度计算器：7 mod (-3) = -2
Google 计算器： 7 mod (-3) = -2

4 整除

计算机程序设计语言中，不同语言对 /(整除) 的具体实现也不同:

C&Java 语言中, 整除是向零取整

Python 语言中, 整除是向下取整

*/

#endif