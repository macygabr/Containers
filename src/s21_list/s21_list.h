#ifndef LIST_H
#define LIST_H
// #include <algorithm>
// #include <cstddef>
// #include <initializer_list>
// #include <limits>
// #include <stdexcept>
// #include <utility>

namespace s21 {

template <typename T>
class list {
 public:
  class listIterator;
  class listConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = listIterator;
  using const_iterator = listConstIterator;
  using size_type = std::size_t;
  using iterator_pointer = T *;

  list();             // default constructor, creates empty list
  list(size_type n);  // parameterized constructor, creates the list of size n
  list(std::initializer_list<value_type> const
           &items);  // initializer list constructor, creates list initizialized
                     // using std::initializer_list
  list(const list &l);  //	copy constructor
  list(list &&l);       //	move constructor
  ~list();              //	destructor
  list &operator=(
      list &&l);  //	assignment operator overload for moving object

  const_reference front() const;  // access the first element
  const_reference back() const;   // access the last element

  iterator begin();              // returns an iterator to the beginning
  iterator end();                // returns an iterator to the end
  const_iterator begin() const;  // returns an iterator to the beginning
  const_iterator end() const;    // returns an iterator to the end

  bool empty() const;          // checks whether the container is empty
  size_type size() const;      // returns the number of elements
  size_type max_size() const;  // returns the maximum possible number of
                               // elements

  void clear();  // clears the contents
  iterator insert(
      iterator pos,
      const_reference value);  // inserts element into concrete pos and returns
                               // the iterator that points to the new element
  void erase(iterator pos);    // erases element at pos
  void push_back(const_reference value);   //	adds an element to the end
  void pop_back();                         // removes the last element
  void push_front(const_reference value);  //	adds an element to the head
  void pop_front();                        //	removes the first element
  void swap(list &other);                  // swaps the contents
  void merge(list &other);                 // merges two sorted lists
  void splice(
      iterator pos,
      list &other);  // transfers elements from list other starting from pos
  void reverse();    // reverses the order of the elements
  void unique();     //	removes consecutive duplicate elements
  void sort();       //	sorts the elements
  template <class... Args>
  iterator insert_many(const_iterator pos,
                       Args &&...args);  // inserts new elements into the
                                         // container directly before pos
  template <class... Args>
  void insert_many_back(
      Args &&...args);  // appends new elements to the end of the container
  template <class... Args>
  void insert_many_front(
      Args &&...args);  // void insert_many_front(Args&&... args)
        void change_end();


  //  private:
 public:
  struct Node {
    value_type value_;
    Node *prev_;
    Node *next_;
    Node(const value_type &value)
        : value_(value), prev_(nullptr), next_(nullptr) {}
  };
  Node *head_;
  Node *tail_;
  Node *end_;
  size_type size_;
};

template <typename T>
class list<T>::listIterator {
 public:
  listIterator() { ptr_ = nullptr; }

  listIterator(Node *ptr) : ptr_(ptr) {}

  reference operator*() {
    if (!this->ptr_) {
      throw std::invalid_argument("Value is nullptr");
    }
    return this->ptr_->value_;
  }

  listIterator operator++(int) {
    listIterator it = *this;
    ptr_ = ptr_->next_;
    return it;
  }

  listIterator operator--(int) {
    listIterator it = *this;
    ptr_ = ptr_->prev_;
    return it;
  }

  listIterator operator++() {
    ptr_ = ptr_->next_;
    return *this;
  }

  listIterator operator--() {
    ptr_ = ptr_->prev_;
    return *this;
  }

  listIterator operator+(int n) const {
    Node *tmp = ptr_;
    for (size_type i = 0; i < n; i++) {
      tmp = tmp->next_;
    }
    listIterator res(tmp);
    return res;
  }

  listIterator operator-(const size_type value) {
    Node *tmp = ptr_;
    for (size_type i = 0; i < value; i++) {
      tmp = tmp->prev_;
    }
    listIterator res(tmp);
    return res;
  }
  // ptrdiff_t operator-(const listIterator &other) const;
  bool operator==(const listIterator &other) const {
    return this->ptr_ == other.ptr_;
  }
  bool operator!=(const listIterator &other) const {
    return this->ptr_ != other.ptr_;
  }
  Node *ptr_;
  //  private:
};

template <typename T>
  class listConstIterator : public list<T>::listIterator  {

  const T &operator*() { return list<T>::listIterator::operator*(); }
};


}  // namespace s21
#include "s21_list.tpp"

#endif  // LIST_H