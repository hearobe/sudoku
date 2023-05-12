#include "grid.h"

Grid::Grid(std::array<std::array<int, 9>, 9> g) {
    this->grid = g;
    this->perm = std::array<std::array<int, 9>, 9> {0};
    emptySlots = 0;
    for(int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            if (this->grid[i][j] == 0) {
                emptySlots++;
            } else {
                this->perm[i][j] = 1;
            }
        }
    }
}

bool Grid::addNumber(int row, int col, int num) {
    if (this->grid[row][col] != 0) {
        return false;
    }

    this->grid[row][col] = num;
    emptySlots--;
    return false;
}

bool Grid::removeNumber(int row, int col) {
    if (this->perm[row][col] == 1) {
        return false;
    }
    if (this->grid[row][col] == 0) {
        return true;
    }

    this->grid[row][col] = 0;
    emptySlots++;
    return true;
}

bool Grid::_isColumnsValid() {
    std::array<int, 9> used;
    for (int col = 0; col < 9; col++) {
        used = {0};
        for (int i = 0; i < 9; i++) {
            if (used[this->grid[i][col]] != 0) {
                return false;
            }
            used[this->grid[i][col]] = 1;
        }
    }

    return true;
}

bool Grid::_isRowsValid() {
    std::array<int, 9> used;
    for (int row = 0; row < 9; row++) {
        used = {0};
        for (int i = 0; i < 9; i++) {
            if (used[this->grid[row][i]] != 0) {
                return false;
            }
            used[this->grid[row][i]] = 1;
        }
    }
    return true;
}

bool Grid::_isSquaresValid() {
    std::array< std::array<int, 2>, 9 > squares = {{
        {0,0},
        {0,1},
        {0,2},
        {1,0},
        {1,1},
        {1,2},
        {2,0},
        {2,1},
        {2,2},
    }};

    int sqRow, sqCol;
    std::array<int, 9> used;
    for(int j = 0; j< 9; j++) {
        sqRow = squares[j][0];
        sqCol = squares[j][1];
        used = {0};
        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                if (used[this->grid[sqRow + i][sqCol + j]] != 0) {
                    return false;
                }
                used[this->grid[sqRow + i][sqCol + j]] = 1;
            }
        }
    }
    return true;
}

bool Grid::isComplete() {
    if (emptySlots != 0) {
        return false;
    }

    if (Grid::_isColumnsValid() && Grid::_isRowsValid() && Grid::_isSquaresValid()) {
        return true;
    }
    return false;
}

std::string Grid::toString() {
    std::string str;
    for ( auto it = this->grid.begin(); it != this->grid.end(); ++it ) {
        for ( auto jt = it->begin(); jt != it->end(); ++jt ) {
            str += std::to_string(*jt) + " ";
//            std::cout << ' ' << *jt;
        }
        str += '\n';
    }
    return str;
}

Grid::~Grid(){}
