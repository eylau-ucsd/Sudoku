CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=SudokuSolver

all: $(OUTFILES)

SudokuSolver: SudokuSolver.cpp Board.cpp SudokuSolver.h
	$(CXX) $(CXXFLAGS) -o SudokuSolver SudokuSolver.cpp Board.cpp

clean:
	$(RM) $(OUTFILES) *.o
