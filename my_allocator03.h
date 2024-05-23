#pragma once
#include <iostream>
#include <limits>
#include <memory>

template <typename T, std::size_t N> struct MyAllocator03;

template <> struct MyAllocator03<void, 0> {
  typedef void value_type;
  typedef value_type *pointer;
  typedef value_type const *const_pointer;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  template <typename U> struct rebind { typedef MyAllocator03<U, 0> other; };
};

template <typename T, std::size_t N> struct MyAllocator03 {
  typedef T value_type;
  typedef T *pointer;
  typedef const T *const_pointer;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  template <typename U> struct rebind { typedef MyAllocator03<U, N> other; };

  MyAllocator03() throw(){};

  template <typename U, std::size_t N1>
  MyAllocator03(MyAllocator03<U, N1> const &u) throw(){};

  /**
   * allocate memory
   */
  pointer allocate(size_type n, MyAllocator03<void, 0>::const_pointer = 0) {
    return static_cast<pointer>(::operator new(n * sizeof(value_type)));
  }

  /**
   * deallocate memory
   */
  void deallocate(pointer p, size_type) { ::operator delete(p); };

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

  pointer address(reference x) const { return &x; };

  const_pointer address(const_reference x) const { return &x; };

  size_type max_size() const throw() {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  };
};

template <class T, std::size_t N, class U, std::size_t N1>
bool operator==(MyAllocator03<T, N> const &, MyAllocator03<U, N1> const &) {
  return true;
}

template <class T, std::size_t N, class U,  std::size_t N1>
bool operator!=(MyAllocator03<T,N> const &x, MyAllocator03<U,N1> const &y) {
  return !(x == y);
}
