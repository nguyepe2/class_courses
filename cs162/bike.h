#ifndef BIKE_H
#define BIKE_H
#include "vehicle.h"
#include <string>
class bike:public vehicle {
  public:
    static const std::string getDescription();
  private:
    static const std::string description;
};
#endif
