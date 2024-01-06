/*
** Problem: https://leetcode.cn/problems/valid-anagram/
** Article: https://memcpy0.blog.csdn.net/article/details/108631591
** Author: memcpy0
*/
从另一个角度考虑，$t$ 是 $s$ 的异位词等价于「两个字符串中字符出现的种类和次数均相等」。用两个整数数组，进行字符计数，然后比较。代码如下：
// cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 考虑字符集和空串
        int sset[26] = {0}, tset[26] = {0};
        for (const char &c : s) ++sset[c - 'a'];
        for (const char &c : t) ++tset[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (sset[i] != tset[i]) return false;
        return true;
    }
};
进一步优化，我们可以**只维护**一个长度为 $26$ 的频次数组 $cnt$ ，先遍历记录字符串 $s$ 中字符出现的频次，**同时遍历记录**字符串 $t$ 并减去对应的频次。最后检查 $cnt$ 数组，如果出现 $cnt[i]<0$ ，则返回 $false$ ：
// cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        //优化:长度不等时直接返回
        if (s.size() != t.size()) return false;
        int cnt[26] = {0};
        for (int i = 0, n = s.size(); i < n; ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        return all_of(cnt, cnt + 26, [](int x) { return x >= 0; });
    }
};
// python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        for c in t:
            cnt[ord(c) - ord('a')] -= 1
            if cnt[ord(c) - ord('a')] < 0:
                return False
        return True
// go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    cnt := [26]int{}
    for i := range s { // 一次遍历
        cnt[s[i] - 'a']++
        cnt[t[i] - 'a']--
    }
    for _, v := range cnt {
        if v != 0 {
            return false
        }
    }
    return true
}
对于进阶问题，$\text{Unicode}$ 是为了解决传统字符编码的局限性而产生的方案，**它为每个语言中的字符规定了一个唯一的二进制编码**。而 $Unicode$ 中可能存在**一个字符对应多个字节**的问题，==为了让计算机知道多少字节表示一个字符，面向传输的编码方式的 $\text{UTF}-8$ 和 $\text{UTF}-16$ 也随之诞生逐渐广泛使用== 。

回到本题，进阶问题的核心点在于「字符是离散未知的」，因此我们用哈希表维护对应字符的频次即可。同时需要注意 $\text{Unicode}$ 一个字符可能对应多个字节的问题，不同语言对于字符串读取处理的方式是不同的：
// java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Integer> cnt = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            cnt.put(c, cnt.getOrDefault(c, 0) + 1);
        }
        for (int i = 0; i < t.length(); ++i) {
            char c = t.charAt(i);
            cnt.put(c, cnt.getOrDefault(c, 0) - 1);
            if (cnt.get(c) < 0) return false; 
            // cnt为s中字符的频次,现在为负,说明不为异位词
        }
        return true;
    }
}
// python: 使用defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        from collections import defaultdict
        cnt = defaultdict(int)
        for c in s:
            cnt[c] += 1
        for c in t:
            cnt[c] -= 1
            if cnt[c] < 0:
                return False
        return True
// go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    cnt := map[rune]int{} // rune
    for _, c := range s { // 一次遍历
        cnt[c]++
    }
    for _, c := range t {
        cnt[c]--
        if cnt[c] < 0 {
            return false
        }
    }
    return true
}