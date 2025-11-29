/**
 * @file
 * @brief   P6   similar 105-106-889
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-14
 *       2020-05-05
 *       2020-05-14 O(N)
 */

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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


class Solution {
   public:
    TreeNode* build(vector<int>& pre, int p1, int p2, vector<int>& in, int i1, int i2) {
        if (p1 >=p2 || i1>=i2) {
            return NULL;
        }
        int r = pre[p1];
        TreeNode *p = new TreeNode(r);
        int idx = -1;
        for (int i = i1; i < i2; ++i) {
            if (in[i] == r) {
                idx = i;
                break;
            }
        }
        int dis = idx -i1;
        if (idx != -1){
            p->left = build(pre, p1+1, p1+1+dis, in, i1, idx);
            p->right = build(pre, p1+1+dis, p2, in, idx+1, i2);
        }
        return p;
    }

/*
Runtime: 28 ms, faster than 34.42% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 21.4 MB, less than 23.81% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
*/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    /*
     INT_MIN两个作用：
     1是占位符，为了触发递归函数的调用
     2是 INT_MIN 不能和inOrder[0]相同，否则报错
     例如，当树只有一个根节点时，根节点的值不能和占位符相同，否则会报错
     因此占位符尽量用不可能出现的数字，于是采用INT_MIN，但是如果只有一个根节点，且它的值也是INT_MIN，则会报错，返回NULL，而不是预期的INT_MIN根节点
INT_MIN=-2147483648
 Your input
[-2147483648]
[-2147483648]
Output
[]
Expected
[-2147483648]
        */
    TreeNode* buildTreeM4(vector<int>& preorder, vector<int>& inorder) {
        int inPos = 0;
        int prePos = 0;
        int stopPos = -1;
        //return buildM4(preorder, inorder, INT_MIN, inPos, prePos);
        return buildM41(preorder, inorder, INT_MIN, inPos, prePos);
        //return buildM42(preorder, inorder, stopPos, inPos, prePos);
    }

//Runtime: 12 ms, faster than 98.75% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage: 23 MB, less than 9.52% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
    TreeNode* buildM4(vector<int>& preorder, vector<int>& inorder, int stop, int& inPos, int& prePos) {
        if (prePos >= preorder.size())
            return NULL;
        if (inorder[inPos] == stop) {
            inPos++;
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prePos]);
        prePos++;
        node->left = buildM4(preorder, inorder, node->val, inPos, prePos);
        node->right = buildM4(preorder, inorder, stop, inPos, prePos);
        return node;
    }


   // 函数调用递归树  部分减枝 这个剪枝意义不大，只是减少了最后一层的递归而已
    //Runtime: 8 ms, faster than 99.78% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
     //Memory Usage: 23.1 MB, less than 9.52% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
    TreeNode* buildM41(vector<int>& preorder, vector<int>& inorder, int stop, int& inPos, int& prePos) {
        if (prePos >= preorder.size())
            return NULL;
        if (inorder[inPos] == stop) {
            inPos++;
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prePos]);
        prePos++;
        if (node->val != inorder[inPos]) {
            node->left = buildM41(preorder, inorder, node->val, inPos, prePos);
        } else { // this mean left sub tree of inPos is done, so no need to build left
            inPos++;
        }
        if (inPos >= inorder.size()) {
            return node;
        }
        if (stop != inorder[inPos]) {
            node->right = buildM41(preorder, inorder, stop, inPos, prePos);
        } else {
            inPos++;
        }
        return node;
    }

//Runtime: 16 ms, faster than 93.21% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage: 23.1 MB, less than 9.52% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// 去掉INT_MIN的限制 把stop换成stopPos
    TreeNode* buildM42(vector<int>& preorder, vector<int>& inorder, int stopPos, int& inPos, int& prePos) {
        if (prePos >= preorder.size())
            return NULL;
        if (stopPos >=0 && inorder[inPos] == preorder[stopPos]) {
            inPos++;
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prePos]);
        int leftStop=prePos;
        prePos++;
        node->left = buildM42(preorder, inorder, leftStop, inPos, prePos);
        node->right = buildM42(preorder, inorder, stopPos, inPos, prePos);
        return node;
    }


    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex = 0, postIndex = 0;
        return constructFromPrePostLee215(pre, preIndex, post, postIndex);
        //return constructTree(pre, 0, pre.size(), post, 0, post.size());
    }

    TreeNode* constructFromPrePostLee215(vector<int>& pre, int &preIndex, vector<int>& post, int &postIndex) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[postIndex])
            root->left = constructFromPrePostLee215(pre, preIndex, post, postIndex);
        if (root->val != post[postIndex])
            root->right = constructFromPrePostLee215(pre, preIndex, post, postIndex);
        postIndex++;
        return root;
    }
};


