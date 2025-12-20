/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-19
 * @tag   sql;
 * @similar 511, 550
 */

/*

Table: Activity

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
（player_id，event_date）是此表的主键（具有唯一值的列的组合）。
这张表显示了某些游戏的玩家的活动情况。
每一行是一个玩家的记录，他在某一天使用某个设备注销之前登录并玩了很多游戏（可能是 0）。
编写解决方案，报告在首次登录的第二天再次登录的玩家的 比率，四舍五入到小数点后两位。换句话说，你需要计算从首次登录后的第二天登录的玩家数量，并将其除以总玩家数。

结果格式如下所示：



示例 1：

输入：
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
输出：
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+
解释：
只有 ID 为 1 的玩家在第一天登录后才重新登录，所以答案是 1/3 = 0.33

*/


--M1

-- ERRORSQL
with tbl (
    select count(distinct(player_id)) as totalCnt
    from activity
),
tbl2 as (
    select count(distinct(t1.player_id)) as cnt2day
    from activity t1
    inner join activity t2  on datediff(t1.event_date, t2.event_date) = 1
    where t1.player_id = t2.player_id
)
select round(tbl2.cnt2day/tbl.totalCnt,2) as fraction
from tbl, tbl2;


-- Error 2  why? 少了AS
with t3 (
    select COUNT(distinct player_id) as totalCnt
    from activity
),
t4 as (
    select COUNT(distinct t1.player_id) as cnt2day
    from activity t1
    inner join activity t2
        on  t1.player_id = t2.player_id
        and datediff(t1.event_date, t2.event_date) = 1
)
select round(t4.cnt2day / t3.totalCnt, 2) as fraction
from t3, t4;

--Error3 why? 少了 AS
with t3 (
select COUNT(distinct player_id) as totalCnt
from activity
),
t4 as (
    select COUNT(distinct t1.player_id) as cnt2day
    from activity t1
    inner join activity t2  on datediff(t1.event_date, t2.event_date) = 1
    where t1.player_id = t2.player_id
)
select round(t4.cnt2day/t3.totalCnt, 2) as fraction
from t3, t4;

--WORK But not right, 但是不符合题意  检查任意连续两天，题目需要首次登陆后的第二天

WITH total_players AS (
    SELECT COUNT(DISTINCT player_id) AS total
    FROM activity
),
consecutive_players AS (
    SELECT COUNT(DISTINCT t1.player_id) AS consecutive_count
    FROM activity t1
    INNER JOIN activity t2
        ON t1.player_id = t2.player_id
        AND DATEDIFF(t1.event_date, t2.event_date) = 1
)
SELECT
    ROUND(
        consecutive_count / NULLIF(total, 0),
        2
    ) AS fraction
FROM total_players, consecutive_players;

-- OK
with t0 as (
    select player_id, min(event_date) as first_date
    from activity
    group by player_id
),
tbl as (
    select count(distinct(player_id)) as totalCnt
    from activity
),
tbl2 as (
    select count(distinct(t0.player_id)) as cnt2day
    from  t0
    inner join activity t2  on t0.player_id = t2.player_id
    and datediff(t2.event_date, t0.first_date) = 1
)
select round(tbl2.cnt2day/tbl.totalCnt,2) as fraction
from tbl, tbl2;


