#ifndef HUMAN_H
#define HUMAN_H
#include "creature.h"
#include <string>
using namespace std;

class human : public creature {
  private:
    int num_humans;
    std::string name_h;
    static const double cost;
    int hitpoints=100;
  public:
    human();
    void set_name_h();
    std::string get_name_h();
    void set_num_humans();
    int get_num_humans(); 
    static const double get_cost();
};

#endif
