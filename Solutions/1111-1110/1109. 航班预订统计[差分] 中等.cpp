/*
** Problem: https://leetcode-cn.com/problems/corporate-flight-bookings/
** Article: https://memcpy0.blog.csdn.net/article/details/116857235
** Author: memcpy0
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size(), sum = 0;
        vector<int> d(n + 1, 0), ans;
        for (const vector<int>& book : bookings) d[book[0] - 1] += book[2], d[book[1]] -= book[2];
        for (int i = 0; i < n; ++i) {
            sum += d[i];
            ans.push_back(sum);
        }
        return ans;
    }
};