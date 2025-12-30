/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-31
 * @tag   sql;
 * @similar
 */

/*


*/


--M1
with t1 as (
    select customer_number, count(*) as cnt
    from orders
    group by customer_number
    order by cnt desc
    limit 1
)
select t1.customer_number
from t1
limit 1;


--M2

    select customer_number
    from orders
    group by customer_number
    order by count(*) desc
    limit 1



