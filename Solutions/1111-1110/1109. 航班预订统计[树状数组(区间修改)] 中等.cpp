/*
** Problem: https://leetcode-cn.com/problems/corporate-flight-bookings/
** Article: https://memcpy0.blog.csdn.net/article/details/116857235
** Author: memcpy0
*/
const int maxn = 2e4 + 100;
#define lowbit(x) ((x) & (-(x)))
int tree[maxn];
void add(int i, int d) {
    while (i < maxn) { tree[i] += d; i += lowbit(i); }
}
int sum(int i) {
    int ans = 0;
    while (i) { ans += tree[i]; i -= lowbit(i); }
    return ans;
}
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans;
        memset(tree, 0, sizeof(tree)); //注意清空数组
        for (const vector<int>& book : bookings) add(book[0], book[2]), add(book[1] + 1, -book[2]);
        for (int i = 0; i < n; ++i) ans.push_back(sum(i + 1));
        return ans;
    }
};