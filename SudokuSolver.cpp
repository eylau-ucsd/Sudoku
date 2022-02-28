#include "SudokuSolver.h"

Board* explore(Board* board, std::vector<Board*>& boardList) {
    if (board->getIndex() == BOARD_SIZE * BOARD_SIZE) {
        return board;
    }
    for (int i = 1; i <= BOARD_SIZE; i++) {
        if (board->isValid(i)) {
            Board* newBoard = new Board(*board, i);
            boardList.push_back(newBoard);
            Board* result = explore(newBoard, boardList);
            if (result != nullptr) {
                return result;
            }
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
    std::vector<Board*> boardList;
    Board* answer = explore(&initBoard, boardList);
    if (answer == nullptr) {
        std::cout << "No solution" << std::endl;
        return 1;
    }
    answer->print();
    for (Board* board : boardList) {
        delete board;
    }
    return 0;
}
