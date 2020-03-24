#ifndef LOCATION_H
#define LOCATION_H

class location {
  private:
  public:
     location();
     void make_map(int argc, char (*argv[]));
     void place_event(char *argv[]);
     void get_location(char *argv[], int *map);

};

#endif
