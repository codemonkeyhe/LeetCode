/**
 * @file
 * @brief  十二大排序算法V2
 * @author MonkeyHe
 * @version  2.0
 * @date 20250608
 */

/*
TestData
https://leetcode.cn/leetbook/read/sort-algorithms/ev4tee/

LeetCode
164
283
215-第K大的元素
912
147
506
169
1122
164
561
1137


*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;



// LC215 TLE36-42
void BubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) { //总共执行 n-1躺
        for (int j = 1; j <= n - i; ++j) {
            if (a[j] < a[j-1]) { //把最大的放末尾
                swap(a[j], a[j-1]);
            }
        }
    }
}

// LC215 TLE36-42
void BetterBubbleSort(vector<int>& a) {
    int n = a.size();
    bool exchange = false;
    for (int i = 1; i < n; ++i) {
        exchange = false;
        for (int j = 1; j <= n - i; ++j) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                exchange = true;
            }
        }
        if (!exchange) break;
    }
}

// LC215 TLE36-42
void CockTailSort(vector<int>& a) {
    int n = a.size();
    int head = 0;
    int tail = n-1;
    while(head < tail) {
        // 最小的放到head处
        for (int j = tail; j > head; --j) {
            if (a[j] < a[j-1])
                swap(a[j], a[j-1]);
        }
        head++;
        // 最大的放到tail处
        for (int j = head; j < tail; ++j) {
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
        tail--;
    }
}



// LC215 TLE38-42
void InsertSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) //保证了稳定性
            continue;
        int x = a[i];     //待插入元素复制为哨兵
        int j = i - 1;  // j指向有序区间[0 .. i-1]的末尾元素
        while (j >= 0 && x < a[j]) {  // 注意此处的稳定性 if x==a[j],则把x插入到a[j]之后
            a[j + 1] = a[j];  //元素后移
            j--;
        }
        a[j + 1] = x;  //插入到正确位置
    }
}


// LC215 TLE38-42
void BinInsertSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) //保证了稳定性
            continue;
        int x = a[i];  //待插入元素复制为哨兵 , [0 i-1]为已排序区间
        int low = 0;
        int high = i - 1;
        while (low <= high) { //注意是<=，这样保证了当low==high时，也会把最后的a[low]和哨兵x进行比较
            int mid = low+((high-low)>>1); //避免了下标溢出
            if (a[mid] > x) { //若改为>=，则破坏稳定性
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        int pos = low; //最终的插入位置 low或者high+1 都可以
        //int pos = high+1;
        for (int j = i - 1; j >= pos; --j) {
            a[j + 1] = a[j];
        }
        a[pos] = x;    // high+1为插入的位置
    }
}


//LC215 42/42 cases passed (1411 ms)
static const int DELTA_LEN = 5;
static const int DELTA[DELTA_LEN] = {9, 5, 3, 2, 1};
void ShellInsertSort(vector<int>& a) {
    int n = a.size();
    for (int k = 0; k < DELTA_LEN; ++k) {
        int dt = DELTA[k];
        //i从dt开始遍历，因为dt之前的元素都是每个有序子序列的第一个元素
        for (int i = dt; i < n; ++i) {  //每次++i说明了之前的a[i]已经插入到有序的子序列中了
            if (a[i] >= a[i - dt])  //说明已经有序了，不需要调整a[i]
                continue;
            int x = a[i];   //待插入元素a[i]暂存x
            int j = i - dt; //j指向某个有序子序列的末尾
            while (j >= 0 && a[j] > x) {  //从有序子序列末尾开始往前寻找插入位置
                a[j + dt] = a[j];
                j -= dt;
            }
            a[j + dt] = x;
        }
    }
}


// LC215 TLE38-42
void SelectSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int min = a[i];
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < min) {
                min = a[j];
                idx = j;
            }
        }
        if (idx != i) {
            swap(a[idx], a[i]);
        }
    }
}

/*
双指针swap法，swap后不能++low和--high，否则会有bug
i和j必须保留，不建议修改low和high，并且最后swap时，对原始的low有依赖
 */

int PartitionV2(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j) {
        //从右往左找到第一个小于pivot的值的下标
        while (i < j && a[j] >= pivot)
            --j;
        //从左往右找到第一个大于pivot的值的下标
        while (i < j && a[i] <= pivot)
            ++i;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[i]);
    return i;
}


// LC215 TLE41-42
void QuickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = PartitionV2(a, low, high);
        QuickSort(a, low, p - 1);
        QuickSort(a, p + 1, high);
    }
}


