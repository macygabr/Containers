#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
namespace s21 {
template <typename Key, typename T>
class BinaryTree {
 public:
  class Node;
  class Iterator;

 public:  // change to protected
  Node* root;
  Node* terminal_node;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;
  using iterator = Iterator;
  using size_type = std::size_t;

 public:  // Member functions
  BinaryTree();
  BinaryTree& operator=(const BinaryTree& other);

  //  public:  // Element access
  //   T& at(const Key& key);
  //   T& operator[](const Key& key);

 public:  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

 public:  // Lookup
  bool contains(const Key& key);

 public:  // Modifiers
  std::pair<iterator, bool> insert(const value_type val);
  std::pair<iterator, bool> insert(const Key& key, const T& obj = T());
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);

 public:             // Iterators
  iterator begin();  // returns an iterator to the beginning
  iterator end();    // returns an iterator to the end

 public:  // suport
  Node* rotate_Left(Node* x);
  Node* rotate_Right(Node* x);
  iterator Nurlanization(Node* x);
  void add_terminal_node(Node* x, bool add);
  int get_height(Node* node);
  int get_balance_factor(Node* node);
  virtual Key get_key(value_type val) { return 0; };
  virtual T get_val(value_type val) { return 0; };
  virtual bool set_val(Node* fir, value_type sec) { return 0; };
  std::pair<iterator, bool> insert_recursive(Node* x, value_type val,
                                             bool* check, bool permission);
  // void printTree(Node* x, int level = 0);

 public:
  class Node {
   public:
    Node* left;
    Node* right;
    Node* parent;
    int balanceFactor = 0;
    value_type node_key;
    std::size_t size;

   public:
    Node()
        : node_key(value_type()),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}

    Node(value_type val)
        : node_key(value_type(val)),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}
  };

  class Iterator {
   public:
    using pointer = T*;
    using reference = T&;

    Iterator();
    Iterator(Node* node);
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    // reference operator*();
    // bool operator==(const iterator& it);
    bool operator!=(const iterator& it);
    // pointer operator->() const {
    //   int Size(Node<T, V> * node) {
    //     if (node) return node->size;
    //     return 0;
    //   }
    // }
    // reference operator*() const {
    //   if (node == nullptr) {
    //     static T default_value = T{};
    //     return default_value;
    //   }
    //   return node->node_key;
    // }

   public:
    Node* node;
  };
};
};  // namespace s21
#include "BinaryTree.inc"
#endif