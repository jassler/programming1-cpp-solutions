#include <iostream>
#include "calcbox.h"

char prompt_command()
{
    while(true)
    {
        std::string input;

        std::cout << "What do you wanna do?\n"
                "p - print number\n"
                "i - increment\n"
                "d - decrement\n"
                "m - multiply by 2\n"
                "h - divide by 2\n"
                "u - undo\n"
                "r - redo\n"
                "b - print buffer\n"
                ": ";

        std::getline(std::cin, input);
        if(input.length() > 0)
            return input[0];
    }
}

void execute_command(char command, CalcBox& box)
{
    /*
     * Accepted commands are
     * - p
     * - i
     * - d
     * - m
     * - h
     * - u
     * - r
     * - b
     */
    switch(command)
    {
    case 'p':
    case 'P':
        std::cout << "The number currently is " << box.get_number();
        break;
    
    case 'i':
    case 'I':
        box.increment();
        std::cout << "Incremented number";
        break;

    case 'd':
    case 'D':
        box.decrement();
        std::cout << "Decremented number";
        break;

    case 'm':
    case 'M':
        box.multiply(2);
        std::cout << "Multiplied number by 2";
        break;

    case 'h':
    case 'H':
        box.divide(2);
        std::cout << "Divided number by 2";
        break;

    case 'u':
    case 'U':
        if(box.undo())
            std::cout << "Undo successful!";
        else
            std::cout << "Couldn't undo";
        break;

    case 'r':
    case 'R':
        if(box.redo())
            std::cout << "Redo successful!";
        else
            std::cout << "Couldn't redo";
        break;

    case 'b':
    case 'B':
        std::cout << box.get_buffer_representation();
        break;
    
    default:
        std::cout << "Unkown command";
    }
}

int main()
{
    // determine buffer size
    std::string line;
    std::cout << "How big should the buffer be: ";
    std::getline(std::cin, line);

	// note: throws error if input isn't a number
	// could sorround with try catch, but do your own job!
    int size = std::stoi(line);

    // create calcbox with specified buffer size
    CalcBox box(size);

    while(true)
    {
        // do command stuff
        char command = prompt_command();
        execute_command(command, box);

        // wait to continue
        std::cout << "\nPress enter to continue...";
        std::getline(std::cin, line);
        std::cout << std::string(10, '\n');
    }
}
