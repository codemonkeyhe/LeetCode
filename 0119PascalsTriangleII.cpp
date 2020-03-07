/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-07
 */

/*
Given a non-negative index k where k < 33, return the kth index row of the
Pascal's triangle. Note that the row index starts from 0. In Pascal's triangle,
each number is the sum of the two numbers directly above it.
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Example:
Input: 3
Output: [1,3,3,1]

Follow up:
Could you optimize your algorithm to use only O(k) extra space?

*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        for (int i = 0; i <= rowIndex; ++i) {
            res[i] = 1;
            for (int j = i-1; j >=1; --j) {
                res[j] = res[j - 1] + res[j];
            }
        }
        return res;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* res = (int*)malloc((rowIndex + 1) * sizeof(int));
    *returnSize =  rowIndex+1;
    for (int i = 0; i <= rowIndex; ++i) {
        res[i] = 1;
        for (int j = i - 1; j >= 1; --j) {
            res[j] = res[j - 1] + res[j];
        }
    }
    return res;
}

int main() {
    int ri = 3;
    int rs = 0;
    auto result = getRow(ri, &rs);
    for (int i = 0; i < rs; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);

    Solution s;
    auto res = s.getRow(ri);
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

/*

*/
