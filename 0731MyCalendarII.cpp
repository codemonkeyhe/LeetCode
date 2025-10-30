/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-30
 * @tag  setmentTree,diffArray
 * @similar   729, 731, 732
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 *
 * https://leetcode.cn/problems/my-calendar-ii/description/
 *
 * algorithms
 * Medium (62.82%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    43.5K
 * Total Submissions: 67.3K
 * Testcase Example:  '["MyCalendarTwo","book","book","book","book","book","book"]\n' +
  '[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
 *
 * 实现一个程序来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。
 * 当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生 三重预订。
 * 事件能够用一对整数 startTime 和 endTime 表示，在一个半开区间的时间 [startTime, endTime) 上预定。实数 x
 * 的范围为  startTime <= x < endTime。
 *
 * 实现 MyCalendarTwo 类：
 *
 *
 * MyCalendarTwo() 初始化日历对象。
 * boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致三重预订，返回
 * true。否则，返回 false 并且不要将该日程安排添加到日历中。
 *
 *
 *
 *
 * 示例 1：
 * 输入：
 * ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
 * [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
 * 输出：
 * [null, true, true, true, false, true, true]
 *
 * 解释：
 * MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
 * myCalendarTwo.book(10, 20); // 返回 True，能够预定该日程。
 * myCalendarTwo.book(50, 60); // 返回 True，能够预定该日程。
 * myCalendarTwo.book(10, 40); // 返回 True，该日程能够被重复预定。
 * myCalendarTwo.book(5, 15);  // 返回 False，该日程导致了三重预定，所以不能预定。
 * myCalendarTwo.book(5, 10); // 返回 True，能够预定该日程，因为它不使用已经双重预订的时间 10。
 * myCalendarTwo.book(25, 55); // 返回 True，能够预定该日程，因为时间段 [25, 40)
 * 将被第三个日程重复预定，时间段 [40, 50) 将被单独预定，而时间段 [50, 55) 将被第二个日程重复预定。
 *
 *
 *
 *
 * 提示：
 * 0 <= start < end <= 10^9
 * 最多调用 book 1000 次。
 *
 *
 */

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    // 相当于在给原始数组[startTime, endTime-1]全部+1，对应差分数组就是posDiff[startTime]+=1, posDiff[endTime]-=1
    bool book(int startTime, int endTime) {
        //先尝试预订，再检测是否冲突了，冲突了再回滚
        posDiff[startTime] += 1;
        posDiff[endTime] -= 1;
        int originCnt = 0;
        for (auto& [pos, diff] : posDiff) { //有序遍历差分数组
            originCnt += diff; //通过差分数组的DIff还原原始数组
            if (originCnt > 2) {
                //操作回滚，相当于undolog
                posDiff[startTime] -= 1;
                posDiff[endTime] += 1;
                return false;
            }
        }
        //
        return true;
    }

    map<int, int> posDiff; //按照区间的端点有序
    //差分数组的map版本，通过差分数组可以还原原始数组
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end

/*
差分数组
book[1,4)  range[1, 3] +=1 ; means diff[1]+=1, diff[4]-=1
book[2,5)  range[2, 4] +=1;  means diff[2]+=1, diff[5]-=1

DIFF如下
        0   1   2    3   4   5
val     0   1   2    2   1   0
diff    0   1   1    0   -1  -1

然后再 book[3,4)  range[3, 3] +=1;   means diff[3]+=1, diff[4]-=1


        0   1   2    3     4     5
val     0   1   2    2+1   1     0
diff    0   1   1    0+1   -1-1  -1

可以看到 时间点3定了3次，重复了，val=3
因此，从diff从左往右扫描，依次恢复val，只要val>2，就定了3次了

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
