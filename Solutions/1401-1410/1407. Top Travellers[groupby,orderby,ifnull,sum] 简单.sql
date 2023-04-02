/*
** Problem: https://leetcode.cn/problems/top-travellers/
** Article: https://memcpy0.blog.csdn.net/article/details/129907243
** Author: memcpy0
*/
select Users.name as name, ifnull(sum(Rides.distance), 0) as travelled_distance
from Users left join Rides on Users.id = Rides.user_id
group by Rides.user_id
order by travelled_distance desc, Users.name asc;