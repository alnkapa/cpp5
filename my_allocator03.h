#pragma once
#include <iostream>
#include <limits>
#include <memory>

template <typename T, typename U>
struct is_same
{
  static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
  static const bool value = true;
};

template <typename T, typename U>
struct if_same_enable
{
};

template <typename T>
struct if_same_enable<T, T>
{
  typedef void type;
};
/**
 * С++03
 * Аллокатор работает с фиксированным количеством элементов.
 * Попытку выделить большее число элементов считать ошибкой.
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
  /**
   * destruct allocator
   */
  ~MyAllocator03()
  {
    MyAllocator03<T, N>::m_next = 0;
  };
  /**
   * construct allocator
   * !!! not call allocate !!!
   */
  MyAllocator03()
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    MyAllocator03<T, N>::m_next = 0;
  };
  /**
   * construct allocator element
   * call allocate
   */
  template <typename U, int N1>
  MyAllocator03(const MyAllocator03<U, N1> &u)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "ctor" << std::endl;
  }
  /**
   * allocate memory
   */
  pointer allocate(size_type n)
  {
    std::cout << "allocate: " << n << std::endl;
    if (n > 1)
    {
      throw std::bad_alloc();
    }
    if (n > N || m_next + n > N)
    {
      throw std::bad_alloc();
    }
    pointer result = m_ptr + m_next;
    m_next += n;
    return result;
  }
  /**
   * deallocate memory
   */
  void deallocate(pointer p, size_type n)
  {
    std::cout << "deallocate: " << std::endl;
  };

  /**
   * call object constructor
   */
  void construct(pointer p, value_type const &val)
  {
    std::cout << "construct: " << std::endl;
    ::new (p) value_type(val);
  }
  /**
   * call object destructor
   */
  void destroy(pointer p)
  {
    std::cout << "deallocate: " << std::endl;
    p->~value_type();
  };

  size_type max_size() const throw()
  {
    std::cout << "max_size: " << std::endl;
    return N;
  };

private:
  static value_type m_ptr[N];
  static int m_next;
};

template <class T, int N>
T MyAllocator03<T, N>::m_ptr[N] = {};
template <class T, int N>
int MyAllocator03<T, N>::m_next = 0;

template <class T, int N, class U, int N1>
bool operator==(MyAllocator03<T, N> const &, MyAllocator03<U, N1> const &)
{
  std::cout << "==" << std::endl;
  return N == N1 && is_same<T, U>::value;
}

template <class T, int N, class U, int N1>
bool operator!=(MyAllocator03<T, N> const &x, MyAllocator03<U, N1> const &y)
{
  std::cout << "!=" << std::endl;
  return !(x == y);
}
