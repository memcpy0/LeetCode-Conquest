/*
** Problem: https://leetcode.cn/problems/move-pieces-to-obtain-a-string
** Article: https://memcpy0.blog.csdn.net/article/details/132419096
** Author: memcpy0
*/
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (target[j] == '_') continue;
            while (i < n && start[i] == '_') ++i;
            if (i == n || 
                start[i] != target[j] || // 当前字符不同
                i != j && (start[i] == 'L') == (i < j)) 
                return false; // 顺序不符合
            ++i; 
        }
        while (i < n)
            if (start[i++] != '_') return false;
        return true;
    }
};