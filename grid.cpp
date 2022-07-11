#include "grid.hpp"
#include <iostream>

Grid::Grid(std::vector<int> &grid) { initGrid(grid); }

Grid::~Grid() {}

void Grid::initGrid(std::vector<int> &grid) {
  for (int i{0}; i < 81; i++) {
    int value = grid[i];
    int row = i / 9;
    int col = i % 9;
    int index = row * 9 + col;
    if (value != 0) {
      cells.push_back(Cell(value, index, true));
    } else {
      int index = row * 9 + col;
      value = 0;
      cells.push_back(Cell(value, index, false));
    }
  }
}

void fixCell(Grid::Cell &cell, int newValue) {
  cell.isFixed = true;
  cell.value = newValue;
}

int Grid::getNonet(int index) {
  int nonetRow = index / 9;
  int nonetCol = index % 9;
  int nonet = ((nonetRow / 3) * 3) + (nonetCol / 3);
  return nonet;
}

int Grid::getNonetStart(int nonet) {
  int nonetCol = nonet % 3;
  int nonetRow = (nonet / 3) * 3;
  int nonetStart = (nonetRow * 9) + (nonetCol * 3);
  return nonetStart;
}

bool Grid::checkNonet(int index) {
  int nonet = getNonet(index);
  int startIndex = getNonetStart(nonet);
  std::set<int> nonetValues{cells[index].value};
  std::cout << index << std::endl;
  for (int i{0}; i < 3; i++) {
    for (int j{0}; j < 3; j++) {
      int currentIndex = startIndex + (i * 9) + j;
      int value = cells[currentIndex].value;
      std::cout << " " << value << " ";
    }
    std::cout << std::endl;
  }
  // DEBUG:
  return true;
}

bool Grid::checkCell(int index) { return checkNonet(index); }