#include "simulation.hpp"

using namespace std;


simulation::simulation(){ //constructor
  gameMode = "classic";
}

simulation::simulation(board grid, string mode){ //overload constructor
  gameBoard = grid;
  gameMode = mode;
}

int simulation::countNeighbors(int rowLoc, int colLoc){   //counts the neighbrs of the given cell in each game mode
  int neighbors = 0;
  if(gameMode == "classic"){
    if(rowLoc == 0 && colLoc==0){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
       neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc+1)== true){
        neighbors++;
      }
      return neighbors;

    }else if(rowLoc == 0 && colLoc == gameBoard.getColumns()-1){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == 0 && colLoc != 0 && colLoc != gameBoard.getColumns()-1){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      return neighbors;

    }else if(rowLoc == gameBoard.getRows()-1 && colLoc == 0){

      neighbors = 0;
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == gameBoard.getRows()-1 && colLoc == gameBoard.getColumns()-1){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc-1, rowLoc)==true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == gameBoard.getRows()-1 && colLoc != 0 && colLoc!= gameBoard.getColumns()-1){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      return neighbors;
   }else if(colLoc == 0 && rowLoc != 0 && rowLoc != gameBoard.getRows()-1){
     neighbors = 0;
     if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
       neighbors++;
     }
     return neighbors;
   }
   else if(colLoc == gameBoard.getColumns()-1 && rowLoc != 0 && rowLoc != gameBoard.getRows()-1){
     neighbors = 0;
     if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
       neighbors++;
     }
     return neighbors;
   }
   else{
     neighbors = 0;
     if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
      neighbors++;
     }

     if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
       neighbors++;
     }
     return neighbors;
   }
  }
  else if((gameMode)=="donut"){ //make sure jonathon changes his

    if (rowLoc ==0 && colLoc ==0){

      neighbors= 0;
      if(gameBoard.isPopulated(colLoc,rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc)==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc+1,rowLoc+1)==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc,gameBoard.getRows()-1) ==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc+1,gameBoard.getRows()-1) ==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(gameBoard.getColumns()-1,rowLoc) ==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(gameBoard.getColumns()-1,rowLoc+1)==true){
        neighbors++;
      }
      return neighbors;
    }

    else if (rowLoc ==0 && colLoc == gameBoard.getColumns()-1){ //will this work???   colLoc == gameBoard.getColumns()-1
      neighbors= 0;
      if (gameBoard.isPopulated(colLoc,rowLoc+1 )==true){
        neighbors++;
      }

      if (gameBoard.isPopulated( colLoc-1,rowLoc)==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc-1,rowLoc+1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,gameBoard.getRows()-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,gameBoard.getRows()-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated( 0,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated( 0,rowLoc+1)==true){
        neighbors++;
      }
      return neighbors;
    }

    else if (rowLoc == gameBoard.getRows()-1 && colLoc == gameBoard.getColumns()-1){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc, rowLoc-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1, 0 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated( colLoc,0)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated( 0,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated( 0,rowLoc-1)==true){
        neighbors++;
      }
      return neighbors;
    }

    else if (rowLoc == gameBoard.getRows()-1 && ((colLoc==0))){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc,rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,0 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1, 0 )==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(gameBoard.getColumns()-1,rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(gameBoard.getColumns()-1, rowLoc )==true){
        neighbors++;
      }
      return neighbors;
    }
    else if (rowLoc==0 && colLoc != 0 && colLoc != gameBoard.getColumns()){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc,rowLoc+1)==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc+1,rowLoc )==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc+1,rowLoc+1 )==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc-1,rowLoc )==true){
        neighbors++;
      }

      if (gameBoard.isPopulated(colLoc-1,rowLoc+1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,gameBoard.getRows()-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,gameBoard.getRows()-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1, gameBoard.getRows()-1 )==true){
        neighbors++;
      }
      return neighbors;
    }
    else if (colLoc==0 && rowLoc !=0 && rowLoc != gameBoard.getRows()-1){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc, rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc, rowLoc+1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1, rowLoc )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated( colLoc+1, rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1, rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(gameBoard.getColumns()-1,rowLoc-1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(gameBoard.getColumns()-1, rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(gameBoard.getColumns()-1,rowLoc+1 )==true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == gameBoard.getRows()-1 && colLoc != 0 && colLoc != gameBoard.getColumns()-1){
      if(gameBoard.isPopulated(colLoc, 0) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, 0) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, 0) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, 0) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, 0) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, 0) == true){
        neighbors++;
      }
    }else if(colLoc = gameBoard.getColumns()-1 && rowLoc != 0 && rowLoc != gameBoard.getRows()){
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(0, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(0, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(0, rowLoc-1) == true){
        neighbors++;
      }

    }else{
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
        neighbors++;
      }
    }

  }
  else if((gameMode)=="mirror"){
    // (++ -> single neighbor) (+=2 -> neighbor and reflection) (+=3 -> corner reflection)
    if (rowLoc ==0 && colLoc ==0){
      neighbors= 0;

      if (gameBoard.isPopulated(colLoc,rowLoc)==true){
        neighbors+=3;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc) ==true){
        neighbors+=2;
      }
      if(gameBoard.isPopulated(colLoc+1,rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc+1)==true){
        neighbors+=2;
      }
      return neighbors;
    }else if (rowLoc ==0 && colLoc == gameBoard.getColumns()-1){
      neighbors= 0;
      if (gameBoard.isPopulated(colLoc,rowLoc)==true){
        neighbors+=3;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc+1 )==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc+1 )==true){
        neighbors++;
      }
      return neighbors;
    }

    else if (rowLoc == gameBoard.getRows()-1 && (colLoc==0)){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc,rowLoc)==true){
        neighbors+=3;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc-1)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc-1 )==true){
        neighbors++;
      }
      return neighbors;
    }
    else if (rowLoc == gameBoard.getRows()-1 && colLoc == gameBoard.getColumns()-1){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc,rowLoc )==true){
        neighbors+=3;
      }
      if (gameBoard.isPopulated(colLoc, rowLoc-1)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc-1 )==true){
        neighbors++;
      }
      return neighbors;
    }
    else if (rowLoc==0 && colLoc != 0 && colLoc != gameBoard.getColumns()-1){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc+1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc )==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc )==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc+1 )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc+1 )==true){
        neighbors++;
      }
      return neighbors;
    }
    else if (colLoc==0 && rowLoc != 0 && rowLoc != gameBoard.getRows()-1){
      neighbors = 0;
      if (gameBoard.isPopulated(colLoc,rowLoc )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc, rowLoc-1 )==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc, rowLoc+1 )==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc-1, rowLoc )==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1, rowLoc-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1, rowLoc+1 )==true){
        neighbors++;
      }
      return neighbors;
    }
    else if(colLoc == gameBoard.getColumns()-1 && rowLoc != 0 && rowLoc != gameBoard.getRows()-1){
      if (gameBoard.isPopulated(colLoc,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc+1)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc-1)==true){
        neighbors+= 2;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc-1)==true){
        neighbors++;
      }
      return neighbors;
    }
    else if(rowLoc == gameBoard.getRows()-1 && colLoc != 0 && colLoc != gameBoard.getColumns()-1){
      if (gameBoard.isPopulated(colLoc,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc)==true){
        neighbors+=2;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc-1)==true){
        neighbors++;
      }
      return neighbors;
    }else{
      if (gameBoard.isPopulated(colLoc,rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc,rowLoc-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc+1,rowLoc-1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc+1)==true){
        neighbors++;
      }
      if (gameBoard.isPopulated(colLoc-1,rowLoc-1)==true){
        neighbors++;
      }
      return neighbors;
    }
  }
}

