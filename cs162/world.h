#ifndef WORLD_H
#define WORLD_H
#include <string>
using namespace std;

class world {
  private:
    int money;
    static const double cost;
    int num_humans=0;
    int num_balrogs=0;
    int num_cyberdemons=0;
    int num_elfs=0;
    int num_gnomes=0;
    std::string name;
    std::string name_h;
    std::string name_b;
    std::string name_c;
    std::string name_e;
    std::string name_g;
  public:
    world();
    ~world();
    void set_money();
    int get_money();
    
    const  double get_cost();
    
    void set_num_humans();
    int get_num_humans(); 
    void set_name_h();
    std::string get_name_h();
    
    void set_num_balrogs();
    int get_num_balrogs(); 
    void set_name_b();
    std::string get_name_b();

    void set_num_cyberdemons();
    int get_num_cyberdemons(); 
    void set_name_c();
    std::string get_name_c();

    void set_num_elfs();
    int get_num_elfs(); 
    void set_name_e();
    std::string get_name_e();

    void set_num_gnomes();
    int get_num_gnomes();
    void set_name_g();
    std::string get_name_g();

    void battle();
};

#endif
