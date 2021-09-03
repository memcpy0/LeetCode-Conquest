/*
** Problem: https://leetcode-cn.com/problems/random-pick-index/
** Article: https://memcpy0.blog.csdn.net/article/details/120022542
** Author: memcpy0
*/
class Solution {
    private HashMap<Integer, ArrayList<Integer>> rec;
    public Solution(int[] nums) {
        rec = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (!rec.containsKey(nums[i])) rec.put(nums[i], new ArrayList<>());
            rec.get(nums[i]).add(i);
        }
    }
    
    public int pick(int target) {
        int n = rec.get(target).size();
        int k = new Random().nextInt(n);
        return rec.get(target).get(k);
    }
}