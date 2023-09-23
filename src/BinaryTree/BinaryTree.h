#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
namespace s21 {
// template <typename Key, typename T>
// class Node {
//    public:
//     using key_type = Key;
//     using mapped_type = T;
//     using value_type = std::pair<const key_type, mapped_type>;

//    public:
//     Node* left;
//     Node* right;
//     Node* parent;
//     int balanceFactor = 0;
//     T value;
//     Key key;

//    public:
//     Node() : value(), key(), left(nullptr), right(nullptr), parent(nullptr)
//     {}
//   };

template <typename Key, typename T>
class BinaryTree {
 public:
  class Node;
  class Iterator;

 public:
  Node* root;

 public:
  using key_type = Key;
  using value_type = T;
  using iterator = Iterator;

 public:
  BinaryTree();
  std::pair<iterator, bool> insert(const Key& key, const T& obj);


  public:
    std::pair<iterator, bool> insert_recursive(Node* x, value_type val,bool* check, bool permission);
    Node* rotate_Left(Node* x);
    Node* rotate_Right(Node* x);
    Node* Nurlanization(Node* x);
    int get_height(Node* node);
    int get_balance_factor(Node* node);
    void printTree(const Node* root, int level = 0);

public:
  T& at(const Key& key);
  T& operator[](const Key& key);


  class Node {
   public:
    Node* left;
    Node* right;
    Node* parent;
    int balanceFactor = 0;
    T value;
    Key key;

  public:
    Node() : value(), key(), left(nullptr), right(nullptr), parent(nullptr) {}

  };

  class Iterator {
   public:
    Iterator();
  };
};
};  // namespace s21
#include "BinaryTree.inc"
#endif