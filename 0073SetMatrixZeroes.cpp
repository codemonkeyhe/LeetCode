/**
 * @file
 * @brief CCI-1.7
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-01
 * @tag
 * @similar
 */

/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-10^9 <= matrix[i][j] <= 10^9

示例 1:
输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

示例 2:
输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
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
M3.5
Runtime: 36 ms, faster than 39.61% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.5 MB, less than 11.77% of C++ online submissions for Set Matrix Zeroes.

第二次遍历矩阵，设置元素时，
i不能从0开始，如果从0开始，否则会把row0的元素设置为0了，会链式反应，导致遍历后续元素时发生误判
因为row0已经被用作标记了，必须先把row1开始的元素全部设置好，最后再清除row0
*/
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0)
            return;
        int N = matrix[0].size();
        bool clearColZero = false;
        for (int i = 0; i < M; ++i) {
            if (matrix[i][0] == 0) {
                clearColZero = true;
                break;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < N; j++) {
                matrix[0][j] = 0;
            }
        }
        if (clearColZero) {
            for (int i = 0; i < M; ++i) {
                matrix[i][0] = 0;
            }
        }
    }

/*
M1.5
Runtime: 32 ms, faster than 53.09% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.6 MB, less than 5.94% of C++ online submissions for Set Matrix Zeroes.
*/
    void setZeroesM15(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0)
            return;
        int N = matrix[0].size();
        vector<int> row(M, 0);
        vector<int> col(N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

}


int main() {
    Solution s;
}


/*
Tips
M1　使用O(M*N)构造一个标记矩阵，把原矩阵的0全部标记出来
然后遍历标记矩阵，执行置0操作
T=O(M*N)+O(M*N*(M+N))

M1.5 空间改进版 int row[M]和int col[N]; 遍历原矩阵，记录需要置0的行和列,存入row和col数组。
遍历原矩阵，把元素下标(i,j)在row或者col里面的置为0
T=O(M*N)+O(M*N) = O(M*N)

M2 bit位设置标记
1 <= m, n <= 200
说明可以用200个bit存储M1.5中的row和col标记数组
M2.1 std::bitset<200> row,col;
M2.2  char数组
200bit/8=25
因此用 char row[25];  char col[25]; 即可标记行和列

M3 使用特殊数字INT_MAX标记作为要被置为0的数字
因为 -10^9 <= matrix[i][j] <= 10^9  所以 INT_MAX标记法不会和已有的数字冲突
遍历矩阵，遇到0，则置所在的行i和j的非0数字为改为INT_MAX
再次遍历矩阵，把所有的INT_MAX改为0
T=O(M*N*(M+N))

M3.5 改进版
https://leetcode-cn.com/problems/set-matrix-zeroes/solution/ju-zhen-zhi-ling-by-leetcode/
用每个matrix的行首或者列首作为本列置0的标记
例如 matrix[i][j] == 0 则把 matrix[i][0]置为0  matrix[0][j]置为0
但是matrix[0][0] == 0 意味着行0 或者列0 中的某个元素为0  存在二义性，要消除二义性，
因此，只有行0中的元素为0时，matrix[0][0]=0，而列0中的元素为0，用额外的变量去标记

然后遍历矩阵，如果行首为0，或者列首为0，就把该元素置为0
M3.5本质上就是M1.5，只不过把row数组用matrix[0]去表示，把col数组用matrix[i][0]去表示

*/


