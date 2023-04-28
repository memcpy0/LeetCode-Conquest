/*
** Problem: https://leetcode.cn/problems/longest-string-chain/
** Article: https://memcpy0.blog.csdn.net/article/details/130437054
** Author: memcpy0
*/
class Solution {
    private Map<String, Integer> ws = new HashMap<>();
    public int longestStrChain(String[] words) {
        for (var s : words) ws.put(s, 0); // 0表示未被计算
        int ans = 0;
        for (var s : ws.keySet())
            ans = Math.max(ans, dfs(s));
        return ans;
    }
    private int dfs(String s) { // dfs(s)表示以s为最后一个单词的链的最长长度
        int res = ws.get(s);
        if (res > 0) return res; // 之前计算过
        for (int i = 0; i < s.length(); ++i) { // 枚举去掉s[i] 
            var t = s.substring(0, i) + s.substring(i + 1);
            if (ws.containsKey(t)) // t在words中
                res = Math.max(res, dfs(t));
        }
        ws.put(s, res + 1); // 记忆化
        return res + 1;
    }
}

class Solution {
    private Map<String, Integer> ws = new HashMap<>();
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        int ans = 0;
        for (var s : words) {
            int res = 0;
            for (int i = 0; i < s.length(); ++i) { // 枚举去掉s[i]
                var t = s.substring(0, i) + s.substring(i + 1);
                res = Math.max(res, ws.getOrDefault(t, 0));
            }
            ws.put(s, res + 1);
            ans = Math.max(ans, res + 1);
        }
        return ans;
    }
}