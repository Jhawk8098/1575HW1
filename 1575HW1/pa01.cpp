/**
Implement the main here to match input and output.
**/

#include "matrix_search.h"

int main()
{
  int sol[4];
  int rows, cols;
  string word;
  std::cin >> rows;
  std::cin >> cols;
  char ** matrix = build_matrix(rows, cols);
  fill_matrix(rows, cols, matrix);
  std::cin >> word;
  print_matrix(rows, cols, matrix);
  //matrix_search(sol, word,rows, cols, matrix);
  patternSearch(matrix, word, rows , cols);
  delete_matrix(rows, matrix);
  return 0;
}

