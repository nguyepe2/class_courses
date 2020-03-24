/*
 * This is the file in which you will implement the functionality required by
 * the assignment.  Make sure to add your name and @oregonstate.edu email
 * address below:
 *
 * Name: Peter Nguyen
 * Email: nguyepe2@oregonstate.edu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "students.h"

/*
 * This function should initialize a single student struct with name, ID, and
 * GPA data.
 *
 * Params:
 *   student - a pointer to the student struct to be initialized.  The memory
 *     for this student will already be allocated before the function is
 *     called.  You simply need to fill its values.  When the function returns,
 *     the fields of this student struct should contain the corresponding
 *     values passed in the other arguments.  Note that this function must
 *     allocate space for the name field and copy the value from name into the
 *     newly-allocated name field.  Make sure that if any of the fields of
 *     student already have memory on the heap allocated to them, you free that
 *     memory before overwriting it with new values.
 *   name - a string containing the student's name.  Note that you'll have to
 *     make a copy of this string to store in the student struct instead of
 *     storing this string directly.
 *   id - an integer ID for the student
 *   gpa - the student's GPA
 */
void init_student(struct student* student, char* name, int id, float gpa) {

   student->name=malloc(sizeof(char)*(strlen(name)+1));
   strcpy(student->name,name);
   student->id=id;
   student->gpa=gpa;
   //printf("%s\t%d\t%f\n", student->name, student->id, student->gpa);

}


/*
 * This function should free the memory allocated by init_student() for a
 * single student.
 *
 * Params:
 *   student - a pointer to the student whose memory should be freed.  Note
 *     that only memory stored *within* this struct should be freed.  The
 *     struct itself should not be freed.
 */
void free_student(struct student* student) {

   free(student->name);
}



/*
 * This function should make a deep copy of a single student.  A deep copy is
 * a copy where pointer fields don't simply have their values (i.e. the memory
 * addresses they point to) copied, but the pointers are dereferenced and
 * copies made of the values themselves.  In other words, for each pointer
 * field in the object being copied, new memory is allocated for a copy of that
 * field to be created, and a pointer to this newly-allocated memory is stored
 * in the copied object.
 *
 * Params:
 *   student - a pointer to the student to be deep copied
 *
 * Return:
 *   Should return a pointer to a deep copy of student.  Memory for this copy
 *   should be allocated by this function.  This memory will have to be freed
 *   using a combination of free_student() and free().
 */
struct student* deep_copy_student(struct student* student) {
   struct student* copy;
   copy=malloc(sizeof(struct student));
   int len=strlen(student->name);
   copy->name=malloc(len+1*sizeof(char));
   strcpy(copy->name,student->name);
   copy->id=student->id;
   copy->gpa=student->gpa;
   return copy;
}


/*
 * This function should allocate space for an array of student structs and
 * initialize their fields using the provided information.  In particular, you
 * should create an array of student structs where the i'th student has the
 * i'th name, the i'th ID, and the i'th GPA from the arrays provided as
 * arguments.  You should use your init_student() function to perform the
 * initialization of each student in the new array.
 *
 * Params:
 *   num_students - the number of students to be stored in the newly allocated
 *     array
 *   names - an array of the names of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   ids - an array of the IDs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   gpas - an array of the GPAs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *
 * Return:
 *   Should return a pointer to the newly allocated and initialized array of
 *   student structs.  The i'th student in this array should have the i'th
 *   name, the i'th ID, and the i'th GPA from the arrays provided as arguments.
 */
struct student* create_student_array(int num_students, char** names, int* ids,
    float* gpas) {
   int i, j;
   struct student* student_array=malloc(sizeof(struct student)*num_students);
   for(i=0; i<num_students; i++) {
      init_student(&(student_array[i]), names[i], ids[i], gpas[i]);
   }

//void init_student(struct student* student, char* name, int id, float gpa) {
  return student_array;
}


/*
 * This function should free all of the memory allocated to an array of
 * student structs, including the memory allocated to the array itself as
 * well as any memory allocated within the individual student structs.  You
 * should use free_student() to free the memory for each individual student.
 *
 * Params:
 *   students - a pointer to the array of student structs whose memory is to
 *     be freed
 *   num_students - the number of students in the array
 */
void destroy_student_array(struct student* students, int num_students) {
   int i;
   for(i=0; i<num_students; i++) {
     free_student(&students[i]);
    // free(students[i]);
   }
   free(students);

}


/*
 * This function should print the name, ID, and GPA of each student in an
 * array, one student per line.
 *
 * Params:
 *   students - the array of students to be printed
 *   num_students - the number of students in the array
 */
void print_students(struct student* students, int num_students) {
   int i;
   for(i=0; i<num_students; i++) {
   printf("Student's name: %s\n", students[i].name);
   printf("Student's id: %d\n", students[i].id);
   printf("Student's gpa: %f\n", students[i].gpa);
   }
}


/*
 * This function should return a pointer to the student in a given array with
 * the highest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the highest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the highest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_max_gpa(struct student* students, int num_students) {
   int i;
   float max=0;
   int track=0;
   for(i=0; i<num_students; i++) {
      if(students[i].gpa > max) {
	 max=students[i].gpa;
	 track=i;
   }
   }
  return &students[track];
}


/*
 * This function should return a pointer to the student in a given array with
 * the lowest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the lowest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the lowest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_min_gpa(struct student* students, int num_students) {

   int i;
   float min=10;
   int track=0;
   for(i=0; i<num_students; i++) {
      if(students[i].gpa < min) {
	 min=students[i].gpa;
	 track=i;
   }
   }
  return &students[track];
}


/*
 * This function should sort students by descending GPA (i.e. highest GPAs
 * at the beginning of the array).  You may implement any sorting algorithm
 * you want, with the following constraints:
 *   - You must sort in place, i.e. you can't allocate additional memory.
 *   - You may not use built-in sorting functions like qsort(), i.e. you must
 *     implement the sort yourself.
 *
 * Params:
 *   students - the array of students to be sorted; when the function returns,
 *     this array will be sorted by descending GPA
 *   num_students - the number of students in the array
 */
void sort_by_gpa(struct student* students, int num_students) {
   /*int i;
   int range=10;
   float min=10;
   struct student* temp;
   do{
      for(i=0; i<num_students; i++)
	 if(students[i].gpa < min) {
	   temp=&students[num_students];
	   students[num_students]=students[i];
	   students[i]=(*temp);
	   range=range-1;
	 }
   
   }while(range!=1);
*/
   int track;
   struct student temp;
   float min=10;
   int range=num_students;
   do{
      track=0;
      min=students[0].gpa;
      for(int i=0; i<range; i++) {
        if(min > students[i].gpa) {
	  track=i;
	  min=students[i].gpa;
	}
      }
      range=range-1;
      temp=students[range];
      students[range]=students[track];
      students[track]=(temp);

   }while(range > 1);
}
