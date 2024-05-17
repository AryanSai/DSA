package Done.BinaryTree;
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class P1325 {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root==null)
            return null;
        root.left = removeLeafNodes(root.left,target);
        root.right = removeLeafNodes(root.right,target);
        if (root.left==null && root.right==null && root.val == target) 
            root = null;
        return root;
    }
    public static void main(String[] args) {
        System.out.println("sairam");
    }
}
