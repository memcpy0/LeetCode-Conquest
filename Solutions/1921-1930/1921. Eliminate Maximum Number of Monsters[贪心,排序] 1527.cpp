/*
** Problem: https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/
** Article: https://memcpy0.blog.csdn.net/article/details/132657380
** Author: memcpy0
*/
// 贪心+排序
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> a;
        int n = dist.size();
        for (int i = 0; i < n; ++i) a.push_back(i);
        sort(a.begin(), a.end(), [&](const int &u, const int &v) {
                double ma = 1.0 * dist[u] / speed[u];
                double mb = 1.0 * dist[v] / speed[v];
                return ma < mb;
        });
        int k = 0;
        while (k < n && 1.0 * dist[a[k]] / speed[a[k]] > k) ++k;
        return k;
    }
};
// BEST: 贪心+计数排序
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> count(n, 0);  //对每只怪物的最迟消灭时间进行计数
        for(int i = 0; i < n; i++) {
            int time = (dist[i] - 1) / speed[i]; //怪物需要在time时间内被消灭
            if(time < n) //time >= n的怪物不用管
                count[time]++;
        }
        int kill = 0; //能够击杀怪物的数量
        for(int i = 0; i < n; i++) {
            kill++;  //每过一秒能多击杀一只怪物
            kill -= count[i];  //减去限定时间需要击杀的怪物
            if(kill < 0)  //如果怪物到达城市
                return i + 1;
        }
        return n;
    }
};
