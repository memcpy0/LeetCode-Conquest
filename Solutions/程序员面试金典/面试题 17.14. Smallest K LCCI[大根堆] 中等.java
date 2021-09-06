/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
class Solution {
    public int[] smallestK(int[] arr, int k) {
        if (k == 0) return new int[k];
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int v : arr) {
            if (pq.size() < k) pq.add(v);
            else if (v < pq.peek()) { pq.poll(); pq.add(v); }
        }
        int[] ans = new int[k];
        for (int i = k - 1; i >= 0; --i) ans[i] = pq.poll();
        return ans;
    }
}