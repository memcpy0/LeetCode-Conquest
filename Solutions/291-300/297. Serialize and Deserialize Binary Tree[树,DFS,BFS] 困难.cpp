/*
** Problem: https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
** Article: https://memcpy0.blog.csdn.net/article/details/132778608
** Author: memcpy0
*/
// BFS最优写法: StringJoiner
import java.util.StringJoiner;
public class Codec {
    public String serialize(TreeNode root) {
        if (root == null) return "";
        Queue<TreeNode> q = new ArrayDeque<>();
        StringJoiner sj = new StringJoiner(",");
        q.add(root);
        sj.add(Integer.toString(root.val));
        while (!q.isEmpty()) {
            TreeNode head = q.remove();
            if (head.left != null) {
                q.add(head.left);
                sj.add(Integer.toString(head.left.val));
            } else sj.add("null");
            if (head.right != null) {
                q.add(head.right);
                    sj.add(Integer.toString(head.right.val));
            } else sj.add("null");
        }
        return sj.toString();
    }
    public TreeNode deserialize(String data) {
        if (data.length() == 0) return null; // 特判：data == ""
        String[] nodes = data.split(",");
        Queue<TreeNode> q = new ArrayDeque<>();
        TreeNode root = new TreeNode(Integer.parseInt(nodes[0]));
        q.add(root);
        int idx = 1, n = nodes.length;
        while (idx < n) { // 不必以!q.isEmpty()作为判断条件
            TreeNode head = q.remove();
            if (!nodes[idx].equals("null")) {
                TreeNode left = new TreeNode(Integer.parseInt(nodes[idx])); 
                head.left = left; // left挂接到head
                q.add(left);
            } 
            idx++;
            if (!nodes[idx].equals("null")) {
                TreeNode right = new TreeNode(Integer.parseInt(nodes[idx])); 
                head.right = right; // right挂接到head
                q.add(right);
            } 
            idx++;
        }
        return root;
    }
}

// BEST: 先序遍历+深度优先搜索
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        return serialize(root, new StringBuilder()).toString();
    }
    private StringBuilder serialize(TreeNode root, StringBuilder str) {
        if (root == null) str.append("None,");
        else {
            str.append(String.valueOf(root.val) + ",");
            str = serialize(root.left, str);
            str = serialize(root.right, str);
        }
        return str;
    }

    private Integer index;
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] tokenArray = data.split(",");
        index = 0;
        return deserialize(tokenArray);
    }
    public TreeNode deserialize(String[] data) {
        if (data[index].equals("None")) {
            ++index;
            return null;
        }
        TreeNode root = new TreeNode(Integer.valueOf(data[index]));
        ++index;
        root.left = deserialize(data);
        root.right = deserialize(data);
        return root;
    }
}

// 括号表示编码 + 递归下降解码
public class Codec {
    public String serialize(TreeNode root) {
        if (root == null) return "X";
        String left = "(" + serialize(root.left) + ")";
        String right = "(" + serialize(root.right) + ")";
        return left + root.val + right;
    }
    private int ptr;
    public TreeNode deserialize(String data) {
        ptr = 0;
        return parse(data);
    }
    public TreeNode parse(String data) {
        if (data.charAt(ptr) == 'X') {
            ++ptr;
            return null;
        }
        TreeNode cur = new TreeNode(0);
        cur.left = parseSubtree(data);
        cur.val = parseInt(data);
        cur.right = parseSubtree(data);
        return cur;
    }
    public TreeNode parseSubtree(String data) {
        ++ptr; // 跳过左括号
        TreeNode subtree = parse(data);
        ++ptr; // 跳过右括号
        return subtree;
    }
    public int parseInt(String data) {
        int x = 0, sgn = 1;
        if (!Character.isDigit(data.charAt(ptr))) {
            sgn = -1;
            ++ptr;
        }
        while (Character.isDigit(data.charAt(ptr))) 
            x = x * 10 + data.charAt(ptr++) - '0';
        return x * sgn;
    }
}