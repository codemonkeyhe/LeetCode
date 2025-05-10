/**
 * @file
 * @brief 1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-10;20250509
 * @tag
 * @similar  35, 744
 */

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;


/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (43.47%)
 * Likes:    3007
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRangeM1(vector<int>& nums, int target) {
        // first >=
        auto posL = lower_bound(nums.begin(), nums.end(), target);
        if (posL == nums.end() || (*posL != target)) {
            return {-1, -1};
        }
        int idxLeft = posL - nums.begin();

        // first >
        auto posR = upper_bound(nums.begin(), nums.end(), target);
        // must exist, else lower_bound will return
        int idxRight = posR - nums.begin();
        return {idxLeft, idxRight - 1};
    }


    vector<int> searchRangeM2(vector<int>& nums, int target) {
        // first >=
        auto posL = lower_bound(nums.begin(), nums.end(), target);
        if (posL == nums.end() || (*posL != target)) {
            return {-1, -1};
        }
        int idxLeft = posL - nums.begin();

        // first >=
        auto posR = lower_bound(nums.begin(), nums.end(), target+1);
        // must exist, else lower_bound will return
        int idxRight = posR - nums.begin();
        return {idxLeft, idxRight - 1};
    }

    bool isBlue(int val, int target) {
        if (val < target) {
            return true;
        }
        return false;
    }

    // find first >= target
    // blueDef:   any val < target   redDef any val >= target
    // answer = right
    // mid range [0, N)
    /* 3 case
    INT_MAX  left = N-1, right = N  return -1
    INT_MIN  left = -1  right = 0
    [1]  1  left = -1 right = 0

    */
    int lowBound(vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size();
        while (left+1 < right) {
            int mid = left + ((right - left) >> 1);
            if (isBlue(nums[mid], target)) { //
                left = mid;
            } else { //
                right = mid;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        auto posL = lowBound(nums, target);
        if (posL ==  nums.size() || nums[posL] != target) {
            return {-1, -1};
        }
        auto posR = lowBound(nums, target + 1);
        return {posL, posR - 1};
    }
};
// @lc code=end

/*
Wrong Answer
67/88 cases passed (N/A)
Testcase
[1]
1
Answer
[-1,-1]
Expected Answer
[0,0]


Wrong Answer
56/88 cases passed (N/A)
Testcase
[5,7,7,8,8,10]
6
Answer
[1,0]
Expected Answer
[-1,-1]

*/


class SolutionOld {
public:

/*
M1
Runtime: 12 ms, faster than 99.16% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.8 MB, less than 54.83% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/

    vector<int> searchRangeM1(vector<int>& nums, int target) {
        vector<int> res;
        bs(nums, 0, nums.size()-1, target, res);
        return res;
    }

    void bs(vector<int>& nums, int low, int high, int target, vector<int>& res) {
        int begin = -1;
        int end = -1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                begin = mid;
                end = mid;
                while (begin >= low && nums[begin] == nums[mid]) {
                    begin--;
                }
                while (end <= high && nums[end] == nums[mid]) {
                    end++;
                }
                res.push_back(begin + 1);
                res.push_back(end - 1);
                return ;
            }
            if (nums[mid] < target) { //goR
                low = mid + 1;
            } else { //goL
                high = mid - 1;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return;
    }

/*
        if start == last，则end的结果必然是-1
        if nums[start] != target 说明找到第一个大于target的元素位置start, 也应该返回{-1,-1}
        找第一个元素>=(target+1)的位置，位置再-1的元素，要么==target，要么>target
        如果start定位到了target的起始围着，则下面的end必然指向target最后出现的位置，即排除上面>target的选项
    T=2*O(logN)
    Runtime: 16 ms, faster than 91.69% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 14 MB, less than 25.28% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/
    vector<int> searchRangeM21(vector<int>& nums, int target) {
        int start = lowerBound(nums, 0, nums.size(), target);
        int end = lowerBound(nums, 0, nums.size(), target + 1) - 1;
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        } else {
            return {start, end};
        }
    }

/*
在M21基础上，稍微优化了一下
Runtime: 20 ms, faster than 62.94% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 14.1 MB, less than 9.76% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/
    vector<int> searchRangeM22(vector<int>& nums, int target) {
        int start = lowerBound(nums, 0, nums.size(), target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = lowerBound(nums, 0, nums.size(), target + 1) - 1;
        return {start, end};
    }



    /*
        C++的 lowerBound 就是 [low,high)区间
        找到第一个元素大于等于 target的位置,
            找不到时，就返回high!!!
            找不到时，就返回high!!!
            找不到时，就返回high!!!

        理论上当nums[mid] == target时 应该是high=mid+1;
        这里优化成high = mid 有2个原因
        原因1 避免死循环
        因为必有 low <= mid < high ，当设置为high=mid+1时，区间没有收缩，会一直死循环
        例如 [1,3] target=1
        原因2 是为了减少代码，把==和>归为一类
        因为假设nums[mid]==target，分为两种情况：
        nums[mid-1]==target，此时high=mid 没问题
        nums[mid-1] < target, 此时high=mid，最后会找不到target,返回大于target的第一个位置，也即是mid-1+1=mid
    */
   // 左闭右开 [low, high)
    int lowerBound(vector<int>& nums, int low, int high, int target) {
        //如果用<=可能越界
        while (low < high) {
            int mid = low + ((high - low) >> 1); //[low,high) 这样保证了mid=low
            // low <= mid < high
            if (nums[mid] == target) { //high = mid 相当于排除掉了nums[mid]
                high = mid;
            } else if (nums[mid] < target) { //goR
                low = mid + 1;
            } else { //goL
                high = mid;
            }
        }
        return low;
    }


/*
M24
Runtime: 20 ms, faster than 62.94% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.9 MB, less than 47.49% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, 0, nums.size(), target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = findLast(nums, 0, nums.size(), target);
        return {start, end};
    }

    /*
   [low, high) 最后1个元素大于等于target的位置，
   找不到，
   如果target小于整个数组,low=0 high=0 返回了-1
   如果target大于整个数组,low=size high=size 返回了size-1

   为何  if (nums[mid] == target) 时， low=mid+1而不是 low=mid
   很简单， 因为 mid的计算方式决定了  low <= mid < high
    如果low=mid 会有死循环风险， 所以 low=mid+1  跳出死循环后，答案就是low-1
    */
    int findLast(vector<int>& nums, int low, int high, int target) {
        while (low < high) {
            int mid = low + ((high - low) >> 1); //[low,high) 这样保证了mid=low
            // low <= mid < high
            if (nums[mid] == target) { //high = mid 相当于排除掉了nums[mid]
                low = mid + 1;
            } else if (nums[mid] < target) { //goR
                low = mid + 1;
            } else { //goL
                high = mid;
            }
        }
        return low - 1;
    }

};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

}


