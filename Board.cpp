#include "Board.hpp"
#include <sstream>

void Board::move_gary(unsigned int k) {

    print_board();

    for(unsigned int i = 0; i < k ; ++i) {

        Cell* C = &(g.at(std::get<0>(snail.get_location())).at(std::get<1>(snail.get_location())));
        snail.move(C);
        print_board();
    }
}

void Board::setOutputFilename(std::string s) {

    filename = s;

    output.open(filename);

    if(not output.is_open()) {

        filename.clear();
    }
}

void Board::print_board() {

    std::stringstream ss;
    ss << "[Gary Location] {"<< std::get<0>(snail.get_location())<<", "<<std::get<1>(snail.get_location())<<"} ";
    ss << "[Gary Orientation] "<< snail.get_orientation_string()<<" ";

        for (unsigned int i = 0; i < g.size(); ++i) {

            ss << "[Row " << i <<"] ";
            
            row_t* row = &(g.at(i));

            for (unsigned int j = 0; j < g.size(); ++j) {

                Cell* C = &(row->at(j));

                if (C->get_color() == Cell::white) {

                    ss << "0 ";
                }

                else {

                    ss << "1 ";
                }
            }
        }

    if(filename.empty()) {

        std::cout << ss.str()<<std::endl;
    }

    else {

        output << ss.str()<<std::endl;

    }

}

