/**
 * @file
 * @brief 437-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-08
 */

/*
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.
For each integer in this list:
1.The hundreds digit represents the depth D of this node, 1 <= D <= 4.
2.The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
3.The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation:
The tree that the list represents is:
    3
   / \
  5   1
The path sum is (3 + 5) + (3 + 1) = 12.


Example 2:
Input: [113, 221]
Output: 4
Explanation:
The tree that the list represents is:
    3
     \
      1
The path sum is (3 + 1) = 4.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

 void ps(int root, int &sum, const unordered_map<int, int>& m, int& total) {
    unordered_map<int, int>::const_iterator it;
     int rootVal = 100;
     if ((it = m.find(root)) != m.end()) {
         rootVal = it->second;
     }
     if (rootVal == 100) { // NULL node
        return;
     }
     sum+= rootVal;
     int left = 2*root;
     if (!m.count(left) && !m.count(left+1)) { // leaf
        total+=sum;
    }
    ps(left, sum, m, total);
    ps(left+1, sum, m, total);
    sum-=rootVal;
 }

 int pathSum(vector<int>& nums) {
     unordered_map<int, int> m;
     int cnt[5] = {0,1,2,4,8};
     for (int i = 0; i < nums.size(); ++i) {
         int depth = nums[i]/100;
         int pos = (nums[i]%100)/10;
         int val = nums[i]%10;
         m.insert(make_pair(cnt[depth]+pos-1, val));
     }
     int total = 0;
     int sum = 0;
     ps(1, sum, m, total);
     return total;
 }

};



int main() {
    const int len = 2;
    //int nums[len] = {113, 215, 221};
    int nums[len] = {113,  221};

    vector<int> nu(nums, nums + len);

    Solution s;
    cout << s.pathSum(nu) << endl;

    return 0;
}


/*
Tips
每个node用三位数的数字表示，格式是[Depth, LevelPos, Val]
因为Depth<=4, 第4层最多有8个节点, 所以LevelPos<=8, Val只能是个位数<=9
M1 先构建BT，再求PathSum
肯定有不建立BT的方法

M2 用Map<int, int> 存储这颗二叉树，结构是<下标idx，值val>
下标从1开始编号，idx=2^(Depth-1)+LevelPos
接下来使用递归求二叉树的路径和，只不过树的左右节点变成了下标计算而已

*/
