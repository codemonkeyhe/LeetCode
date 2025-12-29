/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-28
 * @tag   sql; groupBy; sumIf
 * @similar
 */

/*


*/


--M1
with t1 as (
    select question_id, count(*) as showCnt
    from SurveyLog
    where action = 'show'
    group by question_id
),
t2 as (
    select question_id, count(*) as ansCnt
    from SurveyLog
    where action = 'answer'
    group by question_id
),
t3 as(
select t1.question_id, ROUND(t2.ansCnt/t1.showCnt, 4) as ansRate
from t1 inner join t2 on t1.question_id = t2.question_id
order by ansRate desc, question_id asc
)
select t3.question_id  as 'survey_log'
from t3
limit 1;


--M2
# Write your MySQL query statement below
with t1 as (
    select question_id,
    sum(if(action='show', 1, 0)) as showCnt,
    sum(if(action='answer', 1, 0)) as ansCnt
    from SurveyLog
    group by question_id
),
t3 as(
    select t1.question_id, ROUND(t1.ansCnt/t1.showCnt, 4) as ansRate
    from t1
    order by ansRate desc, question_id asc
)
select t3.question_id  as 'survey_log'
from t3
limit 1


