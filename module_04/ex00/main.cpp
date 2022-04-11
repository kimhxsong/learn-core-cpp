#include <iostream>
#include <string>
#include <new>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "WrongDog.h"

void  Call() {
  {
    Animal meta1;
    Animal meta2(meta1);
    Animal meta3 = meta2;
  }

  const Animal* meta = new Animal();
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete i;
  delete j;
}

void  WrongCall() {
  {
    WrongAnimal meta1;
    WrongAnimal meta2(meta1);
    WrongAnimal meta3 = meta2;
  }

  const WrongAnimal* meta = new WrongAnimal();
  const WrongAnimal* i = new WrongCat();
  const WrongAnimal* j = new WrongDog();
  
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete i;
  delete j;
}

int main() {
  Call();
  WrongCall();
  system("leaks test");
  return 0;
}
