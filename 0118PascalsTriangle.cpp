/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-07
 */

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's
triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above
it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {
            return res;
        }
        for (int i = 0; i < numRows; ++i) {
            vector<int> rowi(i + 1, 0);
            rowi[0] = 1;
            rowi[i] = 1;
            for (int j = 1; j < i; ++j) {
                rowi[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(rowi);
        }
        return res;
    }
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int*));
    int** res = (int**)malloc(numRows * sizeof(int*));
    if (numRows == 0) {
        return res;
    }
    for (int i = 0; i < numRows; ++i) {
        int* rowi = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        rowi[0] = 1;
        rowi[i] = 1;
        for (int j = 1; j < i; ++j) {
            rowi[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res[i] = rowi;
    }
    return res;
}

int main() {
    int numRows = 5;
    int returnS;
    int *cs;
    auto result = generate(numRows, &returnS, &cs);
    for (int i = 0; i < returnS; ++i) {
        for (int j = 0; j< cs[i]; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);


    Solution s;
    auto res = s.generate(numRows);
    for (size_t i = 0; i < res.size(); i++) {
        const auto& rowi = res[i];
        for (size_t j = 0; j < rowi.size(); j++) {
            cout << rowi[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
https://leetcode.com/problems/pascals-triangle/discuss/38262/Question-about-the-last-two-parameters-in-C
Dears,

I have a question about the method signature of C:

int** generate(int numRows, int** columnSizes, int* returnSize)
Q1: The second parameter stores the number of columns in each row, is that
right? If so, why should it be two-dimensional instead of one-dimensional? I
think that one-dimension is enough?

Q2: As for the third parameter, it simply stores the number of rows, which is
exactly the same as the first parameter. Then, why we need the value that seems
like a duplicated information?

Thanks for your time and it would be grate to hear from you.


February 16, 2016 8:04 PM

Q1: Yes. This is because the pointer int * is passed in using a pointer int **
so it allows you to allocate a 1D array like this in your function:

*columnSizes = (int *) malloc(sizeof(int) * col_size);
If columnSizes was passed in using int *, then if you attempt to assign the
reference to 1D array like this:

columnSizes = (int *) malloc(sizeof(int) * col_size);
You are assigning the reference to the copy of the pointer being passed in, and
therefore the caller won't know about the 1D array you allocated.

Q2: Yes for this question it is duplicated information. This is due to the
design such that it is generic and work for all other cases. I will work on
removing this duplicate parameter. Thanks for pointing it out.

UPDATE:
I have removed the duplicate third parameter. Please click the refresh button
just above the code editor to get the updated default code definition.


*/
