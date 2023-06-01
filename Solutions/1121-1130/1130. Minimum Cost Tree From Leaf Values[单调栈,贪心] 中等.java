/*
** Problem: https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values
** Article: https://memcpy0.blog.csdn.net/article/details/111707603
** Author: memcpy0
*/
// z,y,x
class Solution {
    public int mctFromLeafValues(int[] arr) {
        Stack<Integer> st = new Stack<>();
        st.push(Integer.MAX_VALUE); // st不可能为空,哨兵
        int ans = 0;
        for (int x : arr) {
            while (st.peek() <= x) { // 栈顶为y
                ans += st.pop() * Math.min(st.peek(), x); // 代价加上min(z, x)
            }
            st.push(x);
        }
        while (st.size() > 2) 
            ans += st.pop() * st.peek();
        return ans;
    }
}