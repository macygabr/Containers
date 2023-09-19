#include "s21_vector.h"

#include <iostream>
#include <vector>
// --------------------------------------------------------------------Functions
namespace s21 {

template <typename T>
vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, value_type());  // заполнение
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const& items) {
  capacity_ = size_ = items.size();
  if (items.size() != 0) {
    data_ = new value_type[size_];
    std::copy(items.begin(), items.end(), data_);
  } else
    data_ = nullptr;
}

template <typename T>
vector<T>::vector(const vector& v) : size_(v.size_), capacity_(v.capacity_) {
  if (data_) delete[] data_;
  data_ = new value_type[size_];
  for (size_type i = 0; i < size_; i++) {
    data_[i] = v.data_[i];
  }
}  // copy constructor

// moving

template <typename T>
vector<T>::vector(vector&& v) {
  v = std::move(this);
}

template <typename T>
vector<T>::~vector() {
  if (data_) delete[] data_;
  data_ = nullptr;
  size_ = capacity_ = 0;
}

template <typename T>
bool vector<T>::empty() {
  return (size_ == 0);
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
}

template <class value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_type pos) {
  return data_[pos];
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size < 0 || size > max_size())
    throw std::out_of_range("Index out of range");
  if (size <= size_) return;
  if (size > size_) {
    capacity_ = size;
    value_type* tmp = data_;
    data_ = new value_type[size];
    for (size_t i = 0; i < size_; ++i) data_[i] = tmp[i];
    delete[] tmp;
  }
}

template <typename T>
void vector<T>::shrink_to_fit() {
  capacity_ = size_;
  value_type* tmp = data_;
  data_ = new value_type[size_];
  for (size_t i = 0; i < size_; ++i) data_[i] = tmp[i];
  delete[] tmp;
}

template <typename T>
void vector<T>::clear() {
  size_ = 0;
}

}  // namespace s21
using namespace s21;
int main() {
  s21::vector<float> v{1, 2, 3, 4, 5};
  std::cout << v.size() << std::endl;
  std::cout << v.capacity() << std::endl;
  for (int i = 0; i < v.capacity(); i++) std::cout << v[i] << " ";
  std::cout << "\n";
  v.reserve(9);
  v.shrink_to_fit();
  std::cout << v.size() << std::endl;
  std::cout << v.capacity() << std::endl;
  for (int i = 0; i < v.capacity(); i++) std::cout << v[i] << " ";
  // std::cout << "\n";

  // s21::vector<float> A(0);
  // if (A.empty())
  //   std::cout << "em";
  // else
  //   std::cout << "not em";
}
