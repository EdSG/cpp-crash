#include <iostream>
#include <memory>

class Singleton
{
  private:

    static unsigned int NextSingletonId;

    static std::auto_ptr<Singleton> singleton_instance;

    const int singleton_id;

    Singleton():singleton_id(NextSingletonId++)
    {
      std::cout << *this << std::endl;
    }

  public:

    static const Singleton& GetInstance()
    {
      if (Singleton::singleton_instance.get() == NULL)
      {
        Singleton::singleton_instance.reset(new Singleton);
      }

      return *(Singleton::singleton_instance.get());
    }

    ~Singleton()
    {
      std::cout << "~" << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Singleton& s)
    {
      return out << "Singleton(" << s.singleton_id << "):" << &s;
    }

};

unsigned int Singleton::NextSingletonId = 1;

std::auto_ptr<Singleton> Singleton::singleton_instance(NULL);

int main(int argc, char *argv[], char *envp[])
{
  // Singleton s1; // Cannot instantiate

  std::cout << "Singleton: Cannot instantiate our own object." << std::endl << std::endl;

  std::cout << Singleton::GetInstance() << std::endl;

  return 0;
}

