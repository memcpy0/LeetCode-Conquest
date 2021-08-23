/*
** Problem: https://leetcode-cn.com/problems/get-maximum-in-generated-array/
** Article: https://memcpy0.blog.csdn.net/article/details/119879925
** Author: memcpy0
*/
class Solution {
private:
    int ans[101] = {0,1,1,2,2,3,3,3,3,4,4,5,5,5,5,5,5,5,5,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,11,11,11,11,11,11,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,14,14,14,15,15,18,18,18,18,18,18,18,18,19,19,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21};
public:
    int getMaximumGenerated(int n) { 
        return ans[n];  
    }
};