#pragma once
#include <map>
#include <set>
#include <vector>

struct Cell {
  int value;
  std::set<int> possibilities;
};

class Grid {
public:
  Grid(std::vector<int> &grid);
  ~Grid();

  std::map<int, Cell> cellsByIndex;
  void updatePossibilities(int index);

private:
  void initGrid(std::vector<int> &grid);
  // Nonet logic
  int getNonet(int index);
  int getNonetStart(int nonet);
  void checkNonet(int index);
  // Row logic
  void checkRow(int index);
  // Column logic
  void checkColumn(int index);
  void printPossibilities(int index);
};