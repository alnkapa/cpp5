#pragma once
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

/**
 * С++17
 * Аллокатор работает с фиксированным количеством элементов.
 * При попытке выделить число элементов,
 * которое превышает текущее зарезервированное количество,
 * аллокатор расширяет зарезервированную память.
 * реализовать поэлементное освобождение
 * @param N кол-во элементов
 */
template <typename T, int N> class MyAllocator17 {
public:
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using reference = T &;
  using const_reference = const T &;
  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;
  template <typename U> struct rebind { typedef MyAllocator17<U, N> other; };
  MyAllocator17() { m_store.reserve(N); };
  template <typename U, int N1> MyAllocator17(const MyAllocator17<U, N1> &u) {}
  ~MyAllocator17() {
    for (auto &&p : m_store) {
      if (p) {
        ::operator delete(p);
      }
    }
  };

  /**
   * allocate memory
   */
  pointer allocate(size_type n) {
    pointer result =
        static_cast<pointer>(::operator new(sizeof(value_type) * n));
    auto it = std::find(m_store.begin(), m_store.end(), nullptr);
    if (it != m_store.end()) {
      *it = result;
    } else {
      m_store.push_back(result);
    }
    return result;
  }
  /**
   * deallocate memory
   */
  void deallocate(pointer p, size_type n) {
    auto it = std::find(m_store.begin(), m_store.end(), p);
    if (it != m_store.end()) {
      ::operator delete(p);
      *it = nullptr;
    }
  };
  /**
   * call object constructor
   */
  void construct(pointer p, value_type const &val) {
    ::new (p) value_type(val);
  }
  /**
   * call object destructor
   */
  void destroy(pointer p) { p->~value_type(); };
  size_type max_size() const throw() {
    return std::numeric_limits<size_type>::max();
  };

private:
  std::vector<pointer> m_store{};
};

template <class T, int N, class U, int N1>
bool operator==(MyAllocator17<T, N> const &, MyAllocator17<U, N1> const &) {
  return (N == N1);
}

template <class T, int N, class U, int N1>
bool operator!=(MyAllocator17<T, N> const &x, MyAllocator17<U, N1> const &y) {
  return !(N == N1 && x == y);
}
