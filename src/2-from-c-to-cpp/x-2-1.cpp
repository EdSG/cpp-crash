#include <iostream>

int main(int argc, char *argv[], char *envp[])
{
  char * char_ptr = new char;
  char * const char_const_ptr = char_ptr;
  const char * const_char_ptr = char_ptr;
  const char * const const_char_const_ptr = char_const_ptr;
  char & char_ref = *char_const_ptr;
  const char & const_char_ref = *const_char_const_ptr;

  if ( *const_char_ptr == char_ref)
  {
    std::cout << "*const_char_ptr == char_ref" << std::endl;
  }

  if ( *const_char_ptr == const_char_ref )
  {
    std::cout << "*const_char_ptr == const_char_ref" << std::endl;
  }

  return 0;
}

