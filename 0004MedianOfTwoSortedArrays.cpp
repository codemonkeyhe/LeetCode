/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-15
 * @tag  binarySearch
 * @similar
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (42.25%)
 * Likes:    7567
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
public:
    //Your runtime beats 11.01 % of cpp submissions
    // merge first, then find  medianNum
    double findMedianSortedArraysM1(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1+len2;
        vector<int> data(total, 0);
        int i = 0, j = 0, k = 0;
        while(i < len1 && j < len2) {
            if (nums1[i] <= nums2[j]) {
                data[k++] = nums1[i++];
            } else {
                data[k++] = nums2[j++];
            }
        }
        while(i < len1) {
            data[k++] = nums1[i++];
        }
        while(j < len2) {
            data[k++] = nums2[j++];
        }
        int mid = total/2;
        if (total%2) {
            return data[mid];
        }
        return ((data[mid-1]+data[mid])/2.0f);
    }

    // M1V2
    double findMedianSortedArraysM1v2(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1+len2;
        vector<int> data(total, 0);
        int i = 0, j = 0, k = 0;
        while(i < len1 || j < len2) {
            int v1 = i < len1 ? nums1[i] : INT_MAX;
            int v2 = j < len2 ? nums2[j] : INT_MAX;
            if (v1 <= v2) {
                data[k++] = v1;
                i++;
            } else {
                data[k++] = v2;
                j++;
            }
        }
        int mid = total/2;
        if (total%2) {
            return data[mid];
        }
        return ((data[mid-1]+data[mid])/2.0f);
    }

    // M1V3
    double findMedianSortedArraysM1v3(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1+len2;
        vector<int> data(total, 0);
        int i = 0, j = 0, k = 0;
        while (k < total) {
            if (i < len1 && (j >= len2 || nums1[i] <= nums2[j])) {
                data[k++] = nums1[i++];
            } else {
                data[k++] = nums2[j++];
            }
        }
        int mid = total/2;
        if (total%2) {
            return data[mid];
        }
        return ((data[mid-1]+data[mid])/2.0f);
    }

    // Your runtime beats 19.24 % of cpp submissions
    // use TwoPointers to simulate merge process, find the kth small num
    double findMedianSortedArraysM2Ugly(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1+len2;
        int mid = (total + 1) / 2;
        int n1 = -1;
        int n2 = -1;
        int i = 0, j = 0, k = 0;
        while(i < len1 && j < len2) {
            if (nums1[i] <= nums2[j]) {
                k++;
                if (k == mid) {
                    n1 = nums1[i];
                }
                i++;
            } else {
                k++;
                if (k == mid) {
                    n1 = nums2[j];
                }
                j++;
            }
            if (k == mid && (i < len1) && (j < len2)) {
                n2 = min(nums1[i], nums2[j]);
                break;
            }
        }
        if (n2 != -1) {
            if (total % 2) {
                return n1;
            }
            return (n1 + n2) / 2.0f;
        }

        while(i < len1) {
            k++;
            if (k == mid) {
                n1 = nums1[i];
            } else if (k == mid+1) {
                n2 = nums1[i];
                break;
            }
            i++;
        }
        while(j < len2) {
            k++;
            if (k == mid) {
                n1 = nums2[j];
            } else if (k == mid+1) {
                n2 = nums2[j];
                break;
            }
            j++;
        }
        if (total%2) {
            return n1;
        }
        return (n1+n2)/2.0f;
    }

    /* 1 2 3 4 5 6  */
    // M2V2
    // Your runtime beats 29.67 % of cpp submissions
    double findMedianSortedArraysM2V2(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1+len2;
        // if total%2==1 , mid = (total+1)/2; else need  mid and mid+1
        int mid = (total + 1) / 2;
        int n1 = -1;
        int n2 = -1;
        int i = 0, j = 0, k = 0;
        while (i < len1 || j < len2) {
            int v1 = i < len1 ? nums1[i] : INT_MAX;
            int v2 = j < len2 ? nums2[j] : INT_MAX;
            if (v1 <= v2) {
                n2 = v1;
                i++;
            } else {
                n2 = v2;
                j++;
            }
            k++; // 第k大
            if (k >= mid+1) {
                break;
            }
            n1 = n2;
        }
        if (total%2) {
            return n1;
        }
        return (n1+n2)/2.0f;
    }

    //M3 折半淘汰
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        // if total%2==1 , mid = (total+1)/2; else need  mid and mid+1
        int mid = (total + 1) / 2;
        if (total%2) {
            return getKthSmallV2(nums1, 0,  nums2, 0, mid);
        }
        double res =
            getKthSmallV2(nums1, 0, nums2, 0, mid) + getKthSmallV2(nums1, 0, nums2,0, mid+1);
        return res / 2.0f;
    }


    // get nums1[i..X] nums2[j..X] the kth small
    // data[0]是第1小， data[1]是第2小，因此 k=idx+1，第k小的为data[k-1]
    // 折半淘汰
    double getKthSmall(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        int mid = k/2;
        if (i == nums1.size()) {
            return nums2[j+k-1];
        }
        if (j == nums2.size()) {
            return nums1[i+k-1];
        }
        if (k==1) {
            return min(nums1[i], nums2[j]);
        }

        int k1 = min(i+mid-1, int(nums1.size()-1));
        int k2 = min(j+mid-1, int(nums2.size()-1));

        if (nums1[k1] <= nums2[k2]) { // skip nums1[i..k1]
            return getKthSmall(nums1, k1 + 1, nums2, j, k - k1 + i - 1);
        } else { // skip nums2[j..k2]
            return getKthSmall(nums1, i, nums2, k2+1, k - k2 + j - 1);
        }
    }


    // 非递归版本
    double getKthSmallV2(vector<int> &nums1, int ii, vector<int> &nums2, int jj, int k) {
        int want = k;
        int i = ii;
        int j = jj;
        while (i < nums1.size() && j < nums2.size() && want > 1) {
            int mid = want / 2; //第mid大，mid>=1
            int k1 = min(i + mid - 1, int(nums1.size() - 1));
            int k2 = min(j + mid - 1, int(nums2.size() - 1));
            if (nums1[k1] <= nums2[k2]) { // skip nums1[i..k1]
                want = want - (k1 - i + 1);
                i = k1 + 1;
                // return getKthSmall(nums1, k1 + 1, nums2, j, k - k1 + i - 1);
            } else { // skip nums2[j..k2]
                want = want - (k2 - j + 1);
                j = k2 + 1;
                // return getKthSmall(nums1, i, nums2, k2 + 1, k - k2 + j - 1);
            }
        }
        if (i >= nums1.size()) {
            return nums2[j + want - 1];
        }
        if (j >= nums2.size()) {
            return nums1[i + want - 1];
        }
        if (want == 1) {
            return min(nums1[i], nums2[j]);
        }

        return -123.0f;
    }
};
// @lc code=end

/*
Wrong Answer
1/2096 cases passed (N/A)
Testcase
[1,2]
[3,4]
Answer
0.50000
Expected Answer
2.5

Runtime Error
3/2096 cases passed (N/A)
Testcase
[]
[1]
Expected Answer
1.00000

Wrong Answer
2090/2096 cases passed (N/A)
Testcase
[]
[1]
Answer
-1.00000
Expected Answer
1.0

Wrong Answer
118/2096 cases passed (N/A)
Testcase
[1,2]
[3,4]
Answer
2.00000
Expected Answer
2.5


解答错误
2060 / 2096 个通过的测试用例

官方题解
输入
nums1 =
[1,2,3,4,5]
nums2 =
[6,7,8,9,10,11,12,13,14,15,16,17]

添加到测试用例
标准输出
 i = 0 j=0 k=9 mid=4
 i = 4 j=0 k=5 mid=2
 i = 5 j=0 k=3 mid=1
输出
8.00000
预期结果
9.0

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


