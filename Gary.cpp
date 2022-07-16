#include "Gary.hpp"
#include <string>

std::tuple<unsigned int, unsigned int> Gary::get_location() {

    return location;
}

void Gary::move(Cell* C) {

    if(C->get_color() == Cell::white) {

        turn_clockwise();
    }

    else {

        turn_counterclockwise();
    }

    C->next_color();
    update_location();
}

void Gary::turn_clockwise() {

    if(currOrientation == orientation::up) {

        currOrientation = orientation::right;
    }

    else if (currOrientation == orientation::right) {

        currOrientation = orientation::down;
    }

    else if (currOrientation == orientation::down) {

        currOrientation = orientation::left;
    }

    else {

        currOrientation = orientation::up;
    }

}

void Gary::turn_counterclockwise() {

    if(currOrientation == orientation::up) {

        currOrientation = orientation::left;
    }

    else if (currOrientation == orientation::left) {

        currOrientation = orientation::down;
    }

    else if (currOrientation == orientation::down) {

        currOrientation = orientation::right;
    }

    else {

        currOrientation = orientation::up;
    }
}

void Gary::update_location() {

    unsigned int currentGaryRow = std::get<0>(location);
    unsigned int currentGaryColumn = std::get<1>(location);

    if(currOrientation == orientation::up) {

            currentGaryRow = currentGaryRow - 1;
        }

    else if (currOrientation == orientation::right) {

            currentGaryColumn = currentGaryColumn + 1;
        }

    else if (currOrientation == orientation::down) {

            currentGaryRow =  currentGaryRow + 1;
    }

    else {

            currentGaryColumn = currentGaryColumn - 1;
        }

    if(currentGaryRow == (unsigned int)-1) {

        currentGaryRow = N-1;
    }

    if(currentGaryColumn == N) {

      currentGaryColumn = 0;
    }

    if(currentGaryRow == N) {

        currentGaryRow = 0;
    }

    if (currentGaryColumn == (unsigned int)-1) {

        currentGaryColumn = N-1;
    }

    location = std::make_tuple(currentGaryRow, currentGaryColumn);
}

std::string Gary::get_orientation_string(){

    if(currOrientation == orientation::up) {

        return "up";
    }

    else if(currOrientation == orientation::right) {

        return "right";
    }

    else if(currOrientation == orientation::down) {

        return "down";
    }

    else {

        return "left";
    }
}