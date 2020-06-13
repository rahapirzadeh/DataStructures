#include "board.hpp"
#include <iostream>

using namespace std;

class simulation
{
  public:
    simulation();
    simulation(board grid, string mode);


    board gameBoard;
    string gameMode;


    int countNeighbors(int rowLoc, int colLoc);  //Counts the neighbors of the given location
    void advanceGeneration(); //Utilizies the count neighbors method to populate a new board based on the rules of the game
    bool isStable(); //Checks if the simulation has either stabilizied or has become empty
    string getMode(); //Returns the gamemode being used to play


};
