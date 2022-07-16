#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include <iostream>

class Cell {
public:

    enum Color{white, black};
    Cell() = default;
    ~Cell() = default;

    void next_color();

    Color get_color() {

        return currColor;
    }

private:
    Color currColor = white;
};

#endif