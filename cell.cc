#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
   Info info;
   info.row = r;
   info.col = c;
   info.state = isOn;
   return info;   
}

void Cell::setOn() {
  isOn = true;
}
  
void Cell::toggle() {
  if (isOn) {
    isOn = false;
  } else {
    isOn = true;
  }
  this->notifyObservers(SubscriptionType::All);
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &) {
   this->toggle();
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
