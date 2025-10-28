/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-28
 * @tag   math,hashMap
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
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode.cn/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (60.63%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 73.9K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
 *
 *
 *
 * 示例 1：
 * 输入：s = "owoztneoer"
 * 输出："012"
 *
 *
 * 示例 2：
 * 输入：s = "fviefuro"
 * 输出："45"
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 10^5
 * s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
 * 这些字符之一
 * s 保证是一个符合题目要求的字符串
 *
 *
 */

// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> chCnt;
        for (auto ch: s) {
            chCnt[ch]++;
        }
        //map<int, int> numCnt;
        vector<int> numCnt(10, 0);
        numCnt[0] = chCnt['z'];
        numCnt[2] = chCnt['w'];
        numCnt[4] = chCnt['u'];
        numCnt[6] = chCnt['x'];
        numCnt[8] = chCnt['g'];

        numCnt[5] = chCnt['f'] - numCnt[4];
        numCnt[3] = chCnt['h'] - numCnt[8];
        numCnt[7] = chCnt['s'] - numCnt[6];
        numCnt[9] = chCnt['i'] - numCnt[5] -numCnt[6] - numCnt[8];
        // BUG n 在9里面出现了2次
        // numCnt[1] = chCnt['n'] - numCnt[7] - numCnt[9];
        numCnt[1] = chCnt['o'] - numCnt[0] - numCnt[2] - numCnt[4];

        string res = "";
        int diff = int('0') - 0;
        //for (auto &[num, cnt] : numCnt) {
        for (int num = 0; num <= 9; num++) {
            int cnt = numCnt[num];
            char curNum = num + diff;
            for (int i = 0; i < cnt; i++) {
                res += curNum;
            }
        }
        return res;
    }
};
// @lc code=end


/*
Tricks
首先我们可以统计每个字母分别在哪些数字中出现：

字母	数字
e	0 1 3 5 7 8 9
f	4 5
g	8
h	3 8
i	5 6 8 9
n	1 7 9
o	0 1 2 4
r	0 3 4
s	6 7
t	2 3 8
u	4
v	5 7
w	2
x	6
z	0
可以发现，z, w, u, x, g 都只在一个数字中，即 0,2,4,6,8 中出现。因此我们可以使用一个哈希表统计每个字母出现的次数，那么 z, w, u, x, g 出现的次数，即分别为 0,2,4,6,8 出现的次数。

随后我们可以注意那些只在两个数字中出现的字符：

h 只在 3,8 中出现。由于我们已经知道了 8 出现的次数，因此可以计算出 3 出现的次数。

f 只在 4,5 中出现。由于我们已经知道了 4 出现的次数，因此可以计算出 5 出现的次数。

s 只在 6,7 中出现。由于我们已经知道了 6 出现的次数，因此可以计算出 7 出现的次数。

此时，我们还剩下 1 和 9 的出现次数没有求出：

o 只在 0,1,2,4 中出现，由于我们已经知道了 0,2,4 出现的次数，因此可以计算出 1 出现的次数。
最后的 9 就可以通过 n, i, e 中的任一字符计算得到了。这里推荐使用 i 进行计算，因为 n 在 9 中出现了 2 次，e 在 3 中出现了 2 次，容易在计算中遗漏。

作者：力扣官方题解
链接：https://leetcode.cn/problems/reconstruct-original-digits-from-english/solutions/1117147/cong-ying-wen-zhong-zhong-jian-shu-zi-by-9g1r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


Wrong Answer
12/24 cases passed (N/A)
Testcase
"nnei"
Answer
"19"
Expected Answer
"9"

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


/*
@Golang

func originalDigits(s string) string {
	chCnt := make(map[byte]int)
	for i:= 0; i < len(s); i++ {
        ch := s[i]
		chCnt[ch]++
	}

	numCnt := make([]int, 10, 10)
	numCnt[0] = chCnt['z']
	numCnt[2] = chCnt['w']
	numCnt[4] = chCnt['u']
	numCnt[6] = chCnt['x']
	numCnt[8] = chCnt['g']
	numCnt[5] = chCnt['f'] - numCnt[4]
	numCnt[3] = chCnt['h'] - numCnt[8]
	numCnt[7] = chCnt['s'] - numCnt[6]
	numCnt[9] = chCnt['i'] - numCnt[5] - numCnt[6] - numCnt[8]

	numCnt[1] = chCnt['o'] - numCnt[0] - numCnt[2] - numCnt[4]

	res := ""
	for num := 0; num <= 9; num++ {
		cnt := numCnt[num]
		curNum := string(num + '0')
		for i := 0; i < cnt; i++ {
			res += curNum
		}
	}
	return res
}

*/