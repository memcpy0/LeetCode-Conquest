/*
** Problem: https://leetcode.cn/problems/maximum-score-from-removing-stones/description/
** Article: https://blog.csdn.net/myRealization/article/details/129273423
** Author: memcpy0
*/
class Solution {
    public int maximumScore(int a, int b, int c) {
        int ans = 0;
        int[] rec = new int[]{a, b, c};
        Arrays.sort(rec);
        while (rec[0] != 0 || rec[1] != 0) {
            --rec[2];
            --rec[1];
            ++ans;
            Arrays.sort(rec); // 重新排序
        }
        return ans;
    }
}