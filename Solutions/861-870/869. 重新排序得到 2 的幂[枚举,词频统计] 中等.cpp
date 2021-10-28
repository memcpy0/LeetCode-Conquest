/*
** Problem: https://leetcode-cn.com/problems/reordered-power-of-2/
** Article: https://memcpy0.blog.csdn.net/article/details/121026490
** Author: memcpy0
*/
class Solution {
private:
    int cnts[10] = {0}, xcnts[10] = {0}; // m:n的位数
public:
    bool reorderedPowerOf2(int n) {
        while (n) {
            ++cnts[n % 10]; // 数位统计
            n /= 10;
        }
        for (int i = 1; i < 1e9; i <<= 1) { // 遍历数据范围内2的幂
            memset(xcnts, 0, sizeof(xcnts));
            int x = i; 
            while (x) { // 对2的幂进行数位词频统计
                ++xcnts[x % 10];
                x /= 10;
            }
            bool flag = true;
            for (int j = 0; j < 10; ++j) {
                if (cnts[j] != xcnts[j]) { 
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};