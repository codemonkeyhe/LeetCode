/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-30
 * @tag  linkedList
 * @similar  817, 2181
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 *
 * https://leetcode.cn/problems/linked-list-components/description/
 *
 * algorithms
 * Medium (61.25%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 92.1K
 * Testcase Example:  '[0,1,2,3]\n[0,1,3]'
 *
 * 给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。同时给定列表 nums，该列表是上述链表中整型值的一个子集。
 * 返回列表 nums 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 nums 中）构成的集合。
 *
 *
 *
 * 示例 1：
 * 输入: head = [0,1,2,3], nums = [0,1,3]
 * 输出: 2
 * 解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回
 * 2。
 *
 * 示例 2：
 * 输入: head = [0,1,2,3,4], nums = [0,3,1,4]
 * 输出: 2
 * 解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
 *
 *
 *
 * 提示：
 * 链表中节点数为n
 * 1 <= n <= 10^4
 * 0 <= Node.val < n
 * Node.val 中所有值 不同
 * 1 <= nums.length <= n
 * 0 <= nums[i] < n
 * nums 中所有值 不同
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //题意有误，表达二义性
    int numComponentsError(ListNode* head, vector<int>& nums) {
        unordered_set<int> dup(nums.begin(), nums.end());
        ListNode* p = head;
        int maxLen = 0;
        int cnt = 0;
        while (p != NULL) {
            int len = 0;
            while (p != NULL && dup.count(p->val)) {
                len++;
                p = p->next;
            }
            if (len > maxLen) {
                maxLen = len;
                cnt = 1;
            } else if (len == maxLen) {
                cnt++;
            }
            //maxLen = max(maxLen, len);
            if (p != NULL) {
                p = p->next;
            }
        }
        return cnt;
    }

    int numComponentsV1(ListNode* head, vector<int>& nums) {
        unordered_set<int> dup(nums.begin(), nums.end());
        ListNode* p = head;
        int cnt = 0;
        while (p != NULL) {
            // find start
            int len = 0;
            while (p != NULL && dup.count(p->val) == 0) {
                p = p->next;
            }
            while (p != NULL && dup.count(p->val)) {
                p = p->next;
                len++;
            }
            if (len>0) {
                cnt++;
            }
        }
        return cnt;
    }

    int numComponentsV2(ListNode *head, vector<int> &nums) {
        unordered_set<int> dup(nums.begin(), nums.end());
        ListNode* p = head;
        int cnt = 0;
        while (p != NULL) {
            // find start
            while (p != NULL && dup.count(p->val) == 0) {
                p = p->next;
            }
            if (p != NULL) {
                cnt++;
            }
            while (p != NULL && dup.count(p->val)) {
                p = p->next;
            }
        }
        return cnt;
    }

    int numComponents(ListNode *head, vector<int> &nums) {
        unordered_set<int> dup(nums.begin(), nums.end());
        ListNode* p = head;
        int cnt = 0;
        while (p != NULL) {
            // find start
            while (p != NULL && dup.count(p->val) == 0) {
                p = p->next;
            }
            if (p == NULL) {
                break;
            }
            cnt++;
            while (p != NULL && dup.count(p->val)) {
                p = p->next;
            }
        }
        return cnt;
    }
};
// @lc code=end

/*
Wrong Answer
6/57 cases passed (N/A)
Testcase
[0,1,2]
[0,2]
Answer
1
Expected Answer
2


Wrong Answer
11/57 cases passed (N/A)
Testcase
[3,4,0,2,1]
[4]
Answer
4
Expected Answer
1


Wrong Answer
26/57 cases passed (N/A)
Testcase
[0,1,2]
[1,0]
Answer
2
Expected Answer
1

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
