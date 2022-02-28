#include "SudokuSolver.h"

std::vector<int> Board::getRow() {
    if (row.size() == 0) {
        int firstIndex = (index / BOARD_SIZE) * BOARD_SIZE;
        std::vector<int> result;
        for (int i = firstIndex; i < firstIndex + BOARD_SIZE; i++) {
            row.push_back(currBoard[i]);
        }
    }
    return row;
}

std::vector<int> Board::getCol() {
    if (col.size() == 0) {
        int firstIndex = (index % BOARD_SIZE);
        for (int i = firstIndex; i < BOARD_SIZE * BOARD_SIZE; i += BOARD_SIZE) {
            col.push_back(currBoard[i]);
        }
    }
    return col;
}

std::vector<int> Board::getSquare() {
    if (square.size() == 0) {
        int firstIndex = ((index % BOARD_SIZE) / SQUARE_SIZE) * SQUARE_SIZE
        + ((index / BOARD_SIZE) / SQUARE_SIZE) * SQUARE_SIZE * BOARD_SIZE;
        for (int i = 0; i < SQUARE_SIZE; i++) {
            for (int j = 0; j < SQUARE_SIZE; j++) {
                square.push_back(currBoard[firstIndex + BOARD_SIZE*i + j]);
            }
        }
    }
    return square;
}

bool match(int target, std::vector<int> numbers) {
    for (int i : numbers) {
        if (target == i) return true;
    }
    return false;
}

bool Board::isValid(int val) {
    if (match(val, getRow())) return false;
    if (match(val, getCol())) return false;
    if (match(val, getSquare())) return false;
    return true;
}

Board::Board(std::string filename) {
    index = 0;
    std::ifstream file (filename, std::ifstream::in);
    std::string line;
    std::getline(file, line);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            currBoard.push_back(line[j] - '0');
        }
        std::getline(file, line);
    }
    file.close();
    while (index < BOARD_SIZE*BOARD_SIZE && currBoard[index] != 0) {
        index++;
    }
}

Board::Board(const std::vector<int> skeleton) {
    index = 0;
    currBoard = skeleton;
    while (index < BOARD_SIZE*BOARD_SIZE && currBoard[index] != 0) {
        index++;
    }
}

Board::Board(Board& board, int val) {
    currBoard = std::vector<int> (board.currBoard);
    currBoard[board.index] = val;
    index = board.index + 1;
    while (index < BOARD_SIZE*BOARD_SIZE && currBoard[index] != 0) {
        index++;
    }
}

int Board::getIndex() {
    return index;
}

std::vector<int> Board::getBoard() {
    return currBoard;
}

void Board::print() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << currBoard[i*BOARD_SIZE+j] << " ";
        }
        std::cout << std::endl;
    }
}
