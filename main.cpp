#include <iostream>
#include <string>
#include "grid.h"
#include "newgames.h"
#include "ioutil.h"

int main() {
    Grid grid = Grid(game1);
    IOUtil io = IOUtil();

    io.printWelcomeMsg();
    std::string command;
    while (!grid.isComplete()) {
        io.printCurrentBoard(grid);

        std::getline(std::cin, command);

        CommandType type = io.getCommandType(command);
        if (type == INVALID) {
            std::cout << "\nInvalid command\n";
            continue;
        }
        if (type == END) {
            return 0;
        }
        std::string commandParameters = io.getCommandParameters(type, command);
        if (commandParameters.empty()) {
            std::cout << "\nInvalid parameters\n";
            continue;
        }

        switch(type){
            case ADD: {
                bool isAddedSuccessfully = grid.addNumber(
                        std::stoi(command.substr(4,1)),
                        std::stoi(command.substr(6,1)),
                        std::stoi(command.substr(8,1)));
                if (!isAddedSuccessfully) {
                    std::cout << "\nSquare already filled\n";
                }
                break;
            }
            case DELETE: {
                bool isDeletedSuccessfully = grid.removeNumber(std::stoi(command.substr(4,1)),
                                                                std::stoi(command.substr(6,1)));
                if (!isDeletedSuccessfully) {
                    std::cout << "\nCannot be deleted\n";
                }
                break;
            }
            default:
                continue;
        }
    }
}
