/*
** Problem: https://leetcode.cn/problems/special-positions-in-a-binary-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/108651120
** Author: memcpy0
*/
给你一个大小为 `rows x cols` 的矩阵 `mat` ，其中 `mat[i][j]` 是 `0` 或 `1` ，请返回 **矩阵 `mat` 中特殊位置的数目** 。

**特殊位置** 定义：如果 `mat[i][j] == 1` 并且第 `i` 行和第 `j` 列中的所有其他元素均为 `0`（行和列的下标均 **从 `0` 开始** ），则位置 `(i, j)` 被称为特殊位置。

**示例 1：**
```cpp
输入：mat = [[1,0,0],
            [0,0,1],
            [1,0,0]]
输出：1
解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
```
**示例 2：**
```cpp
输入：mat = [[1,0,0],
            [0,1,0],
            [0,0,1]]
输出：3
解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
```
**示例 3：**
```cpp
输入：mat = [[0,0,0,1],
            [1,0,0,0],
            [0,1,1,0],
            [0,0,0,0]]
输出：2
```
**示例 4：**
```cpp
输入：mat = [[0,0,0,0,0],
            [1,0,0,0,0],
            [0,1,0,0,0],
            [0,0,1,0,0],
            [0,0,0,1,1]]
输出：3
```
**提示：**
-  `rows == mat.length`
- `cols == mat[i].length`
- `1 <= rows, cols <= 100`
-  `mat[i][j]` 是 `0` 或 `1`

// cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowsSum(m), colsSum(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1)
                    ++ans;
        return ans;
    }
};

// java
class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] rowsSum = new int[m];
        int[] colsSum = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1)
                    ++ans;
        return ans;
    }
}

// python
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows_sum = [sum(row) for row in mat]
        cols_sum = [sum(col) for col in zip(*mat)]
        ans = 0
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                if x == 1 and rows_sum[i] == 1 and cols_sum[j] == 1:
                    ans += 1
        return ans
    
// go
func numSpecial(mat [][]int) (ans int) {
    rowsSum := make([]int, len(mat))
    colsSum := make([]int, len(mat[0]))
    for i, row := range mat {
        for j, x := range row {
            rowsSum[i] += x
            colsSum[j] += x
        }
    }
    for i, row := range mat {
        for j, x := range row {
            if x == 1 && rowsSum[i] == 1 && colsSum[j] == 1 {
                ans++
            }
        }
    }
    return
}

---
// BEST
### 解法2 列的标记值
在方法一的基础上，我们可以看到对于 $(i,j)$ ，它为特殊位置的条件为 $\textit{mat}[i][j]=1$ 且该行和该列中 $1$ 的数量都为 $1$ 。据此，定义**第 $j$ 列的标记值为：该列所有 $1$ 所在行中的 $1$ 的数量之和**。下面证明，$(i,j)$ 为特殊位置的充要条件是，第 $j$ 列的标记值恰好为 $1$ ：
- 如果 $(i,j)$ 为特殊位置，则说明第 $j$ 列只有一个 $1$ ，这一个 $1$ 所在的第 $i$ 行也只有它这一个 $1$ ，那么按照标记值的定义可得，第 $j$ 列的标记值为 $1$ 。
- 如果第 $j$ 列的标记值为 $1$ ，那么说明该列只能有一个 $1$ 。反证：如果有 $x$ 个 $1$（$x > 1$），则第 $j$ 列的标记值一定 $\ge x$ 。**既然只能有一个 $1$ ，设其在第 $i$ 行，那么标记值也是第 $i$ 行中的 $1$ 的数量**，即：第 $i$ 行也有且仅有这个 $1$ 。所以 $(i,j)$ 为特殊位置。
- 那么==整个矩阵的特殊位置的数量，就是最后标记值为 $1$ 的列的数量==。

进一步地，我们可以**用原始矩阵的第一行来作为我们标记列的额外空间**，从而使空间复杂度降至 $O(1)$ 。

// cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int cnt1 = 0;
            for (int j = 0; j < n; ++j) 
                if (mat[i][j] == 1) ++cnt1;
            if (i == 0) --cnt1;
            if (cnt1 > 0) {
                for (int j = 0; j < n; ++j) 
                    if (mat[i][j] == 1) 
                        mat[0][j] += cnt1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (mat[0][i] == 1) ++sum;
        return sum;
    }
};

// java
class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        for (int i = 0; i < m; ++i) {
            int cnt1 = 0;
            for (int j = 0; j < n; ++j) 
                if (mat[i][j] == 1) ++cnt1;
            if (i == 0) --cnt1;
            if (cnt1 > 0) {
                for (int j = 0; j < n; ++j) 
                    if (mat[i][j] == 1) 
                        mat[0][j] += cnt1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (mat[0][i] == 1) ++sum;
        return sum;
    }
}

// python
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        for i, row in enumerate(mat):
            cnt1 = sum(row) - (i == 0)
            if cnt1:
                for j, x in enumerate(row):
                    if x == 1:
                        mat[0][j] += cnt1
        return sum(x == 1 for x in mat[0])

// go
func numSpecial(mat [][]int) (ans int) {
    for i, row := range mat {
        cnt1 := 0
        for _, x := range row {
            cnt1 += x
        }
        if i == 0 {
            cnt1--
        }
        if cnt1 > 0 {
            for j, x := range row {
                if x == 1 {
                    mat[0][j] += cnt1
                }
            }
        }
    }
    for _, x := range mat[0] {
        if x == 1 {
            ans++
        }
    }
    return
}