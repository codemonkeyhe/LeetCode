/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-18
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.96%)
 * Likes:    1873
 * Dislikes: 0
 * Total Accepted:    685.9K
 * Total Submissions: 1M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 *
 *
 *
 * 示例 1:
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 *
 * 示例 3:
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > key2list;
        for (int i = 0; i < strs.size(); i++)  {
            auto key = getKeyV2(strs[i]);
           //cout << "i=" << i << " key=" << key << endl;
            key2list[key].push_back(strs[i]);
        }

        for (auto it = key2list.begin(); it != key2list.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }

    // 存储字母然后加次数
    string getKey(string& str) {
        int arr[27] = {0};
        for (int i = 0; i < str.size(); i++) {
            char& c = str[i];
            int val = c-'a'; //0~27
            arr[val] += 1;
        }
        string total = "";
        for (int i = 0; i < 27; i++) {
            int cnt = arr[i];
            if (cnt > 0) {
                int c = int('a') + i;
                total += char(c);
                total += std::to_string(cnt);
            }
        }
        return total;
    }


    //不存储字母，下标就代表了字母了，直接把次数当作字母来存
    //因为 0 <= strs[i].length <= 100，所以单个字母在字符串内最多重复100次，ASCII的范围是0～127，所以可以强行把次数转为字符
    string getKeyV2(string& str) {
        int arr[27] = {0};
        for (int i = 0; i < str.size(); i++) {
            char& c = str[i];
            int val = c-'a'; //0~27
            arr[val] += 1;
        }
        string total = "";
        for (int i = 0; i < 27; i++) {
            int cnt = arr[i];
            if (cnt > 0) {
              // error  total += std::to_string(cnt);
                total += (char)cnt;
            } else {
                total += '0';
            }
        }
        return total;
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


