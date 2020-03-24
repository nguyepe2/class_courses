#include <string>
using namespace std;

struct county {
  string name; //name of county
  string *city; //name of cities in county
  int cities; //number of cities in county
  int population; //total population of county
  float avg_income; //avg household income
  float avg_house; // avg household price
};

struct state {
  string name; //name of state
  struct county *c; //name of counties
  int counties; //number of counites in state
  int population; //total population of state
};

bool is_valid_arguments(char *[], int);

state * create_states(int);

void get_state_data(state *, int, ifstream &);

county * create_counties(int);

void get_county_data(county *, int, ifstream &);

void delete_info(state **, int);

