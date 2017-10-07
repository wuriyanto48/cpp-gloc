#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROWS = 10;
const int ELEMENTS = 10;

int maxships = 10;

int matrix[ROWS][ELEMENTS];

void genShips()
{
  int ship = 0;
  while(ship < maxships)
  {
    int x = rand() % ROWS;
    int y = rand() % ELEMENTS;

    if(matrix[x][y] != 1)
    {
      ship++;
      matrix[x][y] = 1;
    }
  }
}

bool attack(int x, int y)
{
  if(matrix[x][y] == 1)
  {
    matrix[x][y] = 2;
    return true;
  }

  return false;
}

int numOfShips()
{
  int c = 0;

  for(int i=0; i < ROWS; i++)
  {
    for(int j=0; j < ELEMENTS; j++)
    {
      if(matrix[i][j] == 1){
        c++;
      }
    }
  }

  return c;
}

void clear()
{
  for(int i=0; i < ROWS; i++)
  {
    for(int j=0; j < ELEMENTS; j++)
    {
      matrix[i][j] = 0;
    }
  }
}

void show()
{
  for(int i=0; i < ROWS; i++)
  {
    for(int j=0; j < ELEMENTS; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  /*code*/
  srand(time(NULL));

  clear();
  genShips();

  show();

  int pos1, pos2;

  while(1)
  {
    cout << "Guess the location: ";
    cin >> pos1 >> pos2;

    if(attack(pos1, pos2))
    {
      cout << "Got it" << endl;
    }else
    {
      cout << "Sorry" << endl;
    }
    show();
    cout << "Ships left : " << numOfShips() << endl;
  }
  return 0;
}
