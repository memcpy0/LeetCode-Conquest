/*
** Problem: https://leetcode.cn/problems/k-items-with-the-maximum-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/131547505
** Author: memcpy0
*/
class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) return k;
        if (k <= numOnes + numZeros) return numOnes;
        return numOnes - (k - numOnes - numZeros);
    }
}