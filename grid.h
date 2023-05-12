#ifndef SUDOKU_GRID_H
#define SUDOKU_GRID_H

#include <array>
#include <string>

class Grid {
    std::array<std::array<int, 9>, 9> grid;
    std::array<std::array<int, 9>, 9> perm;
    int emptySlots;

public:
    Grid(std::array<std::array<int, 9>, 9> g);
    ~Grid();
    bool addNumber(int row, int col, int num);
    bool removeNumber(int row, int col);
    bool isComplete();
    std::string toString();

    bool _isColumnsValid();
    bool _isRowsValid();
    bool _isSquaresValid();
};

#endif //SUDOKU_GRID_H
