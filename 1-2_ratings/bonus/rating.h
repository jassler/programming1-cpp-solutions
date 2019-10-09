#ifndef H_RATING
#define H_RATING

#include <iostream>

enum Rating_Scale { POOR = 1, OK, GOOD, VERY_GOOD, EXCELLENT };

class Rating
{
public:
    // saved as doubles so we can calculate averages later on
    double quality;
    double pricing;
    double cleanliness;
    double accomodation;

    Rating(double _quality, double _pricing, double _cleanliness, double _accomodation);

    Rating();

    void input_rating();
    void print();
};

#endif
