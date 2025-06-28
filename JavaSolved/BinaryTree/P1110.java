package Done.BinaryTree;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }

    @Override
    public String toString() {
        return String.valueOf(val);
    }
}

public class P1110 {
    public static List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> forest = new ArrayList<>();
        Set<Integer> toDelete = new HashSet<>();
        boolean rootPresent = true; // if root also to be deleted
        for (int i : to_delete) {
            toDelete.add(i);
        }
        if (dfs(root, toDelete, forest))
            rootPresent = false;
        if (rootPresent)
            forest.add(root);
        
        System.gc();
        return forest;
    }

    public static boolean dfs(TreeNode root, Set<Integer> toDelete, List<TreeNode> forest) {
        if (root == null)
            return false;
        if (root.left != null && dfs(root.left, toDelete, forest))
            root.left = null;

        if (root.right != null && dfs(root.right, toDelete, forest))
            root.right = null;

        if (toDelete.contains(root.val)) {
            toDelete.remove(root.val);
            if (root.left != null)
                forest.add(root.left);
            if (root.right != null)
                forest.add(root.right);
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(4);
        // root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(3);
        // root.right.left = new TreeNode(6);
        // root.right.right = new TreeNode(7);

        // List<TreeNode> forest = new ArrayList<>();
        // int[] to_delete = { 3 };
        // forest = delNodes(root, to_delete);

    }
}
