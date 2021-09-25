/*
** Problem: https://leetcode-cn.com/problems/ugly-number-ii/
** Article: 
** Author: memcpy0
*/
class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        Set<Long> st = new HashSet<>();
        pq.add(1L);
        st.add(1L);
        int[] ps = new int[]{2, 3, 5};
        for (int i = 1; i <= n; ++i) {
            long u = pq.poll();
            if (i == n) return (int)u;
            for (int p : ps) {
                long v = u * p;
                if (!st.contains(v)) {
                    pq.add(v);
                    st.add(v);
                }
            }
        }
        return 0;
    }
}