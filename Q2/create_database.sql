DROP DATABASE IF EXISTS company;
CREATE DATABASE company;
USE company;
    
CREATE TABLE departments (
	department_id int NOT NULL AUTO_INCREMENT,
	department_name varchar(50),
    location varchar(50),
    PRIMARY KEY (department_id)
);
INSERT INTO departments (department_id, name, location) VALUES 
	(DEFAULT, 'Executive', 'Sydney'),
	(DEFAULT, 'Production', 'Sydney'),
	(DEFAULT, 'Resources', 'Cape Town'),
	(DEFAULT, 'Technical', 'Texas'),
    (DEFAULT, 'Management', 'Paris');
    
CREATE TABLE employees(
	employee_id int NOT NULL AUTO_INCREMENT,
	employee_name varchar(50),
    salary int,
    department int,
    PRIMARY KEY (employee_id),
	FOREIGN KEY (department) REFERENCES departments(department_id)
);
INSERT INTO employees (employee_id, name, salary, department) VALUES 
	(DEFAULT, 'Candice', 4685, 1),
	(DEFAULT, 'Julia', 2559, 2),
    (DEFAULT, 'Bob', 4405, 4),
    (DEFAULT, 'Scarlet', 2350, 1),
	(DEFAULT, 'Ilieana', 1151, 4);


