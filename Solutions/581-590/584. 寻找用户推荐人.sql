/*
** Problem: https://leetcode.cn/problems/find-customer-referee
** Article: https://memcpy0.blog.csdn.net/article/details/129809183
** Author: memcpy0
*/
-- is null
-- select name
-- from customer
-- where referee_id is null or referee_id != 2;

-- 子查询+not in
-- select name
-- from customer
-- where id not in (
-- 	select id
-- 	from customer 
-- 	where referee_id = 2
-- );

-- union all
-- select name
-- from customer
-- where referee_id != 2
-- union all
-- select name
-- from customer
-- where referee_id is null;

-- not exists
select name
from customer C
where not exists (
    select name
    from customer C1
    where C1.id = C.id and C1.referee_id = 2
);