#ifndef GARY_H
#define GARY_H
#include <tuple>
#include <cstddef>
#include <iostream>
#include "Cell.hpp"

enum class orientation{up, right, down, left};

class Gary{

public:
    Gary() = delete;
    Gary (unsigned int boardSize): N(boardSize) {

        location = std::make_tuple((boardSize-1)/2, (boardSize-1)/2);
    }

     ~Gary() = default;

    std::tuple<unsigned int, unsigned int> get_location();

    void turn_clockwise();

    void turn_counterclockwise();

    void update_location();

    void move(Cell* C);

    orientation get_orientation() {

        return currOrientation;
    }

    std::string get_orientation_string();

private:
    orientation currOrientation = orientation::up;
    unsigned int N;
    std::tuple<unsigned int, unsigned int> location;
};

#endif