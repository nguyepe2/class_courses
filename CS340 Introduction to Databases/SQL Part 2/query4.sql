-- Find the actor_id, first_name and last_name of all actors who have never been in a Sci-Fi film.
-- Order by the actor_id in ascending order.
-- Put your query for Q4 here


SELECT actor.actor_id, actor.first_name, actor.last_name FROM `actor` LEFT OUTER JOIN
scifi_list ON actor.actor_id = scifi_list.actor_id
AND
category_id = '14'
WHERE
length IS NULL
GROUP BY actor.actor_id ASC
