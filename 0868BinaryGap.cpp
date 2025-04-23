/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-23
 * @tag  bitManipulation
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 *
 * https://leetcode.cn/problems/binary-gap/description/
 *
 * algorithms
 * Easy (69.63%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 79.1K
 * Testcase Example:  '22'
 *
 * 给定一个正整数 n，找到并返回 n 的二进制表示中两个 相邻 1 之间的 最长距离 。如果不存在两个相邻的 1，返回 0 。
 *
 * 如果只有 0 将两个 1 分隔开（可能不存在 0 ），则认为这两个 1 彼此 相邻 。两个 1
 * 之间的距离是它们的二进制表示中位置的绝对差。例如，"1001" 中的两个 1 的距离为 3 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：n = 22
 * 输出：2
 * 解释：22 的二进制是 "10110" 。
 * 在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
 * 第一对相邻的 1 中，两个 1 之间的距离为 2 。
 * 第二对相邻的 1 中，两个 1 之间的距离为 1 。
 * 答案取两个距离之中最大的，也就是 2 。
 *
 *
 * 示例 2：
 * 输入：n = 8
 * 输出：0
 * 解释：8 的二进制是 "1000" 。
 * 在 8 的二进制表示中没有相邻的两个 1，所以返回 0 。
 *
 *
 * 示例 3：
 * 输入：n = 5
 * 输出：2
 * 解释：5 的二进制是 "101" 。
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int mask = 0x00000001;
        int pos = 0;
        int res = 0;
        int p1 = -1;
        int p2 = -1;
        while (n > 0) {
            if (n & mask) {  // 1
                p1 = p2;
                p2 = pos;
                if (p1 != -1) {
                    int dis = p2 - p1;
                    if (dis > res) {
                        res = dis;
                    }
                }
            }
            n >>= 1;
            pos++;
        }
        return res;
    }
};
// @lc code=end


/*

lowbit
例如x=22 二进制10110
第一次取出 last = 10(二进制)
第二次取出 now = 100（二进制）
两者相除取对数。log2(now / last) 就可以直接得到想间隔的距离。

作者：Maserhe
链接：https://leetcode.cn/problems/binary-gap/solutions/481470/wei-yun-suan-lowbitkuai-su-qu-1beats100-by-maserhe/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


