/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-30
 * @tag trie
 * @similar 208, 211, 212
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode.cn/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (71.98%)
 * Likes:    1819
 * Dislikes: 0
 * Total Accepted:    445.2K
 * Total Submissions: 611.4K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Trie（发音类似 "try"）或者说 前缀树
 * 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。
 *
 * 请你实现 Trie 类：
 *
 *
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回
 * false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true
 * ；否则，返回 false 。
 *
 *
 *
 *
 * 示例：
 * 输入
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 输出
 * [null, null, true, false, true, null, true]
 *
 * 解释
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 *
 *
 *
 *
 * 提示：
 * 1 <= word.length, prefix.length <= 2000
 * word 和 prefix 仅由小写英文字母组成
 * insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
 *
 *
 */

// @lc code=start
class Trie {
public:
    vector<Trie*> childs;
    bool isEnd;

    Trie() {
        childs.resize(26, NULL);
        isEnd = false;
    }

    void insertError(string word) {
        Trie* last = NULL;
        // Error Case
        vector<Trie*>& chs = childs;
        for (auto& ch: word) {
            int idx = ch - 'a';
            if (chs[idx] == NULL) {
                chs[idx] = new Trie();
            }
            last = chs[idx];
            // 相当于 this.childs = this.childs[idx]->childs
            // 覆盖了根节点 引用相当于别名
            chs = chs[idx]->childs;
        }
        last->isEnd = true;
    }


    void insert(string word) {
        Trie* last = this;
        for (auto& ch: word) {
            int idx = ch - 'a';
            if (last->childs[idx] == NULL) {
                last->childs[idx] = new Trie();
            }
            last = last->childs[idx];
        }
        last->isEnd = true;
    }

    bool search(string word) {
        Trie* last = this;
        for (auto& ch: word) {
            int idx = ch - 'a';
            if (last->childs[idx] == NULL) {
                return false;
            }
            last = last->childs[idx];
        }
        return last->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* last = this;
        for (auto& ch: prefix) {
            int idx = ch - 'a';
            if (last->childs[idx] == NULL) {
                return false;
            }
            last = last->childs[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


