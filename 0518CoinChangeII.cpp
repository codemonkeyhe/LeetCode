/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-16
 * @tag  dynamicProgramming
 * @similar  322
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode.cn/problems/coin-change-ii/description/
 *
 * algorithms
 * Medium (71.37%)
 * Likes:    1401
 * Dislikes: 0
 * Total Accepted:    404.9K
 * Total Submissions: 590.8K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 * 假设每一种面额的硬币有无限个。 
 * 题目数据保证结果符合 32 位带符号整数。
 *
 *
 *
 *
 * 示例 1：
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * 示例 2：
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 *
 *
 * 示例 3：
 * 输入：amount = 10, coins = [10]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * coins 中的所有值 互不相同
 * 0 <= amount <= 5000
 *
 *
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    unordered_map<int, int> cache;

    int change(int amount, vector<int>& coins) {
      //  vector<int> path;
       // changeBT(amount, coins, 0, path);
      //sort(coins.begin(), coins.end());
      // return changeNum(amount, coins, 0);
        //ErrorCase  vector<int> dp(amount+1, 0);
        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            int& curUse = coins[i];
            for (int j = curUse; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - curUse];
            }
        }
        return dp[amount];
    }

    // Time Limit Exceeded
    int changeNum(int amount, vector<int>& coins, int idx) {
        if (amount < 0) {
            return 0;
        }
        if (amount == 0) {
            // find one solution
            return 1;
        }
        int total = 0;
        for (int i = idx; i < coins.size(); i++) {
            int& val = coins[i];
            if (amount < val) {
                continue;
            }
            total += changeNum(amount - val, coins, i);
        }
        return total;
    }


    void changeBT(int amount, vector<int>& coins, int idx, vector<int>& path) {
        if (amount < 0) {
            return;
        }
        if (amount == 0) {
            res++;
            return;
        }
        for (int i = idx; i < coins.size(); i++) {
            int val = coins[i];
            if (amount < val) {
                continue;
            }
            path.push_back(val);
            changeBT(amount - val, coins, i, path);
            path.pop_back();
        }
    }
};
// @lc code=end

/*
BT时的去重
3 = 1 + 1 + 1
3 = 1+2
3 = 2+1

   3
1      2
1 2    1 2
1

path1=1+2
path2=2+1
重复
只取大于当前的值
需要对coins进行排序


Time Limit Exceeded
14/29 cases passed (N/A)
Testcase
500
[3,5,7,8,9,10,11]
Expected Answer
35502874


Runtime Error
28/29 cases passed (N/A)
Error
Line 16: Char 31: runtime error: signed integer overflow: 27131803 + 2123074792 cannot be represented in type 'value_type' (aka 'int') (solution.cpp)
Line 16: Char 31: runtime error: signed integer overflow: 27131803 + 2123074792 cannot be represented in type 'value_type' (aka 'int') (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:25:31
Testcase
4681
' +
  '[2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,342,344,346,348,350,352,354,356,358,360,362,364,366,368,370,372,374,376,378,380,382,384,386,388,390,392,394,396,398,400,402,404,406,408,410,412,414,416,418,420,422,424,426,428,430,432,434,436,438,440,442,444,446,448,450,452,454,456,458,460,462,464,466,468,470,472,474,476,478,480,482,484,486,488,490,492,494,496,498,500,502,504,506,508,510,512,514,516,518,520,522,524,526,528,530,532,534,536,538,540,542,544,546,548,550,552,554,556,558,560,562,564,566,568,570,572,574,576,578,580,582,584,586,588,780,936,1170,1560,2340,4680]
Expected Answer
0


500-3-7=490
500-10=490
下面的重复计算被剪去了，不存在
500-7-3=490


 示例 1：
 输入：amount = 5, coins = [1, 2, 5]
 输出：4
 解释：有四种方式可以凑成总金额：
 5=5
 5=2+2+1
 5=2+1+1+1
 5=1+1+1+1+1


dp[i] 定义 凑成金额i的组合数
因为coins=[1,2,5]
易得
dp[i]=dp[i-1]+dp[i-2]+dp[i-5]

dp[0]=1
dp[1]=1
dp[2]=dp[1]+dp[0]+dp[-3] = 1+1=2
2=1+1
2=2
dp[3]=dp[2]+dp[1]+dp[-2] = 2+1+0=3
3=1+1+1
3=2+1
3=1+2
2+1和1+2 重复，需要去重，因此，上面的DP公式不对，求的是排列数，需要去重才行

需要换种思路
amount = 5, coins = [1]
dp[1]=dp[2]=dp[3]=dp[4]=dp[5]=1
只有1种，5=1+1+1+1+1

amount = 5, coins = [1,2]
dp[0]=1
dp[1]=1
dp[2]=2
2=1+1
2=2

当coins=[1]时，dp[3]=1 表示 3=1+1+1这一种组合
现在多了一枚coin=2
则有dp[3]=旧dp[3]+dp[1] = 1+1=2
dp[1]表示dp[3]使用了一枚硬币2，贴在dp[1]所有组合情况数的后面
旧的dp[1]=1 即1+1
因此，这里相当于
dp[3]=旧dp[3]+dp[1](use coin=2)  = (3=1+1+1) +  (3=1+2) = 2
3=1+1+1
3=1+2

dp[4]=旧dp[4]+dp[2]=1+2=3
dp[4]=旧dp[4]+dp[2](use coin=2)= (4=1+1+1+1) + (4=1+1+2 4=2+2) =1+2=3
dp[2](use coin=2)相当于把2附加在dp[2]所有组合数的后面构成dp[4]
例如
2=1+1  (use coin=2)  相当于  4 =1+1+2
2=2  (use coin=2)A 相当于  4 = 2+2

dp[5]=旧dp[5]+dp[3](use coin=2)=1+2=3
3=1+1+1(use 2)
3=1+2 (use 2)



扩成2维
dp[3,2]表示使用前2枚硬币凑成数额3的组合数
dp[3,2]=dp[3,1]+dp[1, 2] = 1+1=2







*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


