#include "graphicsdisplay.h"
#include "cell.h"
#include "info.h"
#include "window.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int n,Xwindow &w): w{w}, gridSize{n}, width{500/n} {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
       w.fillRectangle(width*j, width*i, width, width);
    }
  }
}

GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::notify(Subject &whoNotified) {
  int row = whoNotified.getInfo().row;
  int col = whoNotified.getInfo().col;
  if (whoNotified.getInfo().state) {
     w.fillRectangle(width*col, width*row, width, width, 0); // on: coloured with white
  } else {
     w.fillRectangle(width*col, width*row, width,width); // off: coloured with black
  }
}
  

SubscriptionType GraphicsDisplay::subType() const {
  return SubscriptionType::All;
}
