#include <iostream>
#include "scripts.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"

#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;


using namespace std;

int main(){
    /*
        The *start pointer will point to the start of the Array
        The size variable will hold the size of the Array
    */
    int *start,size;
    /*
        The makeArray() creates an Array(internally a vector) function returns a tuple. 
        We use the in-built tie function to tie the returning values to variables
        The tuple consist of 1.address of the starting variable and 2. size of the Array
    */
    tie(start,size)=makeArray();
    //Displaying the Inital State of the Array
    cout<<"Initial State\t:";
    displayArray(start,size);
    cout<<"1. Selection Sort(Default)\n2. Insertion Sort\n3. Merge Sort\nEnter Choice:";
        int temp;
        cin>>temp;
    //recording function start time
    auto _start = high_resolution_clock::now();
    if(temp==2) insertionSort(start,size);
    else if(temp==3) mergeSort(start,size);
    else selectionSort(start,size);
    //recording function end time and calulating the difference
    auto _end = high_resolution_clock::now();
    duration<double, milli> duration = _end - _start;
    //Displaying the Final State of the Array
    cout<<"Sorted Array\t:";
    displayArray(start,size);
    //Displaying Execution Time
    cout<<"Execution Time:"<<duration.count()<<"ms"<<endl;
    return 0;
}