// for maxHeap adjust
void HeapAdjust(vector<int>& a, int i, int n) {
    int cur = a[i];
    int j = (i << 1) + 1;  // j指向左孩子
    while (j < n) {
        if (j + 1 < n && a[j] < a[j + 1]) {
            //右孩子大的话,j指向右孩子
            j++;
        }
        if (a[j] <= cur)
            break;
        a[i] = a[j];  //大的孩子往上浮
        i = j;
        j = (i << 1) + 1;
    }
    a[i] = cur;
}

//LC215 42/42 cases passed (53 ms)
void HeapSort(vector<int>& a) {
    // BuildMaxHeap
    int n = a.size();
    //int idx = (n - 1) / 2; // last non-leaf node
    int idx = n / 2 - 1; // last non-leaf node
    for (int i = idx; i >= 0; --i) {
        HeapAdjust(a, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        //把堆顶最大值放到末尾
        swap(a[0], a[i]);
        //对剩余的a[0..i-1]重新调整为堆
        HeapAdjust(a, 0, i);
    }
}

/*
首选
将有序的a[s…m]和有序a[m+1…e]，借助辅助数组h[s…e],归并到a[s..e]
性能太低, 每次合并，每个元素至少拷贝2次，整体要拷贝2n次
*/
void MergeV1(vector<int>& a, int s, int m, int e, vector<int>& help) {
    int i = s;      //用于遍历 a[s…m]
    int j = m + 1;  //用于遍历 a[m+1…e]
    int k = s;
    while (i <= m && j <= e) {
        if (a[j] <= a[i])
            help[k++] = a[j++];
        else
            help[k++] = a[i++];
    }
    while (i <= m)
        help[k++] = a[i++];
    while (j <= e)
        help[k++] = a[j++];
    //将有序的help[s..e]拷贝回a[s..e]
    for(int i = s; i <= e; ++i) {
        a[i] = help[i];
    }
}



/*
将有序的a[s…m]和有序a[m+1…e]，借助辅助数组h[m+1…e],归并到a[s..e]
即把 有序的a[s…m]和有序h[m+1…e]就地归并，V2减少了元素拷贝次数
这点优化没意义，可读性不好，首选V1
*/
void MergeV2(vector<int>& a,  int s, int m, int e, vector<int>& help) {
    for (int j = m + 1; j <= e; ++j) {
        help[j] = a[j];
    }
    int i = m;  //用于逆序遍历 a[s…m]
    int j = e;  //用于逆序遍历 h[m+1…e]
    int k = e;
    while (i >= s && j > m) {
        if (help[j] <= a[i])
            a[k--] = a[i--];
        else
            a[k--] = help[j--];
    }
    while (i >= s)
        a[k--] = a[i--];
    while (j > m)
        a[k--] = help[j--];
}

//把a[s..e]递归的归并到h[s..e]
//LC215 42/42 cases passed
void MSort(vector<int>& a, int s, int e, vector<int>& help) {
    if (s >= e) {
        return;
    }
    int m = (s + e) >> 1;
    MSort(a, s, m, help);      //递归左序列
    MSort(a, m + 1, e, help);  //递归右序列
    //LC215 42/42 cases passed (71 ms)
    //MergeV1(a, s, m, e, help);
    //LC215 42/42 cases passed (79 ms)
    MergeV2(a, s, m, e, help);
}

void MergeSort(vector<int>& a) {
    int n = a.size();
    vector<int> help(n, 0)
    MSort(a, 0, n - 1, help);
}


/*
把a[0..n-1]排序到res[0..n-1]
若已知a[0..n-1]的元素的(min,max)范围在一个很小的值，比如1000，都可以使用计数排序
count一开始存储的是次数，其实遍历count数组一样可以把排序结果写到res数组。
之所以多了一步，把count里面的次数升级成关键字在有序数组中的最后位置，是因为不一定是给int排序
T可能是一个类对象，只是用类对象里面的某个key排序而已，此时就必须把a[i]的元素搬到res[j]
*/
//LC215 42/42 cases passed (8 ms)
void CountingSort(vector<int>& a, vector<int>& res) {
    int n = a.size();
    if (n == 0)
        return;
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        } else if (a[i] > max) {
            max = a[i];
        }
    }
    int k = max - min + 1;
    vector<int> count(k, 0);
    for (int i = 0; i < k; ++i) {
        count[i] = 0;  //初始化为0
    }
    for (int i = 0; i < n; ++i) {
        //统计出现的次数
        count[a[i] - min]++;
    }
    for (int i = 1; i < k; ++i) {
        //统计数字i在最终排序数组中最后出现的位置
        // 位置从1开始计数，因此复制到res时lastPos要减去1
        count[i] = count[i] + count[i-1];
    }
    for (int i = n-1; i>=0; i--) {
        int offset = a[i] - min;
        int lastPos = count[offset];
        res[lastPos-1] = a[i];
        count[offset]--;
    }
}

