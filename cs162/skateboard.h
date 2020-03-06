#ifndef SKATEBOARD_H
#define SKATEBOARD_H
#include "vehicle.h"
#include <string>
class skateboard : public vehicle {
  public:
    static const std::string getDescription();
  private:
    static const std::string description;
};
#endif
