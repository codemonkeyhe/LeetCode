/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-08
 * @tag binarySearch
 * @similar  34, 153
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 *
 * https://leetcode.cn/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (49.24%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    144.6K
 * Total Submissions: 286.1K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * 给你一个字符数组 letters，该数组按非递减顺序排序，以及一个字符 target。letters 里至少有两个不同的字符。
 *
 * 返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。
 *
 *
 *
 * 示例 1：
 * 输入: letters = ["c", "f", "j"]，target = "a"
 * 输出: "c"
 * 解释：letters 中字典上比 'a' 大的最小字符是 'c'。
 *
 * 示例 2:
 * 输入: letters = ["c","f","j"], target = "c"
 * 输出: "f"
 * 解释：letters 中字典顺序上大于 'c' 的最小字符是 'f'。
 *
 * 示例 3:
 * 输入: letters = ["x","x","y","y"], target = "z"
 * 输出: "x"
 * 解释：letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。
 *
 *
 *
 * 提示：
 * 2 <= letters.length <= 10^4
 * letters[i] 是一个小写字母
 * letters 按非递减顺序排序
 * letters 最少包含两个不同的字母
 * target 是一个小写字母
 *
 */

// @lc code=start
class Solution {
public:



    char nextGreatestLetterM1(vector<char>& letters, char target) {
        auto pos = upper_bound(letters.begin(), letters.end(), target);
        if (pos == letters.end())  {
            return letters[0];
        }
        return *pos;
    }

    // find first >
    /*
    // ThreeCase INT_MAX  INT_MIN  [1]
    INT_MAX
    left=Len, right=Len-1, left=right+1
    INT_MIN
    left=0, right = -1, left=right+1
    [1]   2
    left = 1, right=0   answer=letters[0]

    */
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int left = 0;
        int right = len - 1;
        // [left,  mid-1  mid mid+1   right]
        while(left <= right) { // left=right+1 or  right =left-1
            int mid = left + (right - left) /2;
            if (letters[mid] > target) {
                right = mid-1; // [mid, -1] is bigger, right can be answer
                // why not mid-1
                // as not sure letters[mid-1] is > or < or = target
                // but will enter deadloop
                // so right=mid-1, answer=right+1
            } else if (letters[mid] < target) {
                left = mid + 1; // means (0 ,mid] is lessThanTarget
            } else { // ==   same as <= , move left
                left = mid + 1;
            }
        }
        // left == right+1 ,返回left也行
        /*
        if (right + 1 < letters.size()) {
            return letters[right+1];
        }
        */

        if (left < letters.size()) {
            return letters[left];
        }
        return letters[0];
    }
};
// @lc code=end

/*
left_bound
1 2 2 2  3    target = 2
先找



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


