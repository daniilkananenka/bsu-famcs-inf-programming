package org.daniilkananenka.binarytree;

public class App {
    public static void main(String[] args) {
        BinaryTree<Integer> tree = new BinaryTree<>();
        tree.add(6);
        tree.add(4);
        tree.add(8);
        tree.add(3);
        tree.add(5);
        tree.add(7);
        tree.add(9);

        System.out.println("Pre-order traversal:");
        tree.traversePreOrder(tree.getRoot());

        System.out.println("\nIn-order traversal:");
        tree.traverseInOrder(tree.getRoot());

        System.out.println("\nPost-order traversal:");
        tree.traversePostOrder(tree.getRoot());
    }
}
