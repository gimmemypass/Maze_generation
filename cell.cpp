    #include "cell.h"

Cell::Cell()
{
    left = right = top = bottom = true;
    used = false;
}

Cell::~Cell(){
    delete rect;
}
int Cell::height;
int Cell::width;
