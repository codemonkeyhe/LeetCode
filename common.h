#ifndef  __COMMON_H__
#define  __COMMON_H__

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



const int EMPTY_V = 0x80000000;
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



struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(vector<int>& data, int len) {
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

#endif