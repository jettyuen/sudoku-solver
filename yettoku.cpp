#include "yettoku.hpp"
#include <fstream>
#include <iostream>
#include <vector>

Yettoku::Yettoku(Grid *grid) : _grid(grid) {}

void Yettoku::run() { solve(*_grid, 0); }

void Yettoku::solve(Grid grid, int index) {

  // This loop gets indexes for nonets only once.
  // for (int i{0}; i < 81; i += 3) {
  //   if (i % 9 == 0) {
  //     i += 18;
  //   }
  // }

  grid.updatePossibilities(index);

  if (grid.cellsByIndex[index].possibilities.size() == 0 &&
      grid.cellsByIndex[index].value == 0) {
    return;
  } else if (index == 80) {
    if (grid.cellsByIndex[index].value == 0) {
      grid.cellsByIndex[index].value =
          *grid.cellsByIndex[index].possibilities.begin();
    }
    *_grid = grid;
    return;
  } else if (grid.cellsByIndex[index].value != 0) {
    solve(grid, index + 1);
  }

  auto it = grid.cellsByIndex[index].possibilities.begin();
  while (it != grid.cellsByIndex[index].possibilities.end()) {
    grid.cellsByIndex[index].value = *it;
    solve(grid, index + 1);
    it++;
  }
}
void Yettoku::printBoard() {
  for (int i = 0; i < 9; i++) {
    if (i % 3 == 0) {
      std::cout << "*---------*---------*---------*" << std::endl;
    }
    for (int j = 0; j < 9; j++) {
      int index = i * 9 + j;
      if (index % 3 == 0) {
        std::cout << "|";
      }
      int value = _grid->cellsByIndex[index].value;
      if (value > 9) {
        std::cout << value << " ";
      } else {
        std::cout << " " << value << " ";
      }
      if (j == 8) {
        std::cout << "|";
      }
    }
    std::cout << std::endl;
    if (i == 8) {
      std::cout << "*---------*---------*---------*" << std::endl;
    }
  }
}