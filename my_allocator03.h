#pragma once
#include <memory>
#include <iostream>

template <typename T>
struct MyAllocator03
{
public:
  using value_type = T;
  //using size_type = std::size_t;
  //using pointer = T *;
  //using const_pointer = const T *;
  //using reference = T &;
  //using const_reference = const T &;

  MyAllocator03() noexcept
  {
    std::cout << "MyAllocator03 \n";
  };

  ~MyAllocator03() noexcept
  {
    std::cout << "~MyAllocator03 \n";
  };

  template <typename U>
  MyAllocator03(const MyAllocator03<U> &) noexcept
  {
    std::cout << "MyAllocator03& \n";
  };

  /**
   * @param size number of T object
   */
  T *allocate(size_t size)
  {
    std::cout << "allocate " << size << "\n";
    void *ptr = new T[sizeof(T) * size];
    if (ptr == nullptr)
      throw std::bad_alloc{};

    return static_cast<T *>(ptr);
  };

  void deallocate(T *ptr, size_t size)
  {
    std::cout << "deallocate " << size << "\n";
    if (ptr == nullptr)
      return;

    delete[] (ptr);
  };

  // template <typename U>
  // struct rebind
  // {
  //   typedef MyAllocator03<U> other;
  // };
};

// template <typename T, typename U>
// constexpr bool operator==(const MyAllocator03<T> &,
//                           const MyAllocator03<U> &) noexcept {
//   return true
// };

// template <typename T, typename U>
// constexpr bool operator!=(const MyAllocator03<T> &,
//                           const MyAllocator03<U> &) noexcept
// {
//   return false;
// };