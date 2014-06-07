#include <iostream>

#define N (4)

int main(int argc, char *argv[], char *envp[])
{
  int ** a = new int*[N];

  int i = 0;
  int j = 0;

  for (i = 0 ; i < N ; i++)
  {
    a[i] = new int[N];
  }

  for (i = 0 ; i < N ; i++)
  {
    for(j = 0 ; j < N ; j++)
    {
      a[i][j] = 1 + (i * N) + j;
    }
  }

  for (i = 0 ; i < N ; i++)
  {
    for(j = 0 ; j < N ; j++)
    {
      std::cout << a[i][j] << ((j == N - 1) ? '\0' : '\t');
    }

    std::cout << std::endl;
  }

  for (i = 0 ; i < N ; i++)
  {
    delete a[i];
  }

  delete a;

  return 0;
}

