-- Find the actor_id first_name, last_name and total_combined_film_length 
-- of Sci-Fi films for every actor.
-- That is the result should list the actor ids, names of all of the actors(even if an actor has not been in any Sci-Fi films) 
-- and the total length of Sci-Fi films they have been in.
-- Look at the category table to figure out how to filter data for Sci-Fi films.
-- Order your results by the actor_id in descending order.
-- Put query for Q3 here

CREATE VIEW `scifi_list` AS
SELECT actor.actor_id, actor.first_name, actor.last_name, film_category.category_id, film.length
FROM film
INNER JOIN film_actor ON film_actor.film_id = film.film_id
INNER JOIN film_category ON film_category.film_id = film.film_id
INNER JOIN actor ON actor.actor_id = film_actor.actor_id;

SELECT actor.actor_id, actor.first_name, actor.last_name, COALESCE(SUM(length),0) AS total_combined_film_length FROM `actor` LEFT OUTER JOIN
scifi_list ON actor.actor_id = scifi_list.actor_id
AND
category_id = '14'
GROUP BY actor.actor_id DESC
