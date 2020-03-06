#ifndef EVENT_H
#define EVENT_H
#include "location.h"

class event:public location {
  private:

  public:
     virtual void get_event()=0;

};

#endif
