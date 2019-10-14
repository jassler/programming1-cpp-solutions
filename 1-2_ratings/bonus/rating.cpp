#include <iostream>
#include "rating.h"

/*
 * Ask user to rate a specific category (prompt)
 * It checks that the input is between POOR and EXCELLENT
 * User will be asked to input a valid number when check failed
 */
int prompt_rating(std::string prompt)
{
    std::string line;

    while(true)
    {
        std::cout << prompt;
        std::getline(std::cin, line);

        try {
            int result = std::stoi(line);
            if(result >= POOR && result <= EXCELLENT)
                // success! it's within range
                return result;
            
            std::cout << "Bewertung muss eine Zahl von " << POOR << " bis " << EXCELLENT << " sein!\n\n";
        } catch(...)
        {
            std::cout << "Eingabe muss eine (korrekte) Zahl sein\n\n";
        }
    }
}

Rating::Rating(double _quality, double _pricing, double _cleanliness, double _accomodation)
: quality(_quality), pricing(_pricing), cleanliness(_cleanliness), accomodation(_accomodation)
{
    // everything is already initialized
}

Rating::Rating()
: Rating(0, 0, 0, 0)
{
    // other constructor called
}

void Rating::input_rating()
{
    quality      = (double) prompt_rating("Qualitat      : ");
    pricing      = (double) prompt_rating("Preis-Leistung: ");
    cleanliness  = (double) prompt_rating("Sauberkeit    : ");
    accomodation = (double) prompt_rating("Komfort       : ");
}

void Rating::print()
{
    std::cout << "Qualitat      : " << quality << "\n";
    std::cout << "Preis-Leistung: " << pricing << "\n";
    std::cout << "Sauberkeit    : " << cleanliness << "\n";
    std::cout << "Komfort       : " << accomodation << "\n";
}
