#ifndef PATRON_H
#define PATRON_H
//#include <string>

class patron {
  private:
     std::string name;
     int id;
     int books_checked_out;
  public:
     void check_out_books(const cart &);
     void check_in_books(const cart &);
     void view_my_books_out();
};

#endif
