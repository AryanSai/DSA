package BinaryTreeDS;
import java.util.List;
import java.util.ArrayList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

public class DFS {
    public static boolean dfs(TreeNode root, int x, List<Integer> path) {
        if (root == null)
            return false;
        // since not null, add it to the path list
        path.add(root.val);

        if (root.val == x)
            return true;

        if (dfs(root.left, x, path) || dfs(root.right, x, path))
            return true;

        // remove it from the list since not present in the explored path
        path.remove(path.size() - 1);
        return false;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(5);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(6);
        root.left.right = new TreeNode(2);
        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(8);
        root.left.right.left = new TreeNode(7);
        root.left.right.right = new TreeNode(4);

        List<Integer> path = new ArrayList<>();
        int x = 4;
        if (dfs(root, 4, path)) {
            System.out.println("Path to node " + x + ": " + path);
        } else {
            System.out.println("Node " + x + " not found in the tree.");
        }
    }
}
