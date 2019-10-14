#include <iostream>
#include "trip.h"

int main()
{
    Trip t("Malta", 10, 300);

    std::cout << "Bewerten Sie Ihre Reise nach " << t.destination << "\n";
    t.rating.input_rating();

    std::cout << "\nEine Bewertung wurde abgegeben fur folgende Reise:\n";
    std::cout << "Reiseziel        : " << t.destination << "\n";
    std::cout << "Reisedauer (Tage): " << t.duration << "\n";
    std::cout << "Preis (Euro)     : " << t.price << "\n\n";
    std::cout << "Bewertung\n";
    t.rating.print();
}