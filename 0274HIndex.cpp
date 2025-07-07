/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-05
 * @tag sort,countingSort
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
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 *
 * https://leetcode.cn/problems/h-index/description/
 *
 * algorithms
 * Medium (46.34%)
 * Likes:    477
 * Dislikes: 0
 * Total Accepted:    179K
 * Total Submissions: 386.8K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
 *
 * 根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h
 * 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。
 *
 *
 *
 * 示例 1：
 * 输入：citations = [3,0,6,1,5]
 * 输出：3
 * 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
 * 由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
 *
 * 示例 2：
 * 输入：citations = [1,3,1]
 * 输出：1
 *
 *
 *
 * 提示：
 * n == citations.length
 * 1 <= n <= 5000
 * 0 <= citations[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:

    int hIndexV1(vector<int>& citations) {
        CountingSortV2(citations);
        int i = citations.size() - 1;
        int k = 1;
        while(i >= 0) {
            if (citations[i] < k) {
                break;
            }
            k++;
            i--;
        }
        return k - 1;
    }

    int hIndexV2(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = citations.size() - 1;
        int k = 1;
        while(i >= 0 &&  (citations[i] >= k)) {
            k++;
            i--;
        }
        return k - 1;
    }

    // 非常混乱的逻辑
    int hIndexM2(vector<int>& citations) {
        int len = citations.size();
        vector<int> count(len+1, 0);
        for (auto& num: citations) {
            if (num >= len) {
                count[len]++;
            } else {
                count[num]++;
            }
        }
        int res = 0;
        for (int i = len-1; i >= 0; i--) {
            count[i] += count[i + 1];
        }
        int i = len;
        while (i >= 0 && (i >= count[i])) {
            // 有count[i]篇文章的引用次数为i，且i>=count[i]，所以h指数是count[i]
            res = count[i];
            i--;
        }
        // i < count[i]，比如i=0,count[i]=1000,有1000篇文章引用次数为0
        res = max(i, res);
        return res;
    }

    // M3 改写版
    int hIndexM3v2(vector<int>& citations) {
        int len = citations.size();
        vector<int> count(len+1, 0);
        for (auto& num: citations) {
            if (num >= len) {
                count[len]++;
            } else {
                count[num]++;
            }
        }
        int res = 0;
        for (int i = len-1; i >= 0; i--) { //后缀和
            count[i] += count[i + 1];
        }
        int i = len;
        while (i >= 0) {
            if (count[i] >= i) {
                return i;
            }
            i--;
        }
        return 0;
    }

    int hIndexM3(vector<int>& citations) {
        int len = citations.size();
        vector<int> count(len+1, 0);
        for (auto& num: citations) {
            if (num >= len) {
                count[len]++;
            } else {
                count[num]++;
            }
        }

        int sum = 0;
        // hindex最大只能是len，最小为1，从最大的开始
        int i = len;
        while (i >= 0) {
            sum += count[i];
            if (sum >= i) {
                // 有sum篇文章的引用次数大于等于i
                return i;
            }
            i--;
        }
        return 0;
    }

};
// @lc code=end


/*
Wrong Answer
74/83 cases passed (N/A)
Testcase
[1,1]
Answer
0
Expected Answer
1

Wrong Answer
75/83 cases passed (N/A)
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


