/*
** Problem: https://leetcode-cn.com/problems/reordered-power-of-2/
** Article: https://memcpy0.blog.csdn.net/article/details/121026490
** Author: memcpy0
*/
class Solution {
    public boolean reorderedPowerOf2(int n) {
        String[] rec = {"1", "2", "4", "8", "16", "23", "46", "128", "256", "125", "0124", "0248", "0469", "1289", "13468", "23678", "35566", "011237", "122446", "224588", "0145678", "0122579", "0134449", "0368888", "11266777", "23334455", "01466788", "112234778", "234455668", "012356789"};
        char[] tn = String.valueOf(n).toCharArray();
        Arrays.sort(tn);
        String str = new String(tn);
        for (String p : rec)
            if (str.equals(p)) return true;
        return false;
    }
}