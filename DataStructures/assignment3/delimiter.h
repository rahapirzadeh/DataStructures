#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

class delimiter {
    public:
        delimiter(); //Constructor
        ~delimiter(); //Destructor

        bool checksyntax(string name);
        void scanFile();
        void emptyStacks();

        string fileName;
        int stackSize;
};
