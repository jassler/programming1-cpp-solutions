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

## Übungsblatt 3: Malerei

Folgende Klasse wurde implementiert, um eine Ellipse zu zeichnen. Testen Sie diese aus.

ellipse.h
```C++
#pragma once

class Ellipse
{
private:
    int width, height;
    char fill;
    
public:
	Ellipse(int _width, int _height, char _fill = '#');

	void draw();
	double area();
};
```

ellipse.cpp
```C++
// this define is needed for Windows to use cmath constants
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>	// M_PI
#include "ellipse.h"

Ellipse::Ellipse(int _width, int _height, char _fill)
	: width(_width), height(_height), fill(_fill)
{
}

void Ellipse::draw()
{
	double center_x = width / 2.0;
	double center_y = height / 2.0;

	double width_sq = center_x * center_x;
	double height_sq = center_y * center_y;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; ++x)
		{
			double d_x = (double)x - center_x;
			double d_y = (double)y - center_y;

			if (d_x * d_x / width_sq + d_y * d_y / height_sq <= 1)
				std::cout << get_fill();
			else
				std::cout << ' ';
		}
		std::cout << '\n';
	}
}

double Ellipse::area()
{
	return M_PI * get_width() * get_height() / 4;
}
```

### 3-a: Abstrahieren

Wie vielleicht auffällt, gibt es Ähnlichkeiten zur `Rectangle` Klasse - beide verwenden `width` und `height` für ihre Größe und beide verwenden die Methode `draw()` um das Konstrukt zu zeichnen.

Da es gut Möglich ist, noch mehr dieser Formen zu implementieren, die die gleichen Grundeigenschaften besitzen, ist es durchaus sinnvoll, diese über eine Elternklasse zu abstrahieren.

- Erstellen Sie hierzu eine Klasse `Shape`. Diese soll die Attribute `width`, `height` sowie `fill` beinhalten, die über den Konstruktor gesetzt werden können. Zusätzlich sollen alle Kindklassen, die von `Shape` erben, die Funktion `draw()` implementieren.
- Lassen Sie die Klassen `Rectangle` und `Ellipse` von `Shape` erben. Entfernen Sie dabei auch sämtliche Attribute, die bereits in `Shape` vorhanden sind.
- Erstellen Sie anschließend die Klassen `Triangle` und `Line`, die jeweils ein Dreieck und eine diagonale Linie zeichnen. Ihnen steht dabei frei, noch weitere geometrische Formen hinzuzufügen.

### 3-b: Malfläche

Erstellen Sie eine Klasse `Canvas`, mit der sich ein Bild aus einzelnen Shapes zeichnen lässt.

- Im Konstruktor soll lediglich die Größe der Zeichnung angegeben werden
- Über die Methode `add_shape` soll ein Objekt, das von `Shape` erbt, zusammen mit einer Koordinate übergeben werden könenn
- Über die Methode `clear` soll die Zeichnung gelöscht werden
- Über die Methode `draw` soll die gesamte Zeichnung ausgegeben werden

*Hinweis:* Es müssen durchaus Änderungen an `Shape` vorgenommen werden, um das Zeichnen von überlappenden Formen zu ermöglichen.

### 3-c: Maaalfläche

Um die Verwirrung nun komplett zu machen, lassen Sie `Canvas` von `Shape` erben und versuchen Sie, ein Bild aus mehreren `Canvas` zu machen.
