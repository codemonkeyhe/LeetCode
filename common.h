#ifndef  __COMMON_H__
#define  __COMMON_H__

#include <vector>
#include <iostream>
using namespace std;

//for cpp and c
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//for cpp and c
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() {}
};


struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;

    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};



//for n-tree
namespace ntree {
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
}

//used for graph
namespace graph {
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

namespace C {
/* use for graph c langage
 * Definition for a Node.
*/
struct Node {
    int val;
    int numNeighbors;
    struct CNode** neighbors;
};
}  // graph::C

} // graph

//用 EMPTY_V来表示NULL节点
const int EMPTY_V = 0x80000000;
//nums里面必须包含完备的树节点
TreeNode* buildBinaryTree(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    vector<TreeNode*> data;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == EMPTY_V) {
            data.push_back(NULL);
        } else {
            TreeNode* p = new TreeNode(nums[i]);
            data.push_back(p);
        }
    }
    int len = data.size();
    for (int i = 0; i < len; ++i) {
        TreeNode* node = data[i];
        if (node == NULL) {
            continue;
        }
        int leftPos = 2 * i + 1;
        int rightPos = leftPos + 1;
        if (leftPos < len) {
            node->left = data[leftPos];
        }
        if (rightPos < len) {
            node->right = data[rightPos];
        }
    }
    return data[0];
}

// "5, 4, 7, 3, null, 2, null, -1, null, 9"
//Leetcode 297
// string serialize(TreeNode* root) { }

// TreeNode* deserialize(string data) { }

template <typename T>
void printVector(vector<T>& vec, string msg) {
    cout << "["<< msg <<"] ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <typename T>
void print2DVector(vector<vector<T>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}


void PrintXLR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    PrintXLR(root->left);
    PrintXLR(root->right);
    return;
}

void PrintLXR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintLXR(root->left);
    cout << root->val << " ";
    PrintLXR(root->right);
    return;
}

void PrintLRX(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintLRX(root->left);
    PrintLRX(root->right);
    cout << root->val << " ";
    return;
}

ListNode* buildList(vector<int>& data, size_t len) {
    if (data.size() == 0) {
        return NULL;
    }
    struct ListNode* head = new ListNode(data[0]);
    struct ListNode* tail = head;
    for (size_t i = 1; i < data.size() && i < len; ++i) {
        ListNode* p = new ListNode(data[i]);
        tail->next = p;
        tail = tail->next;
    }
    return head;
}


void printList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void parseMatrix(int ** matrix, int row, int col, vector<vector<int>> *vv) {
    for (auto i=0;i < row; ++i) {
        vector<int> v;
        for (auto j = 0; j < col; ++j) {
            v.push_back(matrix[i][j]);
        }
        vv->push_back(v);
    }
}



#endif