#include <algorithm>
#include <iostream>
#include <stdexcept>
class MojNizInt {
  size_t size_;
  int *data_;

public:
  MojNizInt() : size_(0), data_(nullptr) {}

  MojNizInt(std::initializer_list<int> l) : size_(l.size()) {
    data_ = new int[size_];
    size_t i = 0;
    for (const int &e : l) {
      data_[i] = e;
      ++i;
    }
  }

  MojNizInt(const MojNizInt &old) : size_(old.size_) {
    data_ = new int[old.size_];
    for (int i = 0; i < old.size_; ++i) {
      data_[i] = old.data_[i];
    }
  }

  MojNizInt(MojNizInt &&old) : data_(old.data_), size_(old.size_) {
    old.data_ = nullptr;
    old.size_ = 0;
  }

  MojNizInt operator=(const MojNizInt &old) {
    delete[] data_;
    data_ = new int[old.size_];
    for (int i = 0; i < old.size_; ++i) {
      data_[i] = old.data_[i];
    }
    size_ = old.size_;
    return *this;
  }

  MojNizInt operator=(MojNizInt &&old) {
    delete[] data_;
    data_ = old.data_;
    size_ = old.size_;
    old.data_ = nullptr;
    old.size_ = 0;
    return *this;
  }

  ~MojNizInt() { delete[] data_; }

  int &operator[](size_t index) const { return data_[index]; }

  MojNizInt operator*(int scalar) const {
    MojNizInt novi;
    novi.data_ = new int[size_];
    for (int i = 0; i < size_; ++i) {
      novi.data_[i] = data_[i] * scalar;
    }
    novi.size_ = size_;
    return novi;
  }

  MojNizInt operator+(const MojNizInt &drugi) const {
    if (size_ != drugi.size_) {
      throw std::invalid_argument("Array sizes don't match!");
    }
    MojNizInt suma;
    suma.data_ = new int[size_];
    for (int i = 0; i < size_; ++i) {
      suma.data_[i] = data_[i] + drugi.data_[i];
    }
    suma.size_ = size_;
    return suma;
  }

  MojNizInt operator++(int) {
    MojNizInt old(*this);
    for (int i = 0; i < size_; ++i) {
      data_[i] += 1;
    }
    return old;
  }

  MojNizInt &operator++() {
    for (int i = 0; i < size_; ++i) {
      data_[i] += 1;
    }
    return *this;
  }

  void push_back(int x) {
    int *new_data = new int[size_ + 1];
    std::copy(data_, data_ + size_, new_data);
    new_data[size_] = x;
    delete[] data_;
    data_ = new_data;
    ++size_;
  }

  size_t size() const { return size_; }

  int &at(size_t index) const {
    if (index > size_ - 1 || size_ == 0) {
      throw std::out_of_range("Index out of range!");
    }
    return *(data_ + index);
  }
};
