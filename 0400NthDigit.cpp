/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-12
 * @tag  math,binarySearch?
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
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode.cn/problems/nth-digit/description/
 *
 * algorithms
 * Medium (45.56%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    69.1K
 * Total Submissions: 151.4K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n  位上的数字。
 *
 *
 *
 * 示例 1：
 * 输入：n = 3
 * 输出：3
 *
 *
 * 示例 2：
 * 输入：n = 11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        int width = 1;
        long long start = 1;
        long long posCnt = 9;
        long long totalCnt = 9;
        while (n > totalCnt) {
            width++;
            start = start * 10;
            posCnt = 9 * start * width;
            totalCnt += posCnt;
        }
        // cout << "width=" << width << " start=" << start << " posCnt=" <<
        // posCnt << endl;
        totalCnt = totalCnt - posCnt + 1;
        int dis = n - totalCnt;
        int numDis = dis / width;
        int orderL = dis % width;    // start from 0 ,  leftNum is 0
        int orderR = width - orderL;  // start from 1, rightNum is 1
        int num = start + numDis;
        // cout << "dis=" << dis << " numDis=" << numDis << " digPos="  <<
        // digPos  << " start=" << start  << " num=" << num << endl;

        int cur = -1;
        while (num > 0) {
            cur = num % 10;
            num = num / 10;
            orderR--;
            if (orderR == 0) {
                break;
            }
        }
        return cur;
    }
};
// @lc code=end

/*

ErrorThought
x 为数字
f(x)为数字第一个数的位置

例如 x=10 f(x)=10
x=11  f(x)=12  , 11的第一个1位置是12，第二个1位置是13
x越大，f(x)越大，具有单调性
现在是已知f(x)，求X的某个数字

blueArea: [intMIN, left]  定义： f(x) < n
redArea: [right, intMAX]  定义： f(x) >= n
Anwer  返回 left，然后再加一定偏移量，是的f(x) == n


https://leetcode.cn/problems/nth-digit/solutions/2362054/400-di-n-wei-shu-zi-qing-xi-tu-jie-by-jy-sz5y/?source=vscode



1 先确定位数
width   range    pos     posCnt
1      1-9        1-9     9*1=9
2      10-99    100-189   90*2=180
3      100-999    190-2889   900*3=2700
4     1000-9999  2890-38889      9000*4=36000

2 再确定数字
例如pos=198 可以确定 width=3, startNum=100
100之前已经有 9+180=189个数字了，说明 100的1是第190个数字
198-189-1=8
width=3
8/width=8/3 = 2 说明是从100开始的第2个数字，就是102
，即startNum+(n-totalPosCnt)/3

3 最后确定数字的某个位置的数
 100的1是第190个数字
 100的0是第191个数字
 100的第2个0是第192个数字

 100 - [190 191 192]
 101 - [193 194 195]
 102 - [196 197 198]

确定数字是102后
198-190=8
8%3=2
从102开始第2个数字  即2

demo
998 = [2884, 2885, 2886]

pos2885=9
(2885-190)/3= 898
(2885-190)%3=1    即998的9


width=3
pos=1
num=998

998%10=8
998/10=99

998%100=98
998/100=9

98%10=8
98/10=9


width=4
10*(width-1)=1000

1923
left1-num
1923/1000=1
1923%1000=923

left2-num
923/100=9
923%100=23

left3-num
23/10=2
23%10=3

left4-num
3/1=3
3%1=0


1023
left1-num
1023/1000=1
1023%1000=23  //zeroisMissing

left2-num-wrong
23/100=9
23%100=23

1023
left1-num
1023/1000%10=1

left2-num
1023/100%10=0


left3-num
1023/10%10=2


left4-num
1023/1%10=3





*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


