/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-23
 * @tag    hashtable
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
 * @lc app=leetcode.cn id=822 lang=cpp
 *
 * [822] 翻转卡片游戏
 *
 * https://leetcode.cn/problems/card-flipping-game/description/
 *
 * algorithms
 * Medium (59.55%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    26.7K
 * Total Submissions: 44.9K
 * Testcase Example:  '[1,2,4,4,7]\n[1,3,4,1,3]'
 *
 * 在桌子上有 n 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。
 * 我们可以先翻转任意张卡片，然后选择其中一张卡片。
 * 如果选中的那张卡片背面的数字 x 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。
 *
 * 哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0 。
 * 其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和背面的数字。
 * 如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。
 *
 *
 *
 * 示例 1：
 * 输入：fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
 * 输出：2
 * 解释：假设我们翻转第二张卡片，那么在正面的数变成了 [1,3,4,4,7] ， 背面的数变成了 [1,2,4,1,3]。
 * 接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。
 *
 * 示例 2：
 * 输入：fronts = [1], backs = [1]
 * 输出：0
 * 解释：
 * 无论如何翻转都无法得到想要的数字，所以   返回 0 。
 *
 *
 * 提示：
 * n == fronts.length == backs.length
 * 1 <= n <= 1000
 * 1 <= fronts[i], backs[i] <= 2000
 *
 *
 */

// @lc code=start
class Solution {
public:


    int flipgameMisunderstood(vector<int>& fronts, vector<int>& backs) {
        int minBack = 100000;
        int nLen = fronts.size();
        unordered_map<int, int> f2n;
        for (int i = 0; i < fronts.size(); i++) {
            f2n[fronts[i]]++;
        }
        for (int i = 0; i < nLen; i++) {
            int& fr = fronts[i];
            int& ba = backs[i];
            if (fr == ba) { // not answer
                continue;
            }
            // op1 no flip
            if (f2n.count(ba) == 0) {
                minBack = min(minBack, ba);
            }

            // op2 flip
            f2n[fr]--;
            f2n[ba]++;
            if (f2n[fr] >= 1) { // duplicate
               // reverse  flip
               f2n[fr]++;
               f2n[ba]--;
               continue;
            }
            minBack = min(minBack, fr);
            // reverse
            f2n[fr]++;
            f2n[ba]--;
        }
        if (minBack == 100000) {
            return 0;
        }
        return minBack;
    }


    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int minBack = 100000;
        int nLen = fronts.size();
        unordered_map<int, int> blockNum;
        for (int i = 0; i < nLen; i++) {
            if (fronts[i] == backs[i]) {
                blockNum[fronts[i]] = 0;
            }
        }
        for (int i = 0; i < nLen; i++) {
            if (blockNum.count(fronts[i]) == 0) {
                minBack = min(minBack, fronts[i]);
            }
            if (blockNum.count(backs[i]) == 0) {
                minBack = min(minBack, backs[i]);
            }
        }
        if (minBack == 100000) {
            return 0;
        }
        return minBack;
    }


};
// @lc code=end


/*
@golang

func flipgame(fronts []int, backs []int) int {
	minBack := 100000
	nLen := len(fronts)
	blockNum := make(map[int]struct{})
	for i := 0; i < nLen; i++ {
		if fronts[i] == backs[i] {
			blockNum[fronts[i]] = struct{}{}
		}
	}
	for i := 0; i < nLen; i++ {
		if _, ok := blockNum[fronts[i]]; !ok {
			minBack = min(minBack, fronts[i])
		}
		if _, ok := blockNum[backs[i]]; !ok {
			minBack = min(minBack, backs[i])
		}
	}
	if minBack == 100000 {
		return 0
	}
	return minBack

}


*/

/*
Wrong Answer
105/169 cases passed (N/A)
Testcase
[1,1]
[1,2]
Answer
0
Expected Answer
2


题意理解错误，不是翻转一次，而是翻转多次
解答错误
140 / 169 个通过的测试用例
官方题解
输入
fronts =
[1,1]
backs =
[2,2]
添加到测试用例
输出
2
预期结果
1
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
