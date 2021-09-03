/*
** Problem: https://leetcode-cn.com/problems/random-pick-index/
** Article: https://memcpy0.blog.csdn.net/article/details/120022542
** Author: memcpy0
*/
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
class Solution {
private:
    unordered_map<int, vector<int>> rec;
    uniform_int_distribution<int> ud;
public:
    Solution(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; ++i)
            rec[nums[i]].push_back(i);
    }
    int pick(int target) {
        const vector<int>& v = rec[target];
        int n = v.size() - 1;
        ud.param(uniform_int_distribution<>::param_type{0, n});
        return v[ud(generator)];
    }
};