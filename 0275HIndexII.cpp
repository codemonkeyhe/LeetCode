/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-07
 * @tag sort,binarySearch
 * @similar  274, 275
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 *
 * https://leetcode.cn/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (45.25%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    106.5K
 * Total Submissions: 235.4K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，citations 已经按照 升序排列
 * 。计算并返回该研究者的 h 指数。
 *
 * h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （n 篇论文中）至少 有 h
 * 篇论文分别被引用了至少 h 次。
 *
 * 请你设计并实现对数时间复杂度的算法解决此问题。
 *
 *
 *
 * 示例 1：
 * 输入：citations = [0,1,3,5,6]
 * 输出：3
 * 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
 * 由于研究者有3篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。
 *
 * 示例 2：
 * 输入：citations = [1,2,100]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 * n == citations.length
 * 1 <= n <= 10^5
 * 0 <= citations[i] <= 1000
 * citations 按 升序排列
 *
 *
 */

// @lc code=start
class Solution {
public:
    //开区间写法
    int hIndexV1(vector<int>& citations) {
        int len = citations.size();
        int left = -1;
        int right = len;
        while(left+1 < right) { //开区间非空
            int mid = left + ((right-left) >> 1);
            if (citations[mid] < (len - mid)) { // isBlue
                left = mid;
            } else {
                right = mid;
            }
        }
        //still work
        //return len - right;
        return len - left-1;
    }

    // 闭区间写法
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0;
        int right = len-1;
        while(left <= right) { //闭区间非空
            int mid = left + ((right-left) >> 1);
            if (citations[mid] < (len - mid)) { // isBlue
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return len - right - 1;
        //still work
        //return len - left;
    }

};
// @lc code=end

/*
len=5
i       0 1 2 3 4
ci      0 1 3 5 6
len-i   5 4 3 2 1

i=4 ci[4]=6 >= len-i = 1 意思是，有1篇文章的ci>=6 ,hindex=1
i=3 ci[3]=5 >= len-i = 2 意思是，有2篇文章的ci>=5, hindex=2
i=2 ci[2]=3 >= len-i = 3 意思是，有3篇文章的ci>=3 ,hindex=3
i=1 ci[1]=1 < len-i = 4 意思是，有4篇文章的ci>=3 ,hindex=1  [转折点]

i=k  ci[k]=XXX >= len-k 意思是 ，有len-k篇文章的引用次数>=XXX, 且这个XXX>=len-k，因此hindex=len-k
具有单调性，可以二分
hindex的最小值为1，最大值为ci.size();

需要找到一个k值，满足下面条件
当i=k ci[k]=XXX >= len-k，此时 hindex=len-k
并且满足
当i=k-1 ci[k-1]=YYY < len-k+1，此时 hindex=YYY < len-k+1 ，因为hindex取最大值，此时len-k+1不是答案，之前从len-1,len-2，一直到 len-k是答案，因此最大值就是len-k


left = -1
right = N
isBlue:  ci(i) < len-i
isRed:  ci(i) >= len-i
[intMin, left] 为蓝色
[right, intMax] 为红色,
当全部红蓝染色完毕时，有 left+1==right，且
ci[left]<len-left=len-right+1
ci[right] >= len-right
ans =  len-right;
因为 right=left+1
或者说 ans=len- (left+1) = len - left-1


闭区间
left = 0
right = N-1
isBlue:  ci(i) < len-i
isRed:  ci(i) >= len-i
[intMin, left) 为蓝色
(right, intMax] 为红色,
[left, right]为待染色区间

当全部红蓝染色完毕时，有 left==right+1，且
ci[left-1]<len-left+1
ci[right+1] >= len-right-1
ans =  len-right -1;
因为 right+1=lef
或者说 ans=len- (right+1) = len - left


Wrong Answer
21/83 cases passed (N/A)

Testcase
[1,2,100]

Answer
3
Expected Answer
2


Wrong Answer
37/83 cases passed (N/A)
Testcase
[0]
Answer
1
Expected Answer
0

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


