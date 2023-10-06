#include <iostream>
// #include <list>

#include "s21_list.h"
// --------------------------------------------------------------------Functions
namespace s21 {

template <typename T>
list<T>::list() : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  //   change_end();
}

template <typename T>
list<T>::list(size_type n)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  if (n >= max_size()) {
    throw std::out_of_range("Limit of the container is exceeded");
  }
  end_ = new Node(size_);
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
  //   change_end();
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  for (const auto& item : items) {
    push_back(item);
    // change_end();
  }
}

/*template <typename value_type>
list<value_type>::list(const list& l)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  this->copy(l);
}*/
template <typename T>
list<T>::list(const list& l)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  end_ = new Node(size_);
  //   this->copy(l);
  //------------------
  Node* current = l.head_;
  for (size_type i = 0; i != l.size_; i++) {
    push_back(current->value_);
    current = current->next_;
  }
  //--------------------
}

/*template <typename value_type>
list<value_type>::list(list&& l)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  swap(l);
}*/
template <typename T>
list<T>::list(list&& l)
    : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
  swap(l);
}

/* template <typename value_type>
list<value_type>::~list() {
  clear();
  delete end_;
}*/
template <typename T>
list<T>::~list() {
  clear();
  delete end_;
}

/* template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(list&& l) {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}*/
template <typename T>
list<T>& list<T>::operator=(list<T>&& l) {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}

// // List Element access
/* template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  return !head_ ? end_->value_ : head_->value_;
}*/
template <class value_type>
typename list<value_type>::const_reference list<value_type>::front() const {
  return head_->value_;
}

/* template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  return !tail_ ? end_->value_ : tail_->value_;
}*/
template <class value_type>
typename list<value_type>::const_reference list<value_type>::back() const {
  return tail_->value_;
}

// List Iterators
/* template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return !head_ ? iterator(end_) : iterator(head_);
}*/
template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(head_);
}

/*template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(end_);
}*/
template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(end_);
}

/*template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::begin() const {
  return !head_ ? const_iterator(end_) : const_iterator(head_);
}*/
template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return const_iterator(head_);
}

/*template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::end() const {
  return const_iterator(end_);
}*/
template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return const_iterator(end_);
}

// List Capacity
/*template <typename value_type>
bool list<value_type>::empty() {
  return size_ == 0;
}*/
template <typename T>
bool list<T>::empty() const {
  return (size_ == 0);
}

/*template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() {
  return size_;
}*/
template <typename T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

/*template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(Node) / 2);
}*/
template <typename T>
typename list<T>::size_type list<T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

/*List Modifiers
template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}*/
template <typename T>
void list<T>::clear() {
  while (!empty()) {
    pop_back();
  }
}

/*template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node* current = pos.ptr_;
  Node* add = new Node(value);
  if (empty()) {
    add->next_ = end_;
    add->prev_ = end_;
    head_ = add;
    tail_ = add;
  } else {
    if (current == head_) {
      head_ = add;
    } else if (current == end_) {
      tail_ = add;
    }
    add->next_ = current;
    add->prev_ = current->prev_;
    current->prev_->next_ = add;
    current->prev_ = add;
  }
  size_++;
  change_end();
  return iterator(add);
}*/
// template <typename T>
// typename list<T>::iterator list<T>::insert(iterator pos,
//                                            const_reference value) {
//   if (empty()) {
//     push_back(value);
//   } else {
//     Node* current = pos.ptr_;
//     Node* add = new Node(value);
//     add->next_ = current;
//     add->prev_ = current->prev_;
//     current->prev_->next_ = add;
//     current->prev_ = add;
//   }
//   size_++;
//   //   change_end();
//   return iterator(add);
// }

/*template <typename value_type>
void list<value_type>::erase(iterator pos) {
  Node* current = pos.ptr_;
  if (!empty() && current != end_) {
    if (current == head_) {
      if (current->next_ && current->next_ != end_) {
        head_ = current->next_;
      } else {
        head_ = end_;
      }
    } else if (current == tail_) {
      if (current->prev_ && current->prev_ != end_) {
        tail_ = current->prev_;
      } else {
        tail_ = end_;
      }
    }
    current->prev_->next_ = current->next_;
    current->next_->prev_ = current->prev_;
    delete current;
    this->size_--;
  } else {
    throw std::invalid_argument("Invalid argument");
  }
  change_end();
}*/
template <typename T>
void list<T>::erase(iterator pos) {
  if (!empty()) {
    Node* current = pos.ptr_;
    if (current == head_)
      pop_front();
    else if (current == tail_)
      pop_back();
    else {
      current->prev_->next_ = current->next_;
      current->next_->prev_ = current->prev_;
      delete current;
      size_--;
    }
  } else {
    throw std::invalid_argument("Invalid argument");
  }
  //   change_end();
}

