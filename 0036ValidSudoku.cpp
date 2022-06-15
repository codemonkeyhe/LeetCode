/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2022-06-14
 * @tag
 * @similar
 */

/*



Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

*/







#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:


    bool isValidSudoku(vector<vector<char>>& board) {
        vector< set<char> >  vertical(9, set<char>());
        vector< set<char> >  horizon(9, set<char>());
        vector< set<char> >  mini(9, set<char>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char v = board[i][j];
                if( v == '.') {
                    continue;
                }
                auto pv = vertical[i].insert(v);
                if (pv.second == false) { // means exist
                    return false;
                }
                auto ph = horizon[j].insert(v);
                if (ph.second == false) {
                    return false;
                }
                int k = 3*(i/3) + j/3;
                auto pm = mini[k].insert(v);
                if (pm.second == false) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<vector<char> > d1 = { 
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'} 
    };
    auto r1 = s.isValidSudoku(d1);
    cout << "r1=" << r1 <<endl;
}


/*
   Tips
   M1

   M2

*/


