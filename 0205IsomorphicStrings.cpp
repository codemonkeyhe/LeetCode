/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-1
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
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode.cn/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (49.34%)
 * Likes:    711
 * Dislikes: 0
 * Total Accepted:    265.2K
 * Total Submissions: 537.8K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t ，判断它们是否是同构的。
 *
 * 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
 *
 * 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
 *
 *
 *
 * 示例 1:
 * 输入：s = "egg", t = "add"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：s = "foo", t = "bar"
 * 输出：false
 *
 * 示例 3：
 * 输入：s = "paper", t = "title"
 * 输出：true
 *
 *
 * 提示：
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s 和 t 由任意有效的 ASCII 字符组成
 *
 *
 */

// @lc code=start
class Solution {
public:
 bool isIsomorphic(string s, string t) {
     unordered_map<char, char> hm1;
     unordered_map<char, char> hm2;
     for (int i = 0; i < s.size(); i++) {
         char& c1 = s[i];
         char& c2 = t[i];
         auto it1 = hm1.find(c1);
         auto it2 = hm2.find(c2);
         if (it1 != hm1.end() && it1->second != c2) {
             return false;
         }
         if (it2 != hm2.end() && it2->second != c1) {
             return false;
         }
         hm1[c1] = c2;
         hm2[c2] = c1;
     }
     return true;
 }
};
// @lc code=end

/*
paple
title
 * 输出：true

 "paper"
"title"
 * 输出：true

"badc"
"baba"
输出  false



foo
bar
输出  false

s 中1个字符 对应 t中的2个字符， false
反之 也成立，
即 t中的1个字符，对应s中的2个字符，也是false

Case1 相同字符只能映射到同一个字符上
S  T
a  b
a  c
Case1 说明hashmap需要S的字符作为key


Case2 不同字符不能映射到同一个字符上
S  T
b  a
c  a

Case2 说明hashmap需要T的字符作为key

因此需要2个hashmap
hm1 存储 S到T的映射
key来自S  如果一个key对应2个V，就是false


hm2  依然存储 S到T的映射
只是key来自T  如果一个key对应2个V，就是false


能否只用1个hashmap?
不行
例如上面都用1个hashmap
<a, b>
<b, a>
<c, a>

则从key的角度出发，都是唯一的val对应，并且对于下面的特殊case，也不好支持


特殊case
S  T
p  t
a  i
p  t
e  l
r  e

存在下面映射，也成立
e -> l
r -> e

如果两个hashmap合并成一个，就会出现下面的情况，会误认为e对应两个元素，l和r，因此就会失败
<e, l>
<r, e>

<l, e>
<e, r>




*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


