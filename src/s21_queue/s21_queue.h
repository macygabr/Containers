#ifndef QUEUE_H
#define QUEUE_H

namespace s21 {

template <typename T>
class queue :list{
 public:
  class queueIterator;
  class queueConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  //   using iterator =
  //   queue<T>::queueIterator;-------------------------------------- using
  //   const_iterator = queue<T>::queueConstIterator;
  using size_type = std::size_t;
  //   using iterator_pointer = T *;
  //   using const_iterator_pointer = const T *;

  queue();  // default constructor, creates empty queue
  queue(std::initializer_queue<value_type> const
            &items);      // initializer queue constructor, creates queue
                          // initizialized using std::initializer_queue
  queue(const queue &q);  //	copy constructor
  queue(queue &&q);       //	move constructor
  ~queue();               //	destructor
  queue &operator=(
      queue &&q);  //	assignment operator overload for moving object

//   const_reference front() const;  // access the first element
//   const_reference back() const;   // access the last element

//   bool empty() const;      // checks whether the container is empty
//   size_type size() const;  // returns the number of elements

  void push(const_reference value);  // inserts element at the end
  void pop();                        // removes the first element
//   void swap(queue &other);           //	swaps the contents

//   void insert_many_back(
      Args &&...args);  // appends new elements to the end of the container

  //  private:
 public:
  iterator_pointer data_;
  size_type size_;
  size_type capacity_;
};

}  // namespace s21

#endif  // QUEUE_H