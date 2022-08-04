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
Where Orders.customerId is NULL

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
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
    RETURN (
        SELECT (
            SELECT DISTINCT Salary
            FROM Employee
            ORDER BY Salary DESC
            LIMIT 1 OFFSET N
      )
  );
END

-- 178
Select score, 
    Dense_Rank() Over(Order By score Desc) 'rank'
    From Scores
    Order By score Desc;

-- 180
Select Distinct
    L1.Num As ConsecutiveNums
    From
        Logs L1,
        Logs L2,
        Logs L3
    Where
        L1.Id = L2.Id - 1
        And L2.Id = L3.Id - 1
        And L1.Num = L2.Num
        And L2.Num = L3.Num

--181
Select E.name as Employee
    From Employee as E, Employee as M
    Where E.ManagerId  = M.Id
    And E.salary > M.Salary

-- 182
Select Distinct E1.email as Email
    From Person as E1, Person as E2
    Where E1.Email = E2.Email
    And E1.Id != E2.Id


-- 1873
Select employee_id, 
    IF(
        name Not like 'M%'
        And
        employee_id % 2 != 0,
        salary,
        0
    )
    As
    bonus
    From Employees ORDER BY employee_id;


--627
UPDATE Salary
SET sex  = 
    IF(sex = 'm', 'f', 'm');


--196
DELETE P1 FROM Person P1, Person P2
    WHERE
    P1.email = P2.email 
    AND P1.id > P2.id;