/**
 * @file
 * @brief  54-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-28
 */

/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

Example:
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Spiral Matrix II.
*/
    vector<vector<int> > generateMatrix(int n) {
        //初始化2维vector
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int data=1;
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int i = 0;
        int j = 0;
        while(true) {
            //up
            for (j=left; j<=right; ++j) {
                matrix[up][j] = data++;
            }
            up++;
            //right
            for(i=up; i<=down; ++i) {
                matrix[i][right] = data++;
            }
            right--;
            if (up > down || right < left) {
                break;
            }
            //down
            for (j=right; j>=left; --j) {
                matrix[down][j] = data++;
            }
            down--;
            //left
            for(i=down; i>=up; --i) {
                matrix[i][left] = data++;
            }
            left++;
            if (up > down || left > right) {
                break;
            }
        }
        return matrix;
    }

};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){

}

int main() {

    Solution s;
    auto r = s.generateMatrix(4);
    print2DVector(r);

    return 0;
}


/*
Tips
M1

M2

*/
