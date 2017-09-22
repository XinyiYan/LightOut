#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  Xwindow w;
  int moves = 0;

  // You will need to make changes to this code.

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n,w);
      }
      else if (cmd == "init") {
        while(true) {
          int x, y;
          cin >> x >> y;
          if ( x == -1 && y == -1) {
             break;
          } else {
             g.init(x,y);
          }
        }
      }
      else if (cmd == "game") {
        cin >> moves;
        if (moves == 1) {
           cout << "1 move left" << endl;
        } else {
           cout << moves << " moves left" << endl;
        }
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
        if (moves > 0) {
          g.toggle(r,c);
          moves -= 1;
          if (moves == 1) {
            cout << "1 move left" << endl;
          } else {
            cout << moves << " moves left" << endl;
          }
        }
        if (g.isWon() && (moves >= 0)) {
           cout << "Won" << endl;
           break;
        } else if (moves == 0) {
           cout << "Lost" << endl;
           break;
        }  
      }
    }
  }
  catch (ios::failure &) {
  }
}
