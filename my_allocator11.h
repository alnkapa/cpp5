#pragma once
#include <algorithm>
#include <cstring>
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
template <typename T, int N>
class MyAllocator17
{
public:
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using reference = T &;
  using const_reference = const T &;
  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;
  template <typename U>
  struct rebind
  {
    typedef MyAllocator17<U, N> other;
  };
  MyAllocator17() { m_store.reserve(N); };
  template <typename U, int N1>
  MyAllocator17(const MyAllocator17<U, N1> &u) {}
  ~MyAllocator17()
  {
    m_free.clear();
    m_store.clear();
  };

  /**
   * allocate memory
   */
  pointer allocate(size_type n)
  {
    if (n > 1)
    {
      throw std::bad_alloc();
    }
    if (!m_free.empty())
    {
      auto index = m_free.back();
      m_free.pop_back();
      return &m_store[index];
    }
    else
    {
      m_store.emplace_back();
      return &m_store.back();
    }
  }
  /**
   * deallocate memory
   */
  void deallocate(pointer p, size_type n)
  {
    if (n > 1)
    {
      throw std::bad_alloc();
    }
    for (size_t i = 0; i < m_store.size(); i++)
    {
      if (&m_store[i] == p)
      {
        m_free.push_back(i);
        break;
      }
    }
  };
  /**
   * call object constructor
   */
  void construct(pointer p, value_type const &val)
  {
    ::new (p) value_type(val);
  }
  /**
   * call object destructor
   */
  void destroy(pointer p) { p->~value_type(); };
  size_type max_size() const throw()
  {
    return std::numeric_limits<size_type>::max();
  };

private:
  std::vector<int> m_free{};
  std::vector<value_type> m_store{};
};

template <class T, int N, class U, int N1>
bool operator==(MyAllocator17<T, N> const &, MyAllocator17<U, N1> const &)
{
  return (N == N1);
}

template <class T, int N, class U, int N1>
bool operator!=(MyAllocator17<T, N> const &x, MyAllocator17<U, N1> const &y)
{
  return !(N == N1 && x == y);
}
