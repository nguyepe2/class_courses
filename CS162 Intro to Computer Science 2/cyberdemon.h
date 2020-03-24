#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
using namespace std;

class cyberdemon : public demon {
  private:
    int num_cyberdemons;
    std::string name_c;
    static const double cost;
    int hitpoints=100;
  public:
    cyberdemon();
    void set_name_c();
    std::string get_name_c();
    void set_num_cyberdemons();
    int get_num_cyberdemons(); 
    static const double get_cost();
    int getDamage();
};
/*using namespace std;

class cyberdemon : public demon {
  private:

  public:
    cyberdemon();
}; */

#endif
