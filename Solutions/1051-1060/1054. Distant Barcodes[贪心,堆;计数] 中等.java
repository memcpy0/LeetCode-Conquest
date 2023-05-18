/*
** Problem: https://leetcode.cn/problems/distant-barcodes/
** Article: https://memcpy0.blog.csdn.net/article/details/130758345
** Author: memcpy0
*/
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int length = barcodes.length;
        if (length < 2) return barcodes;
        var counts = new HashMap<Integer, Integer>();
        for (int barcode : barcodes) counts.put(barcode, counts.getOrDefault(barcode, 0) + 1);
        int[] ans = new int[length];
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            int x = entry.getKey(), c = entry.getValue();
            while (c > 0 && c <= halfLength && oddIndex < length) {
                ans[oddIndex] = x;
                --c;
                oddIndex += 2;
            }
            while (c > 0) {
                ans[evenIndex] = x;
                --c;
                evenIndex += 2;
            }
        } 
        return ans;
    }
}
/*
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        if (barcodes.length < 2) return barcodes;
        var counts = new HashMap<Integer, Integer>();
        for (int barcode : barcodes) counts.put(barcode, counts.getOrDefault(barcode, 0) + 1);
        var q = new PriorityQueue<Integer>(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                int c1 = counts.get(a), c2 = counts.get(b);
                // if (c1 == c2) return a - b; // 出现次数相同时，按值排序 // 这里可以不写
                return c2 - c1; // 大顶堆
            }
        });
        // for (int barcode : barcodes) q.offer(barcode); // 这样写q里面会有重复的值
        for (int barcode : counts.keySet()) q.offer(barcode);
        int[] ans = new int[barcodes.length];
        int idx = 0;
        while (q.size() > 1) {
            int b1 = q.poll();
            int b2 = q.poll();
            ans[idx++] = b1;
            ans[idx++] = b2;
            int c1 = counts.get(b1), c2 = counts.get(b2);
            counts.put(b1, c1 - 1);
            counts.put(b2, c2  -1);
            if (c1 > 1) q.offer(b1);
            if (c2 > 1) q.offer(b2);
        }
        if (q.size() > 0) ans[idx++] = q.poll();
        return ans;
    }
}

class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        if (barcodes.length < 2) return barcodes;
        var counts = new HashMap<Integer, Integer>();
        for (int barcode : barcodes) counts.put(barcode, counts.getOrDefault(barcode, 0) + 1);
        var q = new PriorityQueue<int[]>((a, b) -> b[0] - a[0]);
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) 
            q.offer(new int[]{entry.getValue(), entry.getKey()}); // 次数,条形码
        int[] ans = new int[barcodes.length];
        int idx = 0;
        while (q.size() > 1) {
            int[] b1 = q.poll();
            int[] b2 = q.poll();
            ans[idx++] = b1[1];
            ans[idx++] = b2[1]; 
            --b1[0];
            --b2[0];
            if (b1[0] > 0) q.offer(b1);
            if (b2[0] > 0) q.offer(b2);
        }
        if (q.size() > 0) ans[idx++] = q.poll()[1];
        return ans;
    }
}
*/