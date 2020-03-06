#ifndef CART_H
#define CART_H
#include "structs.h"


class cart{
  private:
     book *books;
     int num_books;
     void resize_books(int);
  public:
     cart();
     cart(const cart &);
     ~cart();
     void add_to_cart(const book &);
     void display_books();
     void empty_cart();
     void set_num_books(const int);
     int get_num_books() const;
     book*get_books() const;
     void set_book(const int, const book&);
     void operator=(const cart&);
     void options();



};

#endif
