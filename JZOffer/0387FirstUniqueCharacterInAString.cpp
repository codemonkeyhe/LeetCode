/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2022-06-26
 * @tag
 * @similar
 */

/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
Note: You may assume the string contains only lowercase English letters.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int dic[128] = {0};
        for (int i = 0; i < s.size(); i++) {
            char v = s[i];
            dic[int(v)] += 1;
        }

        for (int i = 0; i < s.size(); i++) {
            char v = s[i];
            if (dic[int(v)] == 1) {
                return i;
            }
        }
        return -1;
    }

};



int firstUniqChar(char * s){

}

int main() {
    Solution s;
    string i1 = "aabb";
    auto res = s.firstUniqChar(i1);
    cout << res << endl;
}


/*
Tips
M1 ???
Runtime: 23 ms, faster than 91.55% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.6 MB, less than 70.49% of C++ online submissions for First Unique Character in a String.



M2

*/


