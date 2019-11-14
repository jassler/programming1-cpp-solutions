#include <iostream>
#include "dog.h"

Dog::Dog(std::string name, char gender, unsigned int birth_year)
: Pet(name, gender, birth_year)
{}

void Dog::speak()
{
    std::cout << "WOOF";
}
