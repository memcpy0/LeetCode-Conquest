/*
** Problem: https://leetcode.cn/problems/my-calendar-iii/
** Article: https://memcpy0.blog.csdn.net/article/details/116875353
** Author: memcpy0
*/
// 有序集合+差分
class MyCalendarThree {
private:
    map<int, int> d;
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++d[start];
        --d[end];
        int sum = 0, ans = 0;
        for (auto &it : d) {
            sum += it.second; 
            if (sum > ans) ans = sum;
        }
        return ans;
    }
};
// 动态开点线段树+lazy标记
class MyCalendarThree {
public:
    unordered_map<int, pair<int, int>> tree;
    MyCalendarThree() { }
    void update(int s, int e, int l, int r, int idx) {
        if (r < s || e < l) return;
        if (s <= l && r <= e) {
            tree[idx].first++;
            tree[idx].second++; // 懒标记
        } else {
            int mid = (l + r) >> 1;
            update(s, e, l, mid, 2 * idx);
            update(s, e, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }
    int book(int sTime, int eTime) {
        update(sTime, eTime - 1, 0, 1e9, 1);
        return tree[1].first;
    }
};