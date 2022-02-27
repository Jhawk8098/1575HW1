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


void matrix_search(int sol[], string word, int rows, int cols, char** matrix)
{
  for (int i = 0; i < cols; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      if (matrix[i][j] == word[0])
      {
        if (matrix[i + 1][j + 1] == word[1])
        {
          
        }
      }
    }
  }
  sol[0] = -1;
  sol[1] = -1;
  sol[2] = -1;
  sol[3] = -1;
  return;
}



// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char** grid, int row, int col,
  string word, int R, int C)
{
  int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
  int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

  // If first character of word doesn't
  // match with given starting point in grid.
  if (grid[row][col] != word[0])
    return false;

  int len = word.length();

  // Search word in all 8 directions
  // starting from (row, col)
  for (int dir = 0; dir < 8; dir++) {
    // Initialize starting point
    // for current direction
    int k, rd = row + x[dir], cd = col + y[dir];

    // First character is already checked,
    // match remaining characters
    for (k = 1; k < len; k++) {
      // If out of bound break
      if (rd >= R || rd < 0 || cd >= C || cd < 0)
        break;

      // If not matched,  break
      if (grid[row][col] != word[0])
        break;

      // Moving in particular direction
      rd += x[dir], cd += y[dir];
    }

    // If all character matched, then value of k must
    // be equal to length of word
    if (k == len)
      return true;
  }
  return false;
}

// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char** grid, string word,
  int R, int C)
{
  // Consider every point as starting
  // point and search given word
  for (int row = 0; row < R; row++)
    for (int col = 0; col < C; col++)
      if (search2D(grid, row, col, word, R, C))
        cout << "pattern found at "
        << row << ", "
        << col << endl;
}
