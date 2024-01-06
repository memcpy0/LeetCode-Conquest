/*
** Problem: https://leetcode.cn/problems/assign-cookies/
** Article: https://memcpy0.blog.csdn.net/article/details/108269396
** Author: memcpy0
*/
// cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) { //当其中一个遍历就结束
            if (s[cookie] >= g[child]) ++child;  //用当前饼干可以满足当前孩子的需求，可以满足的孩子数量+1
            ++cookie;                            //不能满足时饼干太小,抛弃
        }
        return child;
    }
};
// java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int m = g.length, n = s.length;
        int count = 0;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            while (j < n && g[i] > s[j]) {
                j++;
            }
            if (j < n) {
                count++;
            }
        }
        return count;
    }
}
// go
func findContentChildren(g []int, s []int) (ans int) {
    sort.Ints(g)
    sort.Ints(s)
    m, n := len(g), len(s)
    for i, j := 0, 0; i < m && j < n; i++ {
        for j < n && g[i] > s[j] {
            j++
        }
        if j < n {
            ans++
            j++
        }
    }
    return
}

> class Solution:
>     def findContentChildren(self, g: List[int], s: List[int]) -> int:
>         s.sort(reverse = True) 
>         g.sort(reverse = True) # s,g排序
>         lens, leng = len(s), len(g)
>         ans = si = sj = 0
>         while si < lens and sj < leng:
>             if s[si] >= g[sj]: # 足够大的饼干满足了这个孩子的胃口
>                 ans += 1 # 分给他
>                 si += 1
>                 sj += 1
>             else: # 这个孩子的胃口太大,不给他分配,将现在的饼干分给下一个
>                 sj += 1
>         return ans 