int main() {

    const int len = 6;
    int nums[len] = {5,7,7,8,8,10};

    vector<int> data(nums, nums+len);
    //int target = 8;
    int targets[6] = {5,6,7,8,9,10};
    vector<int> tg(targets, targets + 6);
    SolutionOld s;
    for (auto t: tg) {
        auto res = s.searchRange(data, t);
        for (int i : res) {
            cout << i << "  ";
        }
        cout << endl;
    }
}


/*
Tips
M1 二分+左右扩张
先二分找到等价元素，再向左右扩张边界
最坏情况 为 O(N)

M2 单纯二分
M21　左闭右开 [low, high)
即C++的 lower_bound  upper_bound函数
lower_bound：
功能：查找非递减序列[first,last) 内第一个大于或等于某个元素的位置。
返回值：如果找到第一个大于或等于的，则返回找到元素的地址,否则返回last的地址。（这样不注意的话会越界，小心）
用法：int t=lower_bound(a+l,a+r,key)-a; (a是数组)。
即target不在范围内，会返回两种值:
一种是first，说明target比整个数组都小
一种是last，说明target比整个数组都大

upper_bound:
功能：查找非递减序列[first,last) 内第一个大于某个元素的位置。
返回值：如果找到第一个大于或等于的，返回找到元素的地址,否则返回last的地址。（同样这样不注意的话会越界，小心）
用法：int t=upper_bound(a+l,a+r,key)-a; (a是数组)

M23  左闭右闭[low, high]
while(low<=high)
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/da-jia-bu-yao-kan-labuladong-de-jie-fa-fei-chang-2/
这样代码复杂一点，没有左闭右开简单

M24 同时实现FindFirst和FindLast

*/


