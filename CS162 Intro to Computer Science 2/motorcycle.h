#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "vehicle.h"
#include <string>
class motorcycle:public vehicle {
  public:
    static const std::string getDescription();
  private:
    static const std::string description;
};
#endif
