#include "inputgen.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

int less(int value1, int value2,int& count){

    if(value1 < value2){ count++; return true; } // if less return true if not return false
    else{  count++; return false; }

}

int partition(double input[], int left, int right,int& count){

    int index = left;

    for(int i=left; i<right; i++){

        if(less(input[i],input[right],count)){
            std::swap(input[i],input[right]);
            index++;
        }
    }

    std::swap(input[right],input[index]);

    return index;
}

int quicksort(double input[], int left /* 0 */, int right /* max */, int& count){

    if(left < right){

        int pivot = partition(input, left, right,count);

        quicksort(input, left, pivot-1,count);
        quicksort(input, pivot+1, right,count);
    }

    return 0;
}

int main(){

    // Generator input file of length 11k
    //inputgen::generator();

    std::ifstream infile("input.txt"); // Reading in the input file

    std::string lengthStr;
    infile >> lengthStr;
    int length = std::stoi(lengthStr);

    double input[length] = { 0 }; // empty array

    double value; // overwrite value for each iteration
    for(int i=0; i<length; i++){ // Creating input array
        infile >> value;
        input[i] = value;
    }

    int count = 0;

    quicksort(input, 0, length-1,count); // running the quicksort function

    std::cout << "Here is the count from quicksort: " << count << "\n";

    return 0;
}
