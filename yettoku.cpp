#include "yettoku.hpp"
#include <fstream>
#include <iostream>
#include <vector>

Yettoku::Yettoku(Grid *grid) : _grid(grid) {}

void Yettoku::run() {
  std::cout << "Yettoku::run()" << std::endl;
  if (solve(*_grid)) {
    std::cout << "Solved!" << std::endl;
  } else {
    std::cout << "Could not solve!" << std::endl;
  }
}

bool Yettoku::solve(Grid grid) {
  std::cout << "Yettoku::solve()" << std::endl;
  updatePossibilities(grid);
  for (int i{0}; i < 81; i += 3) {
    _grid->checkCell(i);
  }
  return true;
}
void Yettoku::printBoard() {
  std::cout << "Yettoku::printBoard()" << std::endl;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int index = i * 9 + j;
      int value = _grid->getCell(index).value;
      if (value > 9) {
        std::cout << value << " ";
      } else {
        std::cout << " " << value << " ";
      }
    }
    std::cout << std::endl;
  }
}
void Yettoku::updatePossibilities(Grid &grid) {
  std::cout << "Yettoku::updatePossibilities()" << std::endl;
}