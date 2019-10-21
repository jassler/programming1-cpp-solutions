#include "trip.h"

#include <iostream>

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
    // variables are const, so we have to take care of all variables ourselves
    double quality = ratings[0].quality;
    double pricing = ratings[0].pricing;
    double cleanliness = ratings[0].cleanliness;
    double accomodation = ratings[0].accomodation;

    // already have index 0 from initialization, start at 1
    for(int i = 1; i < ratings.size(); i++)
    {
        quality += ratings[i].quality;
        pricing += ratings[i].pricing;
        cleanliness += ratings[i].cleanliness;
        accomodation += ratings[i].accomodation;
    }

    // calculate average
    quality /= ratings.size();
    pricing /= ratings.size();
    cleanliness /= ratings.size();
    accomodation /= ratings.size();

    return Rating(quality, pricing, cleanliness, accomodation);
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

std::string Trip::get_destination()
{
    return destination;
}

unsigned int Trip::get_duration()
{
    return duration;
}

unsigned int Trip::get_price()
{
    return price;
}
