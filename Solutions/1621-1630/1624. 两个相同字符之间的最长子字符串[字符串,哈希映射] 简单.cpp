/*
** Problem: https://leetcode.cn/problems/largest-substring-between-two-equal-characters/
** Article: https://memcpy0.blog.csdn.net/article/details/135321486
** Author: memcpy0
*/
给你一个字符串 `s`，请你返回 **两个相同字符之间的最长子字符串的长度** ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 `-1` 。

**子字符串** 是字符串中的一个连续字符序列。

**示例 1：**
```cpp
输入：s = "aa"
输出：0
解释：最优的子字符串是两个 'a' 之间的空子字符串。
```
**示例 2：**
```cpp
输入：s = "abca"
输出：2
解释：最优的子字符串是 "bc" 。
```
**示例 3：**
```cpp
输入：s = "cbzxy"
输出：-1
解释：s 中不存在出现出现两次的字符，所以返回 -1 。
```
**示例 4：**
```cpp
输入：s = "cabbac"
输出：4
解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
```
**提示：**
- `1 <= s.length <= 300`
- `s` 只含小写英文字母

返回最大的长度 $maxLength$ 即可。
```cpp
// cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLength = -1;
        vector<int> firstIndex(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (firstIndex[s[i] - 'a'] < 0) {
                firstIndex[s[i] - 'a'] = i;
            } else {
                maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
            }
        }
        return maxLength;
    }
};

// java
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int maxLength = -1;
        int[] firstIndex = new int[26];
        Arrays.fill(firstIndex, -1);
        for (int i = 0; i < s.length(); ++i) {
            if (firstIndex[s.charAt(i) - 'a'] < 0) {
                firstIndex[s.charAt(i) - 'a'] = i;
            } else {
                maxLength = Math.max(maxLength, i - firstIndex[s.charAt(i) - 'a'] - 1);
            }
        }
        return maxLength;
    }
}

// python
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        ans = -1
        firstIndex = {}
        for i, c in enumerate(s):
            if c not in firstIndex:
                firstIndex[c] = i
            else:
                ans = max(ans, i - firstIndex[c] - 1)
        return ans

// go
func maxLengthBetweenEqualCharacters(s string) int {
    ans := -1
    firstIndex := [26]int {}
    for i := range firstIndex {
        firstIndex[i] = -1
    }
    for i, c := range s {
        c -= 'a'
        if firstIndex[c] < 0 {
            firstIndex[c] = i
        } else {
            ans = max(ans, i - firstIndex[c] - 1)
        }
    }
    return ans
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
}