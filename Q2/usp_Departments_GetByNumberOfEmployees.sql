CREATE DEFINER=`root`@`localhost` PROCEDURE `usp_Departments_GetByNumberOfEmployees`()
BEGIN
	SELECT department_name, 
    COUNT(employee_id) 
    FROM departments
    LEFT OUTER JOIN employees ON employees.department = departments.department_id
    GROUP BY departments.department_id, department_name
    ORDER BY COUNT(employee_id) DESC, department_name ASC;
END
