/*
** Problem: https://leetcode.cn/problems/my-calendar-i/
** Article: https://memcpy0.blog.csdn.net/article/details/132795135
** Author: memcpy0
*/
// BEST: 动态开点线段树+懒标记
class MyCalendar {
public:
    MyCalendar() {

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
        if (tree[1].first > 1) {
            update(start, end - 1, -1, 0, 1e9, 1);
            return false;
        }
        return true;
    }
private:
    unordered_map<int, pair<int, int>> tree;
};
class MyCalendar {
    unordered_set<int> tree, lazy;
public:
    bool query(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return false;
        }
        /* 如果该区间已被预订，则直接返回 */
        if (lazy.count(idx)) {
            return true;
        }
        if (start <= l && r <= end) {
            return tree.count(idx);
        }
        int mid = (l + r) >> 1;
        return query(start, end, l, mid, 2 * idx) ||
               query(start, end, mid + 1, r, 2 * idx + 1);
    }

    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        }
        if (start <= l && r <= end) {
            tree.emplace(idx);
            lazy.emplace(idx);
        } else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree.emplace(idx);
            if (lazy.count(2 * idx) && lazy.count(2 * idx + 1)) {
                lazy.emplace(idx);
            }
        }
    }

    bool book(int start, int end) {
        if (query(start, end - 1, 0, 1e9, 1)) {
            return false;
        }
        update(start, end - 1, 0, 1e9, 1);
        return true;
    }
};

// 有序集合+二分查找
class MyCalendar {
    set<pair<int, int>> booked;
public:
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};

// 直接遍历
class MyCalendar {
private:
    vector<pair<int, int>> booked;
public:
    bool book(int start, int end) {
        for (auto &[l, r] : booked)
            if (l < end && start < r) return false;
        booked.emplace_back(start, end);
        return true;
    }
};