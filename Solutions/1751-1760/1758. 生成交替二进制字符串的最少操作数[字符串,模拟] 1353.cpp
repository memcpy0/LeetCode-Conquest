/*
** Problem: https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/
** Article: https://memcpy0.blog.csdn.net/article/details/135330968
** Author: memcpy0
*/
给你一个仅由字符 `'0'` 和 `'1'` 组成的字符串 `s` 。一步操作中，你可以将任一 `'0'` 变成 `'1'` ，或者将 `'1'` 变成 `'0'` 。

**交替字符串** 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 `"010"` 是交替字符串，而字符串 `"0100"` 不是。

返回使 `s` 变成 **交替字符串** 所需的 **最少** 操作数。

**示例 1：**
```java
输入：s = "0100"
输出：1
解释：如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
```
**示例 2：**
```java
输入：s = "10"
输出：0
解释：s 已经是交替字符串。
```
**示例 3：**
```java
输入：s = "1111"
输出：2
解释：需要 2 步操作得到 "0101" 或 "1010" 。
```
**提示：**
- `1 <= s.length <= 10^4`
- `s[i]` 是 `'0'` 或 `'1'`


// cpp
class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c != ('0' + i % 2)) ++cnt;
        }
        return min(cnt, (int)s.size() - cnt);
    }
};

// java
class Solution {
    public int minOperations(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c != (char)('0' + i % 2)) ++cnt;
        }
        return Math.min(cnt, s.length() - cnt);
    }
}

// python
class Solution:
    def minOperations(self, s: str) -> int:
        cnt = sum(int(c) != i % 2 for i, c in enumerate(s)) # 010101...
        return min(cnt, len(s) - cnt)

// go
func minOperations(s string) int {
    cnt := 0
    for i, c := range s {
        if i % 2 != int(c - '0') {
            cnt++
        }
    }
    return min(cnt, len(s) - cnt)
}
func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}