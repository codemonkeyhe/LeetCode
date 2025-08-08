/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-08
 * @tag  BFS,matrix
 * @similar 127
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 *
 * https://leetcode.cn/problems/snakes-and-ladders/description/
 *
 * algorithms
 * Medium (44.02%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    55.9K
 * Total Submissions: 123.7K
 * Testcase Example:  '[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]'
 *
 * 给你一个大小为 n x n 的整数矩阵 board ，方格按从 1 到 n^2 编号，编号遵循 转行交替方式 ，从左下角开始 （即，从 board[n - 1][0] 开始）的每一行改变方向。
 * 你一开始位于棋盘上的方格  1。每一回合，玩家需要从当前方格 curr 开始出发，按下述要求前进：
 * 选定目标方格 next ，目标方格的编号在范围 [curr + 1, min(curr + 6, n^2)] 。
 * 该选择模拟了掷 六面体骰子 的情景，无论棋盘大小如何，玩家最多只能有 6 个目的地。
 * 传送玩家：如果目标方格 next 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地。否则，玩家传送到目标方格 next 。 
 * 当玩家到达编号 n^2 的方格时，游戏结束。
 *
 * 如果 board[r][c] != -1 ，位于 r 行 c 列的棋盘格中可能存在 “蛇” 或 “梯子”。那个蛇或梯子的目的地将会是
 * board[r][c]。编号为 1 和 n^2 的方格不是任何蛇或梯子的起点。
 *
 * 注意，玩家在每次掷骰的前进过程中最多只能爬过蛇或梯子一次：就算目的地是另一条蛇或梯子的起点，玩家也 不能 继续移动。
 *
 * 举个例子，假设棋盘是 [[-1,4],[-1,3]] ，第一次移动，玩家的目标方格是 2 。那么这个玩家将会顺着梯子到达方格 3 ，但 不能 顺着方格
 * 3 上的梯子前往方格 4
 * 。（简单来说，类似飞行棋，玩家掷出骰子点数后移动对应格数，遇到单向的路径（即梯子或蛇）可以直接跳到路径的终点，但如果多个路径首尾相连，也不能连续跳多个路径）
 * 返回达到编号为 n^2 的方格所需的最少掷骰次数，如果不可能，则返回 -1。
 *
 *
 *
 * 示例 1：
 * 输入：board =
 * [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
 * 输出：4
 * 解释：
 * 首先，从方格 1 [第 5 行，第 0 列] 开始。
 * 先决定移动到方格 2 ，并必须爬过梯子移动到到方格 15 。
 * 然后决定移动到方格 17 [第 3 行，第 4 列]，必须爬过蛇到方格 13 。
 * 接着决定移动到方格 14 ，且必须通过梯子移动到方格 35 。
 * 最后决定移动到方格 36 , 游戏结束。
 * 可以证明需要至少 4 次移动才能到达最后一个方格，所以答案是 4 。
 *
 *
 * 示例 2：
 * 输入：board = [[-1,-1],[-1,3]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * n == board.length == board[i].length
 * 2 <= n <= 20
 * board[i][j] 的值是 -1 或在范围 [1, n^2] 内
 * 编号为 1 和 n^2 的方格上没有蛇或梯子
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Similiar with 126, 同层去重+ used去重
    int snakesAndLaddersV1(vector<vector<int>>& board) {
        int n = board.size();
        int step = 1;
        vector<vector<int> > snakeLadder(n, vector<int>(n, 0));
        int target = n * n;
        int k = 1;
        int line = 0;
        unordered_map<int, pair<int, int>> v2xy;
        for (int i = n - 1; i >= 0; i--, line++) {
            for (int j = 0; j < n; j++) {
                int newj = j;
                if (line % 2) {
                    newj = n - 1 - j;
                }
                v2xy[k] = make_pair(i, newj);
                snakeLadder[i][newj] = k;
                k++;
            }
        }

        queue<int> que;
        unordered_set<int> used;
        que.push(1);
        used.insert(1);
        //BFS+ 同层去重
        while(!que.empty()) {
            int cnt = que.size();
          //  cout << " STEP=" << step << " CNT=" << cnt << endl;
            unordered_set<int> nextIdx;
            for (int i = 0; i < cnt; i++) {
                int cur = que.front();
                que.pop();
                for (int j = 1; j <= 6; j++) { // 6 choices
                    int next = cur + j;
                    if (next == target) {
                        return step;
                    }
                    auto [x, y] = v2xy[next];
                    int &jump = board[x][y];
                    //cout << "cur=" << cur << " next=" << next << " jumpTo=" << jump << endl;
                    if (jump == target) {
                        return step;
                    }
                    if (jump == -1) { //no snake or ladder
                        if (used.count(next) == 0) {
                            nextIdx.insert(next);
                            used.insert(next);
                        }
                        //que.push(next);
                    } else {
                        if (jump != cur) { // avoid deadpool
                            if (used.count(jump) == 0) {
                                nextIdx.insert(jump);
                                used.insert(jump);
                                // from next to jump
                                //ERROR   next只是路过，并没有真正走过
                                //used.insert(next);
                            }
                            //que.push(jump);
                        }
                    }
                }
            }
            for (auto& idx: nextIdx) {
                que.push(idx);
            }
            step++;
        }

        return -1;
    }


    int snakesAndLaddersV2(vector<vector<int>>& board) {
        int n = board.size();
        int step = 1;
        int target = n * n;
        int k = 1;
        int line = 0;
        vector<vector<int> > snakeLadder(n, vector<int>(n, 0));
        unordered_map<int, pair<int, int>> v2xy;
        for (int i = n - 1; i >= 0; i--, line++) {
            for (int j = 0; j < n; j++) {
                int newj = j;
                if (line % 2) {
                    newj = n - 1 - j;
                }
                v2xy[k] = make_pair(i, newj);
                snakeLadder[i][newj] = k;
                k++;
            }
        }

        queue<int> que;
        unordered_set<int> used;
        que.push(1);
        used.insert(1);
        while(!que.empty()) {
            int cnt = que.size();
            unordered_set<int> nextIdx;
            for (int i = 0; i < cnt; i++) {
                int cur = que.front();
                que.pop();
                for (int j = 1; j <= 6; j++) { // 6 choices
                    int next = cur + j;
                    if (next > target) {
                        break;
                    }
                    auto& [x, y] = v2xy[next];
                    int &jump = board[x][y];
                    if (next == target || jump == target) {
                        return step;
                    }
                    if (jump == -1) { //no snake or ladder
                        //if (used.count(next) == 0) { //still work
                            nextIdx.insert(next);
                       // }
                    } else {
                        //if (used.count(jump) == 0) { //still work
                            nextIdx.insert(jump);
                       // }
                    }
                }
            }
            for (auto& idx: nextIdx) {
                if (used.count(idx) == 0) {
                    que.push(idx);
                    used.insert(idx);
                }
            }
            step++;
        }
        return -1;
    }

/*

作者：力扣官方题解
链接：https://leetcode.cn/problems/snakes-and-ladders/solutions/846328/she-ti-qi-by-leetcode-solution-w0vl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

/*
     参考官方代码 , 如下优化：
    1  避免初始化棋盘，直接根据idx计算下标(x, y)
    2  不用同层去重 ，直接 used去重
    3 used换成vector<int>加速

    参照LC126，需要同层子节点去重，因为需要记录一个子对应多个父的关系，如果直接用used去重，则s2fa的关系会缺失，所有必须同层去重
        unordered_map<string, vector<string> > s2fa;
    这里只需要求步数，不需要打印所有路径，如果要打印所有路径，一样需要同层去重


*/
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        int step = 1;
        int target = n * n;

        /*
        int k = 1;
        int line = 0;
        unordered_map<int, pair<int, int>> v2xy;
        for (int i = n - 1; i >= 0; i--, line++) {
            for (int j = 0; j < n; j++) {
                int newj = j;
                if (line % 2) {
                    newj = n - 1 - j;
                }
                v2xy[k] = make_pair(i, newj);
                k++;
            }
        }
        */

        queue<int> que;
        //unordered_set<int> used;
        vector<int> used(target+1, 0);
        que.push(1);
        used[1] = 1;
        while(!que.empty()) {
            int cnt = que.size();
            // 不用同层去重 ，直接 used去重
            //unordered_set<int> nextIdx;
            for (int i = 0; i < cnt; i++) {
                int cur = que.front();
                que.pop();
                for (int j = 1; j <= 6; j++) { // 6 choices
                    int next = cur + j;
                    if (next > target) {
                        break;
                    }
                    //auto& [x, y] = v2xy[next];
                    auto [x, y] = id2rc(next, n);

                    int &jump = board[x][y];
                    if (jump > 0) {
                        next = jump;
                    }
                    if (next == target) {
                        return step;
                    }
                    if (used[next] == 0) {
                        que.push(next);
                        used[next] = 1;
                    }
                    //nextIdx.insert(next);
                }
            }
            /*
            for (auto& idx: nextIdx) {
                if (used.count(idx) == 0) {
                    que.push(idx);
                    used.insert(idx);
                }
            }
            */
            step++;
        }
        return -1;
    }
};
// @lc code=end

/*
Wrong Answer
89/217 cases passed (N/A)
Testcase
[[-1,-1,-1],[-1,9,8],[-1,8,9]]
Answer
2
Expected Answer
1

初始化错误
7 8 9
6 5 4
1 2 3
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                for (int j = n - 1; j >= 0; j--) {
                    v2xy[k] = make_pair(i,j);
                    snakeLadder[i][j] = k--;
                }
            } else {
                for (int j = 0; j < n; j++) {
                    v2xy[k] = make_pair(i,j);
                    snakeLadder[i][j] = k--;
                }
            }
        }


TLE
[[1,1,-1],[1,1,1],[-1,1,1]]
2-8都有同样的梯子指向1 .... 死循环


TLE
需要同层去重
board =
[[-1,-1,128,-1,-1,-1,136,-1,-1,-1,109,-1],[-1,-1,-1,-1,-1,103,-1,-1,56,10,-1,-1],[-1,-1,-1,-1,-1,-1,116,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1,50,-1,67,107],[-1,40,-1,-1,-1,20,-1,59,-1,67,-1,-1],[-1,-1,-1,-1,-1,-1,112,133,111,-1,-1,-1],[-1,-1,112,-1,74,-1,-1,-1,-1,-1,-1,-1],[23,-1,115,-1,129,126,-1,-1,-1,-1,-1,-1],[106,143,81,-1,-1,-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1,26,102,1,29],[26,-1,-1,-1,-1,-1,-1,-1,27,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]]


TLE
[[-1,1,1,1],[-1,7,1,1],[1,1,1,1],[-1,1,9,1]]
存在路径循环
走过的路径不可以走了
需要引入used



Wrong Answer
[[-1,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,377,376],[356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375],[355,354,353,352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336],[316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335],[315,314,313,312,311,310,309,308,307,306,305,304,303,302,301,300,299,298,297,296],[276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295],[275,274,273,272,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256],[236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255],[235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216],[196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215],[195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176],[156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175],[155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136],[116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135],[115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96],[76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95],[75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56],[36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55],[35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16],[-1,1,1,1,1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]]

Output:
-1
Expect:
394


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
