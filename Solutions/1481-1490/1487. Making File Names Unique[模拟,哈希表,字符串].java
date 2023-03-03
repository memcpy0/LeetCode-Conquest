/*
** Problem: https://leetcode.cn/problems/making-file-names-unique/discussion/
** Article: https://memcpy0.blog.csdn.net/article/details/129321417
** Author: memcpy0
*/
class Solution {
    public String[] getFolderNames(String[] names) {
        String[] ans = new String[names.length];
        var rec = new HashMap<String, Integer>();
        for (int i = 0; i < names.length; ++i) {
            String s = names[i];
            while (rec.containsKey(s) ) {
                int suffix = rec.get(names[i]);
                s = names[i] + "(" + suffix + ")";
                rec.put(names[i], suffix + 1);
            }
            rec.put(s, 1);
            ans[i] = s;
        }
        return ans;
    }
}