/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-29
 * @tag  setmentTree
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
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 *
 * https://leetcode.cn/problems/my-calendar-i/description/
 *
 * algorithms
 * Medium (58.27%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 129.6K
 * Testcase Example:  '["MyCalendar","book","book","book"]\n[[],[10,20],[15,25],[20,30]]'
 *
 * 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 重复预订 ，则可以存储这个新的日程安排。
 * 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 重复预订 。
 * 日程可以用一对整数 startTime 和 endTime 表示，这里的时间是半开区间，即 [startTime, endTime), 实数 x
 * 的范围为，  startTime <= x < endTime 。
 *
 * 实现 MyCalendar 类：
 * MyCalendar() 初始化日历对象。
 * boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true
 * 。否则，返回 false 并且不要将该日程安排添加到日历中。
 *
 *
 *
 *
 * 示例：
 * 输入：
 * ["MyCalendar", "book", "book", "book"]
 * [[], [10, 20], [15, 25], [20, 30]]
 * 输出：
 * [null, true, false, true]
 *
 * 解释：
 * MyCalendar myCalendar = new MyCalendar();
 * myCalendar.book(10, 20); // return True
 * myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15
 * 已经被另一个日程安排预订了。
 * myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于
 * 20 ，且不包含时间 20 。
 *
 *
 *
 * 提示：
 * 0 <= start < end <= 10^9
 * 每个测试用例，调用 book 方法的次数最多不超过 1000 次。
 *
 *
 */

// @lc code=start
// brutal force
class MyCalendar1 {
public:
    MyCalendar1() {

    }

    bool bookError(int startTime, int endTime) {
        for (auto seg : segments) {
            if (seg.first >= startTime && seg.first < endTime) {
                return false;
            }
            if (seg.second >= startTime && seg.second < endTime) {
                return false;
            }
        }
        segments.push_back(make_pair(startTime, endTime));
        return true;
    }


    // test case : [[],[25,30],[9,30]]
    bool bookError2(int startTime, int endTime) {
        for (auto seg : segments) {
            if (startTime >= seg.first && startTime < seg.second) {
                return false;
            }
            if (endTime > seg.first && endTime < seg.second) {
                return false;
            }
        }
        segments.push_back(make_pair(startTime, endTime));
        return true;
    }

    // works, but duplicated
    bool bookStupid(int startTime, int endTime) {
        //cout << "cur =[" << startTime << ", " << endTime << "]" << endl;
        for (auto seg : segments) {
            if (startTime >= seg.first && startTime < seg.second) {
                return false;
            }
            if (startTime >= seg.second) {
                continue;
            }
            // startTime must < seg.first
            if (endTime > seg.first) {
                return false;
            }
        }
        segments.push_back(make_pair(startTime, endTime));
        return true;
    }

    // more concise
    bool book(int startTime, int endTime) {
        for (auto seg : segments) {
            if (startTime < seg.second &&  seg.first < endTime) {
                return false;
            }
        }
        segments.push_back(make_pair(startTime, endTime));
        return true;
    }

    vector<pair<int, int> > segments;
};


class MyCalendar2 {
public:
    MyCalendar2() {}

    bool book(int startTime, int endTime) {
        //cout << "cur =[" << startTime << ", " << endTime << "]" << endl;
        auto pa = make_pair(endTime, 0);
        auto it = segments.lower_bound(pa);
        if (it == segments.begin()) { // empty or the first one
            segments.insert({startTime, endTime});
            return true;
        }
        //BUG1  prev = *(it--);
        auto prev = *(--it);
        /* test logic
        if (it == segments.end()) {
            prev = *(--segments.end());
        }
        */
       if (prev.second > startTime) {
            return false;
        }
        segments.insert(make_pair(startTime, endTime));
        return true;
    }

    // 二分查找后再插入，维护有序性，用vector中间插入性能不好，用List无法加速快速二分查找
    //vector<pair<int, int> > segments;
    set<pair<int, int>> segments;
};


class MyCalendar {
public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        posDiff[startTime] += 1;
        posDiff[endTime] -= 1;
        int originCnt = 0;
        for (auto& [pos, diff] : posDiff) {
            originCnt += diff;
            if (originCnt > 1) { // revert
                posDiff[startTime] -= 1;
                posDiff[endTime] += 1;
                return false;
            }
        }
        return true;
    }

    map<int, int> posDiff;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end


/*
输入
["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
[[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]

添加到测试用例
输出
[null,true,true,false,false,true,false,true,true,true,true]
预期结果
[null,true,true,false,false,true,false,true,true,true,false]


输入
["MyCalendar","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]
[[],[20,29],[13,22],[44,50],[1,7],[2,10],[14,20],[19,25],[36,42],[45,50],[47,50],[39,45],[44,50],[16,25],[45,50],[45,50],[12,20],[21,29],[11,20],[12,17],[34,40],[10,18],[38,44],[23,32],[38,44],[15,20],[27,33],[34,42],[44,50],[35,40],[24,31]]

输出
[null,true,false,true,true,false,true,false,true,true,true,true,true,false,true,true,true,false,true,true,true,true,true,false,true,true,false,true,true,true,false]
预期结果
[null,true,false,true,true,false,true,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false]

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
