/**
 * @file
 * @brief  P21
 * @author MonkeyHe
 * @version  2.0
 * @date 2020-03-30
 * @date 2020-05-29
 */

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <stack>

using namespace std;

//Runtime: 40 ms, faster than 27.44% of C++ online submissions for Min Stack.
//Memory Usage: 14.4 MB, less than 100.00% of C++ online submissions for Min Stack.
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        int minV = 0;
        if (st.empty()) {
            minV = x;
        } else {
            minV = min(x, st.top().second);
        }
        st.push(make_pair(x, minV));
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
    stack<pair<int, int> > st;
};

// Runtime: 36 ms, faster than 40.38% of C++ online submissions for Min Stack.
// Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Min
// Stack.
class MinStack2 {
   public:
    /** initialize your data structure here. */
    MinStack2() { min = 0x7FFFFFFF; }

    void push(int x) {
        if (x < min) {
            min = x;
        }
        st.push(make_pair(x, min));
    }

    void pop() {
        st.pop();
        if (st.empty()) {
            min = 0x7FFFFFFF;
        } else {
            min = st.top().second;
        }
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }

    stack<pair<int, int> > st;
    int min;
};

// Runtime: 32 ms, faster than 71.02% of C++ online submissions for Min Stack.
// Memory Usage: 14.3 MB, less than 100.00% of C++ online submissions for Min
// Stack.
class MinStack3 {
   public:
    MinStack3() {}

    void push(int x) {
        st.push(x);
        if (stMin.empty()) {
            stMin.push(x);
        } else if (x <= stMin.top()) {  // XXX 坑 容易写成<
            stMin.push(x);
        }
    }

    void pop() {
        if (st.top() == stMin.top()) {
            stMin.pop();
        }
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return stMin.top(); }

    stack<int> st;
    stack<int> stMin;
};

int main() {
    MinStack2* obj = new MinStack2();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int p1 = obj->getMin();
    obj->pop();
    obj->top();
    int p2 = obj->getMin();
    delete obj;
    cout << "p1=" << p1 << " p2=" << p2;
    return 0;
}

/*
Tips
M1  每个元素都存储一个最小值
stack<pair<int, int> > st;
https://leetcode-cn.com/problems/min-stack/solution/shi-ji-zhan-shu-ju-cun-chu-pairmin-value-by-khrisw/


M2  辅助栈
辅助栈存min值
坑： 和最小值相同的值多次入栈时,辅助栈要存多个最小值


*/