/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-12
 */

/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return disFool(word1, 0, word1.size()-1, word2, 0, word2.size()-1);
    }

    // Time Limit Exceeded
    int disFool(const string &word1, int w1b, int w1e, const string &word2, int w2b, int w2e) {
        if (w1b > w1e) { // w1=""
            if (w2b>w2e) { // w2 = ""
                return 0;
            } else {
                return w2e-w2b +1;
            }
        }
        if (w2b>w2e) { // w2 = ""
            if (w1b > w1e) { // w1=""
                return 0;
            } else {
                return w1e-w1b +1;
            }
        }
        if (word1[w1b] == word2[w2b]) {
            return dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);
        }
        // remove  w1[0] // insert w1[0] before w2[0]
        int d1 = dis(word1, w1b + 1, w1e, word2, w2b, w2e);
        // remove  w2[0] // insert w2[0] before w1[0]
        int d2 = dis(word1, w1b, w1e, word2, w2b + 1, w2e);
        // repace  char  at w1[0] = w2[0]
        int d3 = dis(word1, w1b + 1, w1e, word2, w2b+1, w2e);
        return min(min(d1, d2), d3) +1;
    }

    int dis(const string &word1, int w1b, int w1e, const string &word2, int w2b,
            int w2e) {
        if (w1b > w1e) {      // w1=""
            if (w2b > w2e) {  // w2 = ""
                return 0;
            } else {
                return w2e - w2b + 1;
            }
        }
        if (w2b > w2e) {      // w2 = ""
            if (w1b > w1e) {  // w1=""
                return 0;
            } else {
                return w1e - w1b + 1;
            }
        }
        if (word1[w1b] == word2[w2b]) {
            return dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);
        }

        // repace  char  at w1[0] = w2[0]
        int d3 = dis(word1, w1b + 1, w1e, word2, w2b + 1, w2e);

        // remove  w1[0] // insert w1[0] before w2[0]
        // int d1 = dis(word1, w1b + 1, w1e, word2, w2b, w2e);
        int d1a = dis(word1, w1b + 2, w1e, word2, w2b, w2e);
        // int d1b = dis(word1, w1b + 1, w1e, word2, w2b+1, w2e);
        // d1b = d3
        int d1c = dis(word1, w1b + 2, w1e, word2, w2b + 1, w2e);
        int m = min(min(d1a, d1c), d3) +1;

        // remove  w2[0] // insert w2[0] before w1[0]
        // int d2 = dis(word1, w1b, w1e, word2, w2b + 1, w2e);
        // int d2a = dis(word1, w1b+1, w1e, word2, w2b + 1, w2e);
        // d2a = d3
        int d2b = dis(word1, w1b, w1e, word2, w2b + 2, w2e) ;
        int d2c = dis(word1, w1b + 1, w1e, word2, w2b + 2, w2e);
        int n = min(min(d2b, d2c), d3) +1;

        return min(min(m, n), d3) +1;
    }
};

int minDistance(char *word1, char *word2) {}

int main() {
    string w1 = "intention";
    string w2 = "execution";
    w1 = "horse";
     w2 = "ros";
   // w1 = "dinitrophenylhydrazine";
    //w2 = "acetylphenylhydrazine";
    Solution s;
    cout << s.minDistance(w1, w2) << endl;
    return 0;
}
