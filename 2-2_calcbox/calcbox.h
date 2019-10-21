#ifndef H_CALCBOX
#define H_CALCBOX

#include <string>

class CalcBox
{
private:
    double number;

    double *history;
    const int history_size;

    // pointers to history array
    // pos always shows to current "active number"
    // min / max is there to make sure we don't accidentally undo / redo steps that are not there
    double *min, *max, *pos;

    void num_changes(double to);

public:
    CalcBox(int steps);
    ~CalcBox();

    void increment();
    void decrement();
    void multiply(double other);
    void divide(double other);
    void reset();

    // returns true if successful
    bool undo();
    bool redo();

    // optional, just to visualize where all the pointers are pointing at
    std::string get_buffer_representation();

    double get_number();
};

#endif
