#include "Cell.hpp"

void Cell::next_color() {

    if(currColor == white) {

        currColor = black;
    }

    else {

        currColor = white;
    }
}




