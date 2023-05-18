/*
** Problem: https://leetcode.cn/problems/reorganize-string/
** Article: https://memcpy0.blog.csdn.net/article/details/110389170
** Author: memcpy0
*/
class Solution {
    public String reorganizeString(String s) {
        if (s.length() < 2) return s;
        int[] counts = new int[26];
        int maxCount = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);
            counts[c - 'a']++;
            maxCount = Math.max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) return "";
        char[] ans = new char[length];
        int eventIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; ++i) {
            char c = (char)('a' + i);
            while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) { // 从奇数下标开始放置
                ans[oddIndex] = c;
                --counts[i];
                oddIndex += 2;
            }
            while (counts[i] > 0) { // 可能是奇数下标放完了,现在放置在偶数下标; 或counts[i]>halfLength
                ans[eventIndex] = c;
                --counts[i];
                eventIndex += 2;
            }
        }
        return new String(ans);
    }
}

class Solution {
    public String reorganizeString(String s) {
        if (s.length() < 2) return s;
        int[] counts = new int[26];
        int maxCount = 0;
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            char c = s.charAt(i);
            ++counts[c - 'a'];
            maxCount = Math.max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) return ""; // 超过范围则不可能重构字符串
        var q = new PriorityQueue<Character>(new Comparator<Character>() {
            public int compare(Character letter1, Character letter2) { // 出现次数相同时，按字典序排列
                if (counts[letter1 - 'a'] == counts[letter2 - 'a']) return letter1 - letter2;
                return counts[letter2 - 'a'] - counts[letter1 - 'a']; // 否则次数大的排在前面
            }
        });
        for (char c = 'a'; c <= 'z'; ++c) if (counts[c - 'a'] > 0) q.offer(c);
        StringBuffer sb = new StringBuffer();
        while (q.size() > 1) {
            char letter1 = q.poll();
            char letter2 = q.poll();
            sb.append(letter1);
            sb.append(letter2);
            int idx1 = letter1 - 'a', idx2 = letter2 - 'a';
            --counts[idx1];
            --counts[idx2];
            if (counts[idx1] > 0) q.offer(letter1);
            if (counts[idx2] > 0) q.offer(letter2);
        }
        if (q.size() > 0) sb.append(q.poll());
        return sb.toString();
    }
}

/*
贪心+计数+排序 
class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<char, int>> cnt;
        for (int i = 0; i < 26; ++i) cnt.push_back({'a' + i, 0});
        for (const char &c : s) ++cnt[c - 'a'].second; //统计次数
        sort(cnt.begin(), cnt.end(), [&](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; //从大到小排序
        }); 
        int k = 0, n = s.size();
        if (cnt[0].second > (n + 1) / 2) return "";  //判断冲突
        string str(n, ' ');
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i].second; ++j) {
                str[k] = cnt[i].first;
                //if (k > 0 && str[k] == str[k - 1]) return ""; //判断冲突
                //if (k < n - 1 && str[k] == str[k + 1]) return "";
                k += 2; 
                if (k >= n) { 
                    if (n & 1) k = k % n; //奇数长度时,直接模n,从下个空处开始放置
                    else k = (k + 1) % n; //偶数长度时,需要+1,再模n
                } 
            }
        }
        return str;
    }
};
 */