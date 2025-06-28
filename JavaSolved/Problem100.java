package Done;
// 100. Same Tree(Easy)
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the
//  nodes have the same value.
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

class Problem100 {
    private static boolean compare(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }

        if (p == null || q == null || p.val != q.val) {
            return false;
        }

        return compare(p.left, q.left) && compare(p.right, q.right);
    }

    public static void main(String[] args) {

        TreeNode leftChild = new TreeNode(2);
        TreeNode rightChild = new TreeNode(3);
        TreeNode root = new TreeNode(1, leftChild, rightChild);

        TreeNode leftChild2 = new TreeNode(2);
        TreeNode rightChild2 = new TreeNode(4);
        TreeNode root2 = new TreeNode(1, leftChild2, rightChild2);

        // TreeNode leftGrandchild = new TreeNode(4);
        // TreeNode rightGrandchild = new TreeNode(5);

        // leftChild.left = leftGrandchild;
        // rightChild.right = rightGrandchild;

        System.out.println(compare(root, root2));
        // Now the binary tree looks like this:
        // 1
        // / \
        // 2 3
        // / \
        // 4 5
    }
}
