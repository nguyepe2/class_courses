#ifndef POKEMON_H
#define POKEMON_H
#include "event.h"

class pokemon : public event {
  private:
    int rng;
  public:
    pokemon();
    void get_event();
    virtual void get_capture_rate();

};

#endif
