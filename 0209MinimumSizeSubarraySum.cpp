/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-14
 * @tag  slidingWindow;
 * @similar
 */

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 16 ms, faster than 82.71% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.8 MB, less than 18.56% of C++ online submissions for Minimum Size Subarray Sum.
*/
    int minSubArrayLenM1(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while(left < n) {
            while (sum < s && right < n) {  // R move
                sum += nums[right];
                right++;
            }
            if (sum >= s) {
                //[left, right)
                int len = right - left;
                if (len < minLen) {
                    minLen = len;
                }
            }
            // when sum>=s or right == n ; L move
            sum -= nums[left];
            left++;
        }
        //BUG return minLen;
        return minLen==INT_MAX ? 0: minLen;
    }

/*
语法糖浓缩版
Runtime: 12 ms, faster than 96.77% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.7 MB, less than 49.48% of C++ online submissions for Minimum Size Subarray Sum.
*/
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while(left < n) {
            while (sum < s && right < n) {  // R move
                sum += nums[right++];
            }
            // sum>=s or right == n
            if (sum >= s) {
                //[left, right)
                minLen = min(minLen, right-left);
            }
            // when sum>=s or right == n ; L move
            sum -= nums[left++];
        }
        //BUG return minLen;
        return minLen==INT_MAX ? 0: minLen;
    }


/*
单层for循环
Runtime: 28 ms, faster than 20.77% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.7 MB, less than 49.48% of C++ online submissions for Minimum Size Subarray Sum.
*/
    int minSubArrayLenM3(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while(left < n) {
            if (sum < s && right < n) {  // R move
                sum += nums[right];
                right++;
            } else {
                sum -= nums[left];
                left++;
            }
            if (sum >= s) {
                //[left, right)
                minLen = min(minLen, right-left);
            }
        }
        //BUG return minLen;
        return minLen==INT_MAX ? 0: minLen;
    }

};

int minSubArrayLen(int s, int* nums, int numsSize){

}

/*
同类型题目
某一个大文件被拆成了N个小文件，每个小文件编号从0至N-1，相应大小分别记为S(i)。
给定磁盘空间为C，试实现一个函数从N个文件中连续选出若干个文件拷贝到磁盘中，使得磁盘剩余空间最小。
函数定义如下：
int maximumCopy(const std::vector<size_t>& s, size_t C, size_t &start_index, size_t &end_index);
函数返回值为剩余空间，如无解返回-1。
其中start_index, end_index为文件的编号。
如N=5，S = {1, 2, 3, 5, 4}，C = 7
结果为start_index = 0, end_index = 2, return = 1
本质上和  209-M3方法相似
<C时right++, >=C时left--
*/

int maximumCopy(const vector<int>& s, int C, int& start, int& end) {
    int left = 0;
    int right = 0;
    int maxS = INT_MIN;
    int sum = 0;
   //BUG while (right < s.size() && left < s.size()) {
   while (left < s.size()) {
        if (sum <= C && right < s.size()) {//right move
            sum += s[right];
            right++;
        } else { //left move
            sum -= s[left];
            left++;
        }
        /*
        //useless
        if (left == right && s[left] > C) {
            sum = 0;
            left++;
            right++;
        }
        */
        // BUG if (sum < C && sum > maxS) {
        if (sum <= C && sum > maxS) {
            maxS = sum;
            start = left;
            end = right - 1;
        }
    }
    if (maxS == INT_MIN || maxS == 0)
        return -1;
    return C - maxS;
}

//套用 209-M1方法
int maximumCopy2(const vector<int>& nums, int s, int& start, int& end) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxS = INT_MIN;
        while(left < n) {
            while (sum < s && right < n) {  // R move
                sum += nums[right++];
            }
            // sum>=s or right == n
            if (sum <= s && sum>maxS) {
                //[left, right)
                maxS =  sum;
                start = left;
                end = right - 1;
            }
            // when sum>=s or right == n ; L move
            sum -= nums[left++];
        }
        return maxS == INT_MIN ? -1 : (s - maxS);
    }


int main() {
    int sum = 3;
    vector<int> v{1, 1};
    Solution s;
    // cout << s.minSubArrayLen(sum, v) << endl;

    int C = 8;
    vector<int> files{1, 2, 4, 200,5, 2, 4,100, 5, 2, 4, 4};
    int start = -1;
    int end = -1;
    auto res = maximumCopy(files, C, start, end);
    cout << "res=" << res << " s=" << start << " e=" << end << endl;
    auto res2 = maximumCopy2(files, C, start, end);
    cout << "res2=" << res2 << " s=" << start << " e=" << end << endl;

}


/*
Tips

Input: s = 7
L     R
2,3,1,2,4,3
此时 sum=2+3+1+2=8>7
这是R再往右走无意义，因为已经>7了，且长度为4，此时R往右只会增加长度。
因此应该收缩窗口左界L
  L   R
2,3,1,2,4,3
sum=8-2=6<7 决定了R往右
  L     R
2,3,1,2,4,3
sum=6+4=10>7 决定了L往左
    L   R
2,3,1,2,4,3
sum=10-3=7  决定了L往左，而不是R往右
      L R
2,3,1,2,4,3
      L   R
2,3,1,2,4,3
        L R
2,3,1,2,4,3
得到最小的len=2

          L R
2,3,1,2,4,3

M1 slidingWindow - LR-Pointer
https://leetcode.com/problems/minimum-size-subarray-sum/discuss/433123/JavaC%2B%2BPython-Sliding-Window
Sliding window:
1248 Count Number of Nice Subarrays
1234 Replace the Substring for Balanced String
1004 Max Consecutive Ones III
930 Binary Subarrays With Sum
992 Subarrays with K Different Integers
904 Fruit Into Baskets
862 Shortest Subarray with Sum at Least K


写得太罗嗦了，参见
https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59090/C%2B%2B-O(n)-and-O(nlogn)
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }

M2




*/


