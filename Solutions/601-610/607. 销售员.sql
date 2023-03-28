/*
** Problem: https://leetcode.cn/problems/sales-person/
** Article: https://memcpy0.blog.csdn.net/article/details/129823786
** Author: memcpy0
*/
select distinct SalesPerson.name
from SalesPerson
where sales_id not in (
    select distinct sales_id
    from Orders
    where Orders.com_id in (
        select com_id
        from Company
        where name = "RED"
    )
);