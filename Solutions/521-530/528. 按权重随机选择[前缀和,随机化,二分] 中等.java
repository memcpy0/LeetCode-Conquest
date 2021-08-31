/*
** Problem: https://leetcode-cn.com/problems/random-pick-with-weight/
** Article: https://memcpy0.blog.csdn.net/article/details/120005763
** Author: memcpy0
*/
class Solution {
    private int[] s;
    public Solution(int[] w) {
        s = new int[w.length + 1];
        for (int i = 0; i < w.length; ++i) s[i + 1] = w[i] + s[i];
    }

    public int pickIndex() {
        int n = s.length, l = 1, r = n;
        int target = new Random().nextInt(s[n - 1]); //生成一个随机的int值,介于[0,n)区间
        while (l < r) { //找到第一个大于target的数
            int mid = l + (r - l) / 2;
            if (s[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l - 1; 
    }
}