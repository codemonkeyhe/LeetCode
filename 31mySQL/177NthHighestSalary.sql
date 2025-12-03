/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-03
 * @tag   sql; limit N,Offset
 * @similar
 */

/*
表: Employee

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id 是该表的主键（列中的值互不相同）。
该表的每一行都包含有关员工工资的信息。


编写一个解决方案查询 Employee 表中第 n 高的 不同 工资。如果少于 n 个不同工资，查询结果应该为 null 。

查询结果格式如下所示。



示例 1:

输入:
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
n = 2
输出:
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
示例 2:

输入:
Employee 表:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
n = 2
输出:
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| null                   |
+------------------------+
*/


--M1
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare M INT;
    SET M = N -1;
  RETURN (
    select distinct(salary)
    from employee
    order by salary desc
    limit M, 1
  );
END