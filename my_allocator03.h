#pragma once
#include <iostream>
#include <limits>
#include <memory>

template <typename T, int N>
struct MyAllocator03;

template <>
struct MyAllocator03<void, 0>
{
  typedef void value_type;
  typedef value_type *pointer;
  typedef value_type const *const_pointer;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  template <typename U>
  struct rebind
  {
    typedef MyAllocator03<U, 0> other;
  };
};
/**
 * С++03
 * Аллокатор работает с фиксированным количеством элементов.
 * Попытку выделить большее число элементов считать ошибкой.
 * @param N кол-во элементов
 */
template <typename T, int N>
class MyAllocator03
{
public:
  typedef T value_type;
  typedef T *pointer;
  typedef const T *const_pointer;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  template <typename U>
  struct rebind
  {
    typedef MyAllocator03<U, N> other;
  };
  ~MyAllocator03(){};
  MyAllocator03(){};
  template <typename U, int N1>
  MyAllocator03(MyAllocator03<U, N1> const &u){};
  /**
   * allocate memory
   */
  pointer allocate(size_type n)
  {
    if (n > N || next + n > N)
      throw std::bad_alloc();
    next += n;
    return &(ptr[next]);
  }

  /**
   * deallocate memory
   */
  void deallocate(pointer p, size_type n) {
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
  void destroy(pointer p)
  {
    p->~value_type();
  };

  pointer address(reference x) const { return &x; };

  const_pointer address(const_reference x) const { return &x; };

  /**
   * @return number of object
   */
  size_type max_size() const throw()
  {
    return N;
  };

  static value_type ptr[N];
  static int next;
};
/*
 * хорошо бы еще понять что я тут делаю
 */
template <class T, int N>
T MyAllocator03<T, N>::ptr[N] = {};

/*
 * хорошо бы еще понять что я тут делаю
 */
template <class T, int N>
int MyAllocator03<T, N>::next = 0;

template <class T, int N, class U, int N1>
bool operator==(MyAllocator03<T, N> const &, MyAllocator03<U, N1> const &)
{
  return (N == N1);
}

template <class T, int N, class U, int N1>
bool operator!=(MyAllocator03<T, N> const &x, MyAllocator03<U, N1> const &y)
{
  return !(N == N1 && x == y);
}
