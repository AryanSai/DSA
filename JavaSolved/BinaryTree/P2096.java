package Done.BinaryTree;

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

public class P2096 {
    public static boolean dfs(TreeNode root, int x, StringBuilder path) {
        if (root == null)
            return false;
        // since not null, add it to the path list

        if (root.val == x)
            return true;

        if (dfs(root.left, x, path)) {
            path.append("L");
            return true;
        }

        if (dfs(root.right, x, path)) {
            path.append("R");
            return true;
        }
        // remove it from the list since not present in the explored path
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

        StringBuilder path = new StringBuilder();
        if (dfs(root, 6, path)) {
            path = path.reverse();
        }
        StringBuilder path2 = new StringBuilder();
        if (dfs(root, 4, path2)) {
            path2 = path2.reverse();
        }

        int i = 0;
        while (i < Math.min(path.length(), path2.length()) && path.charAt(i) == path2.charAt(i)) {
            i++;
        }

        path.delete(0, i);
        path2.delete(0, i);
        
        for (int j = 0; j < path.length(); j++) {
            path.setCharAt(j, 'U');
        }
        System.out.println(path + "" + path2);
    }
}
