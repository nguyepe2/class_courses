//#include <string>
class librarian {
  private:
     std::string name;
     int id;
  public:
     void change_library_hours();
     void add_new_books(const cart &);
     void remove_old_books();
     void view_all_books_checked_out();
     void view_specific_book_checked_out(std::string);
};
