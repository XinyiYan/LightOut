#include <iostream>
#include "grid.h"
#include "window.h"
using namespace std;

Grid::Grid(): gridSize{0}, is_init{false}, td{nullptr}, gd{nullptr} {}

Grid::~Grid() {
  delete td;
  delete gd;
}

void Grid::clearGrid() {
   theGrid.clear();
   delete td;
   delete gd;
   gridSize = 0;
   is_init = false;
}

bool Grid::isWon() const {
  for (int i = 0; i < gridSize; ++i) {
     for (int j = 0; j < gridSize; ++j) {
         if ( theGrid[i][j].getState()) {
            return false;
         }
     }
  }
  return true;
}

void Grid::init(int n, Xwindow &w) {
  if (is_init) {
     this->clearGrid();
  } 
  if ( n >= 1) {
    gridSize = n;
    is_init = true;
    for (int i = 0; i < n; ++i) {
      vector<Cell> v;
      for (int j = 0; j < n; ++j) {
         Cell c;
         c.setCoords(i,j);
         v.push_back(c);
      }
      theGrid.push_back(v);
    }
    td = new TextDisplay{n};
    gd = new GraphicsDisplay{n,w};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (i >= 1) {   // attach north cell
            theGrid[i][j].attach(&theGrid[i-1][j]);
         }
         if (i <= n-2) {  // attach south cell
            theGrid[i][j].attach(&theGrid[i+1][j]);
         }
         if (j >= 1) {  // attach west cell
            theGrid[i][j].attach(&theGrid[i][j-1]);
         }
         if (j <= n-2) { // attach east cell
            theGrid[i][j].attach(&theGrid[i][j+1]);
         }
         Observer *p = td;
         theGrid[i][j].attach(p);
         Observer *q = gd;
         theGrid[i][j].attach(q);
      }
   }
 }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
  theGrid[r][c].notifyObservers(SubscriptionType::All);  
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly);   
}

void Grid::init(int r, int c) {
  this->turnOn(r,c);
}

ostream &operator<<(ostream &out, const Grid &g) {
  out << *(g.td);
  return out;
}

