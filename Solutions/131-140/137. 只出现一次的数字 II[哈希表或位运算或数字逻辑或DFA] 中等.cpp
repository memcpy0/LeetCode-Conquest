/*
** Problem: https://leetcode-cn.com/problems/single-number-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/133879612
** Author: memcpy0
*/
// 哈希表略

// 依次确定每一个二进制位
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num : nums) 
                total += ((num >> i) & 1); // 所有数的第i个二进制位之和
            if (total % 3) ans |= (1 << i); // 设置答案的第i个二进制位
        }
        return ans;
    }
};
// 位运算：使用三个变量
class Solution {
public: 
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three;
        for (int num : nums) {
            // two的相应的位等于1，表示该位出现2次
            two |= (one & num);
            // one的相应的位等于1，表示该位出现1次
            one ^= num;
            // three的相应的位等于1，表示该位出现3次
            three = (one & two);
            // 如果相应的位出现3次，则该位重置为0
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

// BEST: 数字逻辑/DFA
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num: nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};