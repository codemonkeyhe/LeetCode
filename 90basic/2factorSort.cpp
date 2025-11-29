#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>


using namespace std;

    static bool lessFn1asc2asc(pair<int, int>& a, pair<int, int>& b) {
        if (a.first < b.first) {
            return true;
        }
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return false;
    }

    static bool lessFn1asc2desc(pair<int, int> &a, pair<int, int> &b) {
        if (a.first < b.first) {
            return true;
        }
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return false;
    }

    static bool greaterFn1desc2desc(pair<int, int> &a, pair<int, int> &b) {
        if (a.first > b.first) {
            return true;
        }
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return false;
    }

    static bool greaterFn1desc2asc(pair<int, int> &a, pair<int, int> &b) {
        if (a.first > b.first) {
            return true;
        }
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return false;
    }

int main() {
    cout << "========== MAIN BEGIN ============" << endl;

    vector<pair<int, int>> data = {
        {3, 100}, {4, 10}, {3, 60}, {2, 72}, {3, 80}, {4, 123}, {2, 0}};


    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&lessFn1asc2desc)> heap(lessFn1asc2desc);
    for (auto& pa : data) {
        heap.push(pa);
    }

    sort(data.begin(), data.end(), greaterFn1desc2asc);
    for (auto& pa : data) {
        cout << "[" << pa.first << "," << pa.second << "], ";
    }
    cout << endl;

    cout << "HEAP: ";
    while(!heap.empty()) {
        auto cur = heap.top();
        heap.pop();
        cout << "[" << cur.first << "," << cur.second << "], ";
    }
    cout << endl;

    cout << "========== MAIN END ============" << endl;

    return 0;
}

/*
    // less(a,b) T: a排前面 F:a排后面
    // greater(a,b) T: a排前面 F:a排后面
    其实和名字没关系cmpFn有2个标准
    cmpFn(a,b)
    1 True: a排前面，即a,b  False:a排后面，即 b,a
    2 a == b 时，必须返回false

    对于堆，正好相反

默认大根堆
    priority_queue<int> maxHeap
等价
    priority_queue<int,vector<int>,less<int>> maxHeap;
小根堆
    priority_queue<int,vector<int>,greater<int>> minHeap;


因为建堆是从最后一个非叶子结点开始，不管是maxHeap还是minHeap，建堆时需要从下往上调整节点，当堆建好了，进行堆排序时，都是从上往下开始调整。
大根堆用的是less，即小的沉下去，保持父节点大于子节点
小根堆用的是greater，即大的沉下去，保持父节点小于子节点
堆算法在实现时，父子节点之间的关系是：
大根堆：父节点 >= 子节点
if (comp(parent, child)) { // 如果父节点 < 子节点
    // 需要调整堆，交换父子
}
这里comp使用less时，当父节点小于子节点就进行调整，这正好符合大根堆的性质。


和函数名无关系
    cmpFn(a,b)
    1 True: a沉下去，即b先出堆  False:a先上来，即a先出堆
    2 a == b 时，必须返回false

对照表
sort(lessFn1asc2asc) ==  heap(greaterFn1desc2desc)
sort(lessFn1asc2desc) ==  heap(greaterFn1desc2asc)
sort(greaterFn1desc2desc) ==  heap(lessFn1asc2asc)
sort(greaterFn1desc2asc) ==  heap(lessFn1asc2desc)


*/