/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-17
 * @tag
 */

/*
 
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

   void sortColorsM1(vector<int>& nums) {
        int arr[3]={0,0,0};
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        int k = 0;
        for (int i = 0; i < 3;i++) {
            auto cnt = arr[i];
            for (int j = 0; j < cnt; j++) {
                nums[k++] = i; 
            }
        }
        return;  
    }

    // M2
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        int p1 = 0;
        int p2 = len-1;
        while(i <= p2)  {
            if (nums[i] == 0 && i != p1) {
                swap(nums, i, p1);
                p1++;
                continue;
            }
            if (nums[i] == 2 && i != p2) {
                swap(nums, i, p2);
                p2--;
                continue;
            }
            i++;
        }
        return;
    }


    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

};


int main() {
    Solution s;
}


/*
Tips
M1 计数排序 

M2 双指针  



 
*/


