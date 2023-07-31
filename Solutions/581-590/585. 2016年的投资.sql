/*
** Problem: https://leetcode.cn/problems/investments-in-2016/
** Article: https://memcpy0.blog.csdn.net/article/details/132029119
** Author: memcpy0
*/
select round(sum(tiv_2016), 2) as tiv_2016
from Insurance as A
where tiv_2015 in (
    select tiv_2015 from Insurance as B
    where A.pid != B.pid
) and (lat, lon) not in (
    select lat, lon from Insurance as B
    where A.pid != B.pid
);

select round(sum(tiv_2016), 2) as tiv_2016
from Insurance as A
where A.tiv_2015 in (
    select tiv_2015
    from insurance
    group by TIV_2015
    having count(*) > 1
) and concat(lat, lon) in (
    select concat(lat, lon) from Insurance
    group by lat, lon
    having count(*) = 1
);

select round(sum(tiv_2016), 2) as tiv_2016
from (
    select tiv_2016,
        count(1) over (partition by tiv_2015) as tiv_2015_count,
        count(1) over (partition by lat, lon) as location_count
    from Insurance
) tmp
where tiv_2015_count <> 1 and location_count = 1