/*
** Problem: https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/
** Article: https://memcpy0.blog.csdn.net/article/details/135353137
** Author: memcpy0
*/
给你一个整数数组 `nums` 。请你创建一个满足以下条件的二维数组：
- 二维数组应该 **只** 包含数组 `nums` 中的元素。
- 二维数组中的每一行都包含 **不同** 的整数。
- 二维数组的行数应尽可能 **少** 。

返回结果数组。如果存在多种答案，则返回其中任何一种。

请注意，二维数组的每一行上可以存在不同数量的元素。

**示例 1：**
```java
输入：nums = [1,3,4,1,2,3,1]
输出：[[1,3,4,2],[1,3],[1]]
解释：根据题目要求可以创建包含以下几行元素的二维数组：
- 1,3,4,2
- 1,3
- 1
nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
可以证明无法创建少于三行且符合题目要求的二维数组。
```
**示例 2：**
```java
输入：nums = [1,2,3,4]
输出：[[4,3,2,1]]
解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
```
**提示：**
- `1 <= nums.length <= 200`
- `1 <= nums[i] <= nums.length`


# python
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        ans = []
        cnt = Counter(nums)
        while cnt:
            ans.append(list(cnt)) # 每次将返回字典的key列表放入ans中
            for x in ans[-1]:
                cnt[x] -= 1
                if cnt[x] == 0:
                    del cnt[x] # 从字典中删除键值对
        return ans

# go
func findMatrix(nums []int) (ans [][]int) {
    cnt := map[int]int {}
    for _, x := range nums {
        cnt[x]++
    }
    for len(cnt) > 0 {
        row := []int {}
        for x := range cnt {
            row = append(row, x)
            if cnt[x]--; cnt[x] == 0 {
                delete(cnt, x)
            }
        }
        ans = append(ans, row)
    }
    return
}

实际上，==我们可以在构造哈希表的循环中，就完成答案二维数组的构造==。类似「二叉树的右视图」那一题，我们遍历数组，记录每个元素的出现次数，**当发现元素 $x$ 第 $idx$ 次出现时，如果二维数组的行数 $\le idx$ ，则不需要新行，将 $x$ 放入第 $idx$ 行；否则添加新一行，再将元素 $x$ 放入**。

// cpp
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int cnt[201] = {0};
        for (int x : nums) {
            ++cnt[x];
            if (ans.size() < cnt[x]) ans.emplace_back();
            ans[cnt[x] - 1].push_back(x);
        }   
        return ans;
    }
};

// java
class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        var ans = new ArrayList<List<Integer>>();
        int[] cnt = new int[220];
        for (int x : nums) {
            ++cnt[x];
            if (ans.size() < cnt[x]) ans.add(new ArrayList<Integer>());
            ans.get(cnt[x] - 1).add(x);
        }
        return ans;
    }
}