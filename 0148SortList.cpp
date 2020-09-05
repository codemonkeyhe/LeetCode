/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-0
 * @tag
 * @similar　147 86-PartitionList  21-MergeTwoSortedList
 */

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
//基于递归实现
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }


   /*
   基于快慢指针实现
    head: 4->2->1->3->NULL 分割后
    head: 4->2->NULL   slow:1->3->NULL

    head: 4->NULL 分割后
    head: 4->NULL  slow:4->NULL
    会导致无限分割，因此head->next==NULL时，不用调用cutMid
   */
    ListNode* cutMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = slow;
        while(fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        return slow;
    }


/*
Runtime: 56 ms, faster than 41.15% of C++ online submissions for Sort List.
Memory Usage: 16.7 MB, less than 34.31% of C++ online submissions for Sort List.
M11
*/
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* mid = cutMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode* newHead = mergeTwoSortedLists(left, right);
        return newHead;
    }

/*
Runtime: 52 ms, faster than 47.28% of C++ online submissions for Sort List.
Memory Usage: 15.5 MB, less than 35.39% of C++ online submissions for Sort List.
M12
*/
    ListNode* sortListM12(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            n++;
        }
        return mergeSort(head, n);
    }

    ListNode* mergeSort(ListNode* head, int n) {
        if (n <= 1) {
            return head;
        }
        int midSize = n/2;
        ListNode* mid = cutMid(head, midSize);
        ListNode* left = mergeSort(head, midSize);
        ListNode* right = mergeSort(mid, n - midSize);
        ListNode* newHead = mergeSortedLists(left, right);
        return newHead;
    }

//基于长度实现  先遍历链表长度n，再走n/2
/*
分割链表 n 分割成  [1 .. len]  [len+1 .. n]
*/
    ListNode* cutMid(ListNode* head, int len){
        ListNode* mid = head;
        while (len-- > 1) {
            mid = mid->next;
        }
        ListNode* pre = mid;
        mid = mid->next;
        pre->next = NULL;
        return mid;
    }

//基于迭代实现
    ListNode* mergeSortedLists(ListNode* l1, ListNode* l2) {
        ListNode preHeader(-1);
        ListNode* tail = &preHeader;
        while(l1!=NULL && l2!=NULL) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1!=NULL) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return preHeader.next;
    }

    /*
    快排 修改节点指针 速度巨慢
    应该改为修改节点的值，指针不变
   Runtime: 688 ms, faster than 6.18% of C++ online submissions for Sort List.
Memory Usage: 18 MB, less than 34.02% of C++ online submissions for Sort List.
    */
    ListNode* sortListM2(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
        }
        quickSortList(head, tail);
        return head;
    }

    void quickSortList(ListNode* &begin, ListNode* &end) {
        if (begin == NULL) return ;
        if (begin == end) return;
        ListNode* pivot = partitionList(begin, end);
        quickSortList(begin, pivot);
        quickSortList(pivot->next, end);
    }


    // [begin , .., end] (stop)
    ListNode* partitionList(ListNode* &begin, ListNode* &end) {
        ListNode* pivot = begin;
        ListNode left(-1);
        ListNode* l = &left;
        ListNode* r = pivot;
        ListNode* p = begin->next;
        ListNode* stop = end->next;
        while (p && p != stop) {
            if (p->val < pivot->val) {
                l->next = p;
                l = l->next;
            } else {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        l->next = pivot;
        r->next = stop;
        begin = left.next;
        end = r;
        return pivot;
    }
};



struct ListNode* sortList(struct ListNode* head){

}


int main() {
    Solution s;
    const int len = 4;
    int nums[len] = {3,1,2,4};
    vector<int> nu(nums, nums+len);
    ListNode* head = buildList(nu, len);
    auto res = s.sortListM2(head);
    printList(res);
}


/*
Tips
插入排序为O(n^2)不可用
只有3大排序算法小于nlogn 分别是 计数排序 桶排序 基数排序
平均为nlogn的有  快排  堆牌  希尔(增量插入排序) 归并排序

因为要求是常量空间，因此不能用递归去实现归并和快排, 得用循环来实现

M1 归并排序
MergeSort 都面临一个问题,计算中间节点mid时
    int m = (s + e) >> 1;
在链表里如何计算mid,快慢指针。用来快慢指针的话，需要O(N)，但是不会影响最终的时间复杂度
最终平均性能依然是 O(nlogn)
T(n) = O(n/2){fast_slow_find_mid}+2*T(n/2){divide}+ O(n){merge}

M2 快排
数组是传递下标去递归，链表只能传递边界节点去递归了
核心点在于PartitionList [参见0086]
链表方便分割 区间
[low high)  mid
[low, mid)  [mid, high)

快排的核心在于要交换值，
对于链表来说，swap两个节点非常麻烦，可以改成链表节点的顺序不变，只是swap节点的值。

如果非要修改指针的指向，则非常耗时。


*/


