/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-04
 * @tag
 * @similar 26
 */

/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

/*
Runtime: 8 ms, faster than 89.61% of C++ online submissions for Remove Duplicates from Sorted Array II.
Memory Usage: 11 MB, less than 70.90% of C++ online submissions for Remove Duplicates from Sorted Array II.
计数器cnt相当于给每个相等的元素打了一个id，根据id做出是否复制的选择，如下所示
i    0 1 2 3 4 5 6 7
data 1 1 1 2 2 2 2 3
cnt  0 1 2 0 1 2 3 0
当i== 3 7时，即变化的元素的第一个，会被复制，同时cnt=0
当i==其他下表时，更新cnt计数，因为重复元素只需要保留2个，重复序列的第一个元素在i=3 7已经保存了
第二个元素正好对应cnt=1的元素，把第2个重复的元素搬到数组首部即可
*/
    int removeDuplicatesM1(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        int k = 1;
        int cnt = 0;
        int n = nums.size();
        for (i = 1; i < n; ++i) {
            if (nums[i-1] == nums[i]) {
                cnt++;
                if (cnt == 1) {
                    nums[k++] = nums[i];
                }
            } else {
                cnt = 0;
                nums[k++] = nums[i];
            }
        }
        return k;
    }

/*
Runtime: 12 ms, faster than 55.01% of C++ online submissions for Remove Duplicates from Sorted Array II.
Memory Usage: 11.2 MB, less than 22.28% of C++ online submissions for Remove Duplicates from Sorted Array II.
M1改进版，完全依赖于下标cnt来决定复制行为
最优版
*/
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        int k = 1;
        int cnt = 0;
        int n = nums.size();
        for (i = 1; i < n; ++i) {
            if (nums[i-1] == nums[i]) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt <= 1) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }



};

int removeDuplicates(int* nums, int numsSize){

}


int main() {
    Solution s;
}


/*
Tips
M1 就地修改 单指针i 配合相同计数器cnt

M2 就地修改 双指针i j
麻烦，放弃

*/


