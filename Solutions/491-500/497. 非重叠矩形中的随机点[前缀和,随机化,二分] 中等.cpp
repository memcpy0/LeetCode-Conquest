/*
** Problem: https://leetcode-cn.com/problems/random-point-in-non-overlapping-rectangles/
** Article: https://memcpy0.blog.csdn.net/article/details/120005910
** Author: memcpy0
*/
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
class Solution {
private:
    vector<int> s;
    vector<vector<int>>::iterator begin;
    uniform_int_distribution<int> ud; //ud用于选取矩形
public:
    Solution(vector<vector<int>>& rects) {
        begin = rects.begin();
        s.push_back(0);
        for (const vector<int>& r : rects) //计算前缀和
            s.push_back(s.back() + (r[2] - r[0] + 1) * (r[3] - r[1] + 1));
        ud.param(uniform_int_distribution<>::param_type{1, s.back()});
    }
    vector<int> pick() {
        int l = 1, r = s.size(), t = ud(generator);
        while (l < r) { //找到第一个大于等于t的s[l]
            int mid = l + r >> 1;
            if (s[mid] >= t) r = mid;
            else l = mid + 1;
        }
        const vector<int>& rect = *(begin + l - 1); //选取矩形
        int k = s[l] - t; //随机数t代表该矩形中的第k个整数点
        int col = rect[3] - rect[1] + 1;
        return vector<int>{rect[0] + k / col, rect[1] + k % col}; //从左下开始
    }
};