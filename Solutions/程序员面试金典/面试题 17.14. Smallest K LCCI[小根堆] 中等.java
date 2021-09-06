/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
class Solution {
    public int[] smallestK(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int v : arr) pq.add(v);
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) ans[i] = pq.poll();
        return ans;
    }
}