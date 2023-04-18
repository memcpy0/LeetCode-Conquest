/*
** Problem: https://leetcode.cn/problems/managers-with-at-least-5-direct-reports/
** Article: https://memcpy0.blog.csdn.net/article/details/130234453
** Author: memcpy0
*/
select A.name
from Employee A, Employee B
where A.id = B.managerId
group by A.id
having count(*) >= 5;