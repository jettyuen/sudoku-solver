#pragma once
#include <map>
#include <set>
#include <vector>

// Methods for storing and manipulating possible values for each cell.
// A map that stores the possible values for each cell.
// - The key is the index of the cell, and the value is a set of possible
// values.
// - The set of possible values is a set of integers, where each integer is a
// possible value for the cell.
// A set that contains the indices of the cells that have no possible values.
// - The set is a set of integers, where each integer is the index of the cell
// that has no possible values.

class Grid {
public:
  struct Cell {
    int value;
    int index;
    bool isFixed;
    std::set<int> possibleValues;
    Cell(int value, int index, bool isFixed)
        : value(value), index(index), isFixed(isFixed) {}
  };

  Grid(std::vector<int> &grid);
  std::vector<Cell> cells{};
  bool checkCell(int index);
  Cell getCell(int index);
  ~Grid();

private:
  void initGrid(std::vector<int> &grid);
  int getNonet(int index);
  int getNonetStart(int nonet);
  bool checkNonet(int index);
};