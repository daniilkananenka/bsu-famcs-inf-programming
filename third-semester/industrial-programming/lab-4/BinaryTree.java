public class BinaryTree<T extends Comparable<T>> {
  public class Node<T> {
    private Node<T> left;
    private Node<T> right;
    private T value;

    // Getters
    public Node<T> getLeft() {
      return this.left;
    }

    public Node<T> getRight() {
      return this.right;
    }

    public T getValue() {
      return this.value;
    }

    // Constructors
    public Node(T value, Node<T> left, Node<T> right) {
      this.left = left;
      this.right = right;
      this.value = value;
    }

    public Node(T value) {
      this.left = null;
      this.right = null;
      this.value = value;
    }
  }

  private Node<T> root;

  public Node<T> getRoot() {
    return this.root;
  }

  public void setRoot(Node<T> val) {
    this.root = val;
  }

  public BinaryTree(T root_value) {
    this.root = new Node<T>(root_value);
  }
}
