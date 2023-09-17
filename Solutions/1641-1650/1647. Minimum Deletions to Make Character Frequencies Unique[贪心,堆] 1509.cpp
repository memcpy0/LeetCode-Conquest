/*
** Problem: https://leetcode.cn/problems/minimum-deletions-to-make-character-frequencies-unique
** Article: https://memcpy0.blog.csdn.net/article/details/132844792
** Author: memcpy0
*/
// BEST: 排序+直接哈希
class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for (auto ch: s) {
            cnt[ch - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        
        int ret = 0;
        int prev = cnt[0];
        for (int i = 1; i < 26 && cnt[i] > 0; i++) {
            if (prev <= cnt[i]) {
                prev = max(prev - 1, 0); // 要保留的字符数
                ret += (cnt[i] - prev);
            } else {
                prev = cnt[i];
            }
        }
        return ret;
    }
};
// 哈希表
class Solution {
    public int minDeletions(String s) {
        int[] a = new int[26];
        char[] cs = s.toCharArray();
        for (char c : cs) a[c - 'a'] ++;// 统计字母个数

        Set<Integer> h = new HashSet<Integer>();
        int res = 0;
        for (int i : a) {
            if (i != 0) {               // 有数目才进行判断
                while (h.contains(i)) { // set已经包含就自减
                    i --;
                    res ++;
                }
                if (i != 0) h.add(i);   // 自减到0时，表示完全删除了某个字母，不能加入set中
            }
        }
        return res;
    }
}