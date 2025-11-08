/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-08
 * @tag   hashTable,twoPointers,topologicalSort,simulation
 * @similar   207, 457
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 *
 * https://leetcode.cn/problems/circular-array-loop/description/
 *
 * algorithms
 * Medium (43.48%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 91.9K
 * Testcase Example:  '[2,-1,1,2,2]'
 *
 * 存在一个不含 0 的 环形 数组 nums ，每个 nums[i] 都表示位于下标 i 的角色应该向前或向后移动的下标个数：
 * 如果 nums[i] 是正数，向前（下标递增方向）移动 |nums[i]| 步
 * 如果 nums[i] 是负数，向后（下标递减方向）移动 |nums[i]| 步
 *
 *
 * 因为数组是 环形 的，所以可以假设从最后一个元素向前移动一步会到达第一个元素，而第一个元素向后移动一步会到达最后一个元素。
 * 数组中的 循环 由长度为 k 的下标序列 seq 标识：
 *
 *
 * 遵循上述移动规则将导致一组重复下标序列 seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] ->
 * ...
 * 所有 nums[seq[j]] 应当不是 全正 就是 全负
 * k > 1
 *
 *
 * 如果 nums 中存在循环，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [2,-1,1,2,2]
 * 输出：true
 * 解释：图片展示了节点间如何连接。白色节点向前跳跃，而红色节点向后跳跃。
 * 我们可以看到存在循环，按下标 0 -> 2 -> 3 -> 0 --> ...，并且其中的所有节点都是白色（以相同方向跳跃）。
 *
 *
 * 示例 2：
 * 输入：nums = [-1,-2,-3,-4,-5,6]
 * 输出：false
 * 解释：图片展示了节点间如何连接。白色节点向前跳跃，而红色节点向后跳跃。
 * 唯一的循环长度为 1，所以返回 false。
 *
 *
 * 示例 3：
 * 输入：nums = [1,-1,5,1,4]
 * 输出：true
 * 解释：图片展示了节点间如何连接。白色节点向前跳跃，而红色节点向后跳跃。
 * 我们可以看到存在循环，按下标 0 --> 1 --> 0 --> ...，当它的大小大于 1 时，它有一个向前跳的节点和一个向后跳的节点，所以
 * 它不是一个循环。
 * 我们可以看到存在循环，按下标 3 --> 4 --> 3 --> ...，并且其中的所有节点都是白色（以相同方向跳跃）。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 5000
 * -1000 <= nums[i] <= 1000
 * nums[i] != 0
 *
 *
 * 进阶：你能设计一个时间复杂度为 O(n) 且额外空间复杂度为 O(1) 的算法吗？
 *
 */


/*
Trick1 nextIdx 计算
((cur + nums[cur]) % n + n) % n;

Trick2 同向判断
M1
            if ((step > 0 && nums[nextI] < 0) || (step < 0 && nums[nextI] > 0)) { // different direction
M2 用乘法
            if ((step * nums[nextI] < 0)) { // different direction

Trick3 循环不能指向自身，必然就k>1


优化方案
走过的节点全部标记为0


*/

// @lc code=start
class Solution {
public:
    //没考虑局部的死循环
    bool circularArrayLoopError(vector<int>& nums) {
        int lenn = nums.size();
        int i = 0;
        int step = 0;
        unordered_set<int> path;
        while(step < lenn) {
            int cur = nums[i];
            cout << "i=" << i << " cur= " << cur << endl;
            if (path.count(i)) {
                return true;
            }
            path.insert(i);
            int nextIdx = i + cur;
            if (nextIdx > 0) {
                if (nextIdx >= lenn) {
                    nextIdx = nextIdx % lenn;
                }
            } else {
                nextIdx = nextIdx % lenn;
                nextIdx = lenn - nextIdx;
            }
            i = nextIdx;
            step++;
            cout << "nextIdx=" << nextIdx << " step=" << step << endl;
        }
        return false;
    }

    // BUG
    int nextIdx2(int lenn, int cur, int step) {
        int nextIdx = cur + step;
        if (nextIdx > 0) {
            if (nextIdx >= lenn) {
                nextIdx = nextIdx % lenn;
            }
        } else {
            nextIdx = nextIdx % lenn;
            //ROOTCAUSE  nextIdx = lenn - nextIdx;
            nextIdx = (nextIdx + lenn) % lenn;
        }
        return  nextIdx;
    }



    int nextIdx(int lenn, int cur, int step) {
        int nextIdx = (cur + step) % lenn;
        nextIdx = (nextIdx + lenn) % lenn;
        return  nextIdx;
    }

    bool circularArrayLoopM1(vector<int>& nums) {
        int lenn = nums.size();
        for (int i = 0; i < lenn; i++) {
            if (existLoop(nums, i)) {
                return true;
            }
        }
        return false;
    }


    // 1 1 1
    bool existLoop(vector<int>& nums, int start) {
        int i = start;
        int cnt = 0;
        int lenn = nums.size();
        unordered_set<int> path;
        while(cnt <= lenn) { // max walk cnt to original pos
            int step = nums[i];
            //auto nextI = nextIdx2(lenn, i, step);
            auto nextI = nextIdx(lenn, i, step);
            //cout << "i=" << i << " step= " << step << " nextI=" << nextI << endl;
            //if ((step > 0 && nums[nextI] < 0) || (step < 0 && nums[nextI] > 0)) { // different direction
            if ((step * nums[nextI] < 0)) { // different direction
                return false;
            }
            if (i == nextI) { // means K > 1
                return false;
            }
            if (path.count(i)) { // repeat
                return true;
            }
            path.insert(i);
            i = nextI;
            cnt++;
        }
        return false;
    }

    bool circularArrayLoop(vector<int> &nums) {
        int lenn = nums.size();
        for (int i = 0; i < lenn; i++) {
            if (existLoop2(nums, i)) {
                return true;
            }
        }
        return false;
    }

    // 1 1 1
    // 走过的设置为0 加速
    bool existLoop2(vector<int>& nums, int start) {
       // cout <<"START=" << start << endl;
        int i = start;
        if (nums[i] == 0) { // already walk
            return false;
        }
        int cnt = 0;
        int lenn = nums.size();
        unordered_set<int> path;
        while(cnt <= lenn) { // max walk cnt to original pos
            int step = nums[i];
            auto nextI = nextIdx(lenn, i, step);
          // cout << "i=" << i << " step= " << step << " nextI=" << nextI << endl;
            if ((step * nums[nextI] < 0)) { // different direction
                return false;
            }
            if (path.count(i)) { // repeat
                return true;
            }
            path.insert(i);
            if (i == nextI) { // means K > 1
                return false;
            }
            // mark walked
            nums[i] = 0;
            i = nextI;
            cnt++;
        }
        return false;
    }


};
// @lc code=end

/*

nums =
[1,1]
添加到测试用例
输出
false
预期结果
true

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
