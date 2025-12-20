/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-20
 * @tag   sql;
 * @similar
 */

/*
表: Customer

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
在 SQL 中，id 是该表的主键列。
该表的每一行表示一个客户的 id、姓名以及推荐他们的客户的 id。
找出以下客户的姓名：

被任何 id != 2 的用户推荐。
没有被 任何用户推荐。
以 任意顺序 返回结果表。

结果格式如下所示。



示例 1：

输入：
Customer 表:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
输出：
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+

*/


--M1
select name
from customer
where referee_id is null or referee_id != 2;


/*


MySQL 使用三值逻辑 —— TRUE, FALSE 和 UNKNOWN。任何与 NULL 值进行的比较都会与第三种值 UNKNOWN 做比较。这个“任何值”包括 NULL 本身！这就是为什么 MySQL 提供 IS NULL 和 IS NOT NULL 两种操作来对 NULL 特殊判断。

因此，在 WHERE 语句中我们需要做一个额外的条件判断 `referee_id IS NULL'。

提示
下面的解法同样是错误的，错误原因同上。避免错误的秘诀在于使用 IS NULL 或者 IS NOT NULL 两种操作来对 NULL 值做特殊判断。
Sql
SELECT name FROM customer WHERE referee_id = NULL OR referee_id <> 2;

作者：LeetCode
链接：https://leetcode.cn/problems/find-customer-referee/solutions/20888/xun-zhao-yong-hu-tui-jian-ren-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

