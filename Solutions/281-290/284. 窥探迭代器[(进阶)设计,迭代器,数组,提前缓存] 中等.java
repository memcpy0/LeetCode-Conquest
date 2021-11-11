/*
** Problem: https://leetcode-cn.com/problems/peeking-iterator/
** Article: https://memcpy0.blog.csdn.net/article/details/121270384
** Author: memcpy0
*/
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<E> {
    private Iterator<Integer> iterator;
    private E cache = null;
	public PeekingIterator(Iterator<E> iterator) {
	    // initialize any member here.
	    this.iterator = iterator;
        if (iterator.hasNext())
            cache = iterator.next(); // 提前缓存
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public E peek() { // 已经缓存过值
        return cache;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public E next() {
	    E ans = cache; // 返回已经缓存的值
        if (iterator.hasNext()) // 如果还有值,就再缓存下一个值
            cache = iterator.next();
        else
            cache = null;
        return ans;
	}
	
	@Override
	public boolean hasNext() {
	    return cache != null; // 由于提前缓存了值,只需判断cache是否为null
	}
}