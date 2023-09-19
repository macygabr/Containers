#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <stdexcept>
#include <utility>

namespace s21 {

// template <typename T>

template <typename T>
class vector {
 public:
  class VectorIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = vector<T>::VectorIterator;
  using size_type = size_t;
  using iterator_pointer = T *;
  using const_iterator = vector<T>::VectorConstIterator;

  vector();
  vector(std::size_t n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  // moving
  vector(vector &&v);
  ~vector();
  //eqv
  vector &operator=(vector &&v);

  // reference at(size_type pos)
  reference operator[](size_type pos);
  // const_reference front()
  // const_reference back()
  // T* data()

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear()
  iterator insert(iterator pos, const_reference value);
  // void erase(iterator pos)
  // void push_back(const_reference value)
  // void pop_back()
  // void swap(vector& other)

  //  private:
 public:
  iterator_pointer data_;
  size_type size_;
  size_type capacity_;
};
/*
template <typename value_type>
class vector<value_type>::VectorIterator {
 public:
    VectorIterator() = default;
  VectorIterator(pointer ptr);

  reference operator*();
  VectorIterator& operator++();
  VectorIterator& operator--();
  VectorIterator operator++(int);
  VectorIterator operator--(int);
  bool operator==(const VectorIterator& other) const;
  bool operator!=(const VectorIterator& other) const;
  VectorIterator operator+(int n) const;
  VectorIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorIterator& other) const;

 private:
  pointer ptr_;
};

template <typename value_type>
class vector<value_type>::VectorConstIterator : public VectorIterator {
 public:
    VectorConstIterator() = default;
  VectorConstIterator(const_pointer ptr);

  const_reference operator*() const;
  VectorConstIterator& operator++();
  VectorConstIterator& operator--();
  VectorConstIterator operator++(int);
  VectorConstIterator operator--(int);
  bool operator==(const VectorConstIterator& other) const;
  bool operator!=(const VectorConstIterator& other) const;
  VectorConstIterator operator+(int n) const;
  VectorConstIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorConstIterator& other) const;

 private:
  const_pointer ptr_;
};
*/

}  // namespace s21
#endif  // VECTOR_H