/**
 * @file 0169MajorityElement.cpp
 * @brief 
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-17
 */


/*
    
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

*/

/*
Boyer-Moore Voting Algorithm  
https://segmentfault.com/a/1190000004905350
https://blog.csdn.net/kimixuchen/article/details/52787307
 
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Simple way
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        map<int, int>::const_iterator it;
        int max = 0;
        int val = 0;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second > max)  {
                max = it->second;        
                val = it->first;
            }
        } 
        return val;
    }
};

int majorityElement(int* nums, int numsSize) {
    return 0; 
}


int main() {
    const int len = 7;
    int nums[len] = {2,2,1,1,1,2,2};
    vector<int> nu(nums, nums+len);   

    // c
    int res = majorityElement(nums, len);
    printf("%d\n", res);

    // cpp
    Solution s;
    int re = s.majorityElement(nu);
    cout << re << endl;

    return 0;
}


