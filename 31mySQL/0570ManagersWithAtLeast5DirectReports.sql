/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-18
 * @tag   sql;
 * @similar
 */

/*

表: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id 是此表的主键（具有唯一值的列）。
该表的每一行表示雇员的名字、他们的部门和他们的经理的id。
如果managerId为空，则该员工没有经理。
没有员工会成为自己的管理者。


编写一个解决方案，找出至少有五个直接下属的经理。

以 任意顺序 返回结果表。

查询结果格式如下所示。



示例 1:

输入:
Employee 表:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | Null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
输出:
+------+
| name |
+------+
| John |
+------+

*/


--M1
select e2.name
from employee e1
inner join  employee e2 on e1.managerId = e2.id
group by e1.managerId
having count(e1.id) >=5


--M2
with manager as (
    select e1.managerId as maid
    from employee e1
    group by e1.managerId
    having count(e1.id) >=5
)
select name
from employee
where id in (
    select manager.maid from manager
)