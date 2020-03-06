#ifndef BALROG_H
#define BALROG_H
#include "demon.h"
using namespace std;

class balrog : public demon {
  private:
    int num_balrogs;
    std::string name_b;
    static const double cost;
    int hitpoints=100;
  public:
    balrog();
    void set_name_b();
    std::string get_name_b();
    void set_num_balrogs();
    int get_num_balrogs(); 
    static const double get_cost();
    int getDamage();
};

#endif
