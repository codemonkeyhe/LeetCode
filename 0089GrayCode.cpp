/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-06
 * @tag backtracking; math
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
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 *
 * https://leetcode.cn/problems/gray-code/description/
 *
 * algorithms
 * Medium (75.41%)
 * Likes:    697
 * Dislikes: 0
 * Total Accepted:    137.2K
 * Total Submissions: 181.9K
 * Testcase Example:  '2'
 *
 * n 位格雷码序列 是一个由 2^n 个整数组成的序列，其中：
 *
 * 每个整数都在范围 [0, 2^n - 1] 内（含 0 和 2^n - 1）
 * 第一个整数是 0
 * 一个整数在序列中出现 不超过一次
 * 每对 相邻 整数的二进制表示 恰好一位不同 ，且
 * 第一个 和 最后一个 整数的二进制表示 恰好一位不同
 * 给你一个整数 n ，返回任一有效的 n 位格雷码序列 。
 *
 *
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：[0,1,3,2]
 * 解释：
 * [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
 * - 00 和 01 有一位不同
 * - 01 和 11 有一位不同
 * - 11 和 10 有一位不同
 * - 10 和 00 有一位不同
 * [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
 * - 00 和 10 有一位不同
 * - 10 和 11 有一位不同
 * - 11 和 01 有一位不同
 * - 01 和 00 有一位不同
 *
 *
 * 示例 2：
 * 输入：n = 1
 * 输出：[0,1]
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 16
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> res;
    unordered_set<int> used;
    int want = 0;

    vector<int> grayCode(int n) {
        want = 1 << n; // 2^n
        vector<int> path;
        path.push_back(0);
        used.insert(0);
        grayBT(0,  n, path);
        return res;
    }

    void grayBT(int cur, int n, vector<int>& path) {
        if (path.size() == want) {
            // 最后1位数字必定只有1个1bit
            // ErrorCase if (cur & (cur - 1)  == 0) {
            if ((cur & (cur - 1) ) == 0) {
                res = path;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            int next = cur ^ ((1 << i));
            if (used.count(next)) {
                continue;
            }
            used.insert(next);
            path.push_back(next);
            grayBT(next, n, path);
            path.pop_back();
            used.erase(next);
            if (!res.empty()) {
                return;
            }
        }
        return;
    }


};
// @lc code=end

/*
BT
BT的思维需要更换一下
比如n=2,从0,1,2,3序列中找答案
相当于两个bit位，每个位置选择放0或者放1，这样思维错误，不能保证相邻的只差1bit

从00开始演化，
从左到右此时有2个选择，
00 -> 10
00 -> 01
继续BT下去，记录path，直到使用完所有的数字，且最后一个数和00只差1个bit


n=5
TLE




*/

/*
https://leetcode.cn/problems/gray-code/solutions/13637/gray-code-jing-xiang-fan-she-fa-by-jyd/

看了半天，终于看明白官解了,可能是我太笨了。
格雷g(n)=g(n-1) 的每一个元素的最前面补0 和补1。如果是这种思路用递推和动态规划的思路应该是都能解决的。
解法中有两处巧妙的逻辑:
1.对于首位补0和首位补1的逻辑 :首位补1=head+res.get(j) ;首位补00=原数(不需要处理)
2.镜像的处理使用。int j=res.size() - 1

tricky
     res.push_back(head + res[j]);

官方解法  按位或
   ret.push_back(ret[j] | (1 << (i - 1)));



*/

vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);

    int head = 1;
    for (int i = 0; i < n; i++) {
        for (int j = res.size() - 1; j >= 0; j--) { //逆序遍历
            //给前面追加 1   ，例如100 +  010 = 110，用加法而不是位操作
            res.push_back(head + res[j]);
        }
        head <<= 1; //生成前缀的1 ，例如  0001, 0010, 0100, 1000
    }
    return res;
}

/*
作者：力扣官方题解
链接：https://leetcode.cn/problems/gray-code/solutions/1196538/ge-lei-bian-ma-by-leetcode-solution-cqi7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class SolutionLC {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.reserve(1 << n);
        ret.push_back(0);
        for (int i = 1; i <= n; i++) {
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(ret[j] | (1 << (i - 1)));
            }
        }
        return ret;
    }
};




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


