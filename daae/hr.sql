create table product(
num number primary key,
name varchar2(30) not null,
price number not null,
quantity number
);
create sequence seq_product;

create table my_order(
num number primary key,
pro_num number references product(num) on delete cascade,
quantity number not null
);

create sequence seq_my_order;

insert into product values(seq_product.nextval,'»õ¿ì±ø',1000,30);
commit;
select * from PRODUCT;
select * from my_order;
delete from my_order;
commit;
update product set num=seq_product.nextval;
desc my_order;

alter table my_order
add(totalprice number);

select * from my_order;