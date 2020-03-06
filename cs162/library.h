
//#include <string>
class library {
  private:
     hours week[7];
     int num_books;
     book * books;
     cart c;
     librarian l;
     patron p;
  public:
     library();
     library(const library &);
     ~library();
     void add_to_cart(const book &);
     void display_books();
     void empty_cart();
     void set_num_books(const int);
     int get_num_books() const;
     book*get_books() const;
     void set_book(const int, const book&);
     void operator=(const library&);
     void options();
     /*library();
     //cart(const cart &);
     void operator=(const library&);
     ~library();
     void display_daily_hours(std::string);
     void display_weekly_hours();
*/
};
