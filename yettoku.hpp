#pragma once
#include "grid.hpp"
#include <vector>

class Yettoku {
public:
  Yettoku(Grid *grid);
  ~Yettoku();
  void run();
  void printBoard();

private:
  bool solve(Grid grid);
  void updatePossibilities(Grid &grid);

  Grid *_grid;
};