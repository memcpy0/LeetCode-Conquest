/*
** Problem: https://leetcode.cn/problems/minimum-number-of-frogs-croaking/
** Article: https://memcpy0.blog.csdn.net/article/details/130627018
** Author: memcpy0
*/
int minNumberOfFrogs(char* croakOfFrogs){
    int status[5] = {0}, ans = 0;
    for (char *q = croakOfFrogs; *q; ++q) {
        int c = *q == 'c' ? 0 : (*q == 'r' ? 1 : (*q == 'o' ? 2 : (*q == 'a' ? 3 : 4)));
        c = (c + 4) % 5;
        if (status[c]) --status[c];
        else if (c == 4) ++ans;
        else return -1;
        ++status[(c + 1) % 5];
    }
    return status[4] == ans ? ans : -1; // 最终所有青蛙必须回到k状态
}
/*
int minNumberOfFrogs(char* croakOfFrogs){
    int status[5] = {0}, ans = 0;
    for (char *q = croakOfFrogs; *q; ++q) {
        int c = *q == 'c' ? 0 : (*q == 'r' ? 1 : (*q == 'o' ? 2 : (*q == 'a' ? 3 : 4)));
        if (c == 0) { // 说明可能需要一只新青蛙从头开始蛙鸣
            if (status[4]) // 已经有青蛙蛙鸣结束
                --status[4], ++status[0]; // 让这只青蛙开始新的蛙鸣
            else ++ans, ++status[0]; // 不够用了,增加一只新青蛙开始新的蛙鸣
        } else { // 如果不是开头,则不能增加青蛙,不够用就直接失败
            if (status[c - 1])
                --status[c - 1], ++status[c]; 
            else return -1;
        }
    }
    return status[4] == ans ? ans : -1; // 最终所有青蛙必须回到k状态
}
*/