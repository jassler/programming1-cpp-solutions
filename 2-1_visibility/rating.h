#ifndef H_RATING
#define H_RATING

enum Rating_Scale { POOR = 1, OK, GOOD, VERY_GOOD, EXCELLENT };

class Rating
{
public:
    // const has to be statically initalized
    // (behind column after constructor declaration)
    // variables cannot be reassigned!
    const double quality;
    const double pricing;
    const double cleanliness;
    const double accomodation;

    Rating(double _quality, double _pricing, double _cleanliness, double _accomodation);

    Rating();

    void print();

    // return Rating based on user input
    static Rating input_rating();
};

#endif
