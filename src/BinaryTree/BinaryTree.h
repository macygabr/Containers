#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H

#include <vector>

namespace s21 {
template <typename Key, typename T, typename Value>
class BinaryTree {
 protected:
  class Node;
  class Iterator;
  class Const_Iterator;

 protected:
  Node* root;
  Node* terminal_node;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = Value;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using const_iterator = Const_Iterator;
  using size_type = std::size_t;
  using pointer = value_type*;

 public:  // Member functions
  BinaryTree();
  BinaryTree(const BinaryTree& other);
  BinaryTree(BinaryTree&& other);
  ~BinaryTree();
  BinaryTree& operator=(const BinaryTree& other);
  BinaryTree& operator=(BinaryTree&& other);

 public:             // Iterators
  iterator begin();  // returns an iterator to the beginning
  const_iterator begin() const;
  iterator end();  // returns an iterator to the end
  const_iterator end() const;

 public:  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

 public:  // Modifiers
  void clear();
  std::pair<iterator, bool> insert(const value_type val);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  iterator erase(iterator it);
  void swap(BinaryTree& other);
  void merge(BinaryTree& other);
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 public:  // Lookup
  bool contains(const Key& key = Key());

 protected:  // suport
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  Node* rotate_Left(Node* x);
  Node* rotate_Right(Node* x);
  Node* Nurlanization(Node* x);
  void add_terminal_node(Node* x, bool add);
  int get_height(Node* x);
  int get_balance_factor(Node* x);
  virtual Key get_key(value_type val) { return Key(); };
  virtual T get_val(value_type val) { return T(); };
  virtual bool set_val(Node* fir, value_type sec) { return 0; };
  virtual bool is_multiset() { return 0; };
  std::pair<iterator, bool> insert_recursive(Node* x, value_type val,
                                             Iterator* it_result,
                                             bool permission,
                                             bool multisetOn = false);
  void freeTree(Node* x);
  iterator delete_node_with_all_childrens(iterator it);
  iterator delete_node_with_right_childrens(iterator it);
  iterator delete_node_with_left_childrens(iterator it);
  iterator delete_node_with_not_childrens(iterator it);
  bool check_balance();
  T& search(bool add, const Key& key);
  Node* copy_recursive(Node* x);
  void SimpleprintTree(typename BinaryTree<Key, T, value_type>::Node* root,
                       int level = 0);
  void printTree(typename BinaryTree<Key, T, value_type>::Node* root,
                 int level = 0);

 private:  // constants
  size_type MAX_SIZE = 100;

 protected:
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

 protected:
  class Iterator {
   public:
    friend class BinaryTree<Key, T, value_type>;

    Iterator() : node(nullptr){};
    Iterator(Node* newnode) : node(newnode){};
    ~Iterator() = default;

   public:
    iterator& operator=(const iterator& it);
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    bool operator==(const iterator& it);
    bool operator!=(const iterator& it);
    pointer operator->() const {
      return node ? &(node->node_key) : throw std::exception();
    };
    reference operator*() const {
      if (node)
        return node->node_key;
      else
        throw std::exception();
    };

   protected:
    Node* node = nullptr;
  };

 protected:
  class Const_Iterator : public Iterator {
    const_reference operator*() const { return Iterator::operator*(); };
  };
};
};  // namespace s21
#include "BinaryTree.inc"
#endif