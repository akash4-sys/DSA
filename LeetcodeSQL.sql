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
Where Orders.customerId is NULL -- 175
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