/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-10
 */

/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.


A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <vector>

using namespace std;

class Solution {
public:
 vector<vector<int> > fourSum(vector<int>& nums, int target) {
    stable_sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    if(n<4)  return res;
    for (int i = 0; i < n-3; ++i) {
      //剪枝
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
      if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
      for (int j = i + 1; j < n-2; ++j) {
        int l = j + 1;
        int r = nums.size() - 1;
        while (l < r) {
          int sum = nums[i] + nums[j] + nums[l] + nums[r];
          if (sum < target) {
            ++l;
          } else if (sum > target) {
            --r;
          } else {
            res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
            // filter same nums[l]
            while (l < r && nums[l] == nums[l+1]) { ++l; }
            // filter same nums[r]
            while (l < r && nums[r] == nums[r-1]) { --r; }
            ++l; --r;
          }
        }
        // filter same nums[j]
        while (j + 1 < nums.size() && nums[j] == nums[j + 1]) { ++j; };
      }
      // filter same nums[i]
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) { ++i; };
    }
    return res;
  }
};



int main() {
    const int len = 6;
    int target = 0;
    int nums[len] = {1, 0, -1, 0, -2, 2};
    vector<int> nu(nums, nums+len);
    Solution s;
    auto res = s.fourSum(nu, target);
    for (auto i = 0; i < res.size(); ++i) {
        for (auto j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


