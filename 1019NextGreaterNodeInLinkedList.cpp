/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-27
 * @tag  linkedList,monotonicStack
 * @similar  496, 503
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 *
 * https://leetcode.cn/problems/next-greater-node-in-linked-list/description/
 *
 * algorithms
 * Medium (64.79%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    72.7K
 * Total Submissions: 109.4K
 * Testcase Example:  '[2,1,5]'
 *
 * 给定一个长度为 n 的链表 head
 * 对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。
 * 返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i
 * 个节点没有下一个更大的节点，设置 answer[i] = 0 。
 *
 *
 *
 * 示例 1：
 * 输入：head = [2,1,5]
 * 输出：[5,5,0]
 *
 *
 * 示例 2：
 * 输入：head = [2,7,4,3,5]
 * 输出：[7,0,5,5,0]
 *
 *
 *
 *
 * 提示：
 * 链表中节点数为 n
 * 1 <= n <= 10^4
 * 1 <= Node.val <= 10^9
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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int> > st; // first: val second: idx
        ListNode* p = head;
        int idx = 0;
        vector<int> res;
        while (p != NULL) {
            if (res.capacity() < idx+1) {
                res.resize(idx * 2 + 100);
                // ERROR res.reserve(idx+1);
            }
            while (!st.empty() && (p->val > st.top().first) ) {
                int i = st.top().second;
                res[i] = p->val;
                st.pop();
            }
            st.push(make_pair(p->val, idx));
            p = p->next;
            idx++;
        }
        res.resize(idx);
        while(!st.empty()) {
            int i = st.top().second;
            res[i] = 0;
            st.pop();
        }
        return res;
    }

    vector<int> nextLargerNodes2(ListNode* head) {
        stack<pair<int, int> > st; // first: val second: idx
        ListNode* p = head;
        int idx = 0;
        vector<int> res;
        while (p != NULL) {
            res.push_back(0);
            while (!st.empty() && (p->val > st.top().first) ) {
                int i = st.top().second;
                res[i] = p->val;
                st.pop();
            }
            st.push(make_pair(p->val, idx));
            p = p->next;
            idx++;
        }
        return res;
    }


};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
