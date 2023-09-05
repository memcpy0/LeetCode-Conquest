/*
** Problem: https://leetcode.cn/problems/line-reflection/
** Article: https://memcpy0.blog.csdn.net/article/details/132694417
** Author: memcpy0
*/
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        s = min(points)[0] + max(points)[0]
        vis = { (x, y) for x, y in points}
        return all( (s - x, y) in vis for x, y in vis)