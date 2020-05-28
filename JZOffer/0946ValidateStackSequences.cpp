/**
 * @file
 * @brief  P22
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-27
 */

/*
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

Note:
0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
/*
Runtime: 8 ms, faster than 95.83% of C++ online submissions for Validate Stack Sequences.
Memory Usage: 15.5 MB, less than 33.33% of C++ online submissions for Validate Stack Sequences.
*/
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack<int> s;
        while(j<popped.size()) {
            int cur = popped[j];
            if (!s.empty() && cur == s.top()) {
                j++;
                s.pop();
                continue;
            }
            while(i < pushed.size()) {
                if (pushed[i]!=cur) {
                    s.push(pushed[i++]);
                } else {
                    j++;
                    break;
                }
            }
            if (i>=pushed.size()) { //not found
                return false;
            }
            i++;
        }
        return true;
    }

};


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1

M2

*/
