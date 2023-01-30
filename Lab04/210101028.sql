---- Task 1
create database week04;

---- Task 2
create table hss_table01 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60)
);

---- Task 3
create table hss_table02 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60),
    primary key (cname)
);

---- Task 4
create table hss_table03 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60),
    primary key (roll_number, cid)
);

---- Task 5
create table hss_table04 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60),
    primary key (sno)
);
alter table hss_table04 add primary key (roll_number);

----- Task 6
create table hss_course01 (
    cid char(10),
    cname char(60),
    primary key (cid)
);
create table hss_table05 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60),
    primary key (roll_number),
    foreign key (cid) references hss_course01 (cid)
);

----- Task 7
create table hss_course02 (
    cid char(10),
    cname char(60),
    primary key (cname)
);
create table hss_table06 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60),
    primary key (roll_number),
    foreign key (cid) references hss_course02 (cid)
);

---- Task 8
create table hss_course03 (
    cid char(10),
    cname char(60)
);
create table hss_table07 (
    sno int,
    roll_number int,
    sname char(50),
    cid char(10),
    cname char(60),
    primary key (roll_number),
    foreign key (cid) references hss_course03 (cid)
);