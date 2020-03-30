/**
 * @file
 * @brief　LCS 最长连续序列
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-15
 * @date 2020-03-28
 */

/*
Given an unsorted array of integers, find the length of the longest
consecutive[连续的] elements sequence. Your algorithm should run in O(n)
complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {}

    // Runtime: 8 ms, faster than 94.83% of C++ online submissions for Longest
    // Consecutive Sequence. Memory Usage: 7.2 MB, less than 100.00% of C++
    // online submissions for Longest Consecutive Sequence.
    int longestConsecutiveM1(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxLen = 1;
        stable_sort(nums.begin(), nums.end());
        int len = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i] - 1) {
                len++;
            } else if (nums[i - 1] == nums[i]) {
                continue;
            } else {
                if (len > maxLen) {
                    maxLen = len;
                }
                len = 1;
            }
        }
        if (len > maxLen) {
            maxLen = len;
        }
        return maxLen;
    }

    // Runtime: 12 ms, faster than 68.07% of C++ online submissions for Longest
    // Consecutive Sequence. Memory Usage: 8 MB, less than 100.00% of C++ online
    // submissions for Longest Consecutive Sequence.
    int longestConsecutiveM3(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> ha(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            int len = 1;
            int begin = nums[i];
            if (ha.count(begin - 1)) {  //不加則超時
                continue;
            }
            while (ha.count(begin + 1)) {
                len++;
                begin++;
            }
            if (len > maxLen) {
                maxLen = len;
                len = 1;
            }
        }
        return maxLen;
    }

    int longestConsecutiveM6(vector<int>& nums) {
        unordered_map<int, int> ha;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (ha.count(nums[i])) {
                continue;
            }
            {
                int cur = nums[i];
                int left = ha.count(cur - 1) ? ha[cur - 1] : 0;
                int right = ha.count(cur + 1) ? ha[cur + 1] : 0;
                int sum = left + right + 1;
                maxLen = max(sum, maxLen);
                ha[cur] = sum;
                ha[cur - left] = sum;
                ha[cur + right] = sum;
            }
        }
        return maxLen;
    }
};

int longestConsecutive(int* nums, int numsSize) { return 0; }

// Runtime: 28 ms, faster than 9.63% of C++ online submissions for Longest
// Consecutive Sequence. Memory Usage: 8.9 MB, less than 100.00% of C++ online
// submissions for Longest Consecutive Sequence.
//带路径压缩的并查集
class Solution4 {
   public:
    unordered_map<int, int> unionf;
    unordered_map<int, int> set2num;

    int find(int i) {
        if (unionf[i] == i) {
            return i;
        }
        // XXX  并查集路径压缩
        unionf[i] = find(unionf[i]);
        return unionf[i];
    }

    int merge(int i, int j) {
        int s1 = find(i);
        int s2 = find(j);
        if (s1 == s2) {
            return set2num[s1];
        }
        unionf[j] = i;
        set2num[s1] += set2num[s2];
        return set2num[s1];
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            unionf[nums[i]] = nums[i];
            set2num[nums[i]] = 1;
        }
        int len = 0;
        int maxLen = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (unionf.count(nums[i] + 1)) {
                len = merge(nums[i], nums[i] + 1);
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
        return maxLen;
    }
};

int main() {
    int len = 6;
    int nums[len] = {100, 4, 200, 1, 3, 2};
    vector<int> nu(nums, nums + len);
    printf("%d\n", longestConsecutive(nums, len));

    Solution4 s;
    cout << s.longestConsecutive(nu) << endl;

    return 0;
}

/*
Tips
M0 暴力法

M1 排序+遍历
三种排序复杂度为O(N)  计数排序  基数排序   桶排序

M2 Set+遍历

M3 哈希表+剪枝
https://leetcode.com/problems/longest-consecutive-sequence/discuss/41057/Simple-O(n)-with-Explanation-Just-walk-each-streak

M4 并查集[union-find]
https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/ha-xi-biao-shi-xian-on-bing-cha-ji-liang-chong-shi/

M5 动态规划

M6 边界长度
12 456
12 3 456
https://leetcode.com/problems/longest-consecutive-sequence/discuss/41055/My-really-simple-Java-O(n)-solution-Accepted
M6精简版
https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines

*/
