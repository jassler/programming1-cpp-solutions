#ifndef H_TRIP
#define H_TRIP

#include <string>
#include <vector>
#include "rating.h"

class Trip
{
private:
    // name of the location
    std::string destination;

    // duration in days
    unsigned int duration;

    // price in euros (no cents)
    unsigned int price;

    std::vector<Rating> ratings;

public:
    Trip(std::string _dest, unsigned int _duration, unsigned int _price);

    void add_rating(Rating r);

    // it doesn't matter if return type is infront or behind function name (trailing return type)
    // in this case I think it's visually more appealing to have all getter function names start in the same column
    auto get_destination() -> std::string;
    auto get_duration() -> unsigned int;
    auto get_price() -> unsigned int;
    auto get_rating() -> Rating;

    void print();
};


#endif
