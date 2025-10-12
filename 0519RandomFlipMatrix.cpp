/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-12
 * @tag   randomized
 * @similar   384,398, 519
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=519 lang=cpp
 *
 * [519] 随机翻转矩阵
 *
 * https://leetcode.cn/problems/random-flip-matrix/description/
 *
 * algorithms
 * Medium (46.14%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    23.9K
 * Total Submissions: 51.9K
 * Testcase Example:  '["Solution","flip","flip","flip","reset","flip"]\n[[3,1],[],[],[],[],[]]'
 *
 * 给你一个 m x n 的二元矩阵 matrix ，且所有值被初始化为 0 。请你设计一个算法，随机选取一个满足 matrix[i][j] == 0
 * 的下标 (i, j) ，并将它的值变为 1 。所有满足 matrix[i][j] == 0 的下标 (i, j) 被选取的概率应当均等。
 * 尽量最少调用内置的随机函数，并且优化时间和空间复杂度。
 *
 * 实现 Solution 类：
 * Solution(int m, int n) 使用二元矩阵的大小 m 和 n 初始化该对象
 * int[] flip() 返回一个满足 matrix[i][j] == 0 的随机下标 [i, j] ，并将其对应格子中的值变为 1
 * void reset() 将矩阵中所有的值重置为 0
 *
 *
 *
 *
 * 示例：
 * 输入
 * ["Solution", "flip", "flip", "flip", "reset", "flip"]
 * [[3, 1], [], [], [], [], []]
 * 输出
 * [null, [1, 0], [2, 0], [0, 0], null, [2, 0]]
 *
 * 解释
 * Solution solution = new Solution(3, 1);
 * solution.flip();  // 返回 [1, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
 * solution.flip();  // 返回 [2, 0]，因为 [1,0] 已经返回过了，此时返回 [2,0] 和 [0,0] 的概率应当相同
 * solution.flip();  // 返回 [0, 0]，根据前面已经返回过的下标，此时只能返回 [0,0]
 * solution.reset(); // 所有值都重置为 0 ，并可以再次选择下标返回
 * solution.flip();  // 返回 [2, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 10^4
 * 每次调用flip 时，矩阵中至少存在一个值为 0 的格子。
 * 最多调用 1000 次 flip 和 reset 方法。
 *
 *
 */

// @lc code=start
class Solution {
public:
    Solution(int m, int n) {
        row = m;
        col = n;
        total = row * col;
    }

    vector<int> flip1() {
        int ranv = rand()%total;
        int lastPos = total - 1;
        cout << "total=" << total << " randv=" << ranv << endl;
        if (use2real.count(ranv) == 0) { // not use
            //cout << "NOTUSE " << " randv=" << ranv << endl;
            // idx = i *n +j;  so    i = idx/n ; j = idx%n;
            // swap(ranv, lastPos);
            if (use2real.count(lastPos)) {
                use2real[ranv] = use2real[lastPos];
            } else {
                use2real[ranv] = lastPos;
            }
            total--;
            return vector<int> { ranv / col, ranv % col };
        }
        int realV = use2real[ranv];
       // cout << "USE " << " randv=" << ranv << " realv=" << realV << endl;
        // swap(ranv, lastPos);
        if (use2real.count(lastPos)) {
            use2real[ranv] = use2real[lastPos];
        } else {
            use2real[ranv] = lastPos;
        }
        total--;
        return  vector<int> { realV / col, realV % col };
    }

    vector<int> flip() {
        int ranv = rand() % total;
        int lastPos = total - 1;
        total--;
        vector<int> res;
        if (use2real.count(ranv) == 0) { // not use
            res = vector<int>{ranv / col, ranv % col};
        } else {
            int realV = use2real[ranv];
            res = vector<int>{realV / col, realV % col};
        }
        if (use2real.count(lastPos)) {
            use2real[ranv] = use2real[lastPos];
        } else {
            use2real[ranv] = lastPos;
        }
        return res;
    }

    void reset() {
        total = row * col;
        use2real.clear();
    }

    int total;
    int row;
    int col;
    // idx = 0 ~ total-1
    // pos=(i, j) ;  0<=i < m;  0<=j < n
    // idx = i * n + j;
    unordered_map<int, int> use2real;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
