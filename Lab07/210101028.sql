-- 4c 5c

-- Task 1
create DATABASE week07;
use week07;


-- Task 2
-- a
create table student18a(
    name char(100),
    roll_number char(10) primary key
);
-- b
create table course18a(
    semester int,
    cid char(7) primary key,
    name char(100),
    l int,
    t int,
    p int,
    c int
);
-- c
create table grade18a(
    roll_number char(10),
    cid char(7),
    letter_grade char(2),
    primary key (roll_number, cid)
);


-- Task 3
-- a - 158 rows
load data local infile "/home/jibala/Desktop/CS246/Lab07/student18.csv"
into table student18a
fields terminated by ','
lines terminated by '\n';
-- b - 63 rows
load data local infile "/home/jibala/Desktop/CS246/Lab07/course18.csv"
into table course18a
fields terminated by ','
lines terminated by '\n';
-- c - 9954 rows
load data local infile "/home/jibala/Desktop/CS246/Lab07/grade18.csv"
into table grade18a
fields terminated by ','
lines terminated by '\n';

-- Task 4
-- a
-- i
create view view4a as
select * from grade18a
where cid like '%M';
-- ii
insert into view4a (roll_number, cid, letter_grade) values ('180101000', 'CS101', 'AB');
-- iii
select * from view4a
where roll_number='180101000';
-- Since 180101000 does not take minor courses, view4a is not modified

-- b
create view view4b as
select distinct(cid), letter_grade from grade18a;

insert into view4b (cid, letter_grade) values('CS101', 'PM');

select * from view4b;
-- Not updatable cuz we used distinct 

-- c
create view view4c as
select cid, letter_grade, count(roll_number)
from grade18a
group by cid,letter_grade;

select * from view4c;


-- Task 5
-- a
create table course18b(
    semester int,
    cid char(7) primary key,
    name char(100),
    l int,
    t int,
    p int,
    c int,
    check(semester between 1 and 8)
);

insert into course18b (semester, cid, name, l, t, p, c) values(10, 'CS 777', 'Introduction to Chat GPT', 3, 0, 0, 6);
-- Yes the constraint is honored semester=10 is out of domain

-- b
create table allowable_letter_grade(
    grade char(2) primary key,
    value int
);
insert into allowable_letter_grade values
('AS', 10),
('AA', 10),
('AB', 9),
('BB', 8),
('BC', 7),
('CC', 6),
('CD', 5),
('DD', 4),
('FP', 0),
('FA', 0),
('NP', 0),
('PP', 0),
('I', 0),
('X', 0);


-- c
-- i
drop table grade18b;
create table grade18b(
    roll_number char(10),
    cid char(7),
    letter_grade char(2) check(letter_grade in ('AS','AA','AB','BB','BC','CC','CD','DD','FP','FA','NP','PP','I','X')),
    primary key (roll_number, cid)
);
-- ii
load data local infile "/home/jibala/Desktop/CS246/Lab07/grade18.csv"
into table grade18b
fields terminated by ','
lines terminated by '\n';
-- iii
update grade18b
set letter_grade='MP'
where cid='XX102M' and letter_grade='DD';
-- iv
-- We are trying to update the table with grade 'MP' which does not exists in the allowable_letter_grade

-- Task 6
-- a
create table student18c(
    name char(100),
    roll_number char(10),
    constraint pk6a primary key (roll_number)
);

-- b
create table grade18c(
    roll_number char(10),
    cid char(7),
    letter_grade char(2),
    constraint pk6b primary key (roll_number, cid),
    constraint fk6b foreign key (roll_number) references student18c(roll_number)
);

-- c
alter table grade18c drop constraint fk6b;


-- Task 7
-- a
create table student18d(
    name char(100),
    roll_number char(10) primary key
);

-- b
load data local infile "/home/jibala/Desktop/CS246/Lab07/student18.csv"
into table student18d
fields terminated by ','
lines terminated by '\n';

-- c
select sum(convert(roll_number, unsigned int)) as sum, min(convert(roll_number, unsigned int)) as min, max(convert(roll_number, unsigned int)) as max, avg(convert(roll_number, unsigned int)) as avg
from student18d;

-- d
select convert(roll_number, datetime) from student18d;




-- Task 8
-- a
create table course18e like course18a;
-- b
insert into course18e 
select * from course18a;



-- Task 9
-- a
-- i
drop table student18f;
create table student18f(
    name char(100),
    roll_number char(10),
    redundant01 int default 10,
    constraint pk primary key (roll_number)
);
-- ii
drop table course18f;
create table course18f(
    semester int,
    cid char(7) primary key,
    name char(100),
    l int,
    t int,
    p int,
    c int,
    redundant01 int default 10
);
-- iii
drop table grade18f;
create table grade18f(
    roll_number char(10),
    cid char(7),
    letter_grade char(2),
    redundant01 int default 10,
    constraint cpk primary key (roll_number, cid)
);

-- b
-- i
load data local infile "/home/jibala/Desktop/CS246/Lab07/student18.csv"
into table student18f
fields terminated by ','
lines terminated by '\n'
set redundant01=default;
-- ii
load data local infile "/home/jibala/Desktop/CS246/Lab07/course18.csv"
into table course18f
fields terminated by ','
lines terminated by '\n'
set redundant01=default;
-- iii
load data local infile "/home/jibala/Desktop/CS246/Lab07/grade18.csv"
into table grade18f
fields terminated by ','
lines terminated by '\n'
set redundant01=default;

-- c
select g.roll_number, s.name, g.letter_grade
from grade18f g left join student18f s
using(roll_number)
join course18f c
using(cid)
where l=3 and t=1 and p=0 and c=8;


-- d
delete from grade18f;

-- e
load data local infile "/home/jibala/Desktop/CS246/Lab07/cs570.csv"
into table grade18f
fields terminated by ','
lines terminated by '\n'
set redundant01=default;

-- f
select g.roll_number, s.name, g.letter_grade
from student18f s left join grade18f g
using(roll_number);
