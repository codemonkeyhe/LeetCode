/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-14
 * @tag   slidingWindow
 * @similar  159
 */

/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string s, int k ) {
        if (s.empty()) return 0;
        unordered_map<char, int>  hm;
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        // [left, right]
        while(right < n) {
            hm[s[right]]++;
            while (hm.size() > k) { //开始收缩窗口左界
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

int lengthOfLongestSubstringKDistinct(char * s, int k){

}


int main() {
    Solution s;
}


/*
Tips
M1 等同于159 只不过把2改成了K

M2

*/


