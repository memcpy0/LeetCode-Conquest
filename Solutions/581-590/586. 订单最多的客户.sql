/*
** Problem: https://leetcode.cn/problems/customer-placing-the-largest-number-of-orders/
** Article: https://memcpy0.blog.csdn.net/article/details/129810718
** Author: memcpy0
*/
-- Write your MySQL query statement below
-- 子查询+group by+having count
-- select customer_number
-- from Orders 
-- group by customer_number having count(order_number) = (
-- 	select max(sum) 
-- 	from (
-- 	    select customer_number, count(order_number) as sum
-- 	    from Orders
-- 	    group by customer_number
-- 	) tmp
-- );

-- 子查询+group by+having count+all
-- select customer_number
-- from orders
-- group by customer_number having count(order_number) >= all(
-- 	select count(order_number)
-- 	from orders
-- 	group by customer_number
-- );

-- order by count+limit
-- select customer_number
-- from Orders
-- group by customer_number
-- order by count(order_number) desc
-- limit 0, 1;

-- 窗口排名函数+order by count
select customer_number
from (
	select *,
		dense_rank() over(order by count(order_number) desc) as ranking
	from Orders
	group by customer_number
) tmp
where ranking = 1;