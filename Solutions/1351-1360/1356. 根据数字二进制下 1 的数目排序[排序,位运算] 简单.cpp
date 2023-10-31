/*
** Problem: https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/
** Article: https://memcpy0.blog.csdn.net/article/details/109536206
** Author: memcpy0
*/
// BEST: 写起来简单
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        // for (int i = 1; i <= 10000; ++i) bit[i] = bit[i >> 1] + (i & 1); 
        for (int i = 1; i <= 10000; ++i) bit[i] = bit[i & (i - 1)] + 1;
        sort(arr.begin(), arr.end(), [&](int x, int y) { return bit[x] != bit[y] ? bit[x] < bit[y] : x < y; });
        return arr;
    }
};
// 汉明距离: Java的 Integer::bitCount
int getHammingWeight(int n) {
    n = (n&0x55555555) + ((n>>1)&0x55555555); // 每两个bit
    n = (n&0x33333333) + ((n>>2)&0x33333333); // 每4个bit
    n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f); // 每8个bit
    n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff); // 每16个bit
    n = (n&0x0000ffff) + ((n>>16)&0x0000ffff); // 每32个bit中1的个数
    return n;
}
// 不同写法的汉明距离
class Solution {
private:
    uint32_t bitCount(uint32_t v) {
        v = v - ((v >> 1) & 0x55555555); // put count of each 2 bits into those 2 bits
        v = (v & 0x33333333) + ((v >> 2) & 0x33333333); // put count of each 4 bits into those 4 bits
        // (v + (v >> 4) & 0x0F0F0F0F) 高4位+低4位中1的个数
        // *0x01010101 = A+B+C+D B+C+D C+D D
        return ((v + (v >> 4) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        sort(arr.begin(), arr.end(), [&](int x, int y) { 
            int bx = bitCount(x), by = bitCount(y);
            return bx != by ? bx < by : x < y; 
        });
        return arr;
    }
};
// 查表
class Solution {
private: 
    int record[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    int getOnesOfNumber(int n) {
        if (n == 0) return 0;
        return getOnesOfNumber(n >> 4) + record[n & 0xf];
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](const int &a, const int &b) {
            int a1 = getOnesOfNumber(a), b1 = getOnesOfNumber(b);
            return a1 != b1 ? a1 < b1 : a < b;
        });
        return arr;
    }
};