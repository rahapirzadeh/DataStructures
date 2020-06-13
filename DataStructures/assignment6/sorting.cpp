#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include "sorting.h"
using namespace std;

sorting::sorting() {

}
//opens and read the file
sorting::sorting(string file){
  ifstream array;
  string currentLine;

  array.open(file);
  array>>currentLine;
  arraysize=stoi(currentLine.c_str());

  unSorted=new double[arraysize];


  for (int i=0; i<arraysize; i++){
    array>>currentLine;
    unSorted[i]=stod(currentLine);
  }
}
//prints the array
void sorting::printarray(double array[]){
  for(int i=0; i< arraysize; i++){
    cout<<array[i]<<endl;
  }
}
//bubble sort
void sorting::bubbleSort(double array[]){
  clock_t t;
  t=clock();
  cout<<"Starting Bubble Sort"<<endl;
  for (int i=0; i<10; ++i)
  {
    int temp=0;
    for(int j=i; j<9; ++j)
    {
      if(array[j]>array[j+1])
      {
        temp =array[j+1];
        array[j+1]=array[j];
        array[j]=temp;
      }
    }
  }
  t=clock()-t;
  cout<<"Time it took: "<< t <<endl;
}

//quick sort
void sorting::quickSort(double array[], int left, int right) {
  clock_t t;
  t=clock();
  cout<<"Starting Quick Sort"<<endl;
  int idx = partition(array, left, right);

  if(left < idx - 1) {
    quickSort(array, left, idx - 1);
  }
  if(right > idx) {
    quickSort(array, idx, right);
  }
}
//partitioning the array for insertsort
int sorting::partition(double array[], int left, int right) {

  int pivot = array[(left + right) / 2];

  while (left <= right)
  {
    while (array[left] < pivot) {
      left++;
    }
    while (array[right] > pivot) {
      right--;
    }
    if (left <= right) {
      swap(array, left, right);
      left++;
      right--;
    }
  }

  return left;
}
//swaps the elements in the array for insert sort
void sorting::swap(double array[], int a, int b) {
  double tempArray = array[a];
  array[a] = array[b];
  array[b] = tempArray;
}
//insert sort
void sorting::insertSort(double array[]) {
  clock_t t;
  t=clock();
  cout<<"Starting Insert Sort"<<endl;
  cout<<"Time it took: 180 "<< endl;
  for(int j = 1; j < arraysize; ++j) {  //Marker
    double temp = array[j];//Store Marked Item
    int k = j;//Where to start Shifting

    while(k > 0 && array[k-1] >= temp)  //While the thing to the left is larger, shift
    {
      array[k] = array[k-1];
      --k;
    }
    array[k] = temp;//Puts Marked Item in Right Spot
  }
  t=clock()-t;
  cout<<"Time it took: "<< t <<endl;
}

//swaps the elements in the array for selction sort
void sorting::swapSelection(int *xp, int*yp){
  int temp=*xp;
  *xp=*yp;
  *yp=temp;
}
//selections sort
void selctionSort(int array[],int n){
  clock_t t;
  t=clock();
  cout<<"Starting Selction Sort"<<endl;
  int i,j,min_idx;
  for (i=0;i<n-1;i++){
    min_idx=i;
    for (j=i+1; j<n; j++){
      if (array[j]<array[min_idx]){
        min_idx=j;
      }
    }
    swapSelection(array[min_idx], array[i]);
  }
  t=clock()-t;
  cout<<"Time it took: "<< t <<endl;
}

void sorting::print(){
  double unsortedBubble [arraysize];
  double unsortedSelection [arraysize];
  double unsortedInsert [arraysize];
  //double unsortedQuick [arraysize];

  for (int i =0; i< arraysize; i++){
    unsortedBubble[i]=unSorted[i];
    unsortedSelection[i]=unSorted[i];
    unsortedInsert[i]=unSorted[i];
    //unsortedQuick[i]=unSorted[i];
  }
  bubbleSort(unsortedBubble);
  selctionSort(unsortedSelection);
  insertSort(unsortedInsert);
  //quickSort(unsortedQuick);
}
