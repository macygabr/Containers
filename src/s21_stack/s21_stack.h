#ifndef STACK_H
#define STACK_H

namespace s21 {

template <typename T>
class stack {
 public:
  class stackIterator;
  class stackConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  //   using iterator = stack<T>::stackIterator;
  //   using const_iterator = stack<T>::stackConstIterator;
  using size_type = std::size_t;
  //   using iterator_pointer = T *;
  //   using const_iterator_pointer = const T *;

  stack();  // default constructor, creates empty stack
  stack(std::initializer_stack<value_type> const
            &items);  // initializer stack constructor, creates stack
                      // initizialized using std::initializer_stack
  stack(const stack &s);  //	copy constructor
  stack(stack &&s);       //	move constructor
  ~stack();               //	destructor
  stack &operator=(
      stack &&s);  //	assignment operator overload for moving object

  const_reference top();  //	accesses the top element

  // bool empty() const;      // checks whether the container is empty
  // size_type size() const;  // returns the number of elements

  void push(const_reference value);  // inserts element at the top
  void pop();                        // removes the top element
  // void swap(queue &other);           //	swaps the contents

  // void insert_many_front(
      Args &&...args);  // void insert_many_front(Args&&... args)

  //  private:
 public:
  iterator_pointer data_;
  size_type size_;
  size_type capacity_;
};

}  // namespace s21

#endif  // STACK_H