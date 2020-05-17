/**
 * @file
 * @brief  P8
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-17
 */

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2]
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
/*
Runtime: 4 ms, faster than 65.53% of C++ online submissions for Find Minimum in Rotated Sorted Array.
Memory Usage: 10.2 MB, less than 6.67% of C++ online submissions for Find Minimum in Rotated Sorted Array.
*/
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        // if delete the 3 lines below,everythings works fine, but this 3 lines can speed up.
        if (nums[0] < nums[r]) {
            return nums[0];
        }
        while(l<r){
            // bug mid  = l + (r-l) >> 1;
            mid  = l + ((r-l) >> 1);
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return nums[l];
    }

};

int findMin(int* nums, int numsSize){

}

int main() {
    int len = 7;
    int nums[len] = {4,5,6,7,0,1,2};
    vector<int> nu(nums, nums+len);

    Solution s;
    cout << s.findMin(nu) << endl;

    return 0;
}


/*
Tips
M1 遍历法 O(N)

M2 二分法 O(lgN)

*/