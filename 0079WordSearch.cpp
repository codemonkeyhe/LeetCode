/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-18
 * @tag  recursion
 * @similar   130  200    212
 */

/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

Constraints:
board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Bug1   k >= word.size() 过不了数据  Input:[["a"]]  word="a"  Output:false    Expected:true
Bug2   不要忘记了回溯的状态重置 visited[i][j] = 0;
Runtime: 276 ms, faster than 37.83% of C++ online submissions for Word Search.
Memory Usage: 150.7 MB, less than 28.92% of C++ online submissions for Word Search.

注意，下面的回溯，在找到一种解法时，visited数组里面是有状态的，不会被重置到全为0
或者改变控制流，不用return true，而是设置 result = true，待状态全部重置后，再return result;
*/
    bool check(vector<vector<char>>& board, int i, int j, vector<vector<int>> &visited,  string word, int k) {
        if (visited[i][j]) {
            return false;
        }
        if (word[k] != board[i][j]) {
            return false;
        }
        if (k + 1 >= word.size()) {
            return true;
        }
        visited[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        // down
        if (i < n-1 && check(board, i + 1, j, visited, word, k + 1))
            return  true;
        // up
        if (i > 0 && check(board, i - 1, j, visited, word, k + 1)) {
            return true;
        }
        //left
        if (j > 0 && check(board, i, j - 1, visited, word, k + 1)) {
            return true;
        }
        //right;
        if (j < m - 1 && check(board, i, j + 1, visited, word, k + 1)) {
            return true;
        }
        visited[i][j] = 0;
        return false;
    }


/*
1. visited前置
2. 使用二维的bool，减少内存
3. string传递引用
Runtime: 48 ms, faster than 92.02% of C++ online submissions for Word Search.
Memory Usage: 11.8 MB, less than 61.62% of C++ online submissions for Word Search.

visited二维数组有2个作用
1是记录是否用过
2是回溯时重置状态
*/
    bool check2(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &visited,  string &word, int k) {
        if (word[k] != board[i][j]) {
            return false;
        }
        if (k + 1 >= word.size()) {
            return true;
        }
        visited[i][j] = true;
        int n = board.size();
        int m = board[0].size();
        // down
        if (i < n - 1 && !visited[i + 1][j] && check2(board, i + 1, j, visited, word, k + 1)) {
            return true;
        }
        // up
        if (i > 0 && !visited[i-1][j] && check2(board, i - 1, j, visited, word, k + 1)) {
            return true;
        }
        //left
        if (j > 0 && !visited[i][j-1] && check2(board, i, j - 1, visited, word, k + 1)) {
            return true;
        }
        //right;
        if (j < m - 1 && !visited[i][j+1] && check2(board, i, j + 1, visited, word, k + 1)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }



/*
因为回溯会重置状态，所以不需要每个if里面构造一个visited数组
*/
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n==0) return false;
        int m = board[0].size();
        //vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    // vector<vector<int>> visited(n, vector<int>(m, 0));
                    // if (check(board, i, j, visited, word, 0)) {
                    if (check2(board, i, j, visited, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }



};

bool exist(char** board, int boardSize, int* boardColSize, char * word){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1  DFS+回溯
二维数组当做1维数组，存储每个字符的pos，同时计算up,down,left,right位置的字符
遍历word[i]，如果在map里面，则判断word[i+1]是否位于四个方位的字符里
T=O(M*N)建立map + O(len(word)*4)
这个思路是错误的
因为每个字符只能用一次，还需要一个矩阵记录字符是否使用过
如果up,down,left,right都等于word[i+1]，选择哪条路呢？ BFS还是DFS+回溯
其实算是图的遍历，DFS+标记数组，
其实不需要建立map加速字母查找了，毕竟建立map也需要O(NM)，查找word[0]也最多需要O(NM)，是一次性的工作

官方解法学习点
https://leetcode-cn.com/problems/word-search/solution/dan-ci-sou-suo-by-leetcode-solution/
四个方向的做法
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }

*/
