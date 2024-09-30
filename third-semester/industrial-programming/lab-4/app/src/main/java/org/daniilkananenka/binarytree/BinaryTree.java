package org.daniilkananenka.binarytree;

public class BinaryTree<T extends Comparable<T>> {
  private Node<T> root;

  public void add(T data) {
    root = addRecursive(root, data);
  }

  private Node<T> addRecursive(Node<T> current, T data) {
    if (current == null) {
      return new Node<>(data);
    }

    if (data.compareTo(current.data) < 0) {
      current.left = addRecursive(current.left, data);
    } else if (data.compareTo(current.data) > 0) {
      current.right = addRecursive(current.right, data);
    }

    return current;
  }

  public boolean containsNode(T data) {
    return containsNodeRecursive(root, data);
  }

  private boolean containsNodeRecursive(Node<T> current, T data) {
    if (current == null) {
      return false;
    }

    if (data.equals(current.data)) {
      return true;
    }

    return data.compareTo(current.data) < 0
        ? containsNodeRecursive(current.left, data)
        : containsNodeRecursive(current.right, data);
  }

  // Root - Left - Right
  public void traversePreOrder(Node<T> node) {
    if (node != null) {
      System.out.print(" " + node.data);
      traversePreOrder(node.left);
      traversePreOrder(node.right);
    }
  }

  // Left - Right - Root
  public void traversePostOrder(Node<T> node) {
    if (node != null) {
      traversePostOrder(node.left);
      traversePostOrder(node.right);
      System.out.print(" " + node.data);
    }
  }

  // Left - Root - Right
  public void traverseInOrder(Node<T> node) {
    if (node != null) {
      traverseInOrder(node.left);
      System.out.print(" " + node.data);
      traverseInOrder(node.right);
    }
  }

  public Node<T> getRoot() {
    return root;
  }
}