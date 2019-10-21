#include <sstream>
#include "calcbox.h"

CalcBox::CalcBox(int _steps)
: history(new double[_steps]), history_size(_steps)
{
    // all pointers show to beginning of history array
    min = max = pos = history;

    // reset first number to 0
    *pos = 0;
}

// deconstructor deleting history array
CalcBox::~CalcBox()
{
    delete[] history;
}

// every number calculation has to go through this
void CalcBox::num_changes(double to)
{
    number = to;

    // loop back to 0 when position exceeds history length
    if(++pos >= (history + history_size))
        pos = history; // point back to beginning of array

    // add current number to history
    *pos = to;

    /*
     * TAKE CARE OF MIN MAX POINTERS
     */
    // updated value is always most resent one, set max to that
    max = pos;

    // make sure min-pointer gets moved when buffer limit is reached
    if(min == pos)
    {
        if(++min >= (history + history_size))
            min = history;
    }
}

bool CalcBox::undo()
{
    // make sure we can undo
    if(pos == min)
        return false;
    
    // put pos to end of array when at index 0
    if(pos == history)
        pos = history + history_size;
    
    pos--;
    number = *pos;
    return true;
}

bool CalcBox::redo()
{
    if(pos == max)
        return false;
    
    if(++pos >= (history + history_size))
        pos = history;
    
    number = *pos;
    return true;
}

void CalcBox::increment() { num_changes(number + 1); }
void CalcBox::decrement() { num_changes(number - 1); }

void CalcBox::multiply(double other) { num_changes(number * other); }
void CalcBox::divide(double other)   { if(other != 0) num_changes(number / other); }

void CalcBox::reset()        { num_changes(0); }
double CalcBox::get_number() { return number; }

std::string CalcBox::get_buffer_representation()
{   
    std::stringstream ss;
    for(double *x = history; x < history + history_size; x++)
    {
        ss << "| ";
        if(x == min)
            ss << "v";
        if(x == max)
            ss << "^";
        if(x == pos)
            ss << "p";
        ss << " ";
    }
    ss << "|";
    return ss.str();
}
