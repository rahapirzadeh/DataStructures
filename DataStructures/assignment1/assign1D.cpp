
#include "assign1D.h"
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

assign1::assign1() //Constructor
{
	string dna="";
	int countLine=0;     //number of lines in text file
	double nucleoCount = 0.0;  //each time that letter shows up in the text file
	double nucleoTotal = 0.0; // total times that letter shows up
	double sum = 0.0;
	double mean = 0.0;
	double variance = 0.0;
	double standDev = 0.0;
	double probOfA = 0.0;
	double probOfC = 0.0;
	double probOfT = 0.0;
	double probOfG = 0.0;
}

assign1::~assign1() //Deconstructor, owns the other file
{
  cout << "object deleted" << endl;
}

void assign1::dna(ifstream & in) //ifstream and in used to take in from the designated file
{
	int countLine = 0;
	char c;
	while(!in.eof()) {
		if(c == '\n') {
			countLine++;
		}
		in.get(c);
		dna += c;
	}
}

//Math Computations
void assign1::fileComputations(ofstream & out)   //ofstream and out used to output to file
{
	int count = 0;
	int countline = 0;
	double nucleoCount = 0.0;
	double stdDev =0;
	double nucleoTotal = 0.0;
	double sum = 0.0;
	double mean = 0.0;
	double variance = 0.0;
	double standDev = 0.0;


	//Calculate the Sum and the Mean
	for(int i = 0; i < dna.size(); ++i)
	{
		if(dna[i] != '\n')
		{
			nucleoTotal += 1;
		}
		else
		{
			count += 1;
			if(count == countLine)
			{
				sum = nucleoTotal;
				mean = sum/countLine;
				count = 0;
				break;
			}
		}
	}
	out << "Sum: " << sum;
	out << "Mean: " << mean;

	//Calculate the Variance and Standard Deviation
	for(int j = 0; j < dna.size(); ++j)
	{
		if(dna[j] != '\n')
		{
			nucleoCount += 1;
		}
		else
		{
			variance += pow((nucleoCount - mean), 2);
			nucleoCount = 0;
			count += 1;
			if(count == countLine)
			{
				variance = variance/nucleoTotal;
				standDev = sqrt(variance);
				break;
			}
		}
	}

	out << "Variance: " << variance;
	out << "Standard Deviation: " << standDev;
}

