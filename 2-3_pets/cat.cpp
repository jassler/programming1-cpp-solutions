#include <iostream>
#include "cat.h"

Cat::Cat(std::string name, char gender, unsigned int birth_year)
: Pet(name, gender, birth_year)
{}

void Cat::speak()
{
    std::cout << "meow";
}
