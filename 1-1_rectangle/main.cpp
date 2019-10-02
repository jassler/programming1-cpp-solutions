#include "rectangle.h"

int main()
{
    Rectangle rect(4, 5);
    rect.draw();
    
    rect.width = 10;
    rect.height = 3;
    rect.draw();
    
    return 0;
}
