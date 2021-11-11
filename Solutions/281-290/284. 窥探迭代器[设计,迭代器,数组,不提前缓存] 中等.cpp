/*
** Problem: https://leetcode-cn.com/problems/peeking-iterator/
** Article: https://memcpy0.blog.csdn.net/article/details/121270384
** Author: memcpy0
*/
class PeekingIterator : public Iterator {
    bool hasPeeked;
    int cache; // 第一次peek时缓存迭代的元素
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), hasPeeked(false), cache(0) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!hasPeeked) {
            cache = Iterator::next();
            hasPeeked = true;
        }
        return cache;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (hasPeeked) {
            hasPeeked = false;
            return cache;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
	    return hasPeeked || Iterator::hasNext();
	}
};