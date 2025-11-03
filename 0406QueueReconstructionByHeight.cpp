/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-03
 * @tag     sort
 * @similar
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode.cn/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (76.47%)
 * Likes:    1936
 * Dislikes: 0
 * Total Accepted:    358.8K
 * Total Submissions: 466.1K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第
 * i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
 *
 * 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj]
 * 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
 *
 *
 *
 *
 * 示例 1：
 * 输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
 * 输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
 * 解释：
 * 编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
 * 编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
 * 编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
 * 编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
 * 编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
 * 编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
 * 因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
 *
 *
 * 示例 2：
 * 输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
 * 输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 *
 *
 *
 *
 * 提示：
 * 1 <= people.length <= 2000
 * 0 <= hi <= 106
 * 0 <= ki < people.length
 * 题目数据确保队列可以被重建
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:

    // 7,0  7,1  5,0 5,2
    static bool cmpFn(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return false;
        }
        if (a[0] == b[0]) {
            return (a[1] < b[1]);
        }
        return true;
    }


    vector<vector<int>> reconstructQueueM1(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmpFn);
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); i++) {
            auto& peo = people[i];
            //int curHei = peo[0];
            int rank = peo[1];
            if (rank == i) {
                res.push_back(peo);
                continue;
            } else {
                res.insert(res.begin()+rank, peo);
            }
        }
        return res;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmpFn);
        list<vector<int>> res;
        for (int i = 0; i < people.size(); i++) {
            auto& peo = people[i];
            //int curHei = peo[0];
            int rank = peo[1];
            if (rank == i) {
                res.push_back(peo);
                continue;
            } else {
                auto inPos = std::next(res.begin(), rank);
                res.insert(inPos, peo);
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end


/*

输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

before
4,4  5,0  5,2   6,1   7,0   7,1
after sort
7,0   7,1   6,1   5,0   5,2   4,4


7,0   7,1   6,1   5,0   5,2   4,4   i=2 move 6,1 to 1st position
7,0   6,1   7,1   5,0   5,2   4,4   i=3 move 5,0 to 0st position
5,0   7,0   6,1   7,1   5,2   4,4   i=4 mov 5,2 to 2st postion
5,0   7,0   5,2   6,1   7,1   4,4   i=5 mov 4,4 to 4st postion
5,0   7,0   5,2   6,1   4,4   7,1    DONE



Want
7,0   7,1   6,1   5,0   5,2   4,4
Actualy
7,0   7,1   6,2   5,3   5,4   4,5




*/



/*
golang


func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i int, j int) bool {
		a := people[i]
		b := people[j]
		if a[0] < b[0] {
			return false
		}
		if a[0] == b[0] {
			return (a[1] < b[1])
		}
		return true
	})

	ans := make([][]int, 0, len(people))
	for i, pp := range people {
        peo := pp
		rank := peo[1]
		if rank == i {
			ans = append(ans, peo)
		} else {
			// insert peo at rank
            // BUG: head append修改了原数据
			head := ans[:rank]
			tail := ans[rank:]
			head = append(head, peo)
            ans = append(ans, head...)
			ans = append(ans, tail...)
	       // head := ans[:rank]
			//tail := ans[rank:]
            // right version
            ans = append(ans, []int{})
            copy(ans[rank+1:], ans[rank:])
            ans[rank] = peo
		}
	}
	return ans
}



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
