#ifndef BOARD_H_
#define BOARD_H_
#include <cstddef>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <tuple>
#include "Gary.hpp"

class Board {

  public:

    Gary snail;
    Board(unsigned int N) : snail(N % 2 == 0? N + 1 : N) {

        if(N % 2 == 0) {

            std::cout<<"Board dimension must be an odd number!! Got " << N << " and adding 1 to equal "<< N+1<<std::endl;
            N += 1;
        }

        g.resize(N);

        for(unsigned int i = 0; i < g.size(); ++i) {

            g.at(i).resize(N);
        }
    }

    ~Board() = default;

    void move_gary(unsigned int k);

    void print_board();

    void setOutputFilename(std::string);

private:

    typedef std::vector<Cell> row_t;
    typedef std::vector<row_t> grid_t;
    grid_t g;
    std::ofstream output;
    std::string filename;

};

#endif