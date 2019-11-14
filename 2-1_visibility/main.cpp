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
     * Fehler C2248 "Trip::price": Kein Zugriff auf private Member, dessen Deklaration in der Trip-Klasse erfolgte.
     */
    t.price = 1;

    
    Rating r = Rating::input_rating();
    std::cout << "Average rating is " << ((r.quality + r.pricing + r.cleanliness + r.accomodation) / 4) << "\n";
    
	/*
	 * Fehler C3892 "r": Einer Variablen, die konstant ist, kann nichts zugeordnet werden.
	 */
	r.quality = 5;
}
