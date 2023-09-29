#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
namespace s21 {
template <typename Key, typename T, typename Value>
class BinaryTree {
 public:
  class Node;
  class Iterator;
  class Const_Iterator;

 public:  // change to protected
  Node* root;
  Node* terminal_node;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = Value;
  using iterator = Iterator;
  using const_iterator = Const_Iterator;
  using size_type = std::size_t;

 public:  // Member functions
  BinaryTree();
  ~BinaryTree();
  BinaryTree& operator=(const BinaryTree& other);

 public:             // Iterators
  iterator begin();  // returns an iterator to the beginning
  iterator end();    // returns an iterator to the end

 public:  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

 public:  // Modifiers
  void clear();
  std::pair<iterator, bool> insert(const value_type val);
  std::pair<iterator, bool> insert(const Key& key = Key(), const T& obj = T());
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator it);
  iterator erase(const_iterator it);
  // void swap(set& other);
  // void merge(set& other);

 public:  // Lookup
  bool contains(const Key& key = Key());

 public:  // suport
  Node* rotate_Left(Node* x);
  Node* rotate_Right(Node* x);
  Node* Nurlanization(Node* x);
  void add_terminal_node(Node* x, bool add);
  int get_height(Node* x);
  int get_balance_factor(Node* x);
  virtual Key get_key(value_type val) { return Key(); };
  virtual T get_val(value_type val) { return T(); };
  virtual bool set_val(Node* fir, value_type sec) { return 0; };
  std::pair<iterator, bool> insert_recursive(Node* x, value_type val,
                                             bool* check, bool permission);
  void freeTree(Node* x);
  void delete_node_with_all_childrens(iterator it);
  void delete_node_with_right_childrens(iterator it);
  void delete_node_with_left_childrens(iterator it);
  void delete_node_with_not_childrens(iterator it);

 public:  // constants
  size_type MAX_SIZE = 100;

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
        : left(nullptr),
          right(nullptr),
          parent(nullptr),
          balanceFactor(0),
          node_key(value_type()),
          size(0) {}

    Node(value_type val)
        : left(nullptr),
          right(nullptr),
          parent(nullptr),
          node_key(value_type(val)) {}
  };

  class Iterator {
   public:
    // using pointer = T*;
    // using reference = T&;

    // Iterator();
    Iterator(Node* node);
    Iterator(const Iterator& it);
    Iterator(Iterator&& it);
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    iterator& operator=(const iterator& it);
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

  class Const_Iterator : public Iterator {};
};
};  // namespace s21
#include "BinaryTree.inc"
#endif