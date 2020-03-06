#ifndef DEMON_H
#define DEMON_H
#include "creature.h"
#include <string>
using namespace std;

class demon : public creature {
  private:
    int num_demons;
    std::string name_d;
    static const double cost;
  public:
    demon();
    void set_name_d();
    std::string get_name_d();
    void set_num_demons();
    int get_num_demons(); 
    static const double get_cost();
    int getDamage();
};
/*
class demon : public creature {
  private:

  public:
    demon();
};
*/
#endif
