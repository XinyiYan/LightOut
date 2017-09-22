#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer {
   Xwindow &w;
   int gridSize; 
   int width; 
  public:
  GraphicsDisplay(int n,Xwindow &w); // Constructor 
  ~GraphicsDisplay(); // destructor
  void notify(Subject &whoNotified) override; // 
  SubscriptionType subType() const override;
};

#endif  