// Runtime: 12 ms, faster than 81.25% of C online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 11.6 MB, less than 100.00% of C online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
struct TreeNode* buildBinTree(int* preorder, int b1, int e1 , int* inorder, int b2, int e2) {
    if (b1 == e1 ||  b2 == e2) {
        return NULL;
    }
    int cur = preorder[b1];
    int i = 0;
    for (i = b2; i < e2; ++i) {
        if (inorder[i] == cur) {
            break;
        }
    }
    int leftLen = i-b2;
    //if (i == e2)  not supposed
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = cur;
    root->left = buildBinTree(preorder, b1+1, b1+leftLen+1, inorder, b2, i);
    root->right = buildBinTree(preorder, b1+leftLen+1, e1, inorder, i+1, e2);
    return root;
}


// Runtime: 16 ms
// pe and ie point to last elements, not the next position.
struct TreeNode* buildBinTree2(int* preorder, int pb, int pe , int* inorder, int ib, int ie) {
    if (pb > pe) { // [] []
        return NULL;
    }
    int cur = preorder[pb];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = cur;
    if (pb == pe) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int i = 0;
    for (i =ib; i <= ie; ++i) {
        if (inorder[i] == cur) {
            break;
        }
    }
    int leftLen = i-ib;
    root->left = buildBinTree2(preorder, pb+1, pb+leftLen, inorder, ib, i-1);
    root->right = buildBinTree2(preorder, pb+leftLen+1, pe, inorder, i+1, ie);
    return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
   // return buildBinTree(preorder, 0, preorderSize, inorder, 0, inorderSize);
    return buildBinTree2(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
}



int main() {
    /*
    int len = 7;
    int preorder[len] = {3,9,20,15,14,16,7};
    int inorder[len] = {9,3,14,15,16,20,7};
    */


    int len = 5;
    int preorder[len] = {3,9,20,15,7};
    int inorder[len] = {9,3,15,20,7};

    /*

    TreeNode* r1 = buildTree(preorder, len, inorder, len);
    PrintXLR(r1);
    cout << endl;
    */

    vector<int> pre(preorder, preorder + len);
    vector<int> in(inorder, inorder + len);

    Solution s;
    TreeNode * r2 = s.buildTreeM4(pre, in);
    PrintLXR(r2);
    return 0;
}


/*
Tips
M1 递归
T=O(n^2)
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34557/My-neat-C%2B%2B-solution
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/340504/C%2B%2B-simple-recursive-(%2B-detail-explanation)
从preorder寻找根节点X，然后在inorder寻找根节点X位置，砍成左右两个子树。
分割后的左子树的数目=L1, 那么preorder里面在节点X后面L1个元素都属于左子树的preorder

因为 preorder = XLR
inorder = LXR, 当在inorder里面找到X后， 左子树leftT的数组长度 L1=len(L)　右子树rightT的数组长度R1=len(R)
那么在preorder数组里面， 必有  preorder[X+1, X+1+L1)必为leftT的preorder， preorder[X+1+L1, X+L2)比为rightT的preorder

M2 M1递归的基础上优化 find过程
    每次遍历太耗时了， 用 unorder_map把find变成O(1)

M3 用Stack来解决
    TODO

sample 16 ms submission
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]), *cur = root;
        for (int i = 1, j = 0; i < preorder.size(); ++i) {
            if (cur->val != inorder[j]) {
                s.push(cur);
                cur->left = new TreeNode(preorder[i]);
                cur = cur->left;
            }
            else {
                j++;
                while (!s.empty() && s.top()->val == inorder[j]) {
                    cur = s.top();
                    s.pop();
                    j++;
                }
                cur = cur->right = new TreeNode(preorder[i]);
            }
        }
        return root;
    }
};

*/

/*
M4 O(N)方法    stefan pochmann
和0889的Lee215的O(N)解法有着异曲同工之妙

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map/383711

Explanation/Discussion:

Consider this input:

preorder: [1, 2, 4, 5, 3, 6]
inorder: [4, 2, 5, 1, 6, 3]
The obvious way to build the tree is:

Use the first element of preorder, the 1, as root.
Search it in inorder.
Split inorder by it, here into [4, 2, 5] and [6, 3].
Split the rest of preorder into two parts as large as the inorder parts, here into [2, 4, 5] and [3, 6].
Use preorder = [2, 4, 5] and inorder = [4, 2, 5] to add the left subtree.
Use preorder =[3, 6]andinorder = [6, 3] to add the right subtree.
But consider the worst case for this: A tree that's not balanced but is just a straight line to the left. Then inorder is the reverse of preorder, and already the cost of step 2, searching in inorder, is O(n^2) overall. Also, depending on how you "split" the arrays, you're looking at O(n^2) runtime and possibly O(n^2) space for that as well.

You can bring the runtime for searching down to O(n) by building a map from value to index before you start the main work, and I've seen several solutions do that. But that is O(n) additional space, and also the splitting problems remain. To fix those, you can use pointers into preorder and inorder instead of splitting them. And when you're doing that, you don't need the value-to-index map, either.

Consider the example again. Instead of finding the 1 in inorder, splitting the arrays into parts and recursing on them, just recurse on the full remaining arrays and stop when you come across the 1 in inorder. That's what my above solution does. Each recursive call gets told where to stop, and it tells its subcalls where to stop. It gives its own root value as stopper to its left subcall and its parent`s stopper as stopper to its right subcall.

传统方法是在InOrder中寻找1节点后，再把InOrder数组分割成2部分后继续递归,与其这样做，还不如直接把整个数组传递下去，然后遇到InOrder里面的1时停止即可。这就是我的上述解法。每一次递归调用都会被告知在哪里stop，然后它会继续告知他的子调用在哪里stop。
它会把当前创建的节点的值当做左子树调用的stopper，同时会把父节点的stopper传递给右子树的调用。 [核心难点]

lambda表达式的解法，避免了传递 INT_MIN
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/182153/c%2B%2B-clean-simple-solutions.-Multiple-answers-with-different-complexities-and-detailed-description


原理分析：
XLR preorder = [3,9,20,15,7]
LXR inorder = [9,3,15,20,7]

    3
   / \
  9  20
    /  \
   15   7

切入点
画出函数调用递归树，走一遍算法流程，有以下几个要点。
1. 递归解法本质上是XLR，先构造根节点，再构造LR。并且必须是L子树完全构造完成后，R的参数InPos和PrePos才能确定下来。所以直接用PreOrder的遍历顺序去构造节点。
2. INT_MIN并没有发挥作用，只是相当于凑齐参数的一个占位符而已。INT_MIN只会沿着最右侧分支一路传递下去。
3. X节点的左子树何时构造完成？当遇到InOrder中的X时，说明左子树已经构造完成了。所以要把X节点的val当做左子树递归调用的stopper。

4. X节点的右子树何时构造完成？令X节点的父节点为P1，分两种情况讨论
    4.1  P1->left == X
    当遇到InOrder中X节点的父节点P1时，X节点的右子树构造完成。为何？
    因为当X节点的右子树构造完成时，按照LXR的顺序遍历，下一个遍历的元素必然是X的父节点P1。

    4.2 P1->right == X
    当X的右子树构造完成时，令P1的父节点为P2,按照InOrder的顺序，又分两种情况,（其实是一种情况而已，通项公式中n=1和n=k的区别）
        4.2.1 P2->left = P1
        则InOrder顺序中的下一个元素是P1的父节点P2。
        4.2.2 P2->right = P1,
        则问题继续递归，需要看P2的父节点P3。
        沿着X节点往上递归，直到遇到父节点PN，且有Pn->left=Pn-1,则InOrder顺序中的下一个元素就是Pn。
        如果不存在这样的PN，说明X节点是最右下的节点,此时X节点一定位于InOrder中的末尾位置，因此Stop的点就是超出了数组的数量。

4的结论就是 its parent`s stopper as stopper to its right subcall.
这个结论不是很显而易见，需要结合函数递归调用树去理解。
X的parent's stopper，即P1的stopper。有两种情况。
一种是X的父节点P1，即4.1讨论的情况。
一种是Pn，满足Pn->left=Pn-1,即4.2讨论的情况。

换种思路去理解，对于X的右子树构造完成时，在InOrder中的下一个节点，必然是X的某个最近祖先节点Pn，且Pn->left节点也是X的祖先节点。
从递归角度去实现时，需要把Pn传递到X节点的右子树调用当做Stopper。
    当构造Pn->left节点Pn-1时，Stopper就是Pn，
    当构造Pn-1->right右节点时，直到到P1的右侧子孙节点链路上，因为传递parent's stopper as stopper，所以Pn这个Stoper能一路往下传，直到X的右子树调用时，Stoper依然是Pn。

XLR preorder = [3,9,20,15,7]
LXR inorder = [9,3,15,20,7]
函数调用递归树 B(Stop, InPos, PrePos)
纸上的树状图横向打散，方便文字表述树结构
B(Nil, 0, 0) & (Node=3, PrePos++)
    3.LeftCall-> B(3, 0, 1) & (Node=9, PrePos++)
        9.LeftCall-> B(9, 0, 2) & (inPos++, return NULL)
        9.RightCall->B(3, 1, 2) & (inPos++, return NULL)
    3.RightCall->B(Nil, 2, 2) & (Node=20, PrePos++)
        20.LeftCall-> B(20, 2, 3) & (Node=15, PrePos++)
            15.LeftCall-> B(15, 2, 4) & (inPos++, return NULL)
            15.RightCall-> B(20, 3, 4) & (inPos++, return NULL)
        20.RightCall->B(NIL, 4, 4) & (Node=7, PrePos++)
            7.LeftCall-> B(7, 4, 5) & (return NULL)
            7.RightCall->B(NIL,4,5) & (return NULL)


为了加深递归树的印象，可以继续做以下两点改动，重新图纸画递归调用树
删掉Node=9
XLR preorder = [3,20,15,7]
LXR inorder = [9,15,20,7]

把15节点增加2个孩子 15->left=14 15->right=16
XLR preorder = [3,9, 20, [15,14,16] ,7]
LXR inorder = [9, 3, [14,15,16] ,20,7]


*/

