package Done.BinaryTree;

// Definition for a binary tree node.

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

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

public class P2196 {
    static TreeNode createBinaryTree(int[][] descriptions) {
        HashMap<Integer, TreeNode> ht = new HashMap<>();
        Set<Integer> children = new HashSet<>();
        int parent, child;
        TreeNode parentNode, childNode;
        for (int[] desc : descriptions) {
            parent = desc[0];
            child = desc[1];
            parentNode = ht.getOrDefault(parent, new TreeNode(parent));
            childNode = ht.getOrDefault(child, new TreeNode(child));
            if (desc[2] == 1) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }
            ht.put(child, childNode);
            ht.put(parent, parentNode);
            children.add(child);
        }
        Set<Integer> leftover = new HashSet<>(ht.keySet());
        leftover.removeAll(children);
        Iterator<Integer> iterator = leftover.iterator();
        TreeNode root = new TreeNode();
        if (iterator.hasNext()) {
            int element = iterator.next();
            root = ht.get(element);
        }
        return root;
    }

    public static void main(String[] args) {
        System.out.println("sairam");
    }
}
