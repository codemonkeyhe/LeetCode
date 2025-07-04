/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-04
 * @tag  trie, dfs
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
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode.cn/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (50.06%)
 * Likes:    619
 * Dislikes: 0
 * Total Accepted:    109.8K
 * Total Submissions: 215.1K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
 * 实现词典类 WordDictionary ：
 * WordDictionary() 初始化词典对象
 * void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
 * bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些
 * '.' ，每个 . 都可以表示任何一个字母。
 *
 *
 *
 *
 * 示例：
 * 输入：
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * 输出：
 * [null,null,null,null,false,true,true,true]
 *
 * 解释：
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // 返回 False
 * wordDictionary.search("bad"); // 返回 True
 * wordDictionary.search(".ad"); // 返回 True
 * wordDictionary.search("b.."); // 返回 True
 *
 *
 *
 *
 * 提示：
 * 1 <= word.length <= 25
 * addWord 中的 word 由小写英文字母组成
 * search 中的 word 由 '.' 或小写英文字母组成
 * 最多调用 10^4 次 addWord 和 search
 *
 *
 */

// @lc code=start

class TrieNode {
public:
    TrieNode() {
        child = vector<TrieNode*>(26, NULL);
        isEnd = false;
    }

    vector<TrieNode*> child;
    bool isEnd;
};


class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = trie;
        for (auto& ch: word) {
            int idx = ch - 'a';
            if (cur->child[idx] == NULL) {
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }

    bool pureSearch(string& word) {
        TrieNode* cur = trie;
        for (auto& ch: word) {
            int idx = ch - 'a';
            if (cur->child[idx] == NULL) {
                return false;
            }
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }

    bool searchDfsV1(TrieNode* trie, string word) {
        if (word == "") {
            return trie->isEnd;
        }
        TrieNode* cur = trie;
        for (int i = 0; i < word.size(); i++) {
            char& ch = word[i];
            if (ch != '.') {
                int idx = ch - 'a';
                if (cur->child[idx] == NULL) {
                    return false;
                }
                cur = cur->child[idx];
                return searchDfsV1(cur, word.substr(i+1));
            }
            // ch == '.'
            bool sonRes = false;
            string sonStr = word.substr(i+1); // to the end
            for (auto& son : cur->child) {
                if (son == NULL) {
                    continue;
                }
                sonRes = searchDfsV1(son, sonStr);
                if (sonRes == true) {
                    return true;
                }
            }
            return false;
        }
        return false;
    }

    bool searchDfs(TrieNode* trie, string& word, int pos) {
        if (pos >= word.size()) {
            return trie->isEnd;
        }
        char& ch = word[pos];
        if (ch != '.') {
            int idx = ch - 'a';
            if (trie->child[idx] == NULL) {
                return false;
            }
            return searchDfs(trie->child[idx], word, pos + 1);
        }

        // ch == '.'
        for (auto& son : trie->child) {
            if (son == NULL) {
                continue;
            }
            if(searchDfs(son, word, pos + 1)) {
                return true;
            }
        }
        return false;
    }

    bool search(string word) {
        if (word.find(".", 0) == string::npos)  { // not exist .
            return pureSearch(word);
        }
        return searchDfs(trie, word, 0);
    }


    TrieNode* trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
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


