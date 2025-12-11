/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-11
 * @tag   sql; 3TablesJoin, windowFunc
 * @similar
 */

/*
表：Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
在 SQL 中，id 是该表的主键。
id 是一个自增列。


找出所有至少连续出现三次的数字。

返回的结果表中的数据可以按 任意顺序 排列。

结果格式如下面的例子所示：



示例 1:

输入：
Logs 表：
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
输出：
Result 表：
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
解释：1 是唯一连续出现至少三次的数字。

*/


--M1

select distinct
    l1.Num as 'ConsecutiveNums'
from
    Logs l1
    inner join Logs l2 on l1.id = l2.id-1
    inner join Logs l3 on l2.id = l3.id-1
where

    l1.Num = l2.Num
    and l2.Num = l3.Num ;


--M2
with t1 as (
    select
            id,
            num,
            cast(row_number() over(partition by num order by id) as signed) as rn
    from Logs
)
select distinct(num) as 'ConsecutiveNums'
from t1
group by t1.num, rn-id
having count(t1.num) >= 3;