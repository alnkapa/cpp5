#pragma once
#include <iostream>
#include <limits>
#include <memory>

template <typename T, int N>
struct MyAllocator11;

template <>
struct MyAllocator11<void, 0>
{
  typedef void value_type;
  typedef value_type *pointer;
  typedef value_type const *const_pointer;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  template <typename U>
  struct rebind
  {
    typedef MyAllocator11<U, 0> other;
  };
};
/**
 * С++03
 * Аллокатор работает с фиксированным количеством элементов.
 * Попытку выделить большее число элементов считать ошибкой.
 * @param N кол-во элементов
 */
template <typename T, int N>
class MyAllocator11
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
    typedef MyAllocator11<U, N> other;
  };
  ~MyAllocator11()
  {
    std::cout << "dtor " << std::endl;
  };
  MyAllocator11()
  {
    std::cout << "tor " << std::endl;
  };
  template <typename U, int N1>
  MyAllocator11(MyAllocator11<U, N1> const &u) {}
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
T MyAllocator11<T, N>::ptr[N] = {};

/*
 * хорошо бы еще понять что я тут делаю
 */
template <class T, int N>
int MyAllocator11<T, N>::next = 0;

template <class T, int N, class U, int N1>
bool operator==(MyAllocator11<T, N> const &, MyAllocator11<U, N1> const &)
{
  return (N == N1);
}

template <class T, int N, class U, int N1>
bool operator!=(MyAllocator11<T, N> const &x, MyAllocator11<U, N1> const &y)
{
  return !(N == N1 && x == y);
}
