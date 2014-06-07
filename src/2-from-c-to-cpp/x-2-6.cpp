#include <iostream>

int main(int argc, char* argv[], char* envp[])
{
  int * ptr1 = new int;
  int * ptr2 = new int;
  int const * const_ptr = ptr1;
  int * const ptr_const = ptr1;
  int const * const const_ptr_const = ptr1;

  *ptr1 = 1;
  *ptr2 = 2;

  std::cout << ptr1 << ':' << *ptr1 << '\t'
            << ptr2 << ':' << *ptr2 << '\t' << std::endl
            << const_ptr << ':' << *const_ptr << '\t'
            << ptr_const << ':' << *ptr_const << '\t'
            << const_ptr_const << ':' << *const_ptr_const << std::endl
            << std::endl;

  const_ptr = ptr2;
  //*const_ptr = 4;

  std::cout << ptr1 << ':' << *ptr1 << '\t'
            << ptr2 << ':' << *ptr2 << '\t' << std::endl
            << const_ptr << ':' << *const_ptr << '\t'
            << ptr_const << ':' << *ptr_const << '\t'
            << const_ptr_const << ':' << *const_ptr_const << std::endl
            << std::endl;

  //ptr_const = ptr2;
  *ptr_const = 6;

  std::cout << ptr1 << ':' << *ptr1 << '\t'
            << ptr2 << ':' << *ptr2 << '\t' << std::endl
            << const_ptr << ':' << *const_ptr << '\t'
            << ptr_const << ':' << *ptr_const << '\t'
            << const_ptr_const << ':' << *const_ptr_const << std::endl
            << std::endl;

  //const_ptr_const = ptr2;
  //*const_ptr_const = 8;

  std::cout << ptr1 << ':' << *ptr1 << '\t'
            << ptr2 << ':' << *ptr2 << '\t' << std::endl
            << const_ptr << ':' << *const_ptr << '\t'
            << ptr_const << ':' << *ptr_const << '\t'
            << const_ptr_const << ':' << *const_ptr_const << std::endl
            << std::endl;
  return 0;
}
