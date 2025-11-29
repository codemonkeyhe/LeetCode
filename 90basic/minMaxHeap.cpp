#include <vector>

using namespace std;


/*
LC 295

    MinHeap minHeap;
    MaxHeap maxHeap;

Equal STD:

    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int, vector<int>, less<int> > maxHeap;

*/

class MaxHeap {
public:
    MaxHeap() { }

    bool empty() { return vc.empty(); }

    int top() { return vc[0]; }

    int size() { return vc.size(); }

    void pop() {
        vc[0] = vc.back();
        vc.pop_back();
        heapAdjustDown(0, vc.size());
    }

    void push(int val) {
        vc.push_back(val);
        heapAdjustUp(vc.size() - 1);
    }

    // i为新节点，从i开始往下调整堆 i = [0, len-1]
    void heapAdjustDown(int i, int len) {
        int cur = vc[i];
        int p = i; // parent
        int j = 2 * p + 1; //leftSon
        while (j < len) {
            if (j + 1 < len && (vc[j] < vc[j + 1])) {
                j++; // j points to bigger one
            }
            if (cur >= vc[j]) {  // no need to swap
                break;
            }
            vc[p] = vc[j]; // son go up
            p = j;
            j = 2 * j + 1;
        }
        vc[p] = cur;
    }

    // i为新节点，从i开始往上调整堆
    void heapAdjustUp(int i) {
        int cur = vc[i];
        int j = i; //son
        int p = (i - 1) / 2; //parent
        while (p >= 0 && j != 0) {
            if (cur <= vc[p]) {  // no need to swap
                break;
            }
            vc[j] = vc[p]; // parent go down
            j = p;
            p = (p - 1) / 2;
        }
        vc[j] = cur;
    }

    vector<int> vc;
};


class MinHeap {
public:
    MinHeap() { }

    bool empty() { return vc.empty(); }

    int top() { return vc[0]; }

    int size() { return vc.size(); }

    void pop() {
        vc[0] = vc.back();
        vc.pop_back();
        heapAdjustDown(0, vc.size());
    }

    void push(int val) {
        vc.push_back(val);
        heapAdjustUp(vc.size() - 1);
    }

    // i为新节点，从i开始往下调整堆 i = [0, len-1]
    void heapAdjustDown(int i, int len) {
        int cur = vc[i];
        int pa = i;
        int son = 2 * pa + 1;
        while (son < len) {
            if (son + 1 < len && (vc[son] > vc[son + 1])) {
                son++; //
            }
            if (cur <= vc[son]) {  // no need to swap
                break;
            }
            vc[pa] = vc[son]; //son go up
            pa = son;
            son = 2 * son + 1;
        }
        vc[pa] = cur;
    }

    // i为新节点，从i开始往上调整堆
    void heapAdjustUp(int i) {
        int cur = vc[i];
        int son = i;
        int pa = (i - 1) / 2;
        while (pa >= 0 && son != 0) {
            if (cur >= vc[pa]) {  // no need to swap
                break;
            }
            vc[son] = vc[pa]; //parent go down
            son = pa;
            pa = (pa - 1) / 2;
        }
        vc[son] = cur;
    }

    vector<int> vc;
};