/*template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  size_++;
  change_end();
}*/
template <typename T>
void list<T>::push_back(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  size_++;
  //   change_end();
}

/*template <typename value_type>
void list<value_type>::pop_back() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* last_node = tail_;
  if (size_ == 1) {
    head_ = nullptr;
    tail_ = nullptr;
  } else {
    tail_ = last_node->prev_;
    tail_->next_ = nullptr;
  }
  delete last_node;
  size_--;
  change_end();
}*/
template <typename T>
void list<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* last_node = tail_;
  tail_ = tail_->prev_;
  if (tail_) (tail_->next_ = nullptr);
  if (last_node == head_) head_ = nullptr;
  delete last_node;
  size_--;
  //   change_end();
}

/*template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }
  size_++;
  change_end();
}*/
template <typename T>
void list<T>::push_front(const_reference value) {
  Node* new_node = new Node(value);
  if (empty()) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }
  size_++;
  //   change_end();
}

/* template <typename value_type>
void list<value_type>::pop_front() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* first_node = head_;
  if (size_ == 1) {
    head_ = nullptr;
    tail_ = nullptr;
  } else {
    head_ = first_node->next_;
    head_->prev_ = nullptr;
  }
  delete first_node;
  size_--;
  change_end();
}*/
template <typename T>
void list<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("list is empty");
  }
  Node* first_node = head_;
  head_ = head_->next_;
  if (head_) (head_->prev_ = nullptr);
  if (first_node == tail_) tail_ = nullptr;
  delete first_node;
  size_--;
  //   change_end();
}

/* template <typename value_type>
void list<value_type>::swap(list& other) {
  using std::swap;
  swap(this->head_, other.head_);
  swap(this->tail_, other.tail_);
  swap(this->size_, other.size_);
  swap(this->end_, other.end_);
}*/
template <typename T>
void list<T>::swap(list& other) {
  std::swap(this->head_, other.head_);
  std::swap(this->tail_, other.tail_);
  std::swap(this->size_, other.size_);
  // std::swap(this->end_, other.end_);
}

// template <typename T>
// void list<T>::merge(list& other) {
//   if (!this->empty() && !other.empty()) {
//     iterator iter_this = this->begin();
//     iterator iter_other = other.begin();
//     while (iter_this != this->end()) {
//       if (iter_other != other.end()) {
//         if (iter_this.ptr_->value_ >= iter_other.ptr_->value_) {
//           this->insert(iter_this, iter_other.ptr_->value_);
//           iter_other++;
//         } else {
// iter_this++;
//         }
//       } else {
//         break;
//       }
//     }
//     while (iter_other != other.end()) {
//       this->insert(iter_this, iter_other.ptr_->value_);
//       iter_other++;
//     }
//   } else if (this->empty() && !other.empty()) {
//     this->copy(other);
//   }
//   other.clear();
// }

// // template <typename value_type>
// // void list<value_type>::reverse() {
// //   if (!this->empty()) {
// //     size_type step = 0;
// //     for (iterator it = this->begin(); step <= this->size(); ++it) {
// //       step++;
// //       std::swap(it.ptr_->prev_, it.ptr_->next_);
// //     }
// //     std::swap(head_, tail_);
// //   }
// // }

/* template <typename value_type>
void list<value_type>::unique() {
  if (!this->empty()) {
    for (iterator it = this->begin(); it != this->end(); it++) {
      if (it.ptr_->value_ == it.ptr_->prev_->value_) {
        iterator del_it = (it - 1);
        this->erase(del_it);
      }
    }
  }
}*/
template <typename T>
void list<T>::unique() {
if (!empty()) {
  for (iterator it = begin(); it != end(); it++) {
    if (it.ptr_->value_ == it.ptr_->prev_->value_) {
      iterator del_it = (it - 1);
      erase(del_it);
    }
  }
}
// if (size_ > 1) {
//   Node* my_node = head_;
//   while (my_node != tail_) {
//     Node* run_node = my_node->next_;
//     while (run_node != tail_) {
//       if (my_node->value_ == run_node->value_) {
//         run_node->prev_->next_ = run_node->next_;
//         run_node->next_->prev_ = run_node->prev_;
//         // delete run_node;
//         size_--;
//       }
//       run_node = run_node->next_;
//     }
//     if (tail_->value_ == tail_->prev_->value_) pop_back();
//     my_node = my_node->next_;
//   }
// }
}

// template <typename value_type>
// void list<value_type>::splice(const_iterator pos, list& other) {
//   if (!other.empty()) {
//     for (iterator it = other.begin(); it != other.end(); ++it) {
//       this->insert(pos, *it);
//     }
//     other.clear();
//   }
// }

