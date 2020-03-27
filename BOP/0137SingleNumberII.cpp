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
每个数字转成二进制后，只有bit=1的位置才有权决定数字大小，bit=0的位置没关系。
令Xi为Number转成二进制后第i个bit上的值，Xi=0或1
当Number出现3次时，
如果Xi=0,则 Count(Xi=0)=3, 因为bit为0并没有权影响大小，可忽略
如果Xi=1,则 Count(Xi=1)=3,
如果很多个Number的二进制的第i位为0或者1
最终的结果是
则 Count(Xi=1)=0,3,6,9,...
当某个N只出现1次时，则Count(Xi=1) = 1,4,7...
因此，统计 Count(Xi)后， mod3就好了。

https://leetcode.com/problems/single-number-ii/discuss/43313/A-general-C%2B%2B-solution-for-these-type-problems
S=O(32) 或者 O(0) 看写法
T=O(N)
https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
推广到一般情况：
如果其他数都出现了 kk 次，一个数出现了一次。那么如果 kk 是偶数，还是把所有的数异或起来就行了。如果 kk 是奇数，那么统计每一位是 1 的个数，然后模 kk 取余数就能得到那个单独的数了。


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

M2.3  bit操作推导 【最通用的解法】
https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
https://leetcode-cn.com/problems/single-number-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--31/
将问题一般化
给一个数组，每个元素都出现 k ( k > 1) 次，除了一个数字只出现 p 次(p >= 1, p % k !=0)，找到出现 p 次的那个数。


M2.4 模拟三进制 [PPT容易理解]
https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
实际上，异或运算的含义是二进制下不考虑进位的加法
三进制下不考虑进位的加法：通过定义某种运算 #，使得 0 # 1 = 1，1 # 1 = 2，2 # 1 = 0。在此运算规则下，出现了 33 次的数字的二进制所有位全部抵消为 00，而留下只出现 11 次的数字二进制对应位为 11。因此，在此运算规则下将整个 arr 中数字遍历加和，留下来的结果则为只出现 11 次的数字。 【原理和M1想通，M1是计算每个bit位置1的数目后mod3，本质上就是在每个bit上执行三进制的加法】


*/
