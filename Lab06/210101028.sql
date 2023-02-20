-- Task 1
CREATE DATABASE week06;
use week06;


-- Task 2
-- a
CREATE TABLE student(
    cid CHAR(7),
    roll_number CHAR(10),
    name CHAR(100) NOT NULL,
    approval_status ENUM('Approved', 'Pending'),
    credit_status ENUM('Credit', 'Audit'),
    PRIMARY KEY (roll_number, cid)
);
-- b
CREATE TABLE course(
    cid CHAR(7) PRIMARY KEY,
    name CHAR(100) NOT NULL
);
-- c
CREATE TABLE credit(
    cid CHAR(7) PRIMARY KEY,
    l INT NOT NULL,
    t INT NOT NULL,
    p INT NOT NULL,
    c FLOAT(2) NOT NULL
);
-- d
CREATE TABLE faculty(
    cid CHAR(7),
    name CHAR(50)
);
CREATE TABLE semester(
    dept CHAR(4),
    number CHAR(4),
    cid CHAR(7)
);


-- Task 3
-- a - 18871 rows
load data local infile "/home/jibala/Desktop/CS246/Lab06/students-credits.csv"
into table student
fields terminated by ','
lines terminated by '\n';
-- b - 348 rows
load data local infile "/home/jibala/Desktop/CS246/Lab06/courses.csv"
into table course
fields terminated by ','
lines terminated by '\n';
-- c - 348 rows
load data local infile "/home/jibala/Desktop/CS246/Lab06/credits.csv"
into table credit
fields terminated by ','
lines terminated by '\n';
-- d - 33 rows
load data local infile "/home/jibala/Desktop/CS246/Lab06/faculty-course.csv"
into table faculty
fields terminated by ','
lines terminated by '\n';
-- e - 166 rows
load data local infile "/home/jibala/Desktop/CS246/Lab06/semester.csv"
into table semester
fields terminated by ','
lines terminated by '\n';


-- Task 4
-- a
select sum(l) from credit;
-- b
select sum(c) from credit where cid like 'EE%';
-- c
select sum(p) from credit where cid like 'DD%';


-- Task 5
-- a
select cid, count(*) 
from student 
where cid like '%M' and credit_status='Audit' 
group by cid;
-- b
select substring(cid, 1, 2) as dept, sum(c)
from credit
group by(substring(cid, 1, 2));


-- Task 6
-- a
select cid, count(*) 
from student 
where credit_status='Audit'
group by cid 
having(count(*) >= 4);
-- b
select f.cid, count(*)
from faculty f join course c 
on f.cid=c.cid
group by f.cid 
having(count(*) > 1);
-- c
select name, count(*)
from faculty
group by name
having(count(*) > 1);

-- Task 7
-- a
select cr.cid, co.name, cr.c
from credit cr join course co
on cr.cid = co.cid
where cr.c = (select min(c) from credit);
-- b
select f.cid, f.name
from faculty f join credit c 
on c.cid = f.cid 
where f.cid like 'CS%' and c.c = (select min(c) from credit where cid like 'CS%');


-- Task 8
-- a & b
create table table08 as(
    select s.dept as dept, s.number as sem, cr.c as cred
    from semester s join credit cr 
    on s.cid = cr.cid 
    where s.dept in ('BSBE', 'DD')
);
-- a
select sem
from table08
where dept='BSBE'
group by sem 
having(sum(cred) < some(
    select sum(cred)
    from table08
    where dept='DD'
    group by sem 
));
-- b
select sem
from table08
where dept='BSBE'
group by sem 
having(sum(cred) >= all(
    select sum(cred)
    from table08
    where dept='DD'
    group by sem 
));