/**
 * @file
 * @brief  BOP 2.5
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-31;2025-06-23
 * @tag  sort,quickSelect,heapSort
 * @similar 215, 347, 692
 */

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;


/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.40%)
 * Likes:    2760
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.3M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    int partitions(vector<int>& a, int low, int high) {
        int pivot = a[low];
        int i = low;
        int j = high;
        while (i < j) {
            // 从右往左找到第一个小于pivot的值的下标
            while (i < j && a[j] >= pivot)
                --j;
            // 从左往右找到第一个大于pivot的值的下标
            while (i < j && a[i] <= pivot)
                ++i;
            if (i < j) {
                swap(a[i], a[j]);
            }
        }
        swap(a[low], a[i]);
        return i;
    }

    int quickFind(vector<int>& nums, int low, int high, int k) {
        int pivotidx = partitions(nums, low, high);
        int order = nums.size() - pivotidx;
        if (order == k) {
            return nums[pivotidx];
        }
        if (order > k) {
            return quickFind(nums, pivotidx + 1, high, k);
        } else {
            return quickFind(nums, low, pivotidx - 1, k);
        }
        return nums[low];
    }

    int findKthLargestM1(vector<int>& nums, int k) {
        return quickFind(nums, 0, nums.size() - 1, k);
    }


    void HeapAdjust(vector<int>& a, int i, int n) {
        int cur = a[i];
        int j = (i << 1) + 1;  // j指向左孩子
        while (j < n) {
            if (j + 1 < n && a[j] < a[j + 1]) {
                // 右孩子大的话,j指向右孩子
                j++;
            }
            if (a[j] <= cur)
                break;
            a[i] = a[j];  // 大的孩子往上浮
            i = j;
            j = (i << 1) + 1;
        }
        a[i] = cur;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // BuildMaxHeap
        int n = nums.size();
        //int idx = (n - 1) / 2;  // last non-leaf node
        int idx = n/2 - 1;  // still ok, because n is not idx
        for (int i = idx; i >= 0; --i) {
            HeapAdjust(nums, i, n);
        }
        // k-1次最大放末尾，堆顶就是第K大
        int last = n - 1;
        for (int i = 0; i < k - 1; i++) {
            // 把堆顶最大值放到末尾
            swap(nums[0], nums[last]);
            // 对剩余的a[0..last-1]重新调整为堆
            HeapAdjust(nums, 0, last);
            last--;
        }
        return nums[0];
    }
};
// @lc code=end



class SolutionOld {
public:

    //Runtime: 28 ms, faster than 26.58% of C++ online submissions for Kth Largest Element in an Array.
    //Memory Usage: 9.2 MB, less than 93.94% of C++ online submissions for Kth Largest Element in an Array.
    //M0 map<num, cnt>
    int findKthLargestM0(vector<int>& nums, int k) {
        map<int, int> num2cnt;
        for (size_t i =0; i < nums.size(); ++i) {
            num2cnt[nums[i]] += 1;
        }
        int idx = 0;
        auto it = num2cnt.rbegin();
        for (; it != num2cnt.rend(); ++it) {
            idx+= it->second;
            if (idx >=k) {
                return it->first;
            }
        }
        return 0;
    }


//https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
//Runtime: 20 ms, faster than 34.25% of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage: 9.5 MB, less than 34.85% of C++ online submissions for Kth Largest Element in an Array.
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        for (int num : nums) {
            mset.insert(num);
            if (mset.size() > k) {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }

//Runtime: 36 ms, faster than 20.64% of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Kth Largest Element in an Array.
// 快排被削弱了，看了其他的C++快排答案，都是36ms.
    int partitions(vector<int>& nums, int low, int high) {
        int p = nums[low];
        while (low<high) {
            while(low<high && nums[high] >= p) --high;
            nums[low] = nums[high];
            while(low<high && nums[low] <= p) ++low;
            nums[high] = nums[low];
        }
        nums[low] = p;
        return low;
    }

    int quickFind(vector<int>& nums, int low, int high, int k) {
        if (low < high) {
            int pivotidx = partitions(nums, low, high);
            int order = nums.size() - pivotidx;
            if (order == k) {
                return nums[pivotidx];
            }
            if (order > k) {
                return quickFind(nums, pivotidx + 1, high, k);
            } else {
                return quickFind(nums, low, pivotidx - 1, k);
            }
        }
        return nums[low];
    }

    int findKthLargestM3(vector<int>& nums, int k) {
        return quickFind(nums, 0, nums.size() - 1, k);
    }

    // 20 ms  34.49%
    int findKthLargestM41(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (size_t i = 0; i < nums.size(); ++i) {
            minHeap.push(nums[i]);
            if (minHeap.size() >k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }

    // 20 ms  34.49%
    int findKthLargestM42(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for (size_t i = 0; i < k-1; ++i) {
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};


static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// Runtime: 4 ms, faster than 99.79% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Kth Largest Element in an Array.
class SolutionM5 {
public:
    void heapAdjust(vector<int>& nums, int s, int len) {
        int child = (s<<1) +1;
        int tmp = nums[s];
        while(child < len) {
            if (child+1 < len && nums[child] < nums[child+1]) {
               ++child;
            }
            if (tmp >= nums[child])
                break;
            nums[s] = nums[child];
            s = child;
            child = (s<<1)+1;
        }
        nums[s] = tmp;
    }

    void buildMaxHeap(vector<int>& nums) {
        int len = nums.size();
        int idx = len/2-1;
        for (int i = idx; i >=0; --i) {
            heapAdjust(nums, i, len);
        }
    }

    void HeapSort(vector<int>& nums) {
        buildMaxHeap(nums);
        int len = nums.size();
        int tmp = 0;
        for (int i = len-1; i >0 ; --i) {
            //swap(nums[0], nums[len-1]);
            tmp = nums[i];
            nums[i] = nums[0];
            nums[0] = tmp;
            heapAdjust(nums, 0, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        int len = nums.size();
        int tmp = 0;
        for (int i = 0; i <k-1 ; ++i) {
            //swap(nums[0], nums[--len]);
            --len;
            tmp = nums[len] ;
            nums[len] = nums[0];
            nums[0] = tmp;
            heapAdjust(nums, 0, len);
        }
        return nums[0];
    }

};

// M1 选择排序  S=O(K*N)
// Runtime: 120 ms, faster than 14.23% of C online submissions for Kth Largest
// Element in an Array. Memory Usage: 6 MB, less than 100.00% of C online
// submissions for Kth Largest Element in an Array.
int findKthLargest(int* nums, int numsSize, int k) {
    int tmp = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < numsSize - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                tmp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    return nums[numsSize - k];
}



int main() {
    // int len = 6;
    // int nums[len] = {3, 2, 1, 5, 6, 4};
    // int k = 2;

    int len = 9;
    int nums[len] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    vector<int> nu(nums, nums + len);

    auto r1 = findKthLargest(nums, len, k);
    printf("C:%d\n", r1);

    SolutionM5 s;
    if (1) {
        s.HeapSort(nu);
        for (auto v : nu) {
            cout << v << " ";
        }
        cout << endl;
    }

    auto r2 = s.findKthLargest(nu, k);
    cout << "CPP:" << r2 << endl;

    return 0;
}

/*
Tips

M0 map<num, cnt>　
然后逆序遍历map，找出第K大的数

M1 选择排序  S=O(K*N)
每次选出最大的，经过第K次选出第K大的。
或者直接stable_sort，输出nums[len-k]

M2 multiset

M3 快排原理

M4 最小堆 最大堆
piority_queue

M5 手动实现最大堆

*/
