/**
Here in the .cpp you should define and implement the functions that are declared in the .h file.
It is not recommended to add extra functions on this assignment.
**/

#include "matrix_search.h"


// We're giving you this one the first time, and you should copy it into all future assignments.
// Change the information to your own email handle (S&T username)
void get_identity(string& my_id)
{
  my_id = "jahk8d";
}


char** build_matrix(int rows, int cols)
{
  char** matrix;
  matrix = new char*[rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new char [cols];
  }
  return matrix;
}


void fill_matrix(int rows, int cols, char** matrix)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
}


void print_matrix(int rows, int cols, char** matrix)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << endl;
  }
}


void delete_matrix(int rows, char** matrix)
{
  for (int i = 0; i < rows; i++)
  {
    delete matrix[i];
  }
  delete matrix;
}


// searches in all directions from a starting point
bool search2D(char** grid, int row, int col, string word, int R, int C, int sol[])
{
  int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
  int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

  if (grid[row][col] != word[0])
    return false;

  int len = word.length();

  for (int dir = 0; dir < 8; dir++) {

    int k, rd = row + x[dir], cd = col + y[dir];

    for (k = 1; k < len; k++) {
      if (rd >= R || rd < 0 || cd >= C || cd < 0)
        break;

      if (grid[rd][cd] != word[0 + k])
      {
        break;
      }
      rd += x[dir], cd += y[dir];
    }

    if (k == len)
    {
      sol[0] = row;
      sol[1] = col;
      sol[2] = rd - x[dir];
      sol[3] = cd - y[dir];
      return true;
    }
  }
  return false;
}

// Searches given word in a given
// matrix in all 8 directions
void matrix_search(int sol[], string word, int rows, int cols, char** matrix)
{
  sol[0] = -1;
  sol[1] = -1;
  sol[2] = -1;
  sol[3] = -1;
  for (int row = 0; row < rows; row++)
    for (int col = 0; col < cols; col++)
      if (search2D(matrix, row, col, word, rows, cols, sol))
      {
        std::cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos : (" << sol[2] << ", " << sol[3] << ")" << endl;
        return;
      }
  std::cout << "The pattern was not found.";
  return;
}
