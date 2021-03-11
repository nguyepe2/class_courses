-- Find the film_title of all films which feature both KIRSTEN PALTROW and WARREN NOLTE
-- Order the results by film_title in descending order.

CREATE VIEW `both_actors` AS
SELECT film.film_id, film.title, actor.actor_id, actor.first_name, actor.last_name
FROM film
INNER JOIN film_actor ON film_actor.film_id = film.film_id
INNER JOIN actor ON actor.actor_id = film_actor.actor_id;

SELECT DISTINCT title AS film_title
FROM both_actors
WHERE title IN
(SELECT title 
 FROM both_actors
 WHERE actor_id = '21' OR actor_id = '108'
 GROUP BY title HAVING COUNT(*) > 1) 
 GROUP BY title DESC