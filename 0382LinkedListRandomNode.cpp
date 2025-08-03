/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-03
 * @tag  math,randomized
 * @similar   382, 394, 398, 470
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 *
 * https://leetcode.cn/problems/linked-list-random-node/description/
 *
 * algorithms
 * Medium (72.64%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    71.3K
 * Total Submissions: 98.2K
 * Testcase Example:  '["Solution","getRandom","getRandom","getRandom","getRandom","getRandom"]\n' +
  '[[[1,2,3]],[],[],[],[],[]]'
 *
 * 给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。
 * 实现 Solution 类：
 * Solution(ListNode head) 使用整数数组初始化对象。
 * int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。
 *
 *
 *
 *
 * 示例：
 * 输入
 * ["Solution", "getRandom", "getRandom", "getRandom", "getRandom",
 * "getRandom"]
 * [[[1, 2, 3]], [], [], [], [], []]
 * 输出
 * [null, 1, 3, 2, 2, 3]
 *
 * 解释
 * Solution solution = new Solution([1, 2, 3]);
 * solution.getRandom(); // 返回 1
 * solution.getRandom(); // 返回 3
 * solution.getRandom(); // 返回 2
 * solution.getRandom(); // 返回 2
 * solution.getRandom(); // 返回 3
 * // getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。
 *
 *
 *
 * 提示：
 * 链表中的节点数在范围 [1, 10^4] 内
 * -10^4 <= Node.val <= 10^4
 * 至多调用 getRandom 方法 10^4 次
 *
 *
 *
 *
 * 进阶：
 * 如果链表非常大且长度未知，该怎么处理？
 * 你能否在不使用额外空间的情况下解决此问题？
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
class Solution1 {
public:
    Solution1(ListNode* head) {
        ListNode *p = head;
        while (p != NULL) {
            vc.push_back(p);
            p = p->next;
        }
    }

    int getRandom() {
        int ran = rand()%vc.size();
        return vc[ran]->val;
    }

    vector<ListNode*> vc;
};

class Solution {
public:
    Solution(ListNode* head) {
        li = head;
    }

    int getRandom() {
        int i = 1; // ibegin from 1
        int res = 0;
        ListNode* p = li;
        while (p != NULL) {
            // 以 1/i的概率进行替换
            if (rand() % i == 0) {
                res = p->val;
            }
            i++;
            p = p->next;
        }
        return res;
    }

    ListNode* li;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

/*
i=1   rand[0,1)      pNode1=100%
i=2   rand[0,2)      pNode2=1/2   pNode1=(第一步是node1，且第二步不是node2)=100%*(1/2)=1/2
i=3   rand[0,3)      pNode3=1/3
pNode1=(第2步是node1,第3步不是node3(没有被替换))=(1/2)*(1-1/3)=1/2* (2/3) = 1/3
pNode2=(第2步是node2,第3步不是node3(没有被替换))=(1/2)*(1-1/3)=1/2* (2/3) = 1/3

i=4   rand[0,4)      pNode4=1/4
pNode1=(第3步是node1,第4步不是node4(没有被替换))=(1/3)*(1-1/4)=1/3 * (3/4) = 1/4
pNode2=(第3步是node2,第4步不是node4(没有被替换))=(1/3)*(1-1/4)=1/3 * (3/4) = 1/4
pNode3=(第3步是node3,第4步不是node4(没有被替换))=(1/3)*(1-1/4)=1/3 * (3/4) = 1/4


同理
i=N时  rand[0,N)    pNodeN=1/N
其余的Node1到NodeN-1的概率都是1/N


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
