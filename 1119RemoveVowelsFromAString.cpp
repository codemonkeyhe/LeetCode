/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-06
 * @tag
 * @similar 345;
 */

/*
Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

Example 1:
Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Example 2:
Input: "aeiou"
Output: ""

Note:
S consists of lowercase English letters only.
1 <= S.length <= 1000

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
20 / 20 ???????
?????
????: 0 ms
????: 6.4 MB
*/
    string removeVowels(string S) {
        int i = 0;
        int j = 0;
        int n = S.size();
        while(j<n) {
            if (S[j]=='a' || S[j]=='e' || S[j]=='i' || S[j]=='o' || S[j]=='u') {
                j++;
            } else {
                S[i++] = S[j++];
            }
        }
        return S.substr(0, i);
    }

};

char * removeVowels(char * S){

}

int main() {

    Solution s;

    return 0;
}


