/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-08
 */

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:
Input: [1,3,4,2,2]
Output: 2

Example 2:
Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {


    }

    int MFool(vector<int>& nums) {
        int idx = 0;
        int pos = 0;
        int value = 0;
        while (idx < nums.size()) {
            for (;idx < nums.size(); ++idx) {
                pos = nums[idx] - 1;
                if (idx != pos) {
                    value = nums[idx];
                    pos = value - 1;
                    nums[idx] = 0;
                    break;
                }
            }
            while (pos < nums.size()) {
                if (nums[pos] == value) {
                    return value;
                } else {
                    if (nums[pos] == 0) {
                        nums[pos] = value;
                        idx = pos + 1;
                        break;
                    }
                    int tmp = nums[pos];
                    nums[pos] = value;
                    value = tmp;
                    pos = value - 1;
                }
            }
        }
        return 0;
    }
};

int findDuplicate(int* nums, int numsSize) { return 0; }

int main() {
    const int len = 5;
   // int nums[len] = {1, 3, 4, 2, 2};
   int nums[len] = {3,1,3,4,2};
    vector<int> nu(nums, nums + len);

    int res = findDuplicate(nums, len);
    printf("%d\n", res);

    Solution s;
    res = s.findDuplicate(nu);
    cout << res << endl;
    return 0;
}

/*
Tips
因为Space=O(1)，无法使用Set或者hashmap

M1 排序＋遍历　O(N*LogN)+O(N)
M2 Cycle Detection  T=O(N) S=O(1)
https://blog.csdn.net/camellhf/article/details/52829893
https://leetcode.com/problems/find-the-duplicate-number/discuss/156106/Four-Solutions-Summary-in-C%2B%2B
Solution :
It is very similiar with Linked List Cycle II problem, which uses two pointers, one of them is slow, the other is fast.
When there exists a cycle in it, slow pointer will equal to fast pointer in first pass.
Then, put the slow in the initial position (slow = 0), run the second pass.
When slow meets fast in the second pass, the position is what we want.
https://blog.csdn.net/camellhf/article/details/52829893

先找环内交点，一个2步，一个1步。
找到交点后，任意一个重置到初始节点，每次都一步。

给有环链表依次标号0..N，
即指针p走了第k步会在第k个节点,该节点标号为k.
假设入环点在第i个节点，第一次快慢指针相交点在第j个节点。
有  0<=i<=j<=N, N->next = i
当p1 p2在j处相交，Step(p2)=2*Step(p1)
Step(p1) = j;
Step(p2) = j + (n-i)
2j = j+n-i
i = n-j
也就是 令已经走了j步的p1从第j个节点开始，再走n-j步时，P2就会走i步到达第i个相交点。


M3 Binary Search T=O(NLogN) S=O(1)  二分查找 鸽笼原理
https://blog.csdn.net/qq_38346791/article/details/92781189
思想就是 把下标当做数据本身，
遍历数组，如果数组所有元素小于下标的次数, 这个次数比下标小的话，说明重复元素在右侧.否则重复元素在左侧

M-Fool 下标去重法 忽略了数组是readonly
下标当数据本身去使用，移走的位置的值用0标记，因为合理的值范围是 [1..N]
当要移动的数据 和对应位置的数据相同，说明重复。 时间复杂度 小于 O(N^2)

快慢指针的问题:
以前在微软面试时遇到过，在bigo面试也遇到过。
快慢指针的问题有很多变种:
比如给一个环形链表，如何快速确定环的长度？
如何判断两个无环链表是否相交？
求两个链表相交的第一个节点？
例如未知长度的链表，如何遍历一次，就能找到中间节点的值？



*/