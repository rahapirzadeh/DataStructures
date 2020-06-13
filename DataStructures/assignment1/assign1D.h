#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class assign1 {
	private:
		string dna;
		int countLine;
		double bigramCount;
		double nucleoCount;
		double sum;
		double mean;
		double variance;
		double standDev;
		double nucleoTotal;
		double probOfA;
		double probOfC;
		double probOfT;
		double probOfG;

	public:
		assign1(); //Constructor
    ~assign1();	//Deconstructor


		void dna (ifstream & in); //Takes input from the file
		void fileComputations (ofstream & out); //Math Computations (sum mean variance standDev)
		void nucleoProbability (ofstream & out); //Probability of each Nucleotide (A T C G)
		void guassianDistribution (ofstream & out); //1000 new dna sequences
};
