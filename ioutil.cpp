#include "ioutil.h"


IOUtil::IOUtil() {}

CommandType IOUtil::getCommandType(std::string command) {
    if (command.substr(0,3) == "add") {
        return ADD;
    } else if (command.substr(0,3) == "del") {
        return DELETE;
    } else if (command.substr(0,3) == "end") {
        return END;
    } else {
        return INVALID;
    }
}

std::string IOUtil::getCommandParameters(CommandType type, std::string command) {
    switch(type){
        case ADD: {
            std::regex addPattern(R"(\d,\d,\d)");
            if (std::regex_match(command.substr(4), addPattern)) {
                return command.substr(4);
            } else {
                return "";
            }
            break;
        }
        case DELETE: {
            std::regex delPattern(R"(\d,\d)");
            if (std::regex_match(command.substr(4), delPattern)) {
                return command.substr(4);
            } else {
                return "";
            }
            break;
        }
        default:
            return "";
    }
}

void IOUtil::printWelcomeMsg() {
    std::cout << "Welcome to Sudoku!\n\n";
    std::cout << "Try the following commands:\n"
                 "Add a number: add [row],[column],[number]\n"
                 "Delete a number: del [row],[column]\n"
                 "End game: end\n";
}

void IOUtil::printCurrentBoard(Grid g){
    std::cout << "\n---------------------\n Your current board:\n";
    std::cout << g.toString();
    std::cout << "---------------------\n" << "Next move:\n";
}

IOUtil::~IOUtil(){}
