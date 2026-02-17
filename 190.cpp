with tempdata as (
select c.algorithm, QUARTER(dt) AS quarter, sum(volume) as volume
from transactions as t 
inner join coins as c 
on c.code = t.coin_code && YEAR(t.dt)=2020 
group by quarter, c.algorithm
order by c.algorithm asc 
)
SELECT 
    algorithm,
    SUM(CASE WHEN quarter = 1 THEN volume ELSE 0 END) AS transaction_Q1,
    SUM(CASE WHEN quarter = 2 THEN volume ELSE 0 END) AS transaction_Q2,
    SUM(CASE WHEN quarter = 3 THEN volume ELSE 0 END) AS transaction_Q3,
    SUM(CASE WHEN quarter = 4 THEN volume ELSE 0 END) AS transaction_Q4
FROM tempdata
GROUP BY algorithm
ORDER BY algorithm ASC;

-----

with tempdata as (
select 
event_id,
participant_name,
max(score) as score
from scoretable
group by event_id, participant_name
order by event_id asc
),
subdata as (
select 
event_id,
participant_name,
dense_rank() over(order by score desc) as rnk
from tempdata
order by rnk asc 
)
select
event_id,
(select * subdata where subdata.event_id=fin.event_id && subdata.participant_name=fin.participant_name and sub_data.rnk=1) as first
from subdata as fin