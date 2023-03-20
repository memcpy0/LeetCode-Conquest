/*
** Problem: https://leetcode.cn/problems/convert-the-temperature
** Article: https://memcpy0.blog.csdn.net/article/details/129680088
** Author: memcpy0
*/
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32.0};
    }
};