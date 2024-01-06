/*
** Problem: https://leetcode.cn/problems/nim-game/
** Article: https://memcpy0.blog.csdn.net/article/details/117917135
** Author: memcpy0
*/
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0}, n = words.size();
        for (const string& word : words)
            for (char c : word) ++cnt[c - 'a'];
        return all_of(cnt, cnt + 26, [n](int x) { return x % n == 0; });
    }
};
// python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = [0] * 26 # 每种字符的频数
        n = len(words)
        for word in words:
            for c in word:
                cnt[ord(c) - ord('a')] += 1
        return all(k % n == 0 for k in cnt)
// go
func makeEqual(words []string) bool {
    n := len(words)
    cnt := [26]int{}
    for _, word := range words {
        for _, c := range word {
            cnt[c - 'a']++
        }
    }
    for _, v := range cnt {
        if v % n > 0 {
            return false
        }
    }
    return true
}
