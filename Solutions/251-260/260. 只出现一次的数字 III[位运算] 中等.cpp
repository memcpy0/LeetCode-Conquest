/*
** Problem: https://leetcode-cn.com/problems/single-number-iii/
** Article: https://memcpy0.blog.csdn.net/article/details/121064507
** Author: memcpy0
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned axorb = 0;
        for (const int &v : nums) axorb ^= v;
        unsigned diffNum = axorb & (~axorb + 1); // axorb中最低置位1代表的值
        int a = 0, b = 0;
        for (const int &v : nums) { // 将nums分为两组
            if (v & diffNum) a ^= v; // 一组元素diffNum对应的位为1
            else b ^= v; // 另一组元素diffNum对应的位为0
        }
        return {a, b};
    }
};