#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class sorting {
public:
    sorting();
    sorting(string file);

    int arraysize;
    double *unSorted;

    void printarray(double array[]);
    void bubbleSort(double array[]);
    void insertSort(double array[]);
    void quickSort(double array[], int left, int right);
    void swap(double array[], int a, int b);
    int partition(double array[], int left, int right);
    void swapSelection(int *xp, int*yp);
    void selctionSort(int array[],int n);

    void print();

};
