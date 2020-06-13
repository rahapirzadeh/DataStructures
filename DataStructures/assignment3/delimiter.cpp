#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "delimiter.h"
#include "GenStack.h"

using namespace std;

// stacks for storing inpaired characters
GenStack<char> bracketStack(4);
GenStack<char> curlybracketStack(4);
GenStack<char> parenthesisStack(4);

// stacks for storing line number of error
GenStack<int> bracketLineStack(4);
GenStack<int> curlybracketLineStack(4);
GenStack<int> parenthesisLineStack(4);

delimiter::delimiter() { //Constructor
};

delimiter::~delimiter() {//Destructor
};

bool delimiter::checksyntax(string name)
{
	ifstream file;
	file.open(name.c_str());

	if (file.is_open())
	{
		cout << "\nFile: " << name.c_str() <<  endl;
		file.close();
		fileName = name;
		return true;
	}

	else
	{
		return false;
	}
}

void delimiter::scanFile() //method to open file
{
	ifstream inputFile;
	inputFile.open(fileName.c_str());

	string line;
	char character;
	int linelength; //length of the line
	int linenum = 1;  //number of line
	bool noError = true;


	if (inputFile.is_open()) //Method to check all brackets
	{
   		while (getline(inputFile, line) && noError)
   		{
   			linelength = line.length();

   			for (int i = 0; i < linelength; i++)
   			{
   				character = line[i];

   				switch (character)
				{

					case ('('): //parenthesis check
					{
						parenthesisStack.push(line[i]);
   					parenthesisLineStack.push(linenum);

						break;
					}

					case (')'): //check if open parenthesis was found, if not, error
					{
						if (parenthesisStack.isEmpty())
						{
							cout << "\nERROR on line:" << linenum << ". Expected '(' and found '"<< line[i] << "'." << endl;
							noError = false;
						}

						else
						{
							parenthesisStack.pop();
	   					parenthesisLineStack.pop();
	   				}

						break;
					}

					case ('['): //bracket check
					{
						bracketStack.push(line[i]);
   					bracketLineStack.push(linenum);

						break;
					}

					case (']'): //check if open bracket was found, if not, error
					{
						if (bracketStack.isEmpty())
						{
							cout << "\nERROR on line:" << linenum << ". Expected '[' and found '"<< line[i] << "'." << endl;
							noError = false;
						}

						else
						{
							bracketStack.pop();
	   					bracketLineStack.pop();
	   				}

						break;
					}

					case ('{'): //curly braces
					{
						curlybracketStack.push(line[i]);
   					curlybracketLineStack.push(linenum);

						break;
					}

					case ('}'): //check if curly braces was found, if not, error
					{
						if (curlybracketStack.isEmpty())
						{
							cout << "\nERROR on line:" << linenum << ". Expected '{' and found '"<< line[i] << "'." << endl;
							noError = false;
						}

						else
						{
							curlybracketStack.pop();
	   					curlybracketLineStack.pop();
	   				}

						break;
					}

					default: //anything else
					{
						break;
					}

				}
      }
   			++linenum;
      }


	   	if (noError) //no closing delimiter found before an opening
	   	{
			if (!parenthesisLineStack.isEmpty())
			{
			 	cout << "\nERROR on line:" << parenthesisLineStack.pop() <<". Expected ')'" << endl;
			}

			else if (!bracketLineStack.isEmpty())
			{
				cout << "\nERROR on line:" << bracketLineStack.pop() <<". Expected ']'"<<  endl;
			}

			else if (!curlybracketLineStack.isEmpty())
			{
				cout << "\nERROR on line:" << curlybracketLineStack.pop() <<". Expected '}'"<<  endl;
			}
	   	}

	   	// No errors found
   		if (noError && parenthesisStack.isEmpty() && bracketStack.isEmpty() && curlybracketStack.isEmpty())
   		{
			cout << "\nNo errors found!!!" << endl;
   		}
	}

	inputFile.close();
}

void delimiter::emptyStacks()//clears the stack
{
	while (!bracketStack.isEmpty())
	{
		bracketStack.pop();
	}

	while (!bracketLineStack.isEmpty())
	{
		bracketLineStack.pop();
	}

	while (!curlybracketStack.isEmpty())
	{
		curlybracketStack.pop();
	}

	while (!curlybracketLineStack.isEmpty())
	{
		curlybracketLineStack.pop();
	}

	while (!parenthesisStack.isEmpty())
	{
		parenthesisStack.pop();
	}

	while (!parenthesisLineStack.isEmpty())
	{
		parenthesisLineStack.pop();
	}
}
