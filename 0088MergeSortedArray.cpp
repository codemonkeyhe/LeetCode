/**
 * @file 0088MergeSortedArray.cpp
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-06
 */

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m +
n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        nums1.resize(len);
        int i = m - 1;
        int j = n - 1;
        int k = len - 1;
        while (k >= 0) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
            if (j < 0) {
                break;
            }
            if (i < 0) {  // move rest nums2 to nums1
                do {
                    nums1[k--] = nums2[j--];
                } while (j >= 0 && k >= 0);
            }
        }
    }
};

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int len = m + n;
    int i = m - 1;
    int j = n - 1;
    int k = len - 1;
    while (k >= 0) {
        if (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        if (j < 0) {
            break;
        }
        if (i < 0) {
            do {
                nums1[k--] = nums2[j--];
            } while (k >= 0 && j >= 0);
        }
    }
}

int main() {
    const int m = 3;
    const int n = 3;
    int nums1[m + n] = {1, 2, 3, 0, 0, 0};
    int nums2[n] = {2, 5, 6};
    vector<int> n1(nums1, nums1 + m + n);
    vector<int> n2(nums2, nums2 + n);


    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    Solution s;
    s.merge(n1, m, n2, n);
    for (size_t i = 0; i < n1.size(); i++) {
        cout << n1[i] << " ";
    }
    cout << endl;
    return 0;
}
