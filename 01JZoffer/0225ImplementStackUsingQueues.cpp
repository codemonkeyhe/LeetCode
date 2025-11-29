/**
 * @file
 * @brief  P7   232
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-17
 */

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Example:
MyStack stack = new MyStack();
stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (!q1.empty()) {
            q1.push(x);
        } else if(!q2.empty()){
            q2.push(x);
        } else {
            q1.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> *p1 = &q1;
        queue<int> *p2 = &q2;
        if (q1.empty()) {
            p1 = &q2;
            p2 = &q1;
        }
        if (p1->empty()) { // not value
            return INT_MIN;
        }
        int i = 1;
        int n = p1->size();
        // bug while(i++ < p1->size()) {
        while(i++ < n) {
            p2->push(p1->front());
            p1->pop();
        }
        int val = p1->front();
        p1->pop();
        // p1 should be empty
        return val;
    }

    /** Get the top element. */
    int top() {
        queue<int> *p = &q1;
        if (q1.empty()) {
            p = &q2;
        }
        return  p->back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }

    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;    // returns 3
    cout << s.pop() << endl;    // returns 3
    cout << s.empty();  // returns false

    return 0;
}


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
//Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Implement Stack using Queues.

/*
Tips
M1  two queues
too silly

M2  one queue
https://leetcode.com/problems/implement-stack-using-queues/discuss/62527/A-simple-C%2B%2B-solution
every push will take n-1 steps to rotate the queue.

M3

*/