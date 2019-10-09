# Lösungen zu C++ Aufgaben in Programmieren 1

## Übungsblatt 1: Klassen

### 1-1: Rechtecke

Eine Klasse `Rectangle` soll über den Methodenaufruf `draw()` ein Rechteck zeichnen. Die Größe des Rechtecks ist im Konstruktor der Klasse anzugegeben. Weitere Methoden sollen dazu dienen, Informationen über das Rechteck zu bekommen und die Größe des Rechtecks zu transformieren.

### 1-2: Travel Ratings

Gegeben sei folgende Klasse

```C++
#include <string>
class Trip
{
public:
    // name of the location
    std::string destination;
    
    // duration in days
    unsigned int duration;
    
    // price in euros (no cents)
    unsigned int price;
    
    Trip(std::string _dest, unsigned int _duration, unsigned int _price)
    : destination(_dest), duration(_duration), price(_price)
    {
        // everything already initialized, nothing to do here
    }
};
```

Mit einer Klasse `Rating` soll Qualität, Preis-Leistungsverhältnis, Sauberkeit und Komfort mit 1-5 Sternen bewertet werden. Dieses Rating soll dann dem Trip hinzugefügt werden.
