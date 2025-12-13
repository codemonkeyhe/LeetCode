/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-13
 * @tag   sql; windowfunc
 * @similar
 */

/*
表: Scores

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id 是该表的主键（有不同值的列）。
该表的每一行都包含了一场比赛的分数。Score 是一个有两位小数点的浮点值。


编写一个解决方案来查询分数的排名。排名按以下规则计算:

分数应按从高到低排列。
如果两个分数相等，那么两个分数的排名应该相同。
在排名相同的分数后，排名数应该是下一个连续的整数。换句话说，排名之间不应该有空缺的数字。
按 score 降序返回结果表。

查询结果格式如下所示。



示例 1:

输入:
Scores 表:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
输出:
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+

*/

/*
rank VS dense_rank
select score,
dense_rank() over (order by score desc) as 'rank',
rank() over (order by score desc) as 'rankSkipID'
from scores;

*/

--M1
select score,
dense_rank() over (order by score desc) as 'rank'
from scores;


--M2
with t1 as (
    select score,
    count(score) as  cnt,
    row_number() over (order by score desc) as rn
    from scores
    group by score
    order by score desc
)
select scores.score, t1.rn as 'RANK'
from scores
inner join t1 on  scores.score = t1.score
order by  scores.score desc


--M3
/*

| score | cnt |
| ----- | --- |
| 4     | 2   |
| 3.85  | 1   |
| 3.65  | 2   |
| 3.5   | 1   |
*/

with t1 as (
    select score,
    count(score) as  cnt
    from scores
    group by score
    order by score desc
)
select scores.score, (select count(*) from t1 where t1.score >= scores.score) as 'RANK'
from scores
order by  scores.score desc;


--M3v2
with t1 as (
    select score
    from scores
    group by score
    order by score desc
)
select scores.score, (select count(*) from t1 where t1.score >= scores.score) as 'RANK'
from scores
order by  scores.score desc;