void CountingSortV2(vector<int>& a) {
    int n = a.size();
    if (n == 0)
        return;
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        } else if (a[i] > max) {
            max = a[i];
        }
    }
    int k = max - min + 1;
    vector<int> count(k, 0);
    for (int i = 0; i < k; ++i) {
        count[i] = 0;  //初始化为0
    }
    for (int i = 0; i < n; ++i) {
        //统计出现的次数
        count[a[i] - min]++;
    }
    for (int i = 1; i < k; ++i) {
        //统计数字i在最终排序数组中最后出现的位置
        // 位置从1开始计数，因此复制到res时lastPos要减去1
        count[i] = count[i] + count[i-1];
    }

    vector<int> res(n,0);
    for (int i = n-1; i>=0; i--) {
        int offset = a[i] - min;
        int lastPos = count[offset];
        res[lastPos-1] = a[i];
        count[offset]--;
    }
    a = res;
}


/*
支持负数，负数放前10个桶[1~10]，正数放后10个桶[10~19]
LC164
LC215 42/42 cases passed (390 ms)
*/
void RadixSort(vector<int>& a) {
    int n = a.size();
    auto [minV, maxV] = std::minmax_element(a.begin(), a.end());
    int maxVal = max(std::abs(*minV), *maxV);
    int width = 0;
    while (maxVal > 0) {
        maxVal = maxVal / 10;
        width++;
    }

    int radix = 0;
    int m = 1;
    vector<list<int> > v(20, list<int>());
    while (width-- > 0) {
        //分配
        for (int i = 0; i < n; i++) {
            radix = (a[i] / m) % 10 + 10;
            v[radix].push_back(a[i]);
        }
        //收集
        int j = 0;
        for (int i = 0; i < 20; i++) {
            list<int>& li = v[i];
            typename list<int>::iterator it;
            for (it = li.begin(); it != li.end(); ) {
                a[j++] = *it;
                it = li.erase(it);
            }
        }
        m *= 10;
    }
}

//LC215 42/42 cases passed (27 ms)
void RadixSortV2(vector<int>& a) {
    int n = a.size();
    auto [minV, maxV] = std::minmax_element(a.begin(), a.end());
    int maxVal = max(std::abs(*minV), *maxV);
    int width = 0;
    while (maxVal > 0) {
        maxVal = maxVal / 10;
        width++;
    }

    int radix = 0;
    int m = 1;
    vector<vector<int> > v(20, vector<int>());
    while (width-- > 0) {
        //分配
        for (int i = 0; i < n; i++) {
            radix = (a[i] / m) % 10 + 10;
            v[radix].push_back(a[i]);
        }
        //收集
        int j = 0;
        for (int i = 0; i < 20; i++) {
            vector<int>& li = v[i];
            for (auto& val: li) {
                a[j++] = val;
            }
            li.clear();
        }
        m *= 10;
    }
}



class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void LXR(Node* root, vector<int>& res) {
    if (root == NULL)
        return;
    LXR(root->left, res);
    res.push_back(root->data);
    LXR(root->right, res);
}

Node* ArrayToBinaryTree(vector<int>& a) {
    int n = a.size();
    Node* root = new Node(a[0]);
    Node* p = NULL;
    for (int i = 1; i < n; ++i) {
        Node* t = new Node(a[i]);
        p = root;
        while (p != NULL) {
            if (t->data < p->data) { //插入到左边
                if (p->left == NULL) {
                    p->left = t;
                    break;
                } else {
                    p = p->left;
                }
            } else { //相等也插入到右边
                if (p->right == NULL) {
                    p->right = t;
                    break;
                } else {
                    p = p->right;
                }
            }
        }
    }
    return root;
}

// LC215 TLE41-42
void BinaryTreeSort(vector<int>& a) {
    Node* r = ArrayToBinaryTree(a);
    vector<int> res;
    LXR(r, res);
    a = res;
}


