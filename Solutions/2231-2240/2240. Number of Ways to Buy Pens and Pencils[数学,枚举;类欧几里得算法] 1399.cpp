/*
** Problem: https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/
** Article: https://memcpy0.blog.csdn.net/article/details/132656947
** Author: memcpy0
*/
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long n = total / cost1, ans = n + 1;
        for (int i = 0; i <= n; ++i)
            ans += (total - i * cost1) / cost2;
        return ans;
    }
};
// BEST: 类欧几里得算法
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long n = total / cost1;
        int a = -cost1, b = total, c= cost2;
        long long ans=n+1;
        if (a<0){
            ans -= n * (n+1) * (1 - a / c) / 2;
            a = a % c + c;
        }
        return ans + floorsum(a, b, c, n);
    }

    long long floorsum(int a, int b, int c, long long n){
        long long ans=0;
        if (a>=c){
            ans += n * (n+1) * (a / c) / 2;
            a = a % c;
        }
        if (b >= c){
            ans += (n+1) * (b / c);
            b = b % c;
        }
        int m = (a*n+b)/c;
        if (m==0)
            return ans;
        return ans + n*m - floorsum(c, c-b-1, a, m-1);
    }
};