#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"

Base *generate() {
  int num = rand() % 3;
  switch (num) {
    case 0:
    {
    	//std::cout << "He generado A" << std::endl;
      return new A();
    }
    case 1:
    {
    	//std::cout << "He generado B" << std::endl;
      return new B();
    }
    default:
    {
    	//std::cout << "He generado C" << std::endl;
      return new C();
    }
  }
}

void identify(Base *p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
}

int main() {
  std::srand(std::time(nullptr));
  // for (int i = 0; i < 10; i++) {
  //   Base *p = generate();
  //   identify(p);
  //   delete p;
  // }
  Base *p = generate();
  identify(p);
  delete p;
  return 0;
}