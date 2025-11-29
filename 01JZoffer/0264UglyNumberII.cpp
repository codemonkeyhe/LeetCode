/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2022-06-26
 * @tag
 * @similar
 */

/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:
1 is typically treated as an ugly number.
n does not exceed 1690.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber1(int n) {
        int i = 0;
        unsigned long res = 0;
        set<unsigned long> ugly;
        ugly.insert(1);
        while (!ugly.empty()) {
            auto it = ugly.begin();
            unsigned long cur = *it;
            i++;
            if (i >= n) {
                res = cur;
                break;
            }
            ugly.erase(it);
            ugly.insert(cur*2);
            ugly.insert(cur*3);
            ugly.insert(cur*5);
        }
        return res;
    }

    int nthUglyNumber2(int n) {
        int i = 0;
        unsigned long res = 0;
        set<unsigned long> dup;
        priority_queue<unsigned long, vector<unsigned long>, greater<unsigned long>> ugly;
        ugly.push(1);
        while (!ugly.empty()) {
            unsigned long cur = ugly.top();
            i++;
            if (i >= n) {
                res = cur;
                break;
            }
            ugly.pop();
            unsigned long v2 = cur*2;
            unsigned long v3 = cur*3;
            unsigned long v5 = cur*5;
            if (!dup.count(v2)) {
                dup.insert(v2);
                ugly.push(v2);
            }
            if (!dup.count(v3)) {
                dup.insert(v3);
                ugly.push(v3);
            }
            if (!dup.count(v5)) {
                dup.insert(v5);
                ugly.push(v5);
            }
        }
        return res;
    }

/*
Runtime: 225 ms, faster than 10.83% of C++ online submissions for Ugly Number II.
Memory Usage: 32.2 MB, less than 9.21% of C++ online submissions for Ugly Number II.
*/
    int nthUglyNumber3(int n) {
        int i = 0;
        unsigned long res = 0;
        set<unsigned long> dup;
        priority_queue<unsigned long, vector<unsigned long>, greater<unsigned long>> ugly;
        ugly.push(1);
        while (!ugly.empty()) {
            unsigned long cur = ugly.top();
            i++;
            if (i >= n) {
                res = cur;
                break;
            }
            ugly.pop();
            unsigned long v2 = cur*2;
            unsigned long v3 = cur*3;
            unsigned long v5 = cur*5;
            auto pa = dup.insert(v2);
            if (pa.second) {
                ugly.push(v2);
            }
            pa = dup.insert(v3);
            if (pa.second) {
                ugly.push(v3);
            }
            pa = dup.insert(v5);
            if (pa.second) {
                ugly.push(v5);
            }
        }
        return res;
    }

};

int nthUglyNumber(int n) {
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    vector<int> ugly;
    ugly.push_back(1);

    while (ugly.size() < (size_t)n) {
        auto n2 = ugly[p2] * 2;
        auto n3 = ugly[p3] * 3;
        auto n5 = ugly[p5] * 5;
        int minU = min(min(n2,n3), n5);
        ugly.push_back(minU);
        if (minU == n2) {
            p2++;
        }
        if (minU == n3) {
            p3++;
        }
        if (minU == n5) {
            p5++;
        }
    }
    // printVector(ugly, "ugly");
    return ugly.back();
}

int main() {
    //Solution s;
    int n = 10;
    //int res = s.nthUglyNumber1(n);
    int res = nthUglyNumber(n);
    cout << res << endl;
}

/*
Tips
M1 优先队列+构造法
Runtime: 206 ms, faster than 13.01% of C++ online submissions for Ugly Number
II. Memory Usage: 29.7 MB, less than 15.62% of C++ online submissions for Ugly
Number II. 把 set换成优先队列后 Runtime: 223 ms, faster than 10.97% of C++
online submissions for Ugly Number II. Memory Usage: 32.1 MB, less than 9.86% of
C++ online submissions for Ugly Number II.

M2 DP


M3 3指针
Runtime: 6 ms, faster than 89.87% of C++ online submissions for Ugly Number II.
Memory Usage: 9.4 MB, less than 46.09% of C++ online submissions for Ugly Number II.

核心思路
丑数= 2^a * 3^b * 5^c
每次 a b c任意一个+1 都能生成新的丑数，意味着在丑数序列中，任意一个丑数都是由左侧丑数乘以2or3or5得来的。
因此用3个指针，p2表示丑数序列中*2的丑数的位置
每个数字都可以乘以2 3 5，只要乘过了，意味着这个数字失去了乘以2or3or5的机会了，因此对应的指针可以往下移一位


*/
