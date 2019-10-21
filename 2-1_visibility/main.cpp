#include <iostream>
#include <vector>
#include "trip.h"

int main()
{
    Trip t(
        "Rom",
        6 /* days */,
        350 /* euros */
    );

    // call getter-functions
    std::cout << "Reise nach " << t.get_destination() << " kostet " << t.get_price() << "€\n";
    
    /* 
     * Attributes of Trip are private, not visible to us.
     * The next line produces the following error
     * 
     * main.cpp:26:7: error: 'price' is a private member of 'Trip'
     *     t.price = 1;
     *     ^
     * ./trip.h:17:18: note: declared private here
     *     unsigned int price;
     *                 ^
     */
    t.price = 1;

    /*
     * Attributes of Rating are public, we can read them directly
     * They are however constant, meaning they can't be reassigned
     * The following error will be produced
     * 
     * main.cpp:42:15: error: cannot assign to non-static data member 'quality' with const-qualified type 'const double'
     *     r.quality = 5;
     *     ~~~~~~~~~ ^
     * ./rating.h:14:18: note: non-static data member 'quality' declared const here
     *     const double quality;
     *     ~~~~~~~~~~~~~^~~~~~~
     */
    Rating r = Rating::input_rating();
    std::cout << "Average rating is " << ((r.quality + r.pricing + r.cleanliness + r.accomodation) / 4) << "\n";
    r.quality = 5;
}
