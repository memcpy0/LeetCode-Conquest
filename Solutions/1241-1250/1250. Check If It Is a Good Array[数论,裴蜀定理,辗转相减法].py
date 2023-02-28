"""
Problem: https://leetcode.cn/problems/check-if-it-is-a-good-array/
Article: https://memcpy0.blog.csdn.net/article/details/129273482
"""
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return reduce(gcd, nums) == 1