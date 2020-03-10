/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-10
 */

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        stable_sort(nums.begin(), nums.end());
        int  mindis = 0x7FFFFFFF;
        int res = 0;
        for (size_t k = 0; k < nums.size(); ++k) {
            int l = k+1;
            int r = nums.size() -1;
            while(l<r) {
                int sum = nums[k] + nums[l] + nums[r];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    int dis = target-sum;
                    if (dis < mindis) {
                        res = sum;
                        mindis = dis;
                    }
                    while(l<r && nums[l] ==nums[l+1] ) {++l;}
                    ++l;
                } else {
                    int dis = sum-target;
                    if (dis < mindis) {
                        res = sum;
                        mindis = dis;
                    }
                    while(l<r && nums[r] ==nums[r-1] ) {--r;}
                    --r;
                }
            }
            while(k+1 < nums.size() && nums[k] == nums[k+1]) {
                ++k;
            }
        }
        return res;
    }
};

static int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int mindis = 0x7FFFFFFF;
    int res = 0;
    for (size_t k = 0; k < numsSize - 2; ++k) {
        int l = k + 1;
        int r = numsSize - 1;
        while (l < r) {
            int sum = nums[k] + nums[l] + nums[r];
            if (sum == target) {
                return sum;
            } else if (sum < target) {
                int dis = target - sum;
                if (dis < mindis) {
                    res = sum;
                    mindis = dis;
                }
                while (l < r && nums[l] == nums[l + 1]) ++l;
                ++l;
            } else {
                int dis = sum - target;
                if (dis < mindis) {
                    res = sum;
                    mindis = dis;
                }
                while (l < r && nums[r] == nums[r - 1]) --r;
                --r;
            }
        }
        while (k + 1 < numsSize && nums[k] == nums[k + 1]) ++k;
    }
    return res;
}

int main() {
    const int len = 4;
    int nums[len] = {-1, 2, 1, -4};
    int target = 1;
    vector<int> nu(nums, nums + len);

    auto res = threeSumClosest(nums, len, target);
    printf("%d\n", res);

    Solution s;
    stable_sort(nu.begin(), nu.end());
    auto r2 = s.threeSumClosest(nu, target);
    cout << r2 << endl;

    return 0;
}


/*
原理同 015-3sum
处理绝对值可用abs()

int  mindis = 0x7FFFFFFF; = MAX_INT

*/