/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-29
 * @tag   prefixSum; binarySearch; randomized
 * @similar  528
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 *
 * https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/description/
 *
 * algorithms
 * Medium (42.00%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 61.9K
 * Testcase Example:  '["Solution","pick","pick","pick","pick","pick"]\n' +
  '[[[[-2,-2,1,1],[2,2,4,6]]],[],[],[],[],[]]'
 *
 * 给定一个由非重叠的轴对齐矩形的数组 rects ，其中 rects[i] = [ai, bi, xi, yi] 表示 (ai, bi) 是第 i
 * 个矩形的左下角点，(xi, yi) 是第 i
 * 个矩形的右上角点。设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。所有满足要求的点必须等概率被返回。
 *
 * 在给定的矩形覆盖的空间内的任何整数点都有可能被返回。
 * 请注意 ，整数点是具有整数坐标的点。
 *
 * 实现 Solution 类:
 * Solution(int[][] rects) 用给定的矩形数组 rects 初始化对象。
 * int[] pick() 返回一个随机的整数点 [u, v] 在给定的矩形所覆盖的空间内。
 *
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入:
 * ["Solution", "pick", "pick", "pick", "pick", "pick"]
 * [[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
 * 输出:
 * [null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]
 *
 * 解释：
 * Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
 * solution.pick(); // 返回 [1, -2]
 * solution.pick(); // 返回 [1, -1]
 * solution.pick(); // 返回 [-1, -2]
 * solution.pick(); // 返回 [-2, -2]
 * solution.pick(); // 返回 [0, 0]
 *
 *
 *
 * 提示：
 * 1 <= rects.length <= 100
 * rects[i].length == 4
 * -10^9 <= ai < xi <= 10^9
 * -10^9 <= bi < yi <= 10^9
 * xi - ai <= 2000
 * yi - bi <= 2000
 * 所有的矩形不重叠。
 * pick 最多被调用 10^4 次。
 *
 *
 */

// @lc code=start
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        rectList = rects;
        total = 0;
        presum.push_back(0); // 前缀和标准操作
        for (auto &rec : rectList) {
            int w = rec[2]-rec[0] + 1;
            int h = rec[3]-rec[1] + 1;
            int docCnt = w*h;
            total += docCnt;
            presum.push_back(total);
        }
       // cout << "total=" << total << endl;
    }

    vector<int> pick() {
        int k = rand()%total;
        int idx = upper_bound(presum.begin(), presum.end(), k) - presum.begin();
        //cout << "k=" << k  << " idx=" << idx << endl;
        auto& rec = rectList[idx - 1];
        //int row = rec[3] - rec[1] + 1;
        int curRectDot = k - presum[idx-1];
        int col = rec[2] - rec[0] + 1;
        int x1 = rec[0] + curRectDot %col;
        int y1 = rec[1] + curRectDot /col;
        return vector<int> {x1, y1};
    }

    vector<vector<int> > rectList;
    vector<int>  presum;
    int total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

/*
rects={rect0, rect1}
rect0: [0,0, 3, 2]  dotCnt=(3-0+1) *(2-0+1) = 12
rect1: [3,3, 4, 4]  docCnt=(4-3+1)*(4-3+1) = 4


preS={0, 12, 16}

totalSize=12+4=16
totalSize=pres.Back()

k = rand()%totalSize;
k=0-15

1 k=0-11; means rect0: 0-11, idx=1
2 k=12-15; means rect1: 12-15, idx=2

use upper_bound not lower_bound, reason:
when k = 11; findFirst>k in pres, idx=1
when k = 12; findFirst>k in pres, idx=2

1 k= 0-11; means rect0: 0-11, idx=1
k和(x1,y1)关系：
8 9 10 11
4 5 6 7
0 1 2 3

2 k=12-15; means rect1: 12-15, idx=2
先把k去掉rect0; curRectDot=k-12; k =[0,3];再转为下标
        int curRectDot = k - presum[idx-1];

leftDown=(x, y)
row=3
col=4

x1 = x + k%col
y1 = y + k/col



Wrong Answer
3/35 cases passed (N/A)
Testcase
["Solution","pick","pick","pick","pick","pick"]
' +,
  '[[[[-2,-2,1,1],[2,2,4,6]]],[],[],[],[],[]]
Answer
[null,[0,0],[-1,-1],[1,-2],[1,-1],[3,8]]
Expected Answer
[null,[1,-2],[1,-1],[-1,-2],[-2,-2],[0,0]]
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
