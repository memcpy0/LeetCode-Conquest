/*
** Problem: https://leetcode.cn/problems/my-calendar-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/132795002
** Author: memcpy0
*/
// BEST: 动态开点线段树+懒标记
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }
    void update(int s, int e, int val, int l, int r, int idx) {
        if (r < s || l > e) return;
        if (s <= l && r <= e) {
            tree[idx].first += val;
            tree[idx].second += val;
        } else {
            int mid = (l + r) >> 1;
            update(s, e, val, l, mid, 2 * idx);
            update(s, e, val, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }    
    bool book(int start, int end) {
        update(start, end - 1, 1, 0, 1e9, 1);
        if (tree[1].first > 2) {
            update(start, end - 1, -1, 0, 1e9, 1);
            return false;
        }
        return true;
    }
private:
    unordered_map<int, pair<int, int>> tree;
};
// 有序映射+差分数组
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        int maxBook = 0;
        ++cnt[start];
        --cnt[end];
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            if (maxBook > 2) {
                --cnt[start];
                ++cnt[end];
                return false;
            }
        }
        return true;
    }
private:
    map<int, int> cnt;
};
// 直接遍历
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        for (auto &[l, r] : overlaps)
            if (l < end && start < r) return false;
        for (auto &[l, r] : booked)
            if (l < end && start < r)
                overlaps.emplace_back(max(l, start), min(r, end));
        booked.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
};