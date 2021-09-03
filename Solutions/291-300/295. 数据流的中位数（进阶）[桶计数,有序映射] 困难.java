/*
** Problem: https://leetcode-cn.com/problems/find-median-from-data-stream/
** Article: https://memcpy0.blog.csdn.net/article/details/120076311
** Author: memcpy0
*/
class MedianFinder {
    int[] arr = new int[101];
    int a, b, c; //a,c为哨兵桶中元素的数量,b为[0,100]范围中元素的数量
    TreeMap<Integer, Integer> h = new TreeMap<>(), t = new TreeMap<>();
    public void addNum(int num) {
        if (num >= 0 && num <= 100) { //进阶第1问和第2问的99%数据
            ++arr[num];
            ++b; //计数
        } else if (num < 0) { //加入到最左侧的哨兵桶中
            h.put(num, h.getOrDefault(num, 0) + 1);
            ++a; //计数
        } else if (num > 100) { //加入到最右侧的哨兵桶中
            t.put(num, t.getOrDefault(num, 0) + 1);
            ++c; //计数
        }
    }
    public double findMedian() {
        int size = a + b + c; //数据流的总长度
        if (size % 2 == 0) return (find(size / 2) + find(size / 2 + 1)) / 2.0;
        return find(size / 2 + 1) * 1.0;
    }
    private int find(int n) { //找到第n个位置的元素
        if (n <= a) {
            for (int num : h.keySet()) {
                n -= h.get(num);
                if (n <= 0) return num;
            }
        } else if (n <= a + b) { 
            n -= a;
            for (int i = 0; i <= 100; ++i) { //进阶第一问的查找方法
                n -= arr[i];
                if (n <= 0) return i;
            }
        } else {
            n -= a + b;
            for (int num : t.keySet()) {
                n -= t.get(num);
                if (n <= 0) return num;
            }
        }
        return -1; //never visited
    }
}