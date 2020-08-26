/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-06  2020-08-26
 * @tag   binary-search
 */

/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Line 10: Char 41: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:19:41
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
Memory Usage: 6.1 MB, less than 26.61% of C++ online submissions for Sqrt(x).
*/
    int mySqrt(int x) {
        long long  left = 0;
        long long right = x ;
        long long tmp = 0;
        long long mid = 0;
        while (left < right) {
            //当left+1==right时，mid=right
            mid = left + ((right - left + 1) >> 1);
            tmp = mid * mid;
            if (tmp == x) {
                return mid;
            } else if (tmp > x) {
                right = mid-1;
            } else {
                left = mid;
            }
        }
        return left;
    }



/*

BUG overflow tmp = mid * mid;
Line 13: Char 23: runtime error: signed integer overflow: 1073697799 * 1073697799 cannot be represented in type 'int' (solution.cpp)

Runtime: 4 ms, faster than 65.13% of C++ online submissions for Sqrt(x).
Memory Usage: 5.9 MB, less than 92.09% of C++ online submissions for Sqrt(x).
*/
    int mySqrtFool(int x) {
        if (x == 1)
            return 1;
        int left = 0;
        //BUG int right = x / 2;
        int right = x ;
        int tmp = 0;
        int mid = 0;
        while (left<right) {
            mid = left + ((right - left) >> 1);
            //BUG overflow tmp = mid * mid;
            tmp = x / mid;
            if (tmp == mid) {
                return mid;
            } else if (tmp < mid) {
                right = mid;
            } else {
                left = mid;
            }
            if (left == right - 1)
                break;
        }
        return left;
    }

/*
Runtime: 4 ms, faster than 65.13% of C++ online submissions for Sqrt(x).
Memory Usage: 5.9 MB, less than 61.14% of C++ online submissions for Sqrt(x).
*/
    int mySqrtFool2(int x) {
        if (x == 1)
            return 1;
        int left = 0;
        int right = x ;
        long long tmp = 0;
        long long mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            tmp = mid * mid;
            if (tmp == x) {
                return mid;
            } else if (tmp > x) {
                right = mid;
            } else {
                left = mid;
            }
            if (left+1 == right) //为了避免死循环
                break;
        }
        return left;
    }

/*
Runtime: 4 ms, faster than 65.13% of C++ online submissions for Sqrt(x).
Memory Usage: 6.1 MB, less than 28.10% of C++ online submissions for Sqrt(x).
*/
    int mySqrtM2(int x) {
        if (x <= 1)
            return x;
        int left = 0;
        int right = x ;
        long long tmp = 0;
        long long mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            tmp = mid * mid;
            if (tmp == x) {
                return mid;
            } else if (tmp > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }


};


int mySqrt(int x){

}


int main() {

    Solution s;
    for (int i = 1; i <= 10; ++i) {
        cout << "x=" << i << " sqrt(x)=" << s.mySqrtM2(i) << endl;
    }

    return 0;
}


