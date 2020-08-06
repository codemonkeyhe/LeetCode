/**
 * @file
 * @brief  46-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-17
 */

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    //Runtime: 4 ms, faster than 92.93% of C++ online submissions for Next Permutation.
    //Memory Usage: 12.3 MB, less than 24.40% of C++ online submissions for Next Permutation.
// 使用swap函数则从4ms->8ms
//Runtime: 8 ms, faster than 56.75% of C++ online submissions for Next Permutation.
//Memory Usage: 12.1 MB, less than 54.90% of C++ online submissions for Next Permutation.
    void nextPermutation(vector<int>& nums) {
        int c = nums.size();
        if (c <= 1) {
            return;
        }
        int i = c-2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1])
                break;
        }
        // i==-1 means no nextP  just revert array
        if (i != -1) { // means exist nextP
            int k = c - 1;
            for (; k > i; --k) {
                if (nums[k] > nums[i])
                    break;
            }
            swap(nums[i], nums[k]);
        }
        int l = i+1;
        int r = c-1;
        while (l<r) {
            swap(nums[l++], nums[r--]);
        }
    }


    void nextPermutation2(vector<int>& nums) {
        int i = nums.size() - 1, k = i;
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;
        for (int j = i; j < k; j++, k--)
            swap(nums[j], nums[k]);
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i])
                k++;
            swap(nums[i], nums[k]);
        }
    }
};

void nextPermutation(int* nums, int numsSize) {}

int main() {
    const int len = 6;
    int nums[len] = {9, 2, 6, 5, 2, 0};

    // const int len = 2;
    // int nums[len] = {1,2};
    vector<int> nu(nums, nums + len);

    Solution s;
    s.nextPermutation2(nu);
    for (auto v : nu) {
        cout << v << " ";
    }
    cout << endl;
    //system("PAUSE");

    return 0;
}


/*
Tips
陷阱
边界情况  3,2,1 → 1,2,3


M1 寻找逆序点对，经典解法
例如 123  132 213 231 312 321
最终排列是321，满足从左到右是降序的,从右往左是升序的
从右往左寻找开始降序的降序点，
从右往左寻找开始找比降序点位置的数要大的数，与降序点的数字交换
把降序点之后的数字反转一下即可
例如926520 -> 950226
1) 寻找降序点2，因为2<6。
2) 寻找比降序点大的数5, 交换一下， 95 6220
3) 降序点5之后的数字反转， 95 0226


M2　先reverse再swap
https://leetcode.com/problems/next-permutation/discuss/13921/1-4-11-lines-C%2B%2B

M3 STL next_permutation
void nextPermutation(vector<int>& nums) {
    next_permutation(begin(nums), end(nums));
}

M4 STL is_sorted_until
原理和M1相同，只是用STL精简代码
void nextPermutation(vector<int>& nums) {
    auto i = is_sorted_until(nums.rbegin(), nums.rend());
    if (i != nums.rend())
        swap(*i, *upper_bound(nums.rbegin(), i, *i));
    reverse(nums.rbegin(), i);
}

*/
