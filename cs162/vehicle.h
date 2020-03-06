#ifndef VEHICLE_H
#define VEHICLE_H

class vehicle {
  protected:
     int wheels;
     int speed;
     bool motor;
  public:
     void set_wheels(int);
     int get_wheels();
     void set_speed(int);
     int get_speed();
     void set_motor(bool);
     int get_motor();
     bool operator>(const vehicle&);
     creature * driver;
     creature * getDriver();
     void setDriver(creature *);
     int getDistance();
     string getVehicle();

};
#endif
