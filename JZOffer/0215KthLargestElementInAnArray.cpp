/**
 * @file
 * @brief  BOP 2.5
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-31
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

class Solution {
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
    int findKthLargestM01(vector<int>& nums, int k) {
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
    int partition(vector<int>& nums, int low, int high) {
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

     //M31
    int quickFind(vector<int>& nums, int low, int high, int k) {
        if (low >= high) {
            return nums[low];
        }
        int pivotidx = partition(nums, low, high);
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

// M32
int findK(vector<int>& data, int begin, int end, int k) {
    if (begin >= end) {  // to check
        return data[begin];
        //BUG return 0;
    }
    int idx = partition(data, begin ,end);
    int rightSize = end-idx;
    if (rightSize == k - 1) {
        return data[idx];
    }
    //BUG  if (rightSize > k)
    if (rightSize >= k) {
        return findK(data, idx+1, end, k);
    } else {  // not better
        //return findK(data, begin, idx, k-rightSize);
        return findK(data, begin, idx-1, k-rightSize-1);
    }
}


    // M3
    int findKthLargest(vector<int>& nums, int k) {
        //M31
        // return quickFind(nums, 0, nums.size() - 1, k);
        //M32
        return findK(nums, 0, nums.size() - 1, k);
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

//Runtime: 28 ms, faster than 57.29% of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage: 10.5 MB, less than 10.75% of C++ online submissions for Kth Largest Element in an Array.
    int findKthLargestM43(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        int ascOrder = nums.size()-k+1;
        for (size_t i = 0; i < ascOrder; ++i) {
            maxHeap.push(nums[i]);
        }
        for (size_t i = ascOrder; i < nums.size(); ++i) {
            maxHeap.push(nums[i]);
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

    int findKthLargestM5(vector<int>& nums, int k) {
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
    int len = 6;
    int nums[len] = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // int len = 9;
    // int nums[len] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // int k = 4;
    vector<int> nu(nums, nums + len);

    auto r1 = findKthLargest(nums, len, k);
    printf("C:%d\n", r1);

    if (0) {
        SolutionM5 s;
        s.HeapSort(nu);
        for (auto v : nu) {
            cout << v << " ";
        }
        cout << endl;
    }

    Solution s;
    for (k = 1; k <= len; k++) {
        auto r2 = s.findKthLargest(nu, k);
        cout <<"k=" << k <<  " CPP:" << r2 << endl;
    }

    return 0;
}

/*
Tips
第K大，K从1开始计数，数组末尾的是第1大，也是第N小
第K大等价于第N+1-K小


M0  排序加遍历
M01 基于map<num, cnt>插入排序
然后逆序遍历map，找出第K大的数

M02 sort从小到大排序+遍历第n-k个元素

M1 选择排序  S=O(K*N)
每次选出最大的，经过第K次选出第K大的。
或者直接stable_sort，输出nums[len-k]

M2 multiset

M3 快排原理
有2个考虑点
Q1 按升序还是按降序去分割
Q2 快排返回的下标idx如何和k去比较

M31  按照默认的升序排序，充分利用已排序数组的下标，第K大的数，在最终排序从小到大数组里面的下标是N-K，第1大的数的下标是N-1
也就是idx其实是第N-idx大的数，比较N-idx和k的大小，
N-idx=k 则return data[idx]
N-idx>k 则去右边 [idx+1, end]
N-idx<k 则去左边 [begin, idx-1]

M32 因为思维惯性，没有意识到K和下标的关系，而是比较 左右区间的元素个数和k的关系
rightSize = end-idx; //意味着idx这个元素是第rightSize+1大的
rightSize+1 == k return data[idx]
rightSize >= k 则去右边 [idx+1, end] ，必须小心 是 >= ,画一个案例就清楚了
rightSize < k 则去左边 [begin, idx] 在左边相当于 k-rightSize大
rightSize < k 则去左边 [begin, idx-1] 在左边相当于 k-rightSize-1大


M4  基于piority_queue
SKILL 有序数组切两半，右入小顶堆，左入大顶堆
M41 最小堆 堆大小为K
令a[0..n-1]为无序数组data[0..n-1]排序后的数组，a[n-1]是第1大，则a[n-k]是第k大
思想是 把a[n-k .. n-1]这k个元素放入大小为K的最小堆，则堆顶就是这K个元素里的最小值，即a[n-k]
遍历data[0..n-1]，把每个元素插入到最小堆，维持最小堆的数目为k，如果超过大小k，则pop堆顶，即淘汰a[0..n-k-1]

最大堆
M42 堆大小为N
把data[0..n-1]全部插入到堆里面，堆大小为n，然后pop K-1次,把K-1个最大值淘汰，则堆顶就是第K大的元素。

M43 堆大小为n-k+1
因为第K大等价于第N+1-K小
插入n+1-k个元素到堆里面，剩余的元素，每插入1个元素就pop 1次，相当于pop了k-1次最大值

M5 手动实现最大堆

*/
