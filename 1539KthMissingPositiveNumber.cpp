/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-11
 * @tag  binarySearch,
 * @similar  34 2089
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 *
 * https://leetcode.cn/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (54.30%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    53.9K
 * Total Submissions: 98.1K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * 给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。
 *
 * 请你找到这个数组里第 k 个缺失的正整数。
 *
 *
 *
 * 示例 1：
 * 输入：arr = [2,3,4,7,11], k = 5
 * 输出：9
 * 解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
 *
 *
 * 示例 2：
 * 输入：arr = [1,2,3,4], k = 2
 * 输出：6
 * 解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
 *
 *
 *
 *
 * 提示：
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * 对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j] 
 *
 *
 *
 *
 * 进阶：
 * 你可以设计一个时间复杂度小于 O(n) 的算法解决此问题吗？
 *
 */

// @lc code=start
class Solution {
public:
    int findKthPositiveUgly(vector<int>& arr, int k) {
        if (arr.size() == 1) {
            if (arr[0] > k) {
                return k;
            }
            return k + 1;
        }
        int misCnt = 0;
        misCnt += arr[0] - 1;
        if (misCnt >= k) {
            return k;
        }
        int res = -1;
        for (int i = 1; i < arr.size(); i++) {
            while (i < arr.size() && (arr[i] == (arr[i-1] + 1))) {
                i++;
            }
            if (i == arr.size()) {
                break;
            }
            int mis= (arr[i] - arr[i-1] - 1);
            if ((misCnt + mis) < k) {
                misCnt+= mis;
                continue;
            }
            res = arr[i - 1] + (k - misCnt);
            break;
        }
        if (res == -1) { // means asc
            return arr.back() + (k - misCnt);
        }
        return res;
    }


    int findKthPositiveSlow(vector<int>& arr, int k) {
        unordered_set<int> dup(arr.begin(), arr.end());
        int i = 1;
        for (; i < 3003; i++ ) {
            if (dup.count(i)) {
                continue;
            }
            k--;
            if (k == 0) {
                break;
            }
        }
        return i;
    }


    int findKthPositiveM1(vector<int>& arr, int k) {
        int j = 0;
        int i = 1;
        for (; i < 3003; i++ ) {
            if (j < arr.size() && (arr[j] == i))  {
                j++;
                continue;
            }
            k--;
            if (k == 0) {
                break;
            }
        }
        return i;
    }



/*
idx 0 1 2 3 4
arr 2 3 4 7 11
规律： arr[idx] -  idx - 1 为到arr[idx]为止的missCnt
对missCnt进行二分，使得
arr[i-1].MissCnt  <= K < arr[i].MissCnt
则k =   arr[i-1] + (k- arr[i-1].MissCnt)

blueArea: [0 left]:  missCnt <k
redArea: [right, END]  missCnt >= k
Answer=  right

x为下标
f(x)= arr[x]-x+1; 为missCnt
x越大， f(x)越大

*/
    int findKthPositive(vector<int>& arr, int k) {
        int left = -1;
        int right = arr.size();
        while (left + 1 < right) { //开区间非空(left, right)
            int mid = left + ((right-left) >> 1);
            //cout << "left=" << left << " right=" << right << " mid=" << mid << endl;
            if (isBlue(arr, mid, k)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        // f(right) >= k
        // f(left) < k
        if (left == -1) {
            return k;
        }
        int missCnt = arr[left] - left - 1;
        return arr[left] + (k - missCnt);
    }

    bool isBlue(vector<int>& arr, int mid, int k) {
        int missCnt = arr[mid] - mid - 1;
        if (missCnt < k) {
            return true;
        }
        return false;
    }

};
// @lc code=end

/*
Runtime Error
1/87 cases passed (N/A)

Testcase
[1,2,3,4]
2
Expected Answer
6


Wrong Answer
12/87 cases passed (N/A)
Testcase
[2]
1
Answer
3
Expected Answer
1

Wrong Answer
14/87 cases passed (N/A)
Testcase
[1,3]
1
Answer
1
Expected Answer
2


Wrong Answer
67/87 cases passed (N/A)
Testcase
[3,10]
2
Answer
3
Expected Answer
2


Wrong Answer
70/87 cases passed (N/A)
Testcase
[3,10]
2
Answer
3
Expected Answer
2


Runtime Error
3/87 cases passed (N/A)
Testcase
[2]
1
Expected Answer
1

left=-1
right=0
left+1 < right 不满足

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


