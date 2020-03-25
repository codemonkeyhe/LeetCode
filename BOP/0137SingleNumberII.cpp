/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-14
 */

/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3

Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            res^= nums[i];
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            res^= nums[i];
        }
        return res;
    }
};

int singleNumber(int* nums, int numsSize){
    return 0;
}



int main() {
    int len = 7;
    int nums[len] = {0,1,0,1,0,1,99};
    vector<int> nu(nums, nums+len);
    printf("%d\n", singleNumber(nums, len));

    Solution s;
    cout << s.singleNumber(nu) << endl;


    return 0;
}


/*
Tips
M0 加减法
3*(a+b) - (a+a+a+b) = 2b
tmp=3*sum(set[arr]) - sum([arr])
res=tmp/2

M1 按位置思考
统计每一个bit上1出现的次数， mod%3=剩余的那个数在该bit上的值。
https://leetcode.com/problems/single-number-ii/discuss/43313/A-general-C%2B%2B-solution-for-these-type-problems
S=O(32)
T=O(N)


M2  bit operation
M2.1 Magic
https://leetcode.com/problems/single-number-ii/discuss/43360/The-simplest-solution-ever-with-clear-explanation
b0' = (b0 ^ num) & (~b1)
b1' = (b1 ^ num) & (~b0')

https://leetcode.com/problems/single-number-ii/discuss/43417/My-C%2B%2B-code-(12ms-one-iteration-3-int-variables-(b0-b1-reset))-with-algorithm-description
            b1 |= (b0 & A[i]);
            b0 = b0 ^ A[i];
            reset = b1 & b0;
            b1 = b1 ^ reset;
            b0 = b0 ^ reset;

M2.2 卡诺图(数电基础-忘光了。。)
https://leetcode-cn.com/problems/single-number-ii/solution/li-yong-qia-nuo-tu-sheng-cheng-zhuang-tai-zhuan-yi/
https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-shu-zi-dian-lu-she/

M2.3  bit操作推导
https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
https://leetcode-cn.com/problems/single-number-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--31/

M2.4 状态机
https://leetcode-cn.com/problems/single-number-ii/solution/zi-dong-ji-wei-yun-suan-zui-xiang-xi-de-tui-dao-gu/

M2.5 模拟三进制
https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/

*/
