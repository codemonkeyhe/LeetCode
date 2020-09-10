/**
 * @file
 * @brief 1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-10
 * @tag  backtracking;
 * @similar
 */

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
Memory Usage: 11.5 MB, less than 82.12% of C++ online submissions for Generate Parentheses.
leftP rightP 表明还剩余多少左右括号未使用
*/
    void gP(int leftP, int rightP, int total, string &path, vector<string>& res) {
        if (path.size() == total) {
        //Same if (leftP == 0 && rightP == 0) {
            res.push_back(path);
            return;
        }
        // SAME if (leftP > 0 && leftP <= rightP) {  //优先用左
        if (leftP > 0) {
            path.push_back('(');
            gP(leftP-1, rightP, total, path, res);
            path.pop_back();
        }
        if (leftP < rightP) { //有条件的使用右
            path.push_back(')');
            gP(leftP, rightP-1, total, path, res);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int leftP = n;
        int rightP = n;
        int total = 2*n;
        string path("");
        gP(leftP, rightP, total, path, res);
        // gP2(leftP, rightP, total, path, res);
        return res;
    }


    /*
    看起来像是DFS，没有了回溯中的做出选择和撤销选择的过程，
    其实本质还是 回溯，  path+'('  就是做出选择，函数结束后，path没有变化，相当于把选择给撤销了
    相比gp,gp2多了复制字符串的开销
    Runtime: 8 ms, faster than 57.76% of C++ online submissions for Generate Parentheses.
Memory Usage: 15.1 MB, less than 45.39% of C++ online submissions for Generate Parentheses.
    */
    void gP2(int leftP, int rightP, int total, string path, vector<string>& res) {
        if (leftP == 0 && rightP == 0) {
            res.push_back(path);
            return;
        }
        if (leftP > 0 ) {
            gP2(leftP-1, rightP, total, path+'(', res);
        }
        if (leftP < rightP) {
            gP2(leftP, rightP-1, total, path+')', res);
        }
    }


};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){

}


int main() {
    Solution s;
    int n = 3;
    auto res =  s.generateParenthesis(n);
    for (auto s : res) {
        cout << s << endl;
    }
}


/*
Tips
M1 构造法 从1开始构造，需要去重，麻烦
n=1
()
n=2
(P1)P2
(())
()()
n=3
((P1)P2)P3
((()))
(()())
(())()
(P1)P2(P3)
(())() //重复
()()()
()(())

M2 Backtracking
Skill
1. 优先用左
2. 有条件的使用右  已用左括号大于或者等于右括号
3. 到达2*n为一种方案
((()))
(()())
(())()
()(())
()()()

M2.1 最优

M2.2 对path不用pop_back, 按复制传参


*/


