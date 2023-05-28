/*
** Problem: https://leetcode.cn/problems/statistics-from-a-large-sample/
** Article: https://memcpy0.blog.csdn.net/article/details/130920060
** Author: memcpy0
*/
class Solution {
    public double[] sampleStats(int[] count) {
        int n = 0, min = -1, max = 0, mode = 0;
        long sum = 0;
        for (int i = 0; i < 256; ++i) {
            if (count[i] == 0) continue;
            n += count[i];
            sum += (long)i * count[i];
            if (min == -1) min = i; // 不要重复计算min值
            max = i;
            if (count[i] > count[mode]) mode = i; // 找到众数
        } 
        int i = 0, j = 255;
        // 从左边跳过最多(n-1)/2个数
        for (int t = n - 1 >> 1; t >= count[i]; t -= count[i++]);
        // 从右边跳过最多(n-1)/2个数
        for (int t = n - 1 >> 1; t >= count[j]; t -= count[j--]);
        // 中间两位数(可能是同一个数)求平均
        return new double[]{min, max, (double) sum / n, (i + j) / 2.0, mode};
    }
}