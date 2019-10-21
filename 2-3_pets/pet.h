#ifndef H_PET
#define H_PET

#include <string>

enum GENDER { MALE = 'm', FEMALE = 'f' };

class Pet
{
public:
    const std::string name;

    // should be either 'm' or 'f'
    // but nothing's stopping you from messing this up
    const char gender;
    const unsigned int birth_year;

    Pet(std::string _name, char _gender, unsigned int _birth_year);

    // has to be virtual for child classes to override
    virtual void speak();
};

#endif
