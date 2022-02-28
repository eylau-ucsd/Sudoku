#include "SudokuSolver.h"

Board* explore(Board* board) {
    if (board->getIndex() == BOARD_SIZE * BOARD_SIZE) {
        return board;
    }
    for (int i = 1; i <= BOARD_SIZE; i++) {
        if (board->isValid(i)) {
            Board* newBoard = new Board(*board, i);
            Board* result = explore(newBoard);
            if (result != nullptr) {
                return result;
            }
            delete newBoard;
        }
    }
    return nullptr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Invalid usage" << std::endl;
        return 1;
    }
    Board initBoard (argv[1]);
    Board* answer = explore(&initBoard);
    if (answer == nullptr) {
        std::cout << "No solution" << std::endl;
        delete answer;
        return 1;
    }
    answer->print();
    delete answer;
    return 0;
}
