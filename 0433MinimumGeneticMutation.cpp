/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-26
 * @tag  bfs, hashTable
 * @similar  126, 127, 433, 2452
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 *
 * https://leetcode.cn/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (54.38%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    90.4K
 * Total Submissions: 165.3K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
 * 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
 *
 *
 * 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
 * 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
 * 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
 * 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
 *
 * 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
 *
 *
 *
 * 示例 1：
 * 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：start = "AACCGGTT", end = "AAACGGTA", bank =
 * ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * 输出：2
 *
 *
 * 示例 3：
 * 输入：start = "AAAAACCC", end = "AACCCCCC", bank =
 * ["AAAACCCC","AAACCCCC","AACCCCCC"]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 * start.length == 8
 * end.length == 8
 * 0 <= bank.length <= 10
 * bank[i].length == 8
 * start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> hs(bank.begin(), bank.end());
        if (hs.count(endGene) == 0) {
            return  -1;
        }
        queue<string> que;
        unordered_set<string> visited;
        que.push(startGene);
        visited.insert(startGene);
        int step = 1;
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                string cur = que.front();
                que.pop();
                auto gens = getSimilar(cur, hs);
                for (auto& gen: gens) {
                    if (gen == endGene) {
                        return step;
                    }
                    if (visited.count(gen)) {
                        continue;
                    }
                    visited.insert(gen);
                    que.push(gen);
                }
            }
            step++;
        }
        return -1;
    }

    const vector<char> chList = {'A', 'C', 'G', 'T'};

    vector<string> getSimilar(string& cur, unordered_set<string>& hs) {
        vector<string> res;
        for (auto& ch: cur) {
            char oldV = ch;
            for (auto& mu: chList) {
                if (oldV == mu) {
                    continue;
                }
                ch = mu;
                if (hs.count(cur))  {
                    res.push_back(cur);
                }
            }
            ch = oldV;
        }
        return res;
    }

};
// @lc code=end




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