void simulation::advanceGeneration(){     //Utilizies the count neighbors method to populate a new board based on the rules of the game

  board nextGen(gameBoard.getRows(), gameBoard.getColumns(), " ");
  int neighbors = 0;
  for(int i = 0; i < gameBoard.getRows(); i++)
  {
    for(int j = 0; j < gameBoard.getColumns(); j++)
    {
      neighbors = countNeighbors(i, j);
      if(neighbors <= 1)
      {
        nextGen.editCell(i, j, '-');
      }
      else if(neighbors == 2)
      {
        if(nextGen.isPopulated(j, i))
        {
          nextGen.editCell(i, j, '*');
        }else{
          nextGen.editCell(i, j, '-');
        }
      }
      else if(neighbors == 3)
      {
        nextGen.editCell(i, j, '*');
      }
      else
      {
        nextGen.editCell(i, j, '-');
      }
    }
  }
  gameBoard.copyBoard(nextGen);
}


string simulation::getMode()
{
  return gameMode;
}

bool simulation::isStable(){   //checks if the simulation has stbilized
  board newBoard(gameBoard.getRows(), gameBoard.getColumns(), "");
  newBoard.copyBoard(gameBoard);
  simulation sim2(newBoard, gameMode);
  sim2.advanceGeneration();
  return (gameBoard.isEqual(newBoard));
}
