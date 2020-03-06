#ifndef GNOME_H
#define GNOME_H
#include "creature.h"
#include <string>
using namespace std;

class gnome : public creature {
  private:
    int num_gnomes;
    std::string name_g;
    static const double cost;
    int hitpoints=100;
  public:
    gnome();
    void set_name_g();
    std::string get_name_g();
    void set_num_gnomes();
    int get_num_gnomes(); 
    static const double get_cost();
    int getDamage();
};

#endif
