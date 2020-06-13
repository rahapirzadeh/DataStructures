#include <iostream>
#include <string>

using namespace std;

class board
{
  public:
    board();
    board( int rows, int columns, string map);
    //~board();

     int row;
     int column;
    string mapLoc;

    int getRows();
    int getColumns();
    char getCell(int row, int col);
    string getMap();
    void editCell(int rowLoc, int columnLoc, char newContents);
    char **grid;
    char gridCols;
    void copyBoard(board newBoard);
    void printBoard();
    bool isPopulated(int row, int col);
    void clearBoard();
    void populateRandom(double populationDensity);
    void populateMap(string targetMap);
    void outputBoard(int generations);
    bool isEqual(board board2);
};
