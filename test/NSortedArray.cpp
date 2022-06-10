/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-0
 * @tag
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> mergeTwo(vector<int> v1, vector<int> v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        vector<int> res(n1+n2, 0);
        int i = 0, j = 0;
        int k = 0;
        while (i < n1 && j < n2) {
            if (v1[i] < v2[j]) {
                res[k++] = v1[i++];
            } else {
                res[k++] = v2[j++];
            }
        }

        while (i < n1) {
            res[k++] = v1[i++];
        }

        while (j < n2) {
            res[k++] = v2[j++];
        }
        return res;
    }


    vector<int> mergeSort(vector< vector<int> > vv ) {
        vector<int> res;
        int n = vv.size();
        if (n == 0) {
            return res;
        }
        //int m = vv[0].size();
        //res = mergeTwo(vv[0], vv[1]);
        for(int i = 0; i < n; i++) {
            res = mergeTwo(res, vv[i]);
            printVector<int>(res, "debug");
        }
        return res;
    }

};




int main() {
    vector< vector<int> > vv  = {{1,3,5,7},{2,4,6,8},{1,5,9,10}};

    Solution s;
    auto res = s.mergeSort(vv);
    printVector<int>(res, "Final");
}


/*
   Tips
   M1

   M2

*/


