#ifndef H_TRIP
#define H_TRIP

#include <string>
#include "rating.h"

class Trip
{
public:
    // name of the location
    std::string destination;

    // duration in days
    unsigned int duration;

    // price in euros (no cents)
    unsigned int price;

    Rating rating;

    Trip(std::string _dest, unsigned int _duration, unsigned int _price);
};


#endif
