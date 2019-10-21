#include <iostream>
#include "pet.h"

Pet::Pet(std::string _name, char _gender, unsigned int _birth_year)
: name(_name), gender(_gender), birth_year(_birth_year)
{}

void Pet::speak()
{
    std::cout << "This one doesn't speak";
}
