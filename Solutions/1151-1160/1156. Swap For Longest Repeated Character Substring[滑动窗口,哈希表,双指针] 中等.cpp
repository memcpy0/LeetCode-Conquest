/*
** Problem: https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/
** Article: https://memcpy0.blog.csdn.net/article/details/131048888
** Author: memcpy0
*/
/*
class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        unordered_map<int, int> rec; // 记录每个字母出现的总次数,判断是否可以借一个字母进行替换
        for (char c : text) ++rec[c];
        int nums[n], idx = -1; // 将原来的字符串压缩为(a,1),(b,3)这种形式
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && text[j] == text[i]) ++j;
            nums[++idx] = j - i; // 记录该字母连续出现的次数
            // 两个同样字母的串只隔了一个不同的字母,小于该字母的总数时,长度为合并+1
            if (idx > 1 && nums[idx - 1] == 1 && i > 1 && text[i - 2] == text[i])
                ans = max(ans, min(nums[idx] + nums[idx - 2] + 1, rec[text[i]]));
            else ans = max(ans, min(nums[idx] + 1, rec[text[i]]));
            i = j - 1;
            // 其他情况，小于总数时，+1;
        }  
        return ans;
    }
};
*/

class Solution {
public:
    int maxRepOpt1(string text) {
        int cnt[26] = {0};
        for (char &c : text) ++cnt[c - 'a'];
        int n = text.size();
        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text[j] == text[i]) ++j;
            int l = j - i; // 左边子串长度
            int k = j + 1;
            while (k < n && text[k] == text[i]) ++k;
            int r = k - j - 1; // 右边子串长度
            ans = max(ans, min(l + r + 1, cnt[text[i] - 'a']));
            i = j;
        }
        return ans;
    }
};