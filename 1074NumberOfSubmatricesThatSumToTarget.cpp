/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-13
 * @tag prefixSum,hashTable
 * @similar  560, 1074
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 *
 * https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (67.67%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 36K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * 给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
 *
 * 子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y]
 * 的集合。
 *
 * 如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 !=
 * x1'），那么这两个子矩阵也不同。
 *
 *
 *
 * 示例 1：
 * 输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * 输出：4
 * 解释：四个只含 0 的 1x1 子矩阵。
 *
 *
 * 示例 2：
 * 输入：matrix = [[1,-1],[-1,1]], target = 0
 * 输出：5
 * 解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
 *
 *
 * 示例 3：
 * 输入：matrix = [[904]], target = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i][j] <= 1000
 * -10^8 <= target <= 10^8
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int cnt = 0;
        for (int i = 0; i < row; i++) {
            //auto& baseRow = matrix[i];
            vector<int> sum(col, 0);
            for (int j = i; j < row; j++) {
                auto& row = matrix[j];
                for (int k = 0; k < col; k++) {
                    sum[k]+= row[k];
                }
                //cnt += sumTarget(sum, target);
                cnt += sumTarget2(sum, target);
            }
        }
        return cnt;
    }

    int sumTarget(vector<int>& sum, int target) {
        int cnt  = 0;
        int lenn = sum.size();
        vector<int> presum(lenn+1, 0);
        for (int i = 0; i < lenn; i++) {
            presum[i + 1] = presum[i] + sum[i];
        }
        for (int i = 0; i < lenn; i++) {
            for (int j = i; j < lenn; j++) {
                // subsum(i, j) == k
                // subsum(i, j)  = presum[j+1] - prsum[i]
                if (presum[j + 1] - presum[i] == target) {
                    cnt++;
                }
            }
        }
        return cnt;
    }


/*
twoSum的思路
presum[j + 1] - presum[i] == target
presum[j + 1]  == target + presum[i]

presum[j + 1] - target  == presum[i]

*/
    int sumTarget2(vector<int> &sum, int target) {
        int cnt  = 0;
        int lenn = sum.size();
        vector<int> presum(lenn+1, 0);
        for (int i = 0; i < lenn; i++) {
            presum[i + 1] = presum[i] + sum[i];
        }
        unordered_map<int, int> sum2cnt;
        for (auto ps : presum) { // rightPoint
            int want = ps - target;
            if (sum2cnt.count(want) == 1) { // exist
                // means find i; leftPoint
                cnt += sum2cnt[want];
            }
            sum2cnt[ps]++;
        }
       return cnt;
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
