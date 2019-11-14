#ifndef H_DOG
#define H_DOG

#include "pet.h"

class Dog : public Pet
{
public:

    Dog(std::string name, char gender, unsigned int birth_year);

    // override parent method "speak"
    void speak();
};

#endif
