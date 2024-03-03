/*
** Problem: https://leetcode.cn/problems/maximum-odd-binary-number/
** Article: https://memcpy0.blog.csdn.net/article/details/136408756
** Author: memcpy0
*/
```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = count(s.begin(), s.end(), '1');
        return string(cnt1 - 1, '1') + string(s.length() - cnt1, '0') + '1';
    }
};
```

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt1 = s.count('1')
        return '1' * (cnt1 - 1) + '0' * (len(s) - cnt1) + '1'
```

```go
func maximumOddBinaryNumber(s string) string {
    cnt1 := strings.Count(s, "1")
    return strings.Repeat("1", cnt1 - 1) + strings.Repeat("0", len(s) - cnt1) + "1"
}
```

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var maximumOddBinaryNumber = function(s) {
    let cnt1 = _.sumBy(s, c => c === '1')
    return '1'.repeat(cnt1 - 1) + '0'.repeat(s.length - cnt1) + '1';
};
```

```java
class Solution {
    public String maximumOddBinaryNumber(String s) {
        int cnt1 = (int) s.chars().filter(c -> c == '1').count();
        return "1".repeat(cnt1 - 1) + "0".repeat(s.length() - cnt1) + "1";
    }
}
```

```rust
impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let cnt1 = s.chars().filter( |&c| c == '1').count();
        "1".repeat(cnt1 - 1) + &*"0".repeat(s.len() - cnt1) + "1"
    }
}
```