#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[], char *envp[])
{
  size_t length = -1;

  std::cout << "Before 'try'" << std::endl;

  try
  {
    std::cout << "Before 'new'" << std::endl;
    float* array = new float[length * sizeof(float)];
    std::cout << "After 'new'" << std::endl;
  }
  catch(std::bad_alloc bae)
  {
    std::cerr << "Inside 'catch': " << bae.what() << std::endl;
  }

  std::cout << "After 'try'" << std::endl;

  return 0;
}

