/*
** Problem: https://leetcode.cn/problems/most-frequent-even-element/
** Article: https://memcpy0.blog.csdn.net/article/details/130147881
** Author: memcpy0
*/
class Solution {
    public int mostFrequentEven(int[] nums) {
        var cnt = new HashMap<Integer, Integer>();
        int mx = -1, ans = -1;
        for (int i : nums) {
            if (i % 2 == 0) {
                int t = cnt.getOrDefault(i, 0) + 1;
                if (t > mx) {
                    mx = t;
                    ans = i;
                } else if (t == mx) ans = Math.min(ans, i);
                cnt.put(i,  t);
            }
        }
        return ans;
    }
}