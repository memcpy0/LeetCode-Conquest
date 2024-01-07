/*
** Problem: https://leetcode.cn/problems/design-a-food-rating-system/
** Article: https://memcpy0.blog.csdn.net/article/details/135444446
** Author: memcpy0
*/
### 解法1 平衡树
我们可以用一个**哈希表** $fs$ 记录每个食物名称、对应的食物评分和烹饪方式，另一个**哈希表套平衡树** $cs$ 记录每个烹饪方式、对应的食物评分和食物名称集合。

对于 `changeRating` 操作，先从 `cs[fs[food].cuisine]` 中删除旧数据，然后将 `newRating` 和 `food` 记录到 $cs$ 和 $fs$ 中：
// cpp
class FoodRatings {
private:
    unordered_map<string, pair<int, string>> fs;
    unordered_map<string, set<pair<int, string>>> cs;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0, n = foods.size(); i < n; ++i) {
            auto &f = foods[i], &c = cuisines[i];
            int r = ratings[i];
            fs[f] = {r, c};
            cs[c].emplace(-r, f);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[r, c] = fs[food];
        auto &s = cs[c];
        s.erase({-r, food}); // 移除旧数据
        s.emplace(-newRating, food); // 添加新数据
        r = newRating;
    }
    
    string highestRated(string cuisine) {
        return cs[cuisine].begin()->second;
    }
};
// java
class FoodRatings {
    Map<String, Pair<Integer, String>> fs = new HashMap<>();
    Map<String, TreeSet<Pair<Integer, String>>> cs = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (var i = 0; i < foods.length; ++i) {
            String f = foods[i], c = cuisines[i];
            var r = ratings[i];
            fs.put(f, new Pair<>(r, c));
            cs.computeIfAbsent(c, k -> new TreeSet<>((a, b) -> 
                !Objects.equals(a.getKey(), b.getKey()) ? 
                    b.getKey() - a.getKey() : // 逆序 
                    a.getValue().compareTo(b.getValue())
                )).add(new Pair<>(r, f));
        }
    }
    
    public void changeRating(String food, int newRating) {
        var e = fs.get(food);
        var s = cs.get(e.getValue());
        s.remove(new Pair<>(e.getKey(), food)); // 移除旧数据
        s.add(new Pair<>(newRating, food)); // 添加新数据
        fs.put(food, new Pair<>(newRating, e.getValue()));
    }
    
    public String highestRated(String cuisine) {
        return cs.get(cuisine).first().getValue();
    }
}
// python
from sortedcontainers import SortedSet
class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.fs = {}
        self.cs = defaultdict(SortedSet)
        for f, c, r in zip(foods, cuisines, ratings):
            self.fs[f] = [r, c]
            self.cs[c].add((-r, f))

    def changeRating(self, food: str, newRating: int) -> None:
        r, c = self.fs[food]
        s = self.cs[c]
        s.remove((-r, food)) # 移除旧数据
        s.add((-newRating, food)) # 添加新数据
        self.fs[food][0] = newRating

    def highestRated(self, cuisine: str) -> str:
        return self.cs[cuisine][0][1]

---
### 解法2 懒删除堆
另一种做法是用堆：
- 对于 `changeRating` 操作，直接往 $cs$ 中记录，不做任何删除操作；
- 对于 $highestRated$ 操作，==查看堆顶的食物评分是否等于其实际值，若不相同则意味着对应的元素已被替换成了其他值==，堆顶存的是个垃圾数据，直接弹出堆顶；否则堆顶就是答案。

// cpp
class FoodRatings {
private:
    unordered_map<string, pair<int, string>> fs;
    unordered_map<string, 
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>>> cs;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0, n = foods.size(); i < n; ++i) {
            auto &f = foods[i], &c = cuisines[i];
            int r = ratings[i];
            fs[f] = {r, c};
            cs[c].emplace(-r, f);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[r, c] = fs[food];
        cs[c].emplace(-newRating, food); // 直接添加新数据，后面 highestRated 再删除旧的
        r = newRating;
    }
    
    string highestRated(string cuisine) {
        auto &q = cs[cuisine];
        while (-q.top().first != fs[q.top().second].first) // 堆顶的食物评分不等于其实际值
            q.pop();
        return q.top().second;
    }
};
// java
class FoodRatings {
    Map<String, Pair<Integer, String>> fs = new HashMap<>();
    Map<String, Queue<Pair<Integer, String>>> cs = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (var i = 0; i < foods.length; ++i) {
            String f = foods[i], c = cuisines[i];
            var r = ratings[i];
            fs.put(f, new Pair<>(r, c));
            cs.computeIfAbsent(c, k -> new PriorityQueue<>((a, b) -> 
                !Objects.equals(a.getKey(), b.getKey()) ? 
                    b.getKey() - a.getKey() : // 逆序 
                    a.getValue().compareTo(b.getValue())
                )).add(new Pair<>(r, f));
        }
    }
    
    public void changeRating(String food, int newRating) {
        var c = fs.get(food).getValue();
        cs.get(c).offer(new Pair<>(newRating, food)); // 直接添加新数据，后面 highestRated 再删除旧的
        fs.put(food, new Pair<>(newRating, c)); // 记录新评分
    }
    
    public String highestRated(String cuisine) {
        var q = cs.get(cuisine);
        while (!Objects.equals(q.peek().getKey(), fs.get(q.peek().getValue()).getKey()))
            q.poll();
        return q.peek().getValue();
    }
}
// python
class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.fs = {}
        self.cs = defaultdict(list)
        for f, c, r in zip(foods, cuisines, ratings):
            self.fs[f] = [r, c]
            heappush(self.cs[c], (-r, f))

    def changeRating(self, food: str, newRating: int) -> None:
        f = self.fs[food]
        heappush(self.cs[f[1]], (-newRating, food)) # 直接添加新数据,后面highestRated再删除旧的
        f[0] = newRating

    def highestRated(self, cuisine: str) -> str:
        h = self.cs[cuisine]
        while -h[0][0] != self.fs[h[0][1]][0]: # 堆顶的食物评分!=实际值
            heappop(h)
        return h[0][1]