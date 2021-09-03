/*
** Problem: https://leetcode-cn.com/problems/random-pick-index/
** Article: https://memcpy0.blog.csdn.net/article/details/120022542
** Author: memcpy0
*/
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
class Solution {
private:
    vector<int>::iterator begin, end;
    uniform_int_distribution<int> ud;
public:
    Solution(vector<int>& nums) { 
        begin = nums.begin(); 
        end = nums.end(); 
    }
    int pick(int target) {
        int cnt = 0, ans, i = 0;
        for (auto cur = begin; cur != end; ++cur, ++i) {
            if (*cur == target) {
                ++cnt;
                ud.param(uniform_int_distribution<>::param_type{1, cnt});
                if (ud(generator) == cnt) ans = i;
            }
        }
        return ans;
    }
};