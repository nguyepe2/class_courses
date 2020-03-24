/*
 * This file contains executable code for testing your work in this assignment.
 */

#include <stdio.h>
#include <stdlib.h>

#include "students.h"


/*
 * This is the total number of students in the testing data set.
 */
#define NUM_TESTING_STUDENTS 8


/*
 * These are the names of the students that'll be used for testing.
 */
char* TESTING_NAMES[] = {
  "Luke Skywalker",
  "Princes Leia",
  "Chewbacca",
  "Han Solo",
  "Lando Calrissian",
  "Darth Vader",
  "C-3PO",
  "R2-D2"
};


/*
 * These are the student IDs for the students in the array above that will be
 * used for testing.
 */
int TESTING_IDS[] = {
  933111111,
  933222222,
  933333333,
  933444444,
  933555555,
  933666666,
  933777777,
  933888888
};


/*
 * These are the GPAs of the students above that will be used for testing.
 */
float TESTING_GPAS[] = {
  3.75,
  4.0,
  3.0,
  2.5,
  3.67,
  1.33,
  3.25,
  3.9
};


int main(int argc, char** argv) {
  struct student student;
  struct student* copy = NULL, * max_gpa, * min_gpa, * students = NULL;
  int i;

  /*
   * Initialize a student using init_student() and print the results.  The
   * power of pointers lets us use print_students() this way!
   */
  init_student(&student, TESTING_NAMES[0], TESTING_IDS[0], TESTING_GPAS[0]);
  printf("\n== Here are the results of init_student():\n");
  print_students(&student, 1);

  /*
   * Make a copy of student using deep_copy_student() and compare the results.
   */
  copy = deep_copy_student(&student);
  printf("\n== Here's that student (left) and its deep copy (right):\n");
  if (copy) {
    printf("name (value):   %s\t%s\n", student.name, copy->name);
    printf("name (pointer): %p\t%p\n", student.name, copy->name);
    printf("id:             %d\t%d\n", student.id, copy->id);
    printf("gpa:            %f\t%f\n", student.gpa, copy->gpa);
  }

  /*
   * Create an array of students using create_student_array() and print the
   * results.
   */
  students = create_student_array(NUM_TESTING_STUDENTS, TESTING_NAMES,
    TESTING_IDS, TESTING_GPAS);
  printf("\n== Here are the results of create_student_array():\n");
  print_students(students, NUM_TESTING_STUDENTS);

  /*
   * Use find_max_gpa() to find the student with the highest GPA and print
   * the result.
   */
  max_gpa = find_max_gpa(students, NUM_TESTING_STUDENTS);
  printf("\n== Here's the student with the highest GPA:\n");
  print_students(max_gpa, 1);

  /*
   * Use find_min_gpa() to find the student with the lowest GPA and print
   * the result.
   */
  min_gpa = find_min_gpa(students, NUM_TESTING_STUDENTS);
  printf("\n== Here's the student with the lowest GPA:\n");
  print_students(min_gpa, 1);

  /*
   * Use sort_by_gpa() to order the students by decreasing GPA and print the
   * results.
   */
  sort_by_gpa(students, NUM_TESTING_STUDENTS);
  printf("\n== Here are the students ordered by decreasing GPA:\n");
  print_students(students, NUM_TESTING_STUDENTS);

  /*
   * Free all of the memory we allocated here.  You should use valgrind to
   * verify that you don't have memory leaks.
   */
  free_student(&student);
  free_student(copy);
  free(copy);
  destroy_student_array(students, NUM_TESTING_STUDENTS);

  return 0;
}
