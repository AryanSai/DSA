class Node{
    int val;
    Node left,right;

    public Node(int val) {
        this.val=val;
        left=right=null;
    }   
}

class BinaryTree{
    Node root;
    static void inorderTraversal(Node root){
        if(root != null){
            inorderTraversal(root.left);
            System.out.println(root.val);
            inorderTraversal(root.right);
        }

    }
    public static void main(String[] args) {
        BinaryTree tree= new BinaryTree();
        tree.root = new Node(1);
        tree.root.left=new Node(2);
        tree.root.right=new Node(3);
        inorderTraversal(tree.root);
    }
}