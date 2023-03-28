/*
** Problem: https://leetcode.cn/problems/game-play-analysis-i/description/
** Article: https://memcpy0.blog.csdn.net/article/details/129807702
** Author: memcpy0
*/
select player_id, min(event_date) as first_login
from Activity
group by player_id;