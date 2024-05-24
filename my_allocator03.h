#pragma once
#include <iostream>
#include <limits>
#include <memory>

/**
 * С++03
 * Аллокатор работает с фиксированным количеством элементов.
 * Попытку выделить большее число элементов считать ошибкой.
 *
 * с с++11 и больше выпадает в корку
 *
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
  ~MyAllocator03()
  {
    std::cout << "dtor " << std::endl;
  };
  MyAllocator03()
  {
    std::cout << "tor " << std::endl;
  };
  template <typename U, int N1>
  MyAllocator03(const MyAllocator03<U, N1> &u) {}
  /**
   * allocate memory
   */
  pointer allocate(size_type n)
  {
    std::cout << "next " << next << " n " << n << " next + n " << next + n << std::endl;
    if (n > N || next + n > N)
      throw std::bad_alloc();
    next += n;
    return &(ptr[next]);
  }

  /**
   * deallocate memory
   */
  void deallocate(pointer p, size_type n) {};

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

private:
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
  return false;
}

template <class T, int N, class U, int N1>
bool operator!=(MyAllocator03<T, N> const &x, MyAllocator03<U, N1> const &y)
{
  return true;
}
