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

## Übungsblatt 2: Sichtbarkeit und Vererbung

### 2-1: Eingeschränkte Sichtbarkeit

Die Attribute aus Übung 1-2 sollen nach dem erstellen des Objekts nur mehr gelesen werden können, jedoch nicht verändert.

### 2-2: CalcBox

Gegeben sei folgende Klasse

```C++
class CalcBox
{
private:
    double number;

public:
    CalcBox() { reset(); }

    void increment() { number += 1; }
    void decrement() { number -= 1; }
    void multiply(double other) { number *= other; }
    void divide(double other) { if(other != 0) number /= other; }
    void reset() { number = 0; }

    double get_number() { return number; }
};
```

Wow was für eine coole, voll nützliche Klasse! Mit den Methoden `undo()` / `redo()` sollen jetzt zusätzlich auch noch Rechenoperationen rückgängig gemacht werden können. Dabei soll es ein Limit geben, wie viele Schritte gespeichert werden. (Hinweis: dynamische Speicherallokierung, Speicher wieder freisetzen, blablabla)

### 2-3: Haustiere

Die Klasse `Pet` soll Name, Geschlecht und Geburtsjahr eines Haustier speichern, zusammen mit einer virtuellen Methode `speak()`, die den Laut des Haustiers in der Konsole ausgibt. Die Kindklassen `Dog` und `Cat` sollen davon erben und die Methode dementsprechend überschreiben.
