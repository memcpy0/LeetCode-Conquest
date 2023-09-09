/*
** Problem: https://leetcode.cn/problems/serialize-and-deserialize-n-ary-tree
** Article: https://memcpy0.blog.csdn.net/article/details/132780304
** Author: memcpy0
*/
// BEST: BFS+类似LeetCode层序遍历格式+StringJoiner
```java
import java.util.StringJoiner;
class Codec {
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        if (root == null) return "";
        StringJoiner sj = new StringJoiner(",");
        Deque<Node> queue = new ArrayDeque<>();
        queue.offer(root);
        sj.add(Integer.toString(root.val));
        sj.add(null);
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            for (Node node : curr.children) { // 将每个节点的子节点作为一组,由空值分隔
                sj.add(Integer.toString(node.val));
                queue.offer(node);
            }
            sj.add(null);
        }
        return sj.toString();
    }
	
    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if (data.isEmpty()) return null;
        String[] tokens = data.split(",");
        Deque<Node> queue = new ArrayDeque<>();
        int index = 0;
        Node root = new Node(Integer.parseInt(tokens[index++]), new ArrayList<Node>());
        ++index; // 跳过null

        queue.offer(root); 
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            while (index < tokens.length) {
                if (tokens[index].equals("null")) {
                    ++index;
                    break;
                }
                Node node = new Node(Integer.parseInt(tokens[index++]), new ArrayList<Node>());
                curr.children.add(node);
                queue.offer(node);
            }
        }
        return root;
    }
}