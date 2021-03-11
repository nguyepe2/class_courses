-- We want to find out how many of each category of film ED CHASE has starred in.

-- So return a table with "category_name" and the count of the "number_of_films" that ED was in that category.

-- Your query should return every category even if ED has been in no films in that category

-- Order by the category name in ascending order.


/*CREATE TABLE `ed chase categories` (
    `category_name` varchar(255) NOT NULL,
    `the_number_of_films` int(11) NOT NULL DEFAULT 0,
    PRIMARY KEY (`category_name`)
)*/

/*CREATE VIEW myview AS
(SELECT film_actor.actor_id, film_actor.film_id, film_category.category_id, category.name
FROM film_actor
INNER JOIN film_category ON film_actor.film_id = film_category.film_id
INNER JOIN category ON category.category_id = film_category.category_id);*/

/*CREATE VIEW filmlist AS
(SELECT film_actor.actor_id, film_actor.film_id, film_category.category_id, category.name
FROM film_actor
LEFT JOIN film_category ON film_actor.film_id = film_category.film_id
LEFT JOIN category ON category.category_id = film_category.category_id
)


INSERT INTO `ed chase categories` (`category_name`, `the_number_of_films`) 
VALUES
(
(SELECT `name` FROM category WHERE 1), 

SELECT name, COUNT(*) FROM myview WHERE actor_id = '3' GROUP BY name
(SELECT COUNT(*) FROM myview WHERE actor_id = '3' GROUP BY `name`)

);*/

CREATE VIEW `EdChaseFilms` AS
SELECT film_actor.actor_id, film_category.category_id, category.name
FROM category
INNER JOIN film_category ON film_category.category_id = category.category_id
INNER JOIN film_actor ON film_actor.film_id = film_category.film_id;

/*SELECT category.category_id, category.name, COALESCE(COUNT(*), 0) AS number_of_films 
FROM category
LEFT OUTER JOIN `EdChaseFilms` ON EdChaseFilms.category_id = category.category_id
AND actor_id = '3' 
GROUP BY name*/

SELECT category.name AS category_name, COALESCE(COUNT(EdChaseFilms.name), 0) AS number_of_films 
FROM category
LEFT OUTER JOIN EdChaseFilms ON EdChaseFilms.category_id = category.category_id
AND actor_id = '3' 
GROUP BY category_name






