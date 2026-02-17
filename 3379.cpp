WITH tempdata AS (
    SELECT 
        event_id,
        participant_name,
        MAX(score) AS score
    FROM scoretable
    GROUP BY event_id, participant_name
),
subdata AS (
    SELECT 
        event_id,
        participant_name,
        DENSE_RANK() OVER(PARTITION BY event_id ORDER BY score DESC) AS rnk
    FROM tempdata
    order by event_id asc, participant_name asc 
)
--group event_id,participant_name,rnk, order by name
subdata2 as (
     SELECT 
        event_id,
        participant_name,
        rnk
    FROM subdata
    group by event_id, rnk
    order by participant_name asc    
)
SELECT
    event_id,
    GROUP_CONCAT(CASE WHEN rnk = 1 THEN participant_name END SEPARATOR ',') AS first,
    GROUP_CONCAT(CASE WHEN rnk = 2 THEN participant_name END SEPARATOR ',') AS second,
    GROUP_CONCAT(CASE WHEN rnk = 3 THEN participant_name END SEPARATOR ',') AS third
FROM subdata2
WHERE rnk <= 3
GROUP BY event_id
ORDER BY event_id;