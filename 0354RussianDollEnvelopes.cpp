/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-14
 * @tag dynamicProgramming,binarySearch+greedy
 * @similar 72, 300, 354, 1143
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 *
 * https://leetcode.cn/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (35.80%)
 * Likes:    1105
 * Dislikes: 0
 * Total Accepted:    128K
 * Total Submissions: 365.2K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 *
 * 注意：不允许旋转信封。
 *
 * 示例 1：
 * 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出：3
 * 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 *
 * 示例 2：
 * 输入：envelopes = [[1,1],[1,1],[1,1]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= envelopes.length <= 10^5
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:

    // strict weak order if a[0] == b[0] ,must return false
    static bool cmpFnErr(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    static bool cmpFn(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        }
        if ((a[0] == b[0]) && (a[1] < b[1])) {
            return true;
        }
        return false;
    }


    // h降序 为了降维，砍掉w
    static bool cmpFn2(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        }
        if ((a[0] == b[0]) && (a[1] > b[1])) {
            return true;
        }
        return false;
    }


    // dp[i]表示以 env[i]结尾的 套娃最大长度
    int maxEnvelopesTLE85(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmpFn);
        vector<int> dp(len, 0);
        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            int maxV = 0;
            auto& curEnv = envelopes[i];
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] >= curEnv[0] ||
                    envelopes[j][1] >= curEnv[1]) {
                    continue;
                }
                maxV = max(maxV, dp[j]);
            }
            dp[i] = maxV + 1;
        }

        int maxRes = *max_element(dp.begin(), dp.end());
        return maxRes;
    }



    // d[i]表示长度为 i+1的LIS的末尾的最小值, 只关注H，W已经降维忽略了
    // answer = d.size()
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmpFn2);

        vector<int> d;
        for (int i = 0; i < len; i++) {
            int& curH = envelopes[i][1];
            int idx = lower_bound(d.begin(), d.end(), curH) - d.begin();
            if (idx == d.size()) {
                d.push_back(curH);
            } else {
                d[idx] = curH;
            }
        }
        return d.size();
    }

};
// @lc code=end


/*
Time Limit Exceeded
85/87 cases passed (N/A)
Testcase
[[1,1],[2,2],[3,3],[4,4],[5,5],[6,6],[7,7],[8,8],[9,9],[10,10],[11,11],[12,12],[13,13],[14,14],... 1367791 more character
Expected Answer
100000


DP的另外一种思路， h降序
官解一样超时
因此，我们必须要保证对于每一种 w 值，我们最多只能选择 1 个信封。

我们可以将 h 值作为排序的第二关键字进行降序排序，这样一来，对于每一种 w 值，其对应的信封在排序后的数组中是按照 h 值递减的顺序出现的，那么这些 h 值不可能组成长度超过 1 的严格递增的序列，这就从根本上杜绝了错误的出现。

作者：力扣官方题解
链接：https://leetcode.cn/problems/russian-doll-envelopes/solutions/633231/e-luo-si-tao-wa-xin-feng-wen-ti-by-leetc-wj68/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


