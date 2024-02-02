/*
** Problem: https://leetcode.cn/problems/stone-game-vi
** Article: https://memcpy0.blog.csdn.net/article/details/136003230
** Author: memcpy0
*/
### 解法 排序+贪心
设 Alice 选的数字之和为 $A$，Bob 选的数字之和为 $B$ 。
- 如果 $A−B>0$ 那么 Alice 赢；
- 如果 $A−B<0$ 那么 Bob 赢；
- 如果 $A-B=0$ 则平局。
- 所以 Alice 需要最大化 $A−B$ ，Bob 需要最小化 $A-B$ 。

下文把数组 $\textit{aliceValues}$ 记作 $A$，把数组 $\textit{bobValues}$ 记作 $B$。

以 $a=[2,4,3,5], b=[1,6,7,1]$ 为例说明。

假设 Bob 把所有石子都拿走，则 $A=0,\ B=15,\ A−B=−15$ 。

先来想一想，如果 Alice 只能拿走一颗石子，应该拿走哪颗呢？
1. 拿走第一颗，那么 $A=2,\ B=14,\ A-B=-12$ 。
2. 拿走第二颗，那么 $A=4,\ B=9,\ A-B=-5$ 。
3. 拿走第三颗，那么 $A=3,\ B=8,\ A-B=-5$ 。
4. 拿走第四颗，那么 $A=5,\ B=14,\ A-B=-9$ 。

对比 Bob 把所有石子都拿走的情况，如果 Alice 拿走第二颗或者第三颗，都可以让 $-15$ 增大为 $-5$ ，增量为 $10$ 。由于 $A$ 增加了 $a[i]$ ，$B$ 减少了 $b[i]$ ，所以 $A−B$ 的增量等于
$$a[i] - (-b[i]) = a[i] + b[i]$$
所以 Alice 拿走 $a[i]+b[i]$ 最大的石子最优。

回到原题，Alice 可以拿走两颗石子，应该拿走哪两颗呢？

**我们从 Bob 把所有石子都拿走的情况出发，也就是在 $A=0,\ B=15$ 的基础上思考**，Alice 拿走哪两颗石子，可以让 $A-B$ 增加的尽量多？

定义 $c[i]=a[i]+b[i]$ ，那么 $c=[3,10,10,6]$ 。现在问题变成：==给定数组 $c$ ，Alice 每回合拿走一个数，Bob 每回合删除一个数，Alice 拿走的数之和最大是多少==？注意 Bob 要让 Alice 拿走的数之和尽量小。

==**如此转换后，贪心策略就很显然了**==：Alice 从大到小拿走数字，Bob 也从大到小删除数字。

所以把 $c$ 从大到小排序为 $[10,10,6,3]$ ，两人从左往右交替取数，那么 Alice 只能拿走下标为偶数的数字，其余数字被 Bob 删除。所以 $A-B$ 最大可以增加 $c[0]+c[2]=10+6=16$ ，**增加后** $A-B=1>0$ ，Alice 险胜！

**算法**
把数组按照 $a[i]+b[i]$ 从大到小排序。可以创建一个 $(a[i],b[i])$ 的 `pair` 数组对其排序，也可以创建一个下标数组排序。

用 $\textit{diff}$ 表示 $A-B$ ，初始化 $\textit{diff}=0$ 。遍历数组，把偶数下标的 $a[i]$ 加到 $A$ 中，相当于 $diff$ 增加了 $a[i]$ ；把奇数下标的 $b[i]$ 加到 $B$ 中，相当于 $\textit{diff}$ 减少了 $b[i]$ 。

循环结束后，如果 $diff>0$ ，返回 $1$ ；如果 $diff<0$ ，返回 $−1$ ；如果 $diff=0$ ，返回 $0$ 。
> 问：从这个思路的本质是什么？为什么这样转换一下，问题就变得简单了许多？
> 答：转换前，我们需要同时考虑 $a[i]$ 和 $b[i]$ **这两个变量**，不好处理。转换成 Bob 先把所有数字选了，我们就只需要思考 Alice 如何选数字，只有 $c[i]$ **这一个变量**，更容易处理。从某种程度上来说，这也可以算作一种「**正难则反**」。

> 问：有没有其它的思考方式？
答：也可以这样思考：对比两颗石子 $(a[i],b[i])$ 和 $(a[j],b[j])$ 。如果 Alice 选 $i$ ，Bob 选 $j$ ，那么 $A−B=a[i]−b[j]$ ；如果 Alice 选 $j$ ，Bob 选 $i$ ，那么 $A−B=a[j]−b[i]$ 。如果 Alice 选 $i$ 更优，则有 $a[i]−b[j]>a[j]−b[i]$ ，即 $a[i]+b[i]>a[j]+b[j]$ ，说明 Alice 应当优先选 $a[i]+b[i]$ 更大的石子。

# python
class Solution:
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        pairs = sorted(zip(a, b), key = lambda p: -(p[0] + p[1])) # a[i]+b[i]越大排在前
        diff = sum(x if i % 2 == 0 else -y for i, (x, y) in enumerate(pairs)) # 表示A-B
        return (diff > 0) - (diff < 0)

# 写法2,和1没有本质区别
class Solution:
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        s = sorted((x + y for x, y in zip(a, b)), reverse = True)
        diff = sum(s[::2]) - sum(b)
        return (diff > 0) - (diff < 0)

# go
func stoneGameVI(a []int, b []int) int {
    type pair struct { x, y int }
    pairs := make([]pair, len(a)) // pair数组
    for i, x := range a {
        pairs[i] = pair{x, b[i]}
    }
    slices.SortFunc(pairs, func(p, q pair) int {
        return q.x + q.y - (p.x + p.y)
    })
    diff := 0
    for i, p := range pairs {
        if i % 2 == 0 {
            diff += p.x
        } else {
            diff -= p.y
        }
    }
    return cmp.Compare(diff, 0)
}