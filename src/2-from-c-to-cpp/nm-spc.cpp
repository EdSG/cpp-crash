#include <iostream>

namespace first  { int var = 5; }
namespace second { int var = 3; }

int main(int argc, char *argv[], char *envp[])
{
  std::cout
    << first::var  << std::endl
    << second::var << std::endl;

  return 0;
}

