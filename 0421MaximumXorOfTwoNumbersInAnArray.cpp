/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-08
 * @tag   bitManipulation
 * @similar    1, 421, 2317, 2429
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 *
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (59.84%)
 * Likes:    688
 * Dislikes: 0
 * Total Accepted:    63.6K
 * Total Submissions: 106.4K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [3,10,5,25,2,8]
 * 输出：28
 * 解释：最大运算结果是 5 XOR 25 = 28.
 *
 * 示例 2：
 * 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * 输出：127
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int highBit = __lg(ranges::max(nums)); // max=25 highBit=4
        int ans = 0;
        int wantAns = 0;
        int mask = 0;
        for (int i = highBit; i >=0; i--) {
            mask = mask | (1 << i);
            wantAns = ans | (1 << i);
            unordered_map<int, int> walked; // 存储val的highBits -> trueVal
            for (int j = 0; j < nums.size(); j++) {
                int x = nums[j];
                x = x & mask; // 只保留mask范围内的bits，低位全改为0
                // x ^ y = wantAns ; y = wantAns^x
                int y = wantAns ^ x;
                if (walked.count(y) == 1) { // find
                    ans = wantAns;
                   // cout << "findAns=" << ans << " x=" << nums[j] << " y=" << walked[y]  << endl;
                    break;
                }
                // not find，x存入hashmap，供后续的y来匹配，借鉴LeetCode twoSum
                walked[x] = nums[j];
            }
        }
        return ans;
    }
};
// @lc code=end

/*
算法
初始化答案 ans=0。
从最高位开始枚举 i，也就是 max(nums) 的二进制长度减一。
设 newAns=ans+2^i
 ，看能否从 nums 中选两个数（低于 i 的比特位当作 0），满足这两个数的异或和等于 newAns。如果可以，则更新 ans 为 newAns，否则 ans 保持不变。
判断【两数异或】的做法和力扣第一题【两数之和】是一样的，请看 我的题解。用 ⊕ 表示异或，如果 a⊕b=newAns，那么两边同时异或 b，由于 b⊕b=0，所以得到 a=newAns⊕b（相当于把两数之和代码中的减法改成异或）。这样就可以一边枚举 b，一边在哈希表中查找 newAns⊕b 了。
请注意，ans 继承了上一位算出的内容，后面比特位的计算不是只看当前位，之前算过的高位也得满足。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/solutions/2511644/tu-jie-jian-ji-gao-xiao-yi-tu-miao-dong-1427d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

已知
ans=11100, 其实相当于111XX  ,XX表示待定的区域，换句话说，接下来的ans只有2种可能: 1111X或者 1110X，于是用预言的方式去检测属于哪一种可能
先做预言  wantAns=11110  看看是否能找到2个数，使得x^y=wantAns
找得到，预言正确， ans=wantAns，相当于 ans从111XX 改为 1111X
找不到，预言不正确， ans保持不变，相当于 ans从111XX 改为 1110X

tricky
x^y= wantAns
x^y^x= wantAns^x
y= wantAns^x


__lg 约等于  log2
__lg()函数是一个非标准的函数，只在部分编译器中支持，它返回一个整数值，表示输入参数的二进制表示中最高位1的位置（从0开始计数）。例如，__lg(8)将返回3，因为8的二进制表示是1000，最高位1在第3位。
log2()函数是C++11标准中提供的函数，它返回一个浮点数值，表示以2为底的对数。例如，log2(8)将返回3.0，因为8等于2的3次方。

链接：https://www.zhihu.com/question/446219057/answer/2993917211


Wrong Answer
30/46 cases passed (N/A)
Testcase
[8,10,2]
Answer
8
Expected Answer
10



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
