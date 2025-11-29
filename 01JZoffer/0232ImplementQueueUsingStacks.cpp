/**
 * @file
 * @brief  P7-Similar 225
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-17
 */

/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Example:
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop_fool() {
        int val = 0;
        if (!out.empty()){
            val = out.top();
        } else {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            val = out.top();
        }
        out.pop();
        return val;
    }


    int pop() {
        int res=peek();
        out.pop();
        return res;
    }

    /** Get the front element. */
    int peek_fool() {
        int val = 0;
        if (!out.empty()){
            val = out.top();
        } else {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            val = out.top();
        }
        return val;
    }

    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }

    stack<int> in;
    stack<int> out;
    // FIFO = FILO + FILO
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;   // returns 1
    cout << q.pop() << endl;    // returns 1
    cout << q.empty() << endl;  // returns false

    return 0;
}


/*
Tips
M1 two stack
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Implement Queue using Stacks.
stefan Pochman
https://leetcode.com/problems/implement-queue-using-stacks/discuss/64206/Short-O(1)-amortized-C%2B%2B-Java-Ruby


*/