/**
 * @file
 * @brief  CCI-1.6
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-01
 * @tag
 * @similar
 */

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Example 3:
Input: matrix = [[1]]
Output: [[1]]

Example 4:
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]


Constraints:
matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
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
[ 方阵
  row==col==size
   row=4 col=4
    tmp=13(i, j); 13(i, j)=12(N-1-j,i); 12=10(N-1-i, N-1-j); 10=1(j,N-1-i); 1=tmp]
    i = 0; j=2;
    tmp=9;  9=2; 2=14; 14=7; 7=9(tmp)
    i=1; j=1;
    tmp=3;  3=6; 6=8; 8=4; 4=3(tmp)
*/
    void rotateM1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return;
        int col = matrix[0].size();
        int i = 0; //row pointer
        int j = 0; //col pointer
        while (i < row / 2) {
            for (j = i; j < col - 1 - i; ++j) {
                // up -> tmp
                int tmp = matrix[i][j];
                //left -> up   (2,0) -> (0, 1)
                matrix[i][j] =  matrix[row-1-j][i];
                //bottom -> left  (3,2) -> (2, 0)
                matrix[row - 1 - j][i] = matrix[row - 1 - i][col - 1 - j];
                //right -> bottom  (1,3) -> (3, 2)
                matrix[row - 1 - i][col - 1 - j] = matrix[j][col - i - 1];
                //up(tmp) -> right   (0,1) -> (1,3)
                matrix[j][col - i - 1] = tmp;
            }
            i++;
        }
    }

/*
Runtime: 4 ms, faster than 67.64% of C++ online submissions for Rotate Image.
Memory Usage: 7.4 MB, less than 25.30% of C++ online submissions for Rotate Image.
*/
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if (N == 0)
            return;
        int maxLevel = N / 2;
        N--;
        int i = 0; //row pointer, means level from out to in
        int j = 0; //col pointer
        while (i < maxLevel) {
            for (j = i; j < N - i; ++j) {
                // up -> tmp
                int tmp = matrix[i][j];
                //left -> up   (2,0) -> (0, 1)
                matrix[i][j] =  matrix[N-j][i];
                //bottom -> left  (3,2) -> (2, 0)
                matrix[N - j][i] = matrix[N - i][N - j];
                //right -> bottom  (1,3) -> (3, 2)
                matrix[N- i][N - j] = matrix[j][N - i];
                //up(tmp) -> right   (0,1) -> (1,3)
                matrix[j][N - i] = tmp;
            }
            i++;
        }
    }

};


void rotate(int** matrix, int matrixSize, int* matrixColSize){

}


int main() {
    int nums[4][4] = {
  { 5, 1, 9,11},
  { 2, 4, 8,10},
  {13, 3, 6, 7},
  {15,14,12,16}
};
    vector<vector<int>> data = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution s;
    s.rotate(data);
    print2DVector(data);
}


/*
Tips
M1 模拟法
S=O(1)
由外及内
先转四个对角元素，其他元素依次类推,如下所示
  [ 5, 1, 9, 11],
  [ 2,  ,  , 10],
  [13,  ,  ,  7],
  [15, 14,12,16]

  [  ,  ,  , 5],
  [14,  ,  , 1],
  [12,  ,  , 9],
  [16,  ,  ,  ]

实现比较耗时-找好特例-验证坐标-加快速度

M2 先转置再每行reverse

*/


