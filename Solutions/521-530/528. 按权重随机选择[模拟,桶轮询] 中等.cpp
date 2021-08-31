/*
** Problem: https://leetcode-cn.com/problems/random-pick-with-weight/
** Article: https://memcpy0.blog.csdn.net/article/details/120005763
** Author: memcpy0
*/
class Solution {
private:
    using bucket = pair<int, int>;
    vector<bucket> seq;
    int bid = 0, inid = 0, tot = 0; //桶编号,桶内编号,最短轮询序列长度
public:
    Solution(vector<int>& w) {
        int n = w.size();
        double sum = 0, minw = DBL_MAX;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            minw = fmin(minw, w[i]);
        }
        double minp = minw / sum;
        int k = 1.0 / minp + 5;
        for (int i = 0; i < n; ++i) {
            int cnt = (int)(w[i] / sum * k);
            seq.push_back(bucket{i, cnt});
            tot += cnt;
        }
    }
    int pickIndex() {
        if (bid >= seq.size()) bid = inid = 0;
        bucket b = seq[bid];
        int id = b.first, cnt = b.second;
        if (inid >= cnt) {
            ++bid;
            inid = 0;
            return pickIndex();
        }
        ++inid;
        return bid;
    }
};