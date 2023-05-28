/*
** Problem: https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/
** Article: https://memcpy0.blog.csdn.net/article/details/130919857
** Author: memcpy0
*/
class Solution {
    public int averageValue(int[] nums) {
        int sum = 0, cnt = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                sum += x;
                cnt++;
            }
        }
        return cnt > 0 ? sum / cnt : 0;
    }
}