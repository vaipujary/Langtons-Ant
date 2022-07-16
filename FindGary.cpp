#include <string>
#include "Board.hpp"

int main(int argc, char** argv){

    unsigned int boardSize;
    unsigned int numberSteps;

    std::sscanf(argv[1], "%u", &boardSize);

    std::sscanf(argv[2], "%u", &numberSteps);

    Board B(boardSize);

    if (argc == 4) {

        std::string outputFilename = argv[3];
        B.setOutputFilename(outputFilename);
    }

    B.move_gary(numberSteps);

    return 0;
}
