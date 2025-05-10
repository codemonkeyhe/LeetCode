/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-09
 * @tag binarySearch
 * @similar   34, 744
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 *
 * https://leetcode.cn/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (49.46%)
 * Likes:    688
 * Dislikes: 0
 * Total Accepted:    180.6K
 * Total Submissions: 361.1K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。
 * 珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k
 * 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 * 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
 *
 *
 *
 * 示例 1：
 * 输入：piles = [3,6,7,11], h = 8
 * 输出：4
 *
 *
 * 示例 2：
 * 输入：piles = [30,11,23,4,20], h = 5
 * 输出：30
 *
 *
 * 示例 3：
 * 输入：piles = [30,11,23,4,20], h = 6
 * 输出：23
 *
 *
 *
 *
 * 提示：
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isBlueUgly(vector<int>& piles, int h, int k) {
        //ErrorCase  int totalH = 0;
        long long totalH = 0;
        for (auto &v: piles) {
          //ErrorCase  totalH += ceil(v/k);
          totalH += ceil(v*1.0/k);
        }
        if (totalH > h) {
            return true;
        }
        return false;
    }

    bool isBlue(vector<int>& piles, int h, int k) {
        long long totalH = 0;
        for (auto &v: piles) {
            totalH += v / k + ((v % k) ? 1 : 0);
        }
        if (totalH > h) {
            return true;
        }
        return false;
    }

    // 开区间写法，必须left从0 开始，而不能从1开始，因为
    // 1的结果为未确定，不能提前染色，不能提前加入到区间
    int minEatingSpeedM1(vector<int>& piles, int h) {
        // ErrorCase: int minV = INT_MAX;
        int minV = 1;
        int maxV = INT_MIN;
        for (auto& val: piles) {
            maxV = max(maxV, val);
        }
        //Error Case int left = minV ;
         int left = minV - 1 ;
        int right = maxV + 1;

        while(left + 1 < right) { //开区间(left, right)
            int mid = left + ((right-left) >> 1);
            if (isBlue(piles, h, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }


    // 闭区间写法
    /*
    INT_MAX  right=maxV left=right+1 = maxV+1   ans = maxV
    INT_MIN  left=1 right=mid =left  deadpool , so right=mid -1 not mid

    */
    int minEatingSpeed(vector<int>& piles, int h) {
        // ErrorCase: int minV = INT_MAX;
        int minV = 1;
        int maxV = INT_MIN;
        for (auto& val: piles) {
            maxV = max(maxV, val);
        }
        //Error Case int left = minV ;
        int left = minV;
        int right = maxV;

        while(left <= right) { //闭区间非空[left, right]
            int mid = left + ((right-left) >> 1);
            if (isBlue(piles, h, mid)) { // means  mid>h ,so [0, left-1] > h
                left = mid + 1;
            } else { // means mid <=h  , so [right+1 , X]  <= h
                right = mid - 1;
            }
        }
        // EndLoop when left == right+1 ,  answer = right+1 = left
        return left;
       // return right + 1;
    }



};
// @lc code=end


/*
k means speed, f(k) means hourToEat, k is bigger, f(k) is smaller

BlueArea: [0, left]:   f(k)> h
RedArea [right, N): f(k) <= h
Answer = right

 * 示例 1：
 * 输入：piles = [3,6,7,11], h = 8
 * 输出：4

left=3 right=11  mid= 7  costH=5  < 8 means  speedDown  moveRight
left=3 right=7   mid= 5  costH=8  = 8 means  speedDown  moveRight
left=3 right=5   mid=4   costH=8 = 8  means  speedDown   moveRight
left=3 right=4   mid=3    costH=10 > 8 means speedUp   moveLeft
left=3 right=4   mid=3     needToStop  ans= 4


Wrong Answer
3/126 cases passed (N/A)
Testcase
[30,11,23,4,20]
5
Answer
12
Expected Answer
30


[30,11,23,4,20]

left=4-1 right=30  mid=17


Wrong Answer
10/126 cases passed (N/A)
Testcase
[312884470]
312884469
Answer
312884470
Expected Answer
2


Wrong Answer
124/126 cases passed (N/A)
Testcase
[312884470]
968709470
Answer
2
Expected Answer
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


