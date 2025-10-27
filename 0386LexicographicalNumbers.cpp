/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-27
 * @tag  dfs
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
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode.cn/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (74.56%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    98.6K
 * Total Submissions: 130.9K
 * Testcase Example:  '13'
 *
 * 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
 *
 * 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
 *
 *
 *
 * 示例 1：
 * 输入：n = 13
 * 输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
 *
 *
 * 示例 2：
 * 输入：n = 2
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 5 * 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> res;

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            dfs(i, n);
        }
        return res;
    }


    void dfs(int cur, int n) {
        if (cur > n) {
            return;
        }
        res.push_back(cur);
        for (int i = 0; i <= 9; i++) {
            dfs(cur * 10 + i, n);
        }
    }
};
// @lc code=end



/*
@golang

func lexicalOrder(n int) []int {
	res := make([]int, 0, n)
	for i := 1; i <= 9; i++ {
		dfs(i, n, &res)
	}
	return res
}

func dfs(cur int, n int, res *[]int) {
	if cur > n {
		return
	}
	*res = append(*res, cur)
	for i := 0; i <= 9; i++ {
		dfs(cur*10+i, n, res)
	}
}

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
