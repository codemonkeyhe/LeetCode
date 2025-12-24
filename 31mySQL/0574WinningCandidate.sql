/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-24
 * @tag   sql;
 * @similar
 */

/*
表: Candidate

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
+-------------+----------+
id 是该表中具有唯一值的列
该表的每一行都包含关于候选对象的id和名称的信息。


表: Vote

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| candidateId | int  |
+-------------+------+
id 是自动递增的主键(具有唯一值的列)。
candidateId是id来自Candidate表的外键(reference 列)。
该表的每一行决定了在选举中获得第i张选票的候选人。


编写解决方案来报告获胜候选人的名字(即获得最多选票的候选人)。

生成的测试用例保证 只有一个候选人赢得 选举。

返回结果格式如下所示。



示例 1:

输入:
Candidate table:
+----+------+
| id | name |
+----+------+
| 1  | A    |
| 2  | B    |
| 3  | C    |
| 4  | D    |
| 5  | E    |
+----+------+
Vote table:
+----+-------------+
| id | candidateId |
+----+-------------+
| 1  | 2           |
| 2  | 4           |
| 3  | 3           |
| 4  | 2           |
| 5  | 5           |
+----+-------------+
输出:
+------+
| name |
+------+
| B    |
+------+
解释:
候选人B有2票。候选人C、D、E各有1票。
获胜者是候选人B。

*/


--M1
with t1 as (
    select candidateId, count(id) as cnt
    from vote
    group by candidateId
    order by cnt desc
    limit 1
)
select name
from candidate
where id in (select t1.candidateId from t1)


--M2
with t1 as (
    select candidateId,
    count(id) over (partition by candidateId ) AS co
    from vote
    order by co desc
    limit 1
)
select name
from candidate
where id in (select t1.candidateId from t1)