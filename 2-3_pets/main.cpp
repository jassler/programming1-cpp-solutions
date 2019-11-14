#include <iostream>
#include <vector>
#include "pet.h"
#include "dog.h"
#include "cat.h"

int main()
{
    std::vector<Pet*> pets;

    pets.push_back(new Cat("Meowto", FEMALE, 2011));
    pets.push_back(new Dog("Doggo", MALE, 2014));

    for(auto& p : pets)
    {
        std::cout << p->name << " says: ";
        p->speak();
        std::cout << "\n";
    }


	// created pets with 'new' keyword
	// -> has to be deleted now
	for(auto& p : pets)
	{
		delete p;
	}
}
