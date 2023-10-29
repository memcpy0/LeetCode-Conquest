/*
** Problem: https://leetcode.cn/problems/h-index/
** Article: https://memcpy0.blog.csdn.net/article/details/118684569
** Author: memcpy0
*/
// BEST
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 0, n = citations.size(); i < n; ++i) 
            if (citations[i] >= n - i) return n - i;
        return 0;
    }
};
// 计数排序+前缀和
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cnt[1010] = {0};
        for (const int &v : citations) ++cnt[v];
        for (int i = 999; i >= 0; --i) cnt[i] += cnt[i + 1];
        for (int h = 1000; h >= 0; --h) {
            //cnt[h]:引用次数至少为h的论文数目为cnt[h]
            if (cnt[h] >= h) return h; //说明至少有h篇(共有cnt[h]篇)文章的引用次数至少为h
        }
        return 0;
    }
};  