#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using namespace std;
class creature {
  protected:
    int type;
    int strength;
    int hitpoints;
    std::string name;
    double payoff;
    double cost;
    //std::string getSpecies(int);
  public:
    creature();
    std::string getSpecies(int);
    creature(int newType, int newStrength, int newHit);
    int getDamage();
    void setStrength(int);
    int getHitpoints();
    void setHitpoints(int);
    int getDriver();

};
#endif
