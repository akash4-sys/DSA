-- 595

Select name,
    population,
    area
from World
where population >= 25000000
    or area >= 3000000;


-- 1757

Select product_id
from Products
where low_fats = 'Y'
    and recyclable = 'Y';


-- 584

Select name
from Customer
where referee_id != 2
    or referee_id is NULL;


-- 183

Select name as Customers
From Customers
    Left Join Orders On (Customers.id = Orders.customerId)
Where Orders.customerId is NULL ;

-- 175

Select firstName,
    lastName,
    city,
    state
From Person
    Left Join Address On Person.personId = Address.PersonId;


-- 176

Select (
        Select Distinct Salary
        From Employee
        Order By Salary Desc
        Limit 1 Offset 1
    ) As SecondHighestSalary;


--177

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN
SET N = N - 1;
RETURN (
    SELECT (
            SELECT DISTINCT Salary
            FROM Employee
            ORDER BY Salary DESC
            LIMIT 1 OFFSET N
        )
);
END;

-- 178

Select score,
    Dense_Rank() Over(
        Order By score Desc
    ) 'rank'
From Scores
Order By score Desc;


-- 180

Select Distinct L1.Num As ConsecutiveNums
From Logs L1,
    Logs L2,
    Logs L3
Where L1.Id = L2.Id - 1
    And L2.Id = L3.Id - 1
    And L1.Num = L2.Num
    And L2.Num = L3.Num;
    
--181

Select E.name as Employee
From Employee as E,
    Employee as M
Where E.ManagerId = M.Id
    And E.salary > M.Salary;
    
-- 182

Select Distinct E1.email as Email
From Person as E1,
    Person as E2
Where E1.Email = E2.Email
    And E1.Id != E2.Id ;
    
-- 1873

Select employee_id,
    IF(
        name Not like 'M%'
        And employee_id % 2 != 0,
        salary,
        0
    ) As bonus
From Employees
ORDER BY employee_id;


--627

UPDATE Salary
SET sex = IF(sex = 'm', 'f', 'm');


--196

DELETE P1
FROM Person P1,
    Person P2
WHERE P1.email = P2.email
    AND P1.id > P2.id;


--1407

SELECT u.name,
    (
        SELECT IFNULL(SUM(r.distance), 0)
        FROM Rides r
        WHERE u.id = r.user_id
    ) AS travelled_distance
FROM users u
ORDER BY travelled_distance DESC,
    u.name ASC;
    
    --197

SELECT DISTINCT WA.id
FROM WEATHER WA,
    WEATHER WB
WHERE WA.Temperature > WB.Temperature
    AND DATEDIFF(WA.Recorddate, WB.Recorddate) = 1 ;
    
--1527

SELECT *
FROM Patients
WHERE conditions LIKE '% DIAB1%'
    OR CONDITIONS LIKE 'DIAB1%';


--511

SELECT player_id,
    MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;


--586

SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY count(*) DESC
limit 1;


--596

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(class) >= 5;


--1667

SELECT user_id,
    CONCAT(
        UPPER(LEFT(name, 1)),
        LOWER(SUBSTRING(name, 2, LENGTH(name)))
    ) AS name
FROM Users
ORDER BY user_id;


--1484

SELECT sell_date,
    count(DISTINCT product) AS num_sold,
    GROUP_CONCAT(
        DISTINCT product
        ORDER BY product asc SEPARATOR ','
    ) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;


--1965

SELECT employee_id
FROM Employees
WHERE employee_id NOT IN (
        SELECT employee_id
        FROM salaries
    )
UNION
SELECT employee_id
FROM Salaries
WHERE employee_id NOT IN (
        SELECT employee_id
        FROM employees
    )
ORDER BY employee_id;



--1795

SELECT product_id,
    'store1' AS store,
    store1 AS price
FROM Products
WHERE store1 IS NOT NULL
UNION
SELECT product_id,
    'store2' AS store,
    store2 AS price
FROM Products
WHERE store2 IS NOT NULL
UNION
SELECT product_id,
    'store3' AS store,
    store3 AS price
FROM Products
WHERE store3 IS NOT NULL;



--608
SELECT id, 
    'Root' as type
FROM tree
WHERE p_id IS NULL
UNION
SELECT id,
    'Leaf' as type
FROM tree
WHERE
    id NOT IN (
        SELECT DISTINCT p_id
        FROM tree
        WHERE p_id IS NOT NULL
    )
AND
    p_id IS NOT NULL
UNION
SELECT id,
    'Inner' as type
FROM tree
WHERE
    id IN (
        SELECT DISTINCT p_id
        FROM tree
        WHERE p_id IS NOT NULL
    )
AND p_id IS NOT NULL
ORDER BY id;


--608 other way


SELECT
    t.id,
    IF(ISNULL(t.p_id),
        'Root',
        IF(t.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
FROM
    tree t
ORDER BY t.id;


--1581


SELECT customer_id,
COUNT(v.visit_id) AS count_no_trans
FROM Visits v
NATURAL LEFT JOIN
Transactions t
WHERE t.visit_id IS NULL
GROUP BY customer_id;


--1148


SELECT DISTINCT V.author_id as id
FROM Views V
WHERE V.author_id = V.viewer_id
ORDER BY id;


--607


SELECT S.name
FROM SalesPerson S
WHERE S.sales_id NOT IN (
    SELECT O.sales_id
    FROM Orders O
    LEFT JOIN Company C 
    ON C.com_id = O.com_id
    WHERE C.name = 'RED'
);


--1141


SELECT activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users,
FROM Activity
WHERE activity_date > "2019-06-27" 
    AND activity_date <= "2019-07-27"
ORDER BY activity_date;



--1393


SELECT stock_name,
SUM(IF(operation = 'BUY', -price, price))
AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;


--1158


SELECT U.user_id AS buyer_id,
    join_date,
IFNULL(COUNT(order_date), 0) AS orders_in_2019
FROM Users AS U
LEFT JOIN
Orders AS O
ON U.user_id = O.user_id
AND YEAR(order_date) = '2019'
GROUP BY U.user_id;



--1729


SELECT DISTINCT user_id,
    COUNT(*) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;


--1693


SELECT 
    date_id, 
    make_name,
    COUNT(DISTINCT lead_id) AS unique_leads,
    COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id, make_name;


--1890


SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = 2020
GROUP BY user_id;


--1741


SELECT 
    event_day AS day, 
    emp_id, 
    SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY day, emp_id;



-1050
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(actor_id) > 2



--1587


SELECT name,
    SUM(amount) AS balance
FROM Users
NATURAL JOIN Transactions
GROUP BY account
HAVING balance > 10000;



--1084



SELECT product_id, product_name
FROM Sales 
JOIN Product 
Using(product_id)
GROUP BY product_id
HAVING MIN(sale_date) >= '2019-01-01' 
    AND MAX(sale_date) <= '2019-03-31' 