/*template <typename value_type>
void list<value_type>::sort() {
  if (size_ > 1) {
    quick_sort(begin(), --end());
  }
}*/
template <typename T>
void list<T>::sort() {
  if (size_ > 1) {
    for (int j = 0; j < size_; j++) {
      Node* my_node = head_;
      while (my_node != tail_) {
        if (my_node->value_ > my_node->next_->value_)
          std::swap(my_node->value_, my_node->next_->value_);
        my_node = my_node->next_;
      }
    }
  }
}

// --------------------------------------------------------------------iterators

// template <typename T>
// list<T>::ListIterator::ListIterator(){};

template <typename T>
list<T>::listIterator::listIterator(Node* ptr) : ptr_(ptr) {}

template <typename T>
typename list<T>::reference list<T>::listIterator::operator*() {
  return ptr_->value_;
}

template <typename T>
typename list<T>::listIterator& list<T>::listIterator::operator++(int) {
  listIterator it = *this;
  ptr_ = ptr_->next_;
  return it;
}

template <typename T>
typename list<T>::listIterator& list<T>::listIterator::operator--(int) {
  listIterator it = *this;
  ptr_ = ptr_->prev_;
  return it;
}

template <typename T>
typename list<T>::listIterator& list<T>::listIterator::operator++() {
  // ++ptr_;
  ptr_ = ptr_->next_;
  return *this;
}

template <typename T>
typename list<T>::listIterator& list<T>::listIterator::operator--() {
  // --ptr_;
  ptr_ = ptr_->prev_;
  return *this;
}
/*
template <typename T>
typename list<T>::listIterator list<T>::listIterator::operator-(int n) const {
  listIterator tmp(*this);
  for (int i = 0; i < n; i++) --tmp;
  return tmp;
}

template <typename T>
typename list<T>::listIterator list<T>::listIterator::operator+(int n) const {
  // listIterator tmp(*this);
  // for (int i = 0; i < n; i++) ++tmp;
  // return tmp;
}*/

template <typename T>
bool list<T>::listIterator::operator==(const listIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool list<T>::listIterator::operator!=(const listIterator& other) const {
  return !(ptr_ == other.ptr_);
}

// template <typename T>
// ptrdiff_t list<T>::listIterator::operator-(const listIterator& other) const {
//   // return ptr_ - other.ptr_;
// }
// Support
// template <typename value_type>
// void list<value_type>::change_end() {
//   if (end_) {
//     end_->next_ = head_;
//     end_->prev_ = tail_;
//     end_->value_ = size();
//     if (head_) {
//       head_->prev_ = end_;
//     }
//     if (tail_) {
//       tail_->next_ = end_;
//     }
//   }
// }

// template <typename value_type>
// void list<value_type>::quick_sort(iterator first, iterator last) {
//   if (first == last || first == end_ || last == end_ || first == tail_) {
//     return;
//   }
//   iterator pivot = partition(first, last);
//   quick_sort(first, --pivot);
//   quick_sort(++pivot, last);
// }

// template <typename value_type>
// typename list<value_type>::iterator list<value_type>::partition(iterator
// first,
//                                                                 iterator
//                                                                 last) {
//   value_type pivot_value = last.ptr_->value_;
//   iterator i = first;

//   for (iterator j = first; j != last; ++j) {
//     if (j.ptr_->value_ <= pivot_value) {
//       std::swap(i.ptr_->value_, j.ptr_->value_);
//       i++;
//     }
//   }

//   std::swap(i.ptr_->value_, last.ptr_->value_);

//   return i;
// }

// template <typename value_type>
// void list<value_type>::print_list() {
//   std::cout << "[";
//   for (iterator it = begin(); it != end(); ++it) {
//     std::cout << *it;
//     if ((it + 1) != end()) {
//       std::cout << ", ";
//     }
//   }
//   std::cout << "]\n";
// }

// template <typename T>
// void list<T>::copy(const list& l) {
//   Node* current = l.head_;
//   for (size_type i = 0; i != l.size_; i++) {
//     push_back(current->value_);
//     current = current->next_;
//   }
// }
}  // namespace s21

int main() {
  s21::list<int> my_list{1, 2, 3, 1,1,1,1,1,2,2,2,3,3,3,1,2,2,1};
  // s21::list<int> my_list_copy(my_list);
my_list.unique();
  s21::list<int>::Node* my_node = my_list.head_;

  if (my_list.empty())
    std::cout << "[ ]\n";
  else {
    std::cout << "[";
    while (my_node != my_list.tail_) {
      std::cout << my_node->value_ << " ";
      my_node = my_node->next_;
    }
    std::cout << my_node->value_;

    std::cout << "]\n";
  }
}