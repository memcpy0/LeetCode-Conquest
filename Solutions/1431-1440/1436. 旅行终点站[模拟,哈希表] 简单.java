/*
** Problem: https://leetcode-cn.com/problems/destination-city/
** Article: https://memcpy0.blog.csdn.net/article/details/109640507
** Author: memcpy0
*/
class Solution {
    public String destCity(List<List<String>> paths) {
        Map<String, String> rec = new HashMap<>();
        for (List<String> path : paths) rec.put(path.get(0), path.get(1));
        String ans = paths.get(0).get(0);
        while (rec.containsKey(ans)) ans = rec.get(ans);
        return ans;
    }
}