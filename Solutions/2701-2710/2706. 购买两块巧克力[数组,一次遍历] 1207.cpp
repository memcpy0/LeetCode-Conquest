/*
** Problem: https://leetcode.cn/problems/buy-two-chocolates/
** Article: https://memcpy0.blog.csdn.net/article/details/135327043
** Author: memcpy0
*/
// python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        mn1 = mn2 = inf
        for p in prices:
            if p < mn1:
                mn2 = mn1
                mn1 = p
            elif p < mn2:
                mn2 = p
        return money if mn1 + mn2 > money else money - mn1 - mn2

// go
func buyChoco(prices []int, money int) int {
    mn1, mn2 := math.MaxInt, math.MinInt
    for _, p := range prices {
        if p < mn1 {
            mn2 = mn1
            mn1 = p
        } else if p < mn2 {
            mn2 = p
        }
    }
    if mn1 + mn2 <= money {
        return money - mn1 - mn2
    }
    return money
}