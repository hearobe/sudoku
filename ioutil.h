#ifndef SUDOKU_IOUTIL_H
#define SUDOKU_IOUTIL_H

#include <string>
#include <tuple>
#include <regex>
#include <iostream>
#include "grid.h"

enum CommandType { ADD, DELETE, END, INVALID };

class IOUtil {
public:
    IOUtil();
    ~IOUtil();

    std::string getCommandParameters(CommandType type, std::string command);

    CommandType getCommandType(std::string command);

    void printWelcomeMsg();
    void printCurrentBoard(Grid g);
};

#endif //SUDOKU_IOUTIL_H
