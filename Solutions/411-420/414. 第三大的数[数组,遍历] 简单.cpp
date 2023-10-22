/*
** Problem: https://leetcode-cn.com/problems/third-maximum-number/
** Article: https://memcpy0.blog.csdn.net/article/details/133973424
** Author: memcpy0
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) { 
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN; 
        for (int &num : nums) {
            if (num > a) {
                c = b; b = a; a = num;
            } else if (num > b && num < a) {
                c = b; b = num;
            } else if (num > c && num < b) {
                c = num;
            }
        }
        return (c == LONG_MIN) ? a : c;
    }
};
// 不依赖数据范围
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for (int &num : nums) {
            if (a == nullptr || num > *a) {
                c = b;
                b = a;
                a = &num;
            } else if (*a > num && (b == nullptr || num > *b)) {
                c = b;
                b = &num;
            } else if (b != nullptr && *b > num && (c == nullptr || num > *c)) {
                c = &num;
            }
        }
        return c == nullptr ? *a : *c;
    }
};