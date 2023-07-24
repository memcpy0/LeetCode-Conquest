/*
** Problem: https://leetcode.cn/problems/jewels-and-stones/
** Article: https://memcpy0.blog.csdn.net/article/details/108900862
** Author: memcpy0
*/
// BEST
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        long mask = 0; // 把 jewels 转换成字符集合 mask
        for (char c : jewels.toCharArray()) mask |= 1L << (c & 63);
        int ans = 0; // 统计有多少 stones[i] 在集合 mask 中
        for (char c : stones.toCharArray())
            ans += mask >> (c & 63) & 1;
        return ans;
    }
}