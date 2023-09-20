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
//---------------------------------------------------------------------
template <typename T>                            //
vector<T>::vector(const vector& v)               //
    : data_(new value_type[v.capacity_]),        //
      size_(v.size_),                            //
      capacity_(v.capacity_) {                   //
  std::copy(v.data_, v.data_ + v.size_, data_);  //
}
//---------------------------------------------------------------------
template <typename T>  //
vector<T>::vector(vector&& v) {
  size_ = std::exchange(v.size_, 0);
  capacity_ = std::exchange(v.capacity_, 0);
  data_ = std::exchange(v.data_, nullptr);
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
//---------------------------------------------------------------------
template <typename T>                             //
vector<T>& vector<T>::operator=(vector<T>&& v) {  //
  if (this != &v) {                               //
    this->swap(v);                                //
    delete[] v.data_;                             //
    v.size_ = 0;                                  //
    v.capacity_ = 0;                              //
    v.data_ = nullptr;                            //
  }                                               //
  return *this;                                   //
}
//---------------------------------------------------------------------
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return const_iterator(data_);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return const_iterator(data_ + size_);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size < 0 || size > max_size())
    throw std::out_of_range("reserve: Index out of range");
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
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) reserve(size_ + 1);
  data_[size_] = value;
  size_++;
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) size_--;
}

template <typename T>
void vector<T>::swap(vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
void vector<T>::clear() {
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type idx = pos - begin();
  if (size_ == capacity_) reserve(size_ + 1);
  iterator new_pos = begin() + idx;
  for (iterator it = end(); it != new_pos; --it) *it = *(it - 1);
  *new_pos = value;
  ++size_;
  return new_pos;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_type position = pos - begin();
  if (position < 0 || position >= size_)
    throw std::out_of_range("erase: Index out of range");
  for (iterator i = pos; i != end(); ++i) *i = *(i + 1);
  --size_;
}
//--------------------------------------------------------
//-----------------------------------------iterators-----------------------------------------

template <typename T>
vector<T>::VectorIterator::VectorIterator(iterator_pointer ptr) : ptr_(ptr) {}

template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator++(int) {
  VectorIterator tmp(*this);
  ++tmp;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator--(int) {
  VectorIterator tmp(*this);
  --tmp;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(
    int n) const {
  VectorIterator tmp(*this);
  for (int i = 0; i < n; i++) --tmp;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(
    int n) const {
  VectorIterator tmp(*this);
  for (int i = 0; i < n; i++) ++tmp;
  return tmp;
}

template <typename T>
bool vector<T>::VectorIterator::operator==(const VectorIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator!=(const VectorIterator& other) const {
  return !(ptr_ == other.ptr_);
}

template <typename T>
ptrdiff_t vector<T>::VectorIterator::operator-(
    const VectorIterator& other) const {
  return ptr_ - other.ptr_;
}

//-------------------------------const iterators------------------------------

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(const_iterator_pointer ptr)
    : ptr_(ptr) {}

template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorConstIterator&
vector<T>::VectorConstIterator::operator++(int) {
  VectorConstIterator tmp(*this);
  ++tmp;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator&
vector<T>::VectorConstIterator::operator--(int) {
  VectorConstIterator tmp(*this);
  --tmp;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator&
vector<T>::VectorConstIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorConstIterator&
vector<T>::VectorConstIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator-(int n) const {
  VectorConstIterator tmp(*this);
  for (int i = 0; i < n; i++) --tmp;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator+(int n) const {
  VectorConstIterator tmp(*this);
  for (int i = 0; i < n; i++) ++tmp;
  return tmp;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator& other) const {
  return !(ptr_ == other.ptr_);
}

template <typename T>
ptrdiff_t vector<T>::VectorConstIterator::operator-(
    const VectorConstIterator& other) const {
  return ptr_ - other.ptr_;
}

//---------------------------INSERT MANY-----------------------------------

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args&&... args) {
  vector<value_type> tmp{args...};
  iterator cur_pos = begin() + (pos - cbegin());
  for (size_t i = 0; i < tmp.size(); ++i) {
    cur_pos = insert(cur_pos, tmp[i]);
    ++cur_pos;
  }
  return cur_pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args&&... args) {
  insert_many(cend(), args...);
}

}  // namespace s21
using namespace s21;
int main() {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v3(v1);
  s21::vector<int> v2(std::move(v1));
  for (int i = 0; i < v1.size(); i++) std::cout << v1[i] << " ";
    std::cout << "\n";
  for (int i = 0; i < v2.size(); i++) std::cout << v2[i] << " ";
    std::cout << "\n";
  for (int i = 0; i < v3.size(); i++) std::cout << v3[i] << " ";
}
