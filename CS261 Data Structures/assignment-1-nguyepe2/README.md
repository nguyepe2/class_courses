# Assignment 1
**Due by 11:59pm on Monday, 10/9/2017**

**Demo due by 11:59pm on Monday 10/23/2017**

This assignment is intended to give you practice writing C code, allocating and freeing memory in C, and working with pointers.  There are several parts to the assignment, each described below.

For this assignment, you are provided with some starter code that defines the structures you'll be working with and prototypes the functions you'll be writing.  *It's important that you don't modify the function prototypes.*  To help grade your assignment, we will use a set of unit tests that assume these functions exist and have the same prototypes that are defined in the starter code.  If you change the prototypes, it will cause the unit tests to break, and your grade for the assignment will likely suffer.  Feel free, however, to write any additional functions you need to accomplish the tasks described below.

In this assignment, your work will be limited to the file `students.c`, where you will implement the functions described below.  In addition to the descriptions below, there is thorough documentation in `students.c` describing how each function should behave.

## 1. Implement a function to initialize a single `struct student`

In `init_student()`, implement a function that initializes the values of a single student.  In particular, this function will be passed a pointer to an already-allocated student along with a value for `name`, `id`, and `gpa`.  You should allocate memory on the heap to store a copy of `name`, copy `name` into that memory, and then assign the copy of `name`, `id`, and `gpa` to the corresponding fields in the student whose pointer was passed to the function.  Other than allocating memory for a copy of `name`, your function won't need to allocate any memory.  However, make sure that if any of the fields of the student already have memory on the heap allocated to them, you free that memory before overwriting it with new values.

## 2. Implement a function to free the memory held by a single `struct student`

In `free_student()`, implement a function that frees any memory that was allocated by `init_student()` for a single student.  This function will be passed a pointer to the student whose held memory is to be freed.  Note that you should only free memory held by the fields of that student and not the student itself.

## 3. Implement a function to make a deep copy of a `struct student`

There are two ways to make a copy of a `struct`: a *shallow copy* and a *deep copy*.  When making a shallow copy, pointer fields pointing to memory allocated on the heap simply have their memory address values copied into the new `struct`, so that the original `struct` and its copy both end up holding pointers to the same place in memory.  When making a deep copy, on the other hand, new memory is allocated to create a copy of any memory pointed to by the original `struct`, and a pointer to the copied memory is stored in the copied `struct`.  This means that no field in the original `struct` will point to the same location in memory as the corresponding field in the copied `struct`, though each pointer field will still point to the same *value* stored in different places in the heap.

In `deep_copy_student()`, write a function to make a deep copy of a student.  You should allocate space for this copy on the heap and return a pointer to it from the function.

## 4. Implement a function to create an array of `struct student`s

In `create_student_array()`, implement a function to allocate and initialize an array of students, and return a pointer to this newly-created array.  This function will be provided with the size of the array to create along with arrays specifying the names, IDs, and GPAs of the students to be stored in the array.  You should use your `init_student()` function to initialize the values of each student in the array.  In the returned array, the `i`th student should have the `i`th name, the `i`th ID, and the `i`th GPA.

## 5. Implement a function to free the memory in an array of `struct student`s

In `destroy_student_array()`, implement a function that frees all of the memory allocated by `create_student_array()`.  In particular, you should use your `free_student()` function to free the memory held by each individual student, and then you should free the memory held by the array itself.

## 6. Implement a function to print an array of `struct student`s

In `print_students()`, implement a function that prints the name, ID, and GPA of each student in an array, one student per line.

## 7. Implement functions to find the students in an array with the lowest and highest GPA

In `find_min_gpa()` and `find_max_gpa()`, implement functions to respectively find the student with the lowest GPA and the one with the highest GPA in an array.  These functions should return a pointer to these students.  The returned pointers should point to a location within the original array, i.e. these functions should not allocate any new memory.

## 8. Implement a function to sort the students in an array by descending GPA

In `sort_by_gpa()`, implement a function to order the students in an array by descending GPA (i.e. with the highest GPAs at the beginning of the array).  You may use any sorting algorithm you like.  This function should abide by the following constraints:

* It should sort the students *in place*.  In other words, you should not allocate memory for a new array in this function.
* It should not use built-in functions like `qsort()`.  In other words, you have to implement the sorting yourself.

## Testing your work

In addition to the skeleton code in `students.h` and `students.c`, you are also provided with some application code in `test.c` to help verify that your functions are behaving the way you want them to.  In particular, the code in `test.c` calls the functions from `students.c`, passing them appropriate arguments, and then prints the results.  You can use the provided `Makefile` to compile all of the code in the project together, and then you can run the testing code as follows:
```
make
./test
```

In order to verify that your memory freeing functions work correctly, it will be helpful to run the testing application through `valgrind`.

## Submission

As always, we'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub. Just make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom. A good way to check whether your files are safely submitted is to look at the master branch of your assignment repo on the github.com website (i.e. http://github.com/OSU-CS261-F17/assignment-1-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

## Grading criteria

The assignment is worth 100 total points, broken down as follows:

* 10 points: `init_student()` initializes the values of a `struct student` as described above
* 10 points: `free_student()` frees the memory held by a `struct student` as described above (no memory leaks!)
* 10 points: `deep_copy_student()` makes a valid deep copy of a `struct student` as described above
* 10 points: `create_student_array()` allocates and initializes an array of `struct student`s as described above
* 10 points: `destroy_student_array()` frees the memory held by an array of `struct student`s as described above (no memory leaks!)
* 10 points: `print_students()` prints an array of students as described above
* 10 points: `find_min_gpa()` finds the student with the lowest GPA as described above
* 10 points: `find_max_gpa()` finds the student with the highest GPA as described above
* 20 points: `sort_by_gpa()` sorts an array of students by descending GPA in place, as described above

Note that we will only consider changes to `students.c` when grading your work.  Changes to other files will be ignored.
