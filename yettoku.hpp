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
  Grid *_grid;

  void solve(Grid grid, int index);
};