/*
** Problem: https://leetcode-cn.com/problems/shortest-completing-word/
** Article: https://memcpy0.blog.csdn.net/article/details/108890484
** Author: memcpy0
*/
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] cnt = getCnt(licensePlate);
        int idx = -1;
        for (int i = 0, n = words.length; i < n; ++i) {
            int[] scnt = getCnt(words[i]);
            boolean flag = true;
            for (int j = 0; j < 26 && flag; ++j)
                if (cnt[j] > scnt[j]) flag = false;
            if (flag && (idx == -1 || words[idx].length() > words[i].length())) idx = i;
        }
        return words[idx];
    }
    int[] getCnt(String s) {
        int[] cnt = new int[26];
        for (int i = 0, n = s.length(); i < n; ++i) 
            if (Character.isLetter(s.charAt(i))) 
                ++cnt[Character.toLowerCase(s.charAt(i)) - 'a'];
        return cnt;
    }
}