//Calculates the Probability of each nucleotide (A T G C)
void assign1::nucleoProbability (ofstream & out)
{
	double probOfAA = 0.0;
	double probOfAC = 0.0;
	double probOfAT = 0.0;
	double probOfAG = 0.0;
	double probOfCA = 0.0;
	double probOfCC = 0.0;
	double probOfCT = 0.0;
	double probOfCG = 0.0;
	double probOfTA = 0.0;
	double probOfTC = 0.0;
	double probOfTT = 0.0;
	double probOfTG = 0.0;
	double probOfGA = 0.0;
	double probOfGC = 0.0;
	double probOfGT = 0.0;
	double probOfGG = 0.0;

	double probOfA = 0.0;
  double probOfT = 0.0;
  double probOfG = 0.0;
  double probOfC =0.0;
	double nucleoCount = 0.0;


	for(int i = 0; i < dna.size();  ++i)
	{
		dna[i] = toupper(dna[i]); //make the characters in the file uppercase
		dna[i+1]= toupper(dna[i+1]);

		//a nucleotides
		if (dna[i] == 'A')
		{
			probOfA += 1;
			if(dna[i+1] != '\n')
			{
				nucleoCount += 1;
				if (dna[i+1] == 'A')
				{
					probOfAA += 1;
				}
				else if (dna[i+1] == 'C')
				{
					probOfAC += 1;
				}
				else if (dna[i+1] == 'T')
				{
					probOfAT += 1;
				}
				else if (dna[i+1] == 'G')
				{
					probOfAG += 1;
				}
			}
		}
		//c nucleotides
    else if (dna[i] == 'C')
		{
			probOfC += 1;
			if(dna[i+1] != '\n')
			{
				nucleoCount += 1;
				if (dna[i+1] == 'A')
				{
					probOfCA += 1;
				}
				else if (dna[i+1] == 'C')
				{
					probOfCC += 1;
				}
				else if (dna[i+1] == 'T')
				{
					probOfCT += 1;
				}
				else if (dna[i+1] == 'G')
				{
					probOfCG += 1;
				}
			}
		}
		//T nucleotides
		else if (dna[i] == 'T')
		{
			probOfT += 1;
			if (dna[i+1] != '\n')
			{
				nucleoCount += 1;
				if (dna[i+1] == 'A')
				{
					probOfTA += 1;
				}
				else if (dna[i+1] == 'C')
				{
					probOfTC += 1;
				}
				else if (dna[i+1] == 'T')
				{
					probOfTT += 1;
				}
				else if (dna[i+1] == 'G')
				{
					probOfTG += 1;
				}
			}
		}
		// G nucleotides
		else if (dna[i] == 'G')
		{
			probOfG += 1;
			if (dna[i+1] != '\n')
			{
				nucleoCount += 1;
				if (dna[i+1] == 'A')
				{
					probOfGA += 1;
				}
				else if (dna[i+1] == 'C')
				{
					probOfGC += 1;
				}
				else if (dna[i+1] == 'T')
				{
					probOfGT += 1;
				}
				else if (dna[i+1] == 'G')
				{
					probOfGG += 1;
				}
			}
		}
	}
	//Singular Nucleotides
	probOfA = (probOfA/nucleoCount)*100;
	probOfC = (probOfC/nucleoCount)*100;
	probOfT = (probOfT/nucleoCount)*100;
	probOfG = (probOfG/nucleoCount)*100;
	//A nucleotide pairs
	probOfAA = (probOfAA/nucleoCount)*100;
	probOfAC = (probOfAC/nucleoCount)*100;
	probOfAT = (probOfAT/nucleoCount)*100;
	probOfAG = (probOfAG/nucleoCount)*100;
	//C nucleotide pairs
	probOfCA = (probOfCA/nucleoCount)*100;
	probOfCC = (probOfCC/nucleoCount)*100;
	probOfCT = (probOfCT/nucleoCount)*100;
	probOfCG = (probOfCG/nucleoCount)*100;
	//T nucleotide pairs
	probOfTA = (probOfTA/nucleoCount)*100;
	probOfTC = (probOfTC/nucleoCount)*100;
	probOfTT = (probOfTT/nucleoCount)*100;
	probOfTG = (probOfTG/nucleoCount)*100;
	//G nucleotide pairs
	probOfGA = (probOfGA/nucleoCount)*100;
	probOfGC = (probOfGC/nucleoCount)*100;
	probOfGT = (probOfGT/nucleoCount)*100;
	probOfGG = (probOfGG/nucleoCount)*100;

	//Printing the percentage values to out
	out << "Singular Nucleotides" << endl;
	out << "A: " << probOfA << " T: " << probOfT << " C: " << probOfC << " G: " << probOfG << endl;

	out << "Nucleotide Pairs (A)" << endl;
	out << "AA: " << probOfAA << " AT: " << probOfAT << " AC: " << probOfAC << " AG: " << probOfAG << endl;

  out << "Nucleotide Pairs (C)" << endl;
	out << "CA: " << probOfCA << " CT: " << probOfCT << " CC: " << probOfCC << " CG: " << probOfCG << endl;

  out << "Nucleotide Bigram Percentage of 'T' pairs " << endl;
	out << "TA: " << probOfTA << " TT: " << probOfTT << " TC: " << probOfTC << " TG: " << probOfTG << endl;

  out << "Nucleotide Pairs (G)" << endl;
	out << "GA: " << probOfGA << " GT: " << probOfGT << " GC: " << probOfGC << " GG: " << probOfGG << endl;
}

//Calculate the Guassian Distribution and generate 1000 new lines of dna sequences
void assign1::guassianDistribution (ofstream & out)
{
	double standDev = 0.0;
  double probOfA = 0.0;
  double probOfT = 0.0;
  double probOfG = 0.0;
  double probOfC = 0.0;


	double a = ((double) rand() / (RAND_MAX));   //random number
	double b = ((double) rand() / (RAND_MAX));   //random number

	double c = (sqrt(-2*log(a)))*(cos(2*(M_PI)*b));
	double d = (standDev * c) + mean;   //guassianDistribution

	//For loop to iterate 1000 times
	for(int i = 0; i < 1000; ++i)
	{
		for(int j = 0; j < d; ++j)  //For loop to iterate the size of double d
		{
			double range = rand() % 100;
			if(range <= probOfA)
			{
				out << "A";
			}
			else if(range <= (probOfC + probOfA))
			{
				out << "C";
			}
			else if(range <= (probOfT + probOfC + probOfA))
			{
				out << "T";
			}
			else if(range <= 100)
			{
				out << "G";
			}
		}
	}
	//Reset the probabilities of Singular Nucleotides
	probOfA = 0;
	probOfC = 0;
	probOfT = 0;
	probOfG = 0;
	standDev = 0;
}
