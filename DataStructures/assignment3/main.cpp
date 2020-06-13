#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "GenStack.h"
#include "delimiter.h"

using namespace std;

int main(int argc, char** argv) {
    delimiter d;
    bool runProgram = true;


	if (argc == 2)//check that there is only one command line arg
	{
		if (d.checksyntax(argv[1]))//check if argument is a file
		{
			d.scanFile();

			while (runProgram)
			{
        string answer;
				cout << "\nWould you like to process another file? [1] for Yes, [2] for No" << endl;
				cin >> answer;

				try
				{
					int intAnswer = stoi(answer); //makes answer an integer

					switch (intAnswer)
					{
						case (1):
						{
              string fileName;
							cout << "\nEnter the new file name: " << endl;
							cin >> fileName;

							d.emptyStacks(); // empty all the stacks before a new file

							if (d.checksyntax(fileName))
							{
								d.scanFile();
							}

							else//invalid file name
							{
								cout << "File not found. Please try again." << endl;
							}
							break;
						}

						case (2):
						{
							runProgram = false;
							break;
						}

						default://not 1 or 2
						{
							cout << "Invalid answer. Please try again." << endl;
							break;
						}
					}
				}

				catch (exception e)//entered anything but a number
				{
					cout << "You did not enter a number! Try again." << endl;
				}
			}
		}

		else // Invalid file name entered in the command line
		{
			cout << "Error loading file: File does not exist in current directory." << endl;
		}
	}


	else 	// 0 or more than one thing entered in the command line
	{
		cout << "Error: Please Enter a valid file input" << endl;
	}

	return 0;
}
