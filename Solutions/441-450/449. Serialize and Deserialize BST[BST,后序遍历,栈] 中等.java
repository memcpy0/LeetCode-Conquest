/*
** Problem: https://leetcode.cn/problems/serialize-and-deserialize-bst
** Article: https://memcpy0.blog.csdn.net/article/details/132779776
** Author: memcpy0
*/
// BEST: BST+后序遍历+栈
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        return postOrder(root, new StringBuilder()).toString();
    }
    private StringBuilder postOrder(TreeNode root, StringBuilder sb) {
        if (root != null) { // 可以不用存储空指针
            sb = postOrder(root.left, sb);
            sb = postOrder(root.right, sb);
            sb.append(String.valueOf(root.val) + ",");
        }
        return sb;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) return null;
        String[] arr = data.split(",");
        Deque<Integer> stack = new ArrayDeque<Integer>();
        int length = arr.length;
        for (int i = 0; i < length; ++i)
            stack.push(Integer.parseInt(arr[i]));
        return construct(Integer.MIN_VALUE, Integer.MAX_VALUE, stack);
    }
    // 使用栈和后序遍历重构二叉搜索树
    private TreeNode construct(int lower, int upper, Deque<Integer> stack) {
        // 当前元素超出范围，不能用作子树根节点的值
        if (stack.isEmpty() || stack.peek() < lower || stack.peek() > upper) return null;
        int val = stack.pop();
        TreeNode root = new TreeNode(val);
        root.right = construct(val, upper, stack);
        root.left = construct(lower, val, stack);
        return root;
    }
}