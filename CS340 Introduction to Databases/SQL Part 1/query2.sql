-- write your queries to insert data here
INSERT INTO client (`first_name`, `last_name`, `dob`) VALUES ('Sara', 'Smith', '1970-01-02');
INSERT INTO client (`first_name`, `last_name`, `dob`) VALUES ('Miguel', 'Cabrera', '1988-02-02');
INSERT INTO client (`first_name`, `last_name`, `dob`) VALUES ('Bo', 'Chang', '1985-03-02');

INSERT INTO employee (`first_name`, `last_name`, `dob`, `date_joined`) VALUES ('Ananya', 'Jaiswal', '1975-01-02', '2009-01-01');
INSERT INTO employee (`first_name`, `last_name`, `dob`, `date_joined`) VALUES ('Michael', 'Fern', '1980-10-18', '2013-06-05');
INSERT INTO employee (`first_name`, `last_name`, `dob`, `date_joined`) VALUES ('Abdul', 'Rehman', '1984-03-21', '2013-11-10');

INSERT INTO project (`cid`, `name`, `notes`) VALUES ((SELECT `id` from `client` WHERE `first_name` = 'Sara'), 'Diamond', 'Should be done by Jan 2019');
INSERT INTO project (`cid`, `name`, `notes`) VALUES ((SELECT `id` from `client` WHERE `first_name` = 'Bo'), 'Chan\'g', 'Ongoing maintenance');
INSERT INTO project (`cid`, `name`, `notes`) VALUES ((SELECT `id` from `client` WHERE `first_name` = 'Miguel'), 'The Robinson Project', 'NULL');

INSERT INTO works_on (`eid`, `pid`, `start_date`) VALUES (
(SELECT `id` from `employee` WHERE `first_name` = 'Ananya'),
(SELECT `id` from `project` WHERE `name` = 'Chan\'g'),
'2012-01-01'
); 

INSERT INTO works_on (`eid`, `pid`, `start_date`) VALUES (
(SELECT `id` from `employee` WHERE `first_name` = 'Michael'),
(SELECT `id` from `project` WHERE `name` = 'The Robinson Project'),
'2013-08-08'
); 

INSERT INTO works_on (`eid`, `pid`, `start_date`) VALUES (
(SELECT `id` from `employee` WHERE `first_name` = 'Abdul'),
(SELECT `id` from `project` WHERE `name` = 'Diamond'),
'2014-09-11'
); 

-- Leave the queries below untouched. These are to test your submission correctly.
select * from project;
select * from client;
select * from employee;
select * from works_on;
