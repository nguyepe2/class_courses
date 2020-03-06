#ifndef POKESTOP_H
#define POKESTOP_H
#include "event.h"

class pokestop : public event {
  private:
     int pokeballs;

  public:
     void get_event();
     void set_pokeballs();
     int get_pokeballs();

};

#endif
