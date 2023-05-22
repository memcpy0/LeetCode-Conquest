/*
** Problem: https://leetcode-cn.com/problems/o8SXZn/
** Article: https://memcpy0.blog.csdn.net/article/details/130813290
** Author: memcpy0
*/
class Solution {
public:
    int storeWater(vector<int>& b, vector<int>& v) {
        int n = b.size();
        if (count(v.begin(), v.end(), 0) == n) return 0;
        int maxv = *max_element(v.begin(), v.end());
        int ans = 100000000;
        for (int i = 1; i <= maxv; ++i) { // 枚举蓄水的次数
            int p = i;
            for (int j = 0; j < n; ++j)
                // 每个水桶v[j]需要蓄水i次，则每个桶的容量应为v[j]/i上取整，和当前容量的差就是要升级的次数
                p += max(0, (v[j] + i - 1) / i - b[j]);
            ans = min(ans, p); // 蓄水的次数和升级水桶的次数
        } 
        return ans;
    }
};
 
class Solution {
public:
    int storeWater(vector<int>& b, vector<int>& v) {
        int n = b.size();
        priority_queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0 && v[i]) { // 桶容量为0,要蓄满v[i]
                ++cnt; // 提前升级一次水桶
                ++b[i];
            }
            if (v[i] > 0) 
                q.emplace((v[i] + b[i] - 1) / b[i], i);
        }
        if (q.empty()) return 0; // 说明v[i]都是0，蓄水次数为0，更不用升级桶
        int ans = INT_MAX;
        while (cnt < ans) {
            auto [tv, i] = q.top();
            ans = min(ans, cnt + tv);
            if (tv == 1) break; // 蓄水次数是1时退出,不可能更少了
            q.pop();
            
            // int t = (v[i] + tv - 2) / (tv - 1); // 尝试对蓄水次数减1,得到应有的桶容量
            // cnt += t - b[i]; // 对应的升级水桶次数
            // b[i] = t;
            // q.emplace(tv - 1, i);
            // 或者尝试升级一次水桶b[i],++cnt,然后重新计算蓄水次数
            ++b[i]; ++cnt;
            q.emplace((v[i] + b[i] - 1) / b[i], i);
        }
        return ans;
    }
}; 