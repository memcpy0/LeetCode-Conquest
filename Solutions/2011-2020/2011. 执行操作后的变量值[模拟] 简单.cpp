/*
** Problem: https://leetcode-cn.com/problems/final-value-of-variable-after-performing-operations/
** Article: https://memcpy0.blog.csdn.net/article/details/120476304
** Author: memcpy0
*/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (int i = 0, n = operations.size(); i < n; ++i)
            x += (operations[i][1] == '+') ? 1 : -1; 
        return x;
    }
};