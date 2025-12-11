/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-03
 * @tag   sql; limit N,Offset;WindowFun
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



--M2
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

with t1 as (
select id,
salary,
dense_rank() over(order by salary desc) as rk
from employee
)
select salary
from t1
where t1.rk = N
limit 1

  );
END


/*
思路6：窗口函数
实际上，在mysql8.0中有相关的内置函数，而且考虑了各种排名问题：

row_number(): 同薪不同名，相当于行号，例如3000、2000、2000、1000排名后为1、2、3、4
rank(): 同薪同名，有跳级，例如3000、2000、2000、1000排名后为1、2、2、4
dense_rank(): 同薪同名，无跳级，例如3000、2000、2000、1000排名后为1、2、2、3
ntile(): 分桶排名，即首先按桶的个数分出第一二三桶，然后各桶内从1排名，实际不是很常用
显然，本题是要用第三个函数。
另外这三个函数必须要要与其搭档over()配套使用，over()中的参数常见的有两个，分别是

partition by，按某字段切分
order by，与常规order by用法一致，也区分ASC(默认)和DESC，因为排名总得有个依据
注：下面代码仅在mysql8.0以上版本可用，最新OJ已支持。



作者：小数志
链接：https://leetcode.cn/problems/nth-highest-salary/solutions/166401/mysql-zi-ding-yi-bian-liang-by-luanz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

********/