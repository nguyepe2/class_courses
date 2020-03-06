#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>

struct hours {
  int begin_time;
  int end_time;
};

struct book {
  std::string title;
  int num_authors;
  std::string *authors;
  int year;
  int copies;
};

#endif
