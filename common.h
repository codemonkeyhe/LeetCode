#ifndef  __COMMON_H__
#define  __COMMON_H__

#include <vector>
#include <iostream>
#include <stack>
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
//nums里面必须包含完备的树节点，必须是一颗完全二叉树，即最下一层的右侧为空,左侧叶子结点为空指针的话，需要显示备注为 EMPTY_V
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



TreeNode* BTreeXLR(vector<int> nums, int& cur) {
    if ( (cur >= nums.size())  ) {
        return NULL;
    }
    if (nums[cur] == EMPTY_V) { // leaf
        cur++;
        return NULL;
    }

    TreeNode* root = new TreeNode(nums[cur]);
    cur++;
    root->left =  BTreeXLR(nums, cur);
    root->right =  BTreeXLR(nums, cur);
    cout << " root= " << root->val;
    if (root->left) {
        cout << " root.left= " << root->left->val;
    } else {
        cout << " root.left= NULL";
    }
    if (root->right) {
        cout << " root.right= " << root->right->val;
    } else {
        cout << " root.right= NULL";
    }
    cout << endl;
    return root;
}

// testcase: [1, null, 2,3]  相当于 先序遍历
// testcase2:   vector<int> nums = {1,2,4,EMPTY_V,EMPTY_V , 5,6,EMPTY_V,EMPTY_V, 7,EMPTY_V,EMPTY_V,3,EMPTY_V,8,9};
// testcase2的XLR结果为  [1,2,4,5,6,7,3,8,9]  from LeetCode144
// 所有叶子结点的空指针都必须打印出来
TreeNode* BuildBTreeByXLR(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    int cur = 0;
    TreeNode* root = BTreeXLR(nums, cur);
    return root;
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

void parseMatrix(int** matrix, int row, int col, vector<vector<int>>* vv) {
    for (auto i = 0; i < row; ++i) {
        vector<int> v;
        for (auto j = 0; j < col; ++j) {
            v.push_back(matrix[i][j]);
        }
        vv->push_back(v);
    }
}




////////////////////////////////////////////////////
///////////          TREE                    ///////
////////////////////////////////////////////////////




// LeetCode0144
void PrintXLR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    PrintXLR(root->left);
    PrintXLR(root->right);
    return;
}

vector<int> XLRByStack(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    stack<TreeNode*> s;
    TreeNode* cur = root;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            res.push_back(cur->val);
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cur = cur->right;
    }
    return res;
}


vector<int> XLRByStack2(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* tmp = st.top();
        st.pop();
        res.push_back(tmp->val);
        if (tmp->right) {
            st.push(tmp->right);
        }
        if (tmp->left) {
            st.push(tmp->left);
        }
    }
    return res;
}


// LeetCode0094
void PrintLXR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintLXR(root->left);
    cout << root->val << " ";
    PrintLXR(root->right);
    return;
}

vector<int> LXRByStack(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || (cur != NULL)) {
        while (cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

// LeetCode0145
void PrintLRX(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintLRX(root->left);
    PrintLRX(root->right);
    cout << root->val << " ";
    return;
}

vector<int> LRXByStack(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    stack<TreeNode*> st;
    TreeNode* pre = NULL;
    TreeNode* cur = root;
    while (!st.empty() || cur != NULL) {
        while (cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        if (cur->right == NULL || (cur->right == pre)) {
            st.pop();
            res.push_back(cur->val);
            pre = cur;
            cur = NULL;
        } else {
            cur = cur->right;
        }
    }
    return res;
}


// 094
vector<int> MorrisLXR(TreeNode* root) {
    vector<int> res;
    return res;
}



// 144
vector<int> MorrisXLR(TreeNode* root) {
    vector<int> res;
    return res;
}


// 145
vector<int> MorrisLRX(TreeNode* root) {
    vector<int> res;
    return res;
}




#endif