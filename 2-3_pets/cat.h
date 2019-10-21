#ifndef H_CAT
#define H_CAT

#include "pet.h"

class Cat : public Pet
{
public:

    Cat(std::string name, char gender, unsigned int birth_year);

    // override parent method "speak"
    void speak();
};

#endif
