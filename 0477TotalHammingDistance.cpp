/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-02
 * @tag  bitManipulation
 * @similar   461, 477
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 *
 * https://leetcode.cn/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (60.64%)
 * Likes:    300
 * Dislikes: 0
 * Total Accepted:    48.8K
 * Total Submissions: 80.6K
 * Testcase Example:  '[4,14,2]'
 *
 * 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
 *
 * 给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和 。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [4,14,2]
 * 输出：6
 * 解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
 * 所以答案为：
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * 2 + 2 + 2 = 6
 *
 *
 * 示例 2：
 * 输入：nums = [4,14,4]
 * 输出：4
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^9
 * 给定输入的对应答案符合 32-bit 整数范围
 *
 *
 */

// @lc code=start
class Solution {
public:
    int totalHammingDistanceTLE38_46(vector<int>& nums) {
        int lenn = nums.size();
        int totalDis = 0;
        for (int i = 0; i < lenn; i++) {
            for (int j = i+1; j < lenn; j++) {
                totalDis += hammingDis(nums[i], nums[j]);
            }
        }
        return totalDis;
    }



/* ^
0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1

 */
    int hammingDis(int num1, int num2) {
        int diff = num1 ^ num2;
        int cnt = 0;
        while(diff > 0) {
            diff = diff & (diff - 1);
            cnt++;
        }
        return cnt;
    }

    /*
    lenn个位置，有oneCnt个1, 有lenn-oneCnt个0
    hammingDis 取决于 不同的bit位
    1 1 0 0 0 比如2个1， 3个0
    hammingDis = 3+3=6 , 2个3
    每个1和所有的0产生Distance=lenn-oneCnt
    这样的Dstance有oneCnt个,
    因此  totalDis = oneCnt*(lenn-oneCnt);
    */
    int totalHammingDistance(vector<int>& nums) {
        int lenn = nums.size();
        int totalDis = 0;
        for (int i = 0; i < 31; i++) {
            int oneCnt = 0;
            for (auto& num : nums) {
                oneCnt += (num >> i) & 0x1;
            }
            totalDis +=  oneCnt * (lenn-oneCnt);
        }
        return totalDis;
    }


};
// @lc code=end


/*
Time Limit Exceeded
38/46 cases passed (N/A)
Testcase
[355449945,540698239,511992416,882540761,193020298,391841516,140992641,988854646,304091189,997017310,848010207,806067557,43563801,470836936,672122735,602823925,212'... 88489 more character
Expected Answer
748454872

*/

/*
4 14 2

4  0100
14 1110
2  0010

   2220

   C个1 (n-C)个0  该bit位hanmingDis=C*(n-C)







*/



/*
@goland

func totalHammingDistance(nums []int) int {
	lenn := len(nums)
	totalDis := 0
	for i := 0; i < 31; i++ {
		oneCnt := 0
		for _, num := range nums {
			oneCnt += (num >> i) & 0x01
		}
		totalDis += oneCnt * (lenn - oneCnt)
	}
	return totalDis
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
