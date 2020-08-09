/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-09
 * @tag backtracking
 */

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
Input: n = 4, k = 2

Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        m1(n, k,1, path, res);
        return res;
    }
/*
try1
Runtime: 88 ms, faster than 30.33% of C++ online submissions for Combinations.
Memory Usage: 9.1 MB, less than 70.62% of C++ online submissions for Combinations.

try2 剪枝
Runtime: 16 ms, faster than 94.27% of C++ online submissions for Combinations.
Memory Usage: 9 MB, less than 79.79% of C++ online submissions for Combinations.
理解 n - (k - path.size()) + 1
k: 要选择的总数目
path.size()： 已选择的数目
k - path.size(): 还缺乏的数目，将要被选择
n是代表数据范围，
n - (k - path.size()): 表示还能允许选择的范围，+1修正一下误差

*/
    void m1(int n, int k, int begin, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // try1         for (int i = begin; i <= n; ++i) {
        for (int i = begin; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            m1(n, k, i + 1, path, res);
            path.pop_back();
        }
    }


};



int main() {
    int n = 4;
    int k = 3;
    Solution s;
    auto res = s.combine(n, k);
    print2DVector(res);
    return 0;
}


/*
Tips
M1 回溯法 同0039
剪枝思路
https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/

M2 迭代-构造
本质上是按照字典序去生成所有组合
0 0 #initialization
1 0
1 1 #if-C
1 2 #if-B
1 3 #if-B
1 4 #if-B
1 5 #if-A
2 5
2 2 #if-C
2 3 #if-B
2 4 #if-B
...
3 4 #if-B
3 5 #if-A
4 5 #
4 4 #if-C
4 5 #if-A
5 5 #if-A  i=0后--i;i=-1终止循环
#if-A 当前数字溢出了，说明当前位的所有情况已经遍历结束了，把下标回退，继续构造下一种情况
#if-B 数字已经集齐k个了，说明找到一种组合了
#if-C 数字既没有溢出，也没有集齐K个，说明还在初始状态扩充阶段，把最低位的值复制到高位，开始下一轮次的遍历

https://leetcode.com/problems/combinations/discuss/26992/Short-Iterative-C%2B%2B-Answer-8ms
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i; // if-A
			else if (i == k - 1)  { //if-B
                result.push_back(p);
			} else { //if-C
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}


M3 递归
https://leetcode.com/problems/combinations/discuss/27019/A-short-recursive-Java-solution-based-on-C(nk)C(n-1k-1)%2BC(n-1k)
C(n,k)=C(n-1,k-1)+C(n-1,k)
Here C(n,k) is divided into two situations.
Situation one, number n is selected, so we only need to select k-1 from n-1 next.
Situation two, number n is not selected, and the rest job is selecting k from n-1.
public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        if (k == n || k == 0) {
            List<Integer> row = new LinkedList<>();
            for (int i = 1; i <= k; ++i) {
                row.add(i);
            }
            return new LinkedList<>(Arrays.asList(row));
        }
        List<List<Integer>> result = this.combine(n - 1, k - 1);
        result.forEach(e -> e.add(n));
        result.addAll(this.combine(n - 1, k));
        return result;
    }
}

*/
