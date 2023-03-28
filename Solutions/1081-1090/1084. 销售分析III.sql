/*
** Problem: https://leetcode.cn/problems/sales-analysis-iii/
** Article: https://memcpy0.blog.csdn.net/article/details/129823893
** Author: memcpy0
*/
-- 表连接+子查询+ not in
-- select distinct Product.product_id, Product.product_name
-- from Product, Sales
-- where Product.product_id = Sales.product_id and Sales.product_id not in (
--     select Sales.product_id
--     from Sales
--     where Sales.sale_date < '2019-01-01' or Sales.sale_date > '2019-03-31'
-- );

-- 左连接+having count条件计数
select sales.product_id as product_id, product.product_name as product_name
from sales left join product on sales.product_id = product.product_id -- 保留左表为NULL的记录
group by product_id
having count(sale_date between '2019-01-01' and '2019-03-31' or null) = count(*);