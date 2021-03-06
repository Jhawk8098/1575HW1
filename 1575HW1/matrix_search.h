/**
matrix_search.h -- These are your function declarations.
Do not edit this file. We will ignore or overwrite file of yours upon submission.
If you change it and your whole program does not run as a result, you will receive a grade of %0.
Remember, a function should ONLY do what it is stated to do, and no more. Anything else should be in main!
**/

#ifndef WORD_SEARCH
#define WORD_SEARCH

#include <iostream>
#include <string> // optional with modern GCC installs
using std::cout;
using std::endl;
using std::cin;
using std::string;


/*
Writes to a string array containing:
    * the your (the student author's) Campus Username
*/
void get_identity(string& my_id);


/*
Builds a two dimensional dynamic array of the given size
  -- rows: The number of rows in the matrix
  -- cols: The number of columns in the matrix
  -- returns a ponter to a pointer to a char, which is the pointer to the matrix.
*/
char** build_matrix(int rows, int cols);


/*
Fills a matrix from std in (command line terminal input)
  -- rows: The number of rows in the matrix
  -- cols: The number of columns in the matrix
  -- **matrix: The matrix to be filled
  -- Should simply accept input via cin or getline, etc.
  -- Should only fill the matrix (not do things like discard junk input; leave that in main if needed).
*/
void fill_matrix(int rows, int cols, char** matrix);


/*
Prints the matrix as follows (don't include extra newlines or spaces in the function; do that in main if needed):
a a a
a a a
a a a
*/
void print_matrix(int rows, int cols, char** matrix);


/*
Deletes a two dimensional dynamically allocated matrix
  -- rows: The number of rows in the matrix
  -- **matrix: the pointer to the matrix to be deleted
  -- What are you supposed to do with a dangling pointer?
*/
void delete_matrix(int rows, char** matrix);


/*
Modifies sol to contain the locations of the start and end characters of the word.
  -- sol: 4-large array of ints, where:
     ind 0: row start,
     ind 1: col start,
     ind 2: row end,
     ind 3: col end
  -- word: the word being searched for
  -- rows: the number of rows in the matrix
  -- cols: the number of columns in the matrix
  -- **matrix: pointer to a dynamically allocated array containing the characters to be searched
  -- if the solution does not exist in the matrix, set all 4 values stored in the sol array to -1
*/
void matrix_search(int sol[], string word, int rows, int cols, char** matrix);

bool search2D(char** grid, int row, int col, string word, int R, int C, int sol[]);


#endif
