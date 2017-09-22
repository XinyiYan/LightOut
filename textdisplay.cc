#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
  if (n >= 1) {
    for (int i = 0; i < n; ++i) {
      vector<char> v;
      for (int j = 0; j < n; ++j) {
        v.push_back('_');
      }
      theDisplay.push_back(v);
    }
  }
}

void TextDisplay::notify(Subject &whoNotified) {
   int r = whoNotified.getInfo().row;
   int c = whoNotified.getInfo().col;
   if (whoNotified.getInfo().state) {
       theDisplay[r][c] = 'X';
   } else {
       theDisplay[r][c] = '_';
   }
}


TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int i = 0; i < td.gridSize; ++i) {
    for (int j = 0; j < td.gridSize; ++j) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}
