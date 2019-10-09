#ifndef H_TRIP
#define H_TRIP

#include <vector>
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

    std::vector<Rating> ratings;

    Trip(std::string _dest, unsigned int _duration, unsigned int _price);

    void add_rating(Rating r);

    // calculate average of all ratings
    // if no rating is present, it returns the default rating
    Rating get_rating();

    void print();
};


#endif
