/*
** Problem: https://leetcode.cn/problems/time-needed-to-inform-all-employees/
** Article: https://memcpy0.blog.csdn.net/article/details/130463567
** Author: memcpy0
*/
class Solution {
	public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
		List<Integer> g[] = new ArrayList[n];
		Arrays.setAll(g, e -> new ArrayList<>());
		for (int i = 0; i < n; ++i)
			if (manager[i] >= 0) g[manager[i]].add(i); // 建树
		return dfs(g, informTime, headID); // 从根结点headID递归，有返回值
	}
	private int dfs(List<Integer>[] g, int[] informTime, int x) {
		int maxPathSum = 0;
		for (int y : g[x]) // 遍历x的儿子y(如果没有就不会进入循环)
			maxPathSum = Math.max(maxPathSum, dfs(g, informTime, y));
		return maxPathSum + informTime[x];  // 和104题代码中return max(lDepth, rDepth) + 1;是一个意思
	}
}

class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
	    List<Integer> g[] = new ArrayList[n];
	    Arrays.setAll(g, e -> new ArrayList<>());
        for (int i = 0; i < n; ++i)
            if (manager[i] >= 0)
                g[manager[i]].add(i); // 建树
        dfs(g, informTime, headID, 0); // 从根结点headID递归
        return ans;
    }
    private int ans;
    private void dfs(List<Integer>[] g, int[] informTime, int x, int pathSum) {
	    pathSum += informTime[x]; // 累加递归路径上的informTime[x]
	    ans = Math.max(ans, pathSum); // 更新答案的最大值
	    for (int y : g[x]) // 遍历x的儿子y（如果没有儿子就不会进入循环）
		    dfs(g, informTime, y, pathSum); // 继续递归
    }
}