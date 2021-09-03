/*
** Problem: https://leetcode-cn.com/problems/random-pick-index/
** Article: https://memcpy0.blog.csdn.net/article/details/120022542
** Author: memcpy0
*/
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
class Solution {
private:
    vector<int> arr;
    uniform_int_distribution<int> ud;
public:
    Solution(vector<int>& nums) { arr = nums; }
    int pick(int target) { 
        //扫描整个数组,如果遇到第cnt个target,就以1/cnt的概率选择其下标并替换之前选取的下标
        int cnt = 0, ans;
        for (int i = 0, n = arr.size(); i < n; ++i) {
            if (arr[i] == target) {
                ++cnt;
                ud.param(uniform_int_distribution<>::param_type{1, cnt});
                if (ud(generator) == cnt) ans = i;
            }
        }
        return ans;
    }
};