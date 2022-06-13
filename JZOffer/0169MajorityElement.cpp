/**
 * @file 0169MajorityElement.cpp
 * @brief BOP 2.3
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-17
 */


/*

Given an array of size n, find the majority element. The majority element is the element that appears more than 鈱?n/2 鈱?times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

*/

/*
????????Majar Element???????????
[3,2,3,1]  There is no majority element
[3,2,3,2]  There is no majority element
?n????? MajorElement?????n/2


Boyer-Moore Voting Algorithm
https://segmentfault.com/a/1190000004905350
https://blog.csdn.net/kimixuchen/article/details/52787307

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//Simple way
class Solution {
   public:
    // 24 ms   47.19%
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        unordered_map<int, int>::const_iterator it;
        int limit = nums.size()/2;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > limit) {
                return it->first;
            }
        }
        return 0;
    }
};


// M2 投票算法
//Runtime: 16 ms, faster than 95.06% of C online submissions for Majority Element.
//Memory Usage: 7.3 MB, less than 100.00% of C online submissions for Majority Element.
int majorityElement(int* nums, int numsSize) {
    int cur = 0;
    int cnt = 0;
    /* ???
    for (int i = 0; i < numsSize; ++i) {
        cnt ? (cur == nums[i] ? ++cnt : --cnt) : (cur=nums[i],cnt=1);
    }*/
    for (int i = 0; i < numsSize; ++i) {
        if (cnt == 0) {
            cur = nums[i];
            cnt = 1;
            continue;
        }
        if (cur == nums[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }
    return cur;
}

int main() {
    const int len = 7;
    int nums[len] = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nu(nums, nums + len);

    // c
    int res = majorityElement(nums, len);
    printf("%d\n", res);

    // cpp
    Solution s;
    int re = s.majorityElement(nu);
    cout << re << endl;

    return 0;
}

/*
Tips
M0 map  unordered_map

M1 sort 中位数
    stable_sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
    Runtime: 36 ms, faster than 9.54% of C++ online submissions for Majority
Element.

M2 投票算法


Same as 0229


*/
