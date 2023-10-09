/*
** Problem: https://leetcode.cn/problems/stock-price-fluctuation/
** Article: https://memcpy0.blog.csdn.net/article/details/133697299
** Author: memcpy0
*/
class StockPrice {
    int maxTimestamp;
    HashMap<Integer, Integer> timePriceMap;
    TreeMap<Integer, Integer> prices;
    public StockPrice() {
        maxTimestamp = 0;
        timePriceMap = new HashMap<>();
        prices = new TreeMap<>();
    }
    
    public void update(int timestamp, int price) {
        maxTimestamp = Math.max(timestamp, maxTimestamp);
        if (timePriceMap.containsKey(timestamp)) { // 时间戳已存在
            int oldPrice = timePriceMap.get(timestamp); // 获取旧价格
            prices.put(oldPrice, prices.get(oldPrice) - 1); // 旧价格对应的时间戳数量-1
            if (prices.get(oldPrice) == 0) {
                prices.remove(oldPrice);
            }
        }
        timePriceMap.put(timestamp, price); // timestamp设置新价格
        prices.put(price, prices.getOrDefault(price, 0) + 1); // 新价格对应的时间戳数量+1
    }
    
    public int current() {
        return timePriceMap.get(maxTimestamp); // 获取股票最新价格
    }
    
    public int maximum() {
        return prices.lastKey();
    }
    
    public int minimum() {
        return prices.firstKey();
    }
}