/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-06
 * @tag   sql; leftJoin
 * @similar
 */

/*
Customers 表：

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
在 SQL 中，id 是该表的主键。
该表的每一行都表示客户的 ID 和名称。
Orders 表：

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
在 SQL 中，id 是该表的主键。
customerId 是 Customers 表中 ID 的外键( Pandas 中的连接键)。
该表的每一行都表示订单的 ID 和订购该订单的客户的 ID。


找出所有从不点任何东西的顾客。

以 任意顺序 返回结果表。

结果格式如下所示。



示例 1：

输入：
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
输出：
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

*/


--M1
select name  as 'Customers'
from customers left join orders on customers.id = orders.customerId
where orders.customerId is null


--M2
select name  as 'Customers'
from customers
where id not in  (
    select distinct(customerId)
    from orders
)

--M2v2
with t as (
    select distinct(customerId) as oid
    from orders
)
select name  as 'Customers'
from customers
where id not in  (
    select t.oid from t
)