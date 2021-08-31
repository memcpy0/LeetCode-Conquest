/*
** Problem: https://leetcode-cn.com/problems/random-pick-with-weight/
** Article: https://memcpy0.blog.csdn.net/article/details/120005763
** Author: memcpy0
*/
unsigned seed = chrono::system_clock::now().time_since_epoch().count();       
default_random_engine generator(seed);
class Solution {
private:
    vector<int> s;
    uniform_int_distribution<int> ud;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = w[i] + s[i];
        ud.param(uniform_int_distribution<>::param_type {1, s.back()});
    }
    
    int pickIndex() {
        int target = ud(generator), l = 1, r = s.size(); 
        while (l < r) { //找到前缀和数组s中第一个>=target的下标位置
            int mid = l + (r - l) / 2;
            if (s[mid] >= target) r = mid;
            else l = mid + 1;
        }    
        return l - 1; //从s的下标位置转换到w的下标位置
    }
};