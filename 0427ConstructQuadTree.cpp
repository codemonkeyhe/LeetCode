/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-14
 * @tag prefixSum,matrix,dfs
 * @similar  304, 427, 558
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 *
 * https://leetcode.cn/problems/construct-quad-tree/description/
 *
 * algorithms
 * Medium (71.66%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    48.5K
 * Total Submissions: 66.1K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 。
 * 你需要返回能表示矩阵 grid 的 四叉树 的根结点。
 * 四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：
 * val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False。注意，当 isLeaf 为 False 时，你可以把 True 或者
 * False 赋值给节点，两种值都会被判题机制 接受 。
 * isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
 *
 *
 * class Node {
 * ⁠   public boolean val;
 * public boolean isLeaf;
 * public Node topLeft;
 * public Node topRight;
 * public Node bottomLeft;
 * public Node bottomRight;
 * }
 *
 * 我们可以按以下步骤为二维区域构建四叉树：
 * 如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null
 * 然后停止。
 * 如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
 * 使用适当的子网格递归每个子节点。
 *
 *
 * 如果你想了解更多关于四叉树的内容，可以参考 wiki 。
 *
 * 四叉树格式：
 * 你不需要阅读本节来解决这个问题。只有当你想了解输出格式时才会这样做。输出为使用层序遍历后四叉树的序列化形式，其中 null
 * 表示路径终止符，其下面不存在节点。
 * 它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 [isLeaf, val] 。
 * 如果 isLeaf 或者 val 的值为 True ，则表示它在列表 [isLeaf, val] 中的值为 1 ；如果 isLeaf 或者 val
 * 的值为 False ，则表示值为 0 。
 *
 *
 *
 * 示例 1：
 * 输入：grid = [[0,1],[1,0]]
 * 输出：[[0,1],[1,0],[1,1],[1,1],[1,0]]
 * 解释：此示例的解释如下：
 * 请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。
 *
 *
 *
 * 示例 2：
 * 输入：grid =
 * [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
 *
 * 输出：[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
 * 解释：网格中的所有值都不相同。我们将网格划分为四个子网格。
 * topLeft，bottomLeft 和 bottomRight 均具有相同的值。
 * topRight 具有不同的值，因此我们将其再分为 4 个子网格，这样每个子网格都具有相同的值。
 * 解释如下图所示：
 *
 *
 *
 *
 *
 * 提示：
 * n == grid.length == grid[i].length
 * n == 2^x 其中 0 <= x <= 6
 *
 *
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    // M1
    Node* constructM1(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* root = build4Tree(grid, 0, 0, n-1, n-1);
        return root;
    }

    // leftUp (r0, c0)  rightBottom(r1,c1)
    Node* build4Tree(vector<vector<int>>& grid, int r0, int c0, int r1, int c1) {
        if (r0 == r1 && c0 == c1) {
            int cur = grid[r0][c0];
            Node* leafNode = new Node(cur, true);
        //    cout << " findLeaf, r0=" << r0 << " c0=" << c0 << " cur=" << cur << endl;
            return leafNode;
        }
        int n = r1 - r0 + 1;
        int half = n/2;
      //  cout << "n=" << n << " half=" << half << endl;
        Node* root = new Node(0, false);
        root->topLeft = build4Tree(grid, r0, c0, r0 + half - 1, c0 + half - 1);
        root->topRight = build4Tree(grid, r0, c0 + half, r0 + half - 1, c1);
        root->bottomLeft = build4Tree(grid, r0 + half, c0, r1, c0 + half - 1);
        root->bottomRight = build4Tree(grid, r0 + half, c0 + half, r1, c1);
        if (root->topLeft->isLeaf
            && root->topRight->isLeaf
            && root->bottomLeft->isLeaf
            && root->bottomRight->isLeaf ) {
            int sum = root->topLeft->val + root->topRight->val + root->bottomLeft->val + root->bottomRight->val;
         //   cout << " root, r0=" << r0 << " c0=" << c0 << " sum=" << sum << endl;
            if (sum == 0) {
                root->isLeaf = true;
                root->val = 0;
            } else if (sum == 4) {
                root->isLeaf = true;
                root->val = 1;
            }
            if (root->isLeaf) { // Keystep
                root->topLeft = NULL;
                root->topRight = NULL;
                root->bottomLeft= NULL;
                root->bottomRight= NULL;
            }
        }
        return root;
    }


    // M2
    Node* constructM2(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* root = buildDfs(grid, 0, 0, n-1, n-1);
        return root;
    }

    // leftUp (r0, c0)  rightBottom(r1,c1)
    Node* buildDfs(vector<vector<int>>& grid, int r0, int c0, int r1, int c1) {
        bool isLeaf = true;
        for (int i = r0; i <= r1; i++) {
            for (int j = c0; j <=c1; j++) {
                if (grid[i][j] != grid[r0][c0]) {
                    isLeaf = false;
                    break;
                }
            }
        }

        int n = r1 - r0 + 1;
        int half = n/2;
        Node* root = new Node(grid[r0][c0], isLeaf);
        if (isLeaf) {
            return root;
        }
        root->topLeft = buildDfs(grid, r0, c0, r0 + half - 1, c0 + half - 1);
        root->topRight = buildDfs(grid, r0, c0 + half, r0 + half - 1, c1);
        root->bottomLeft = buildDfs(grid, r0 + half, c0, r1, c0 + half - 1);
        root->bottomRight = buildDfs(grid, r0 + half, c0 + half, r1, c1);
        return root;
    }


    // M3

    vector<vector<int>>  prefix;
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        prefix = vector<vector<int> >(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + grid[i][j];
            }
        }

        Node* root = buildPrefix(grid, 0, 0, n-1, n-1);
        return root;
    }


    Node* buildPrefix(vector<vector<int>>& grid, int r0, int c0, int r1, int c1) {
        bool isLeaf = false;
        int val = 0;
        int n = r1 - r0 + 1;
        int sum = prefix[r1+1][c1+1] - prefix[r0][c1+1] - prefix[r1+1][c0] + prefix[r0][c0];
        if (sum == 0) {
            isLeaf = true;
        } else if (sum == n*n) {
            isLeaf = true;
            val = 1;
        }

        int half = n/2;
        Node* root = new Node(val, isLeaf);
        if (isLeaf) {
            return root;
        }
        root->topLeft = buildPrefix(grid, r0, c0, r0 + half - 1, c0 + half - 1);
        root->topRight = buildPrefix(grid, r0, c0 + half, r0 + half - 1, c1);
        root->bottomLeft = buildPrefix(grid, r0 + half, c0, r1, c0 + half - 1);
        root->bottomRight = buildPrefix(grid, r0 + half, c0 + half, r1, c1);
        return root;
    }

};
// @lc code=end

/*
1 2
3 4

1 3
4 10

prefix(i, j)  =   prefix(i-1, j) + prefix(i, j-1)  - prefix(i-1, j-1) + matrix[i][j]

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
