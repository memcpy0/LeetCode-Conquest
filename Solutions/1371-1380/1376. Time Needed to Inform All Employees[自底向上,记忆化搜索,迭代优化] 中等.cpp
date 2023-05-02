/*
** Problem: https://leetcode.cn/problems/time-needed-to-inform-all-employees/
** Article: https://memcpy0.blog.csdn.net/article/details/130463567
** Author: memcpy0
*/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
	        if (manager[i] < 0) continue;
	        // 计算从i向上的累加值
	        int s = 0, x = i;
	        for (; manager[x] >= 0; x = manager[x])
		        s += informTime[x];
		    // 此时x要么是headID,要么是一个计算过的结点
		    s += informTime[x];
		    ans = max(ans, s);
		    // 记录从i向上的每个未被计算的节点值的对应累加值
		    for (int x = i; manager[x] >= 0; ) {
			    int t = informTime[x];
			    informTime[x] = s;
			    s -= t;
			    int m = manager[x];
			    manager[x] = -1; // 标记已被访问
			    x = m; // 继续向上
		    }
        } 
        return ans;
    }
};

/*
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
	    int ans = 0;
	    function<int(int)> dfs = [&](int x) -> int {
		    if (manager[x] >= 0) {
			    informTime[x] += dfs(manager[x]);
			    manager[x] = -1; // 标记x计算过
		    }
		    return informTime[x];
	    };
	    for (int i = 0; i < n; ++i) ans = max(ans, dfs(i)); 
        return ans;
    }
};
*/

/*
class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
	    var memo = new int[n];
	    Arrays.fill(memo, -1); // -1表示还没有计算过
	    int ans = 0;
	    for (int i = 0; i < n; ++i)
		    ans = Math.max(ans, dfs(manager, informTime, memo, i));
		return ans;
    }
    private int dfs(int[] manager, int[] informTime, int[] memo, int x) {
		if (manager[x] < 0) return informTime[x]; // 是根
		if (memo[x] >= 0) return memo[x]; // 之前计算过了
		return memo[x] = dfs(manager, informTime, memo, manager[x]) + informTime[x]; 
    }
}
*/