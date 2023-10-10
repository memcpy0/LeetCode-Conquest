/*
** Problem: https://leetcode.cn/problems/last-moment-before-all-ants-fall-out-of-a-plank/
** Article: https://memcpy0.blog.csdn.net/article/details/133759261
** Author: memcpy0
*/
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        return max(n - 
            (right.empty() ? n : *min_element(right.begin(), right.end())),
            left.empty() ? 0 : *max_element(left.begin(), left.end())
        );
    }
};