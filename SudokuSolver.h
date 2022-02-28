#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

static int BOARD_SIZE = 9;
static int SQUARE_SIZE = 3;

class Board {
    private:
        int index;
        std::vector<int> currBoard;
        std::vector<int> row;
        std::vector<int> col;
        std::vector<int> square;
        std::vector<int> getRow();
        std::vector<int> getCol();
        std::vector<int> getSquare();
    public:
        bool isValid(int val);
        Board(const std::vector<int> skeleton);
        Board(std::string filename);
        Board(Board& board, int val);
        int getIndex();
        std::vector<int> getBoard();
        void print();
};
