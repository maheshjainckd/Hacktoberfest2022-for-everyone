


CREATE DATABASE SimpleAPI_DB

Go

USE SimpleAPI_DB


Go


create table Products (
	ID INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
	ProductName VARCHAR(50),
	Price INT,
	Quantity INT
)

Go

insert into Products (ProductName, Price, Quantity) values ('Wine - Clavet Saint Emilion', 40, 2);
insert into Products (ProductName, Price, Quantity) values ('Muffin Hinge Container 6', 97, 51);
insert into Products (ProductName, Price, Quantity) values ('Butter - Unsalted', 8, 46);
insert into Products (ProductName, Price, Quantity) values ('Doilies - 10, Paper', 12, 93);
insert into Products (ProductName, Price, Quantity) values ('Beer - True North Lager', 49, 40);
insert into Products (ProductName, Price, Quantity) values ('Lettuce - Boston Bib - Organic', 8, 31);
insert into Products (ProductName, Price, Quantity) values ('Rum - Dark, Bacardi, Black', 41, 34);
insert into Products (ProductName, Price, Quantity) values ('Pesto - Primerba, Paste', 24, 24);
insert into Products (ProductName, Price, Quantity) values ('Soup - Boston Clam Chowder', 44, 30);
insert into Products (ProductName, Price, Quantity) values ('Easy Off Oven Cleaner', 11, 92);


Go

SELECT * FROM Products
