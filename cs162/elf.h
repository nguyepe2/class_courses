#ifndef ELF_H
#define ELF_H
#include "creature.h"
using namespace std;

class elf : public creature {
  private:
    int num_elfs;
    std::string name_e;
    static const double cost;
    int hitpoints=100;
  public:
    elf();
    void set_name_e();
    std::string get_name_e();
    void set_num_elfs();
    int get_num_elfs(); 
    static const double get_cost();
    int getDamage();
};
/*class elf : public creature {
  private:

  public:
    elf();
    int getDamage();
}; */

#endif
