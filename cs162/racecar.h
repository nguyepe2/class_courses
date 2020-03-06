#ifndef RACECAR_H
#define RACECAR_H
#include "vehicle.h"
#include <string>
class racecar:public vehicle {
  public:
    static const std::string getDescription();
  private:
    static const std::string description;
};
#endif
