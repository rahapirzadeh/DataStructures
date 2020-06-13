#include "assign1D.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {

	ofstream out; //ofstream to signify outgoing info
	ifstream in; //ifstream to signify incoming info

	out.open("RahaPirzadeh.out"); //Opens output file
	if(out.is_open())
	{
		out << "Raha Pirzadeh" <<endl;
		out << "Student ID: 2290732" <<endl;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}

	while( true )
	{
		string file;//filepath input
		file = argv[1];  //takes the 1st index from the command line

		in.open(file.c_str());    //opens the file

		assign1 a;
		a.dna(in);
		a.fileComputations(out);
		a.nucleoProbability(out);
		a.guassianDistribution(out);

		in.close();     //closes the file


		bool again = true; //While Loop to catch any user input error
		while ( again )
		{
			cout << "Do you have another list? Y or N " << endl;
			string input;
			cin >> input;
			input = toupper(input);
			//If user inputs no program exits
			if (input == "N")
			{
				out.close();
				return 0;
			}
			//If user inputs yes program repeats
			else if (input == "Y")
			{
				break;
			}
			//Aerror message for answer other that y or n
			else
			{
				cout << "Please enter 'Y' or 'N' " << endl;
				continue;
			}
		}
	}
	return 0;
}
