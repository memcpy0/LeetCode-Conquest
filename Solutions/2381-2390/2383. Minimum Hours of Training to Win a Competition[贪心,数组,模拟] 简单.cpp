/*
** Problem: https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/
** Article: https://memcpy0.blog.csdn.net/article/details/129483870
** Author: memcpy0
*/
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size(), sum = 0;
        for (int en : energy) sum += en;
        int ans = initialEnergy > sum ? 0 : (sum - initialEnergy + 1);
        for (int ex : experience) {
            if (initialExperience <= ex) {
                ans += (ex - initialExperience + 1);
                initialExperience = ex + 1;
            }
            initialExperience += ex;
        }
        return ans;
    }
};