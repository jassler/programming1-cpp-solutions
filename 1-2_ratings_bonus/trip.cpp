#include <iostream>
#include "trip.h"

Trip::Trip(std::string _dest, unsigned int _duration, unsigned int _price)
: destination(_dest), duration(_duration), price(_price)
{
    // everything already initialized, nothing to do here
}

void Trip::add_rating(Rating r)
{
    ratings.push_back(r);
}

Rating Trip::get_rating()
{
    // return default rating if nothing exists
    if(ratings.size() == 0)
        return Rating();
    
    // sum up all ratings
    Rating average = ratings[0];

    // already have index 0 from initialization, start at 1
    for(int i = 1; i < ratings.size(); i++)
    {
        average.quality += ratings[i].quality;
        average.pricing += ratings[i].pricing;
        average.cleanliness += ratings[i].cleanliness;
        average.accomodation += ratings[i].accomodation;
    }

    // calculate average
    average.quality /= ratings.size();
    average.pricing /= ratings.size();
    average.cleanliness /= ratings.size();
    average.accomodation /= ratings.size();

    return average;
}

void Trip::print()
{
    std::cout << "Reiseziel        : " << destination << "\n";
    std::cout << "Reisedauer (Tage): " << duration << "\n";
    std::cout << "Kosten (Euro)    : " << price << "\n\n";

    std::cout << "Bewertungen (" << ratings.size() << ")\n";
    Rating avg = get_rating();
    avg.print();
}
