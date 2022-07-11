#include "yettoku.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef Yettoku board;

board *parseInput(const std::string &fileName) {
  std::ifstream input{fileName};
  char *line = new char[1024];
  input.getline(line, 1024);
  line = strtok(line, " ,[]");
  std::vector<int> gridArr{};

  while (line != nullptr) {
    int value = atoi(line);
    gridArr.push_back(value);
    line = strtok(nullptr, " ,[]");
  }

  Grid *grid = new Grid(gridArr);
  board *newBoard = new board(grid);
  return newBoard;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }
  board *sudoku = parseInput(argv[1]);
  sudoku->run();
  sudoku->printBoard();
  return 0;
}