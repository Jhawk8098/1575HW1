/**
Implement the main here to match input and output.
**/

#include "matrix_search.h"

int main()
{
  int sol[4];
  int rows, cols, numMatrix;
  string word;

  std::cin >> numMatrix;
  for (int i = 0; i < numMatrix; i++)
  {
    std::cin >> rows;
    std::cin >> cols;
    char ** matrix = build_matrix(rows, cols);
    fill_matrix(rows, cols, matrix);
    std::cin >> word;
    print_matrix(rows, cols, matrix);
    std :: cout << "Searching for " << word << "in matrix " << i << " yields:" << endl;
    matrix_search(sol, word, rows, cols, matrix);
    delete_matrix(rows, matrix);
  }
  return 0;
}

