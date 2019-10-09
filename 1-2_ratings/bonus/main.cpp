#include <vector>
#include "trip.h"

/*
 * Ask user to input a number
 * User will be asked repeatedly if he doesn't comply
 */
unsigned int prompt_uint(std::string prompt)
{
    std::string line;

    while(true)
    {
        std::cout << prompt;
        std::getline(std::cin, line);

        try
        {
            unsigned long result = std::stoul(line);

            // if number is not too big to be cast into an unsigned integer,
            // return it!
            if(result <= std::numeric_limits<unsigned int>::max())
                return (unsigned int) result;
            
            std::cout << "Die Zahl ist zu gross!\n";
        } catch(...)
        {
            std::cout << "Eingabe muss eine (realistische) Zahl sein!\n";
        }

    }
}

/*
 * Ask user line by line about the trip
 * (destination, duration, cost)
 */
Trip prompt_trip()
{
    std::string destination;

    std::cout << "Wohin geht die Reise    : ";
    std::getline(std::cin, destination);

    unsigned int duration = prompt_uint("Wie viele Tage geht sie : ");
    unsigned int price    = prompt_uint("Wie viel Euro kostet sie: ");

    return Trip(destination, duration, price);
}

/*
 * Try to find trip in given vector by destination name
 * If trip doesn't exist, return nullptr
 */
Trip* find_trip(std::vector<Trip>& trips, std::string _dest)
{
    for(int i = 0; i < trips.size(); i++)
    {
        if(trips[i].destination == _dest)
            return &(trips[i]);
    }

    return nullptr;
};

/*
 * Ask user what trip he wants to know more about, print info
 */
void get_trip_info(std::vector<Trip>& trips)
{
    std::string line;
    std::cout << "Von welcher Reise soll die Info abgerufen werden: ";
    std::getline(std::cin, line);

    Trip *t = find_trip(trips, line);

    if(t == nullptr)
        std::cout << "Das Reiseziel " << line << " ist nicht bekannt\n";
    else
        t->print();
}

/*
 * Ask user which trip to rate
 * User will be asked to type in the rating for each category
 */
void add_rating_to_trip(std::vector<Trip>& trips)
{
    std::string line;

    std::cout << "Welches Reiseziel soll bewertet werden: ";
    std::getline(std::cin, line);

    Trip *t = find_trip(trips, line);

    if(t == nullptr)
        std::cout << "Das Reiseziel " << line << " ist nicht bekannt\n";
    else
    {
        Rating r;
        r.input_rating();
        t->add_rating(r);
    }
}

int main()
{
    std::vector<Trip> trips;

    while(true)
    {
        // --- INFOPAGE --- //
        std::cout << "\n\n\n^\\._./^\n\n";
        std::cout << "Anzahl Reisen: " << trips.size() << "\n";
        std::cout << "---\n";
        for(auto t : trips)
            std::cout << t.destination << "\n";
        std::cout << "---\n\n";
        std::cout << "Mit 'neu' kann eine neue Reise angelegt werden\n";
        std::cout << "Mit 'info' kann genaue Informationen uber eine Reise angezeigt werden\n";
        std::cout << "Mit 'bewerten' kann eine Reise bewertet werden\n";
        std::cout << "Mit 'ende' kann das Programm beendet werden\n";
        std::cout << "Was wollen Sie tun: ";

        // --- WAIT FOR COMMAND --- //
        std::string line;
        std::getline(std::cin, line);
        
        // --- CHECK COMMAND --- //
        if(line == "neu")
            trips.push_back(prompt_trip());

        else if(line == "info")
            get_trip_info(trips);
        
        else if(line == "bewerten")
            add_rating_to_trip(trips);

        else if(line == "ende")
            break;

        else
            std::cout << "Der Befehl " << line << " ist unbekannt\n";
        
        std::cout << "Um fortzufahren, Enter drucken";
        std::getline(std::cin, line);
    }
}