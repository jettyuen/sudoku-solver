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
    Cell cell{value, {}};
    cellsByIndex[index] = cell;
    if (value == 0) {
      for (int j{1}; j < 10; j++) {
        cellsByIndex[index].possibilities.insert(j);
      }
    }
  }
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

void Grid::checkNonet(int index) {
  int nonet = getNonet(index);
  int startIndex = getNonetStart(nonet);
  Cell cell = cellsByIndex[index];
  for (int i{0}; i < 3; i++) {
    for (int j{0}; j < 3; j++) {
      int currentIndex = startIndex + (i * 9) + j;
      int value = cellsByIndex[currentIndex].value;
      if (value != 0) {
        cellsByIndex[index].possibilities.erase(value);
      }
    }
  }
}

void Grid::checkRow(int index) {
  Cell cell = cellsByIndex[index];
  for (int i{0}; i < 9; i++) {
    int currentIndex = (index / 9) * 9 + i;
    int value = cellsByIndex[currentIndex].value;
    if (value != 0) {
      cellsByIndex[index].possibilities.erase(value);
    }
  }
}

void Grid::checkColumn(int index) {
  Cell cell = cellsByIndex[index];
  for (int i{0}; i < 9; i++) {
    int currentIndex = (i * 9) + (index % 9);
    int value = cellsByIndex[currentIndex].value;
    if (value != 0) {
      cellsByIndex[index].possibilities.erase(value);
    }
  }
}

void Grid::updatePossibilities(int index) {
  checkNonet(index);
  checkRow(index);
  checkColumn(index);
}

void Grid::printPossibilities(int index) {
  Cell cell = cellsByIndex[index];
  auto start = cell.possibilities.begin();

  while (start != cell.possibilities.end()) {
    std::cout << " " << *start << " ";
    start++;
  }
  std::cout << std::endl;
}