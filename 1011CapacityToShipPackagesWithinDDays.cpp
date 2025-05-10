/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-10
 * @tag binarySearch
 * @similar  875, 34, 744
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 *
 * https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (62.47%)
 * Likes:    654
 * Dislikes: 0
 * Total Accepted:    117.5K
 * Total Submissions: 186K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * 传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。
 *
 * 传送带上的第 i 个包裹的重量为
 * weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
 *
 * 返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力。
 *
 *
 *
 * 示例 1：
 * 输入：weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * 输出：15
 * 解释：
 * 船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
 * 第 1 天：1, 2, 3, 4, 5
 * 第 2 天：6, 7
 * 第 3 天：8
 * 第 4 天：9
 * 第 5 天：10
 *
 * 请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9),
 * (10) 是不允许的。
 *
 *
 * 示例 2：
 * 输入：weights = [3,2,2,4,1,4], days = 3
 * 输出：6
 * 解释：
 * 船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
 * 第 1 天：3, 2
 * 第 2 天：2, 4
 * 第 3 天：1, 4
 *
 *
 * 示例 3：
 * 输入：weights = [1,2,3,1,1], days = 4
 * 输出：3
 * 解释：
 * 第 1 天：1
 * 第 2 天：2
 * 第 3 天：3
 * 第 4 天：1, 1
 *
 *
 *
 *
 * 提示：
 * 1 <= days <= weights.length <= 5 * 10^4
 * 1 <= weights[i] <= 500
 *
 *
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minV = 0;
        int sumV = 0;
        for (auto val: weights) {
            minV = max(minV, val);
            sumV += val;
        }
        //cout << "minV=" << minV << " sumV=" << sumV << endl;
        int left = minV - 1;
        int right = sumV + 1;
        while(left+1 < right) { //开区间非空 (left, right)
            int mid = left + ((right - left) >> 1);
            if (isBlue(weights, days, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    bool isBlue(vector<int>& weights, int days, int mid) {
        int costDay = 0;
        for (int i = 0; i < weights.size(); i++) {
            int sum = 0;
            while(i < weights.size() && (sum + weights[i] <= mid)) {
                sum += weights[i];
                i++;
            }
            costDay++;
            i--;
        }
        if (costDay > days) {
            return true;
        }
        return false;
    }




};
// @lc code=end

/*
包裹不能分割
minCap = max(weights),最多需要 len(weights)天装完
maxCap = sum(weights)，只需要1天就可以装完了

令运载能力为x,f(x)为所需天数，x越大，f(x)越小
在满足f(x)<=days的情况下，求最小的X

blueArea [0, left]  f(x) > day
redArea [right, INT_MAX] f(x) <= day
return right


*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


