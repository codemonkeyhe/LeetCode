/**
 * @file 0001TwoSum.cpp
 * @brief
 * @author MonkeyHe
 * @version 1.0
 * @date 2018-09-16
 */

/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/


#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    //return M1(nums, target);
    //return M3(nums, target);
    return M4(nums, target);
}

vector<int> M1(vector<int>& nums, int target) {
    vector<int> res;
    int size = nums.size();
    for (int i =0; i< size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

vector<int> M3(vector<int>& nums, int target) {
    vector<int> res;
    unordered_multimap<int, int> hashnums;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        hashnums.insert(make_pair(nums[i], i));
    }
    unordered_multimap<int, int>::const_iterator it;
    for (int i = 0; i < size; i++) {
        int e = target - nums[i];
        auto range = hashnums.equal_range(e);
        if (range.first == range.second) {
            continue;
        }
        bool find = false;
        for (auto it = range.first; it!= range.second; it++) {
            if (it->second != i) {
                res.push_back(i);
                res.push_back(it->second);
                find = true;
                break;
            }
        }
        if (find) {
            break;
        }
    }
    return res;
}

// 依然遍历了2遍 
vector<int> M31(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int,  vector<int> > v2i;
    int len = nums.size();
    for (int i=0; i<len; i++) {
        int val = nums[i];
        v2i[val].push_back(i);
    }
    for (int i=0; i < len; i++) {
        int cur = nums[i];
        int want = target - cur;
        auto it = v2i.find(want);
        if (it == v2i.end()) {
            continue;
        }
        for (auto j : it->second) {
            if (j != i) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}


vector<int> M4(vector<int>& nums, int target) {
    vector<int> res;
    vector<int> tmp(nums.begin(), nums.end());
    stable_sort(tmp.begin(), tmp.end());
    size_t i = 0;
    size_t j = tmp.size()-1;
    while(i<j) {
        int sum = tmp[i] + tmp[j];
        if ( sum == target) {
            break;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    for (size_t k = 0; k < nums.size(); ++k) {
        if (nums[k] == tmp[i])  {
            res.push_back(k);
        } else if (nums[k] == tmp[j]){
            res.push_back(k);
        }
        if (res.size()==2) {
            break;
        }
    }
    return res;
}

};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* res = (int*)malloc(sizeof(int)*2);
    for (int i =0; i< numsSize-1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}


class Solution38 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> v2i;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int val = nums[i];
            int want = target - val;
            auto it = v2i.find(want);
            if (it != v2i.end()) {
                return vector<int>{i, it->second};
            }

            v2i[val] = i;
        }

        return res;
    }
};

int main() {
    const int len = 4;
    int nums[len] = {7,2, 11, 15};
    int target = 9;

    // c
    int* res = twoSum(nums, len, target);
    int rs = (sizeof(res)) / (sizeof(int));
    for (size_t i = 0; i < (size_t)rs; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);

    // cpp
    Solution s;
    vector<int> nu(nums, nums+len);
    vector<int> re;
    re = s.twoSum(nu, target);
    for (size_t i = 0; i < re.size(); ++i) {
        cout << re[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
Tips
BOP 2.12
M1 暴力法  O(N^2)
M2 排序+二分查找法O(N*logN)
M3 哈希查找 O(N)
核心点 ：只遍历一遍数据 
M4 排序 + 两端逼近O(NlogN) + O(N)

*/
