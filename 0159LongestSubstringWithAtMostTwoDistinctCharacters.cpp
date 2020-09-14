/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-14
 * @tag  slidingWindow
 * @similar　3 340
 */

/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:
Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:
Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int>  hm;
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        // [left, right]
        while(right < n) {
            hm[s[right]]++;
            while (hm.size() > 2) { //开始收缩窗口左界
                char le = s[left];
                left++;
                hm[le]--;
                if (hm[le] == 0) {
                    hm.erase(le);
                }
            }
            int len = right - left + 1;
            if (len > maxLen) {
                maxLen = len;
            }
            right++;
        }
        return maxLen;
    }

};

int lengthOfLongestSubstringTwoDistinct(char * s){

}


int main() {
    Solution s;
}


/*
Tips
和0003类似

M1  slidingWindow + unordered_map字符计数
unordered_map<char, int>  hm;
char -> 每个字符出现的次数
当char次数为0时，则淘汰掉这个char

hm有2个作用
1是去重，保证数目为2
2是当数目>2时，通过缩减字符计数来淘汰字符

L   R
e c e b a
hm状态如下
e 2次
c 1
当R -> b时，需要淘汰，通过收缩左界L，同时减去hm里面的计数器，最终保持hm里面的数目为2
L-->L R
e c e b a
淘汰掉C后，hm状态如下
e 1
b 1


M2 slidingWindow + unordered_map字符最后的位置
unordered_map<char, int>  hm;
char -> 每个字符最后出现的位置
L     R
e c e b a
hm状态如下
e 0 -> 2
c 1
b 3
当R -> b时，需要淘汰，很明显应该淘汰c，因为c对于的下标最小
这个淘汰需要遍历当前的hm，这是官方做法，这样的话复杂度不是O(N)

用另外一个map维护最小的下标即可
0 e [当把hm[e]从0改成2时，对应的从map删除0->e，插入2->e,即维护hm的同时维护map]
1 c
2 e
3 b
4 a

*/


