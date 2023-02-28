/*
** Problem: https://leetcode.cn/problems/circular-permutation-in-binary-representation/
** Article: https://memcpy0.blog.csdn.net/article/details/129273462
** Author: memcpy0
*/
/*
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans, circ;
        int pos, tot = 1 << n;
        for (int i = 0; i < tot; ++i) { // 这种算法下
            circ.push_back(i ^ (i >> 1)); // 从0到第tot个transnum形成循环码
            if (circ.back() == start) pos = i; // 找到start在这个循环码数组中的位置
        }
        for (int i = 0; i < tot; ++i) {
            ans.push_back(circ[pos]); 
            pos = (pos + 1) % tot; // 然后从该位置开始循环
        }
        return ans;
    }
};
*/
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        int tot = (int)Math.pow(2, n);
        List<Integer> rs = new ArrayList<>(tot);
        // 递增遍历,利用格雷码特性,相邻两数的格雷码二进制只有一位不同
        for (int i = 0; i < tot; ++i) {
            int grayCode = i ^ (i >> 1);  // 求格雷码
            // 对start做异或，保证格雷码顺序以start值为起点而不是0
            rs.add(start ^ grayCode);
        }
        return rs;
    }
}