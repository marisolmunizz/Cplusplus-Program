#include <iostream> 

#include "GroceryTracker.h" 



using namespace std;



int main() {

    // Create a GroceryTracker object with the input file 

    GroceryTracker tracker("input.txt");



    // Print item frequencies 

    tracker.printItemFrequencies();



    // Print the histogram of item frequencies 

    tracker.printHistogram();



    // Write the frequency data to a file (frequency.dat) 

    tracker.writeFrequencyToFile();



    return 0;

}

