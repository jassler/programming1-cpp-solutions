#ifndef H_RATING
#define H_RATING

enum Rating_Scale { POOR = 1, OK, GOOD, VERY_GOOD, EXCELLENT };

class Rating
{
public:
    double quality;
    double pricing;
    double cleanliness;
    double accomodation;
    double staff;

    Rating(double _quality, double _pricing, double _cleanliness, double _accomodation, double _staff)
    : quality(_quality), pricing(_pricing), cleanliness(_cleanliness), accomodation(_accomodation), staff(_staff)
    {
        // everything is already initialized
    }

    
};

#endif
