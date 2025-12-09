/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-09
 * @tag  mutithread
 * @similar  1117,1195
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class FizzBuzz {
private:
    int n;
    int cur;

    std::mutex mu;
    std::condition_variable cv;


public:
    FizzBuzz(int n) {
        this->n = n;
        cur = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        std::unique_lock<mutex> lk(mu);
        for (;cur <= n; ) {
            if (cur%3==0 && cur%5!=0) {
                printFizz();
                cur++;
                cv.notify_all();
            }
            cv.wait(lk, [this]{
                return (cur > n || cur%3 == 0 && cur%5 != 0);
            });
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        std::unique_lock<mutex> lk(mu);
        for (;cur <= n; ) {
            if (cur%3!=0 && cur%5==0) {
                printBuzz();
                cur++;
                cv.notify_all();
            }
            cv.wait(lk, [this]{
                return (cur > n || cur%3!=0 && cur%5==0);
            });
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        std::unique_lock<mutex> lk(mu);
        for (;cur <= n; ) {
            if (cur%3==0 && cur%5==0) {
                printFizzBuzz();
                cur++;
                cv.notify_all();
            }
            cv.wait(lk, [this]{
                return (cur > n || cur%3==0 && cur%5==0);
            });
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        std::unique_lock<mutex> lk(mu);
        for (;cur <= n; ) {
            if (cur%3!=0 && cur%5!=0) {
                printNumber(cur);
                cur++;
                continue;
            } else {
                cv.notify_all();
            }
            cv.wait(lk, [this]{
                return (cur > n || cur%3!=0 && cur%5!=0);
            });
        }
        cv.notify_all();
    }
};

int main() {
    FizzBuzz s;
}


/*
Tips
M1

M2

*/
