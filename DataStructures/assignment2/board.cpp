#include "board.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

board::board(){ //constuctor
  row = 1;
  column = 1;
  grid = new char*[1];
}

board::board( int rows,  int columns, string map){  // overloaded constructor
  row = rows;
  column = columns;
  string mapLoc = map;    //string of map file (map locator)
  grid = new char*[row];
  //dynmically creates the grid
  for(int i = 0; i < row; i++){
    grid[i] = new char[column];
  }
}

int board::getRows(){
  return row;
}

int board::getColumns(){
  return column;
}

string board::getMap(){  //gets the name of the text file whne called
  return mapLoc;
}

char board::getCell(int row, int col){   //returns contents of the cell
  return grid[row][col];
}

void board::editCell(int rowLoc, int columnLoc, char newContents){  // edits the cell
    grid[rowLoc][columnLoc] = newContents;
}

void board::copyBoard(board newBoard){     //copies the contents of the perameter board to the current board
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      char contents = newBoard.getCell(i, j);
      editCell(i, j, contents);
    }
  }
}


void board::printBoard(){    //prints the current board
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      if(grid[i][j] == '*'){
        cout << "X";
      }else{
        cout << "-";
      }
    }
    cout << endl;
  }
  cout << "" << endl;
}


bool board::isPopulated(int col, int row){   //checks f a cell is populated or not
  if(grid[row][col] == '*'){
    return true;
  }else{
    return false;
  }
}


void board::clearBoard(){   //clears the current board
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      grid[i][j] = '-';
    }
  }
}

void board::populateRandom(double populationDensity){    //generates random board based on given population density
  srand(time(NULL));
  int r;
  int maxPopulation = populationDensity*row*column;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      r = (rand()%10) + 1;
      if(r%2 == 0 && (maxPopulation > 0)){
        grid[i][j] = '*';
        maxPopulation-1;
      }else{
        grid[i][j] = '-';
      }
    }
  }
}


void board::populateMap(string targetMap){     //populates current board based off of file configuration
  ifstream layout;
  string currentLine;
  layout.open(targetMap);
  for(int i = 0; i < row+2; i++){
    layout >> currentLine;
    if(i > 1){
    for(int j = 0; j < column; j++){
      if(currentLine[j] == 'X'){
        grid[i-2][j] = '*';
      }else{
        grid[i-2][j] = '-';
      }
    }
  }
  }
}

void board::outputBoard(int generations){  //outs the current board
  ofstream outfile;
  outfile.open("output.txt", std::ios_base::app);
  outfile << generations << "\r\n";
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      if(grid[i][j] == '*'){
        outfile << "X";
      }else{
        outfile << "-";
      }
    }
    outfile <<"\r\n";
  }
  cout << "" << endl;
}


bool board::isEqual(board board2){   //checks if two boards are the same 
  if(row != board2.getRows() || column != board2.getColumns()){
    return false;
  }
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      if(grid[i][j] != board2.getCell(i, j)){
        return false;
      }
    }
  }
  return true;
}
