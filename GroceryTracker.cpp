#include "GroceryTracker.h" 

#include <iostream> 

#include <fstream> 

#include <unordered_map> 

#include <string> 



using namespace std;



// Constructor: Opens the input file and populates the frequency map 

GroceryTracker::GroceryTracker(const string& inputFileName) {

    ifstream inputFile(inputFileName); // Open the file for reading 



    if (!inputFile.is_open()) {

        cerr << "Error: Could not open file " << inputFileName << endl;

        exit(1); // Exit if the file can't be opened 

    }



    string item;

    while (inputFile >> item) { // Read items from the file 

        itemFrequency[item]++; // Increment the count for each item 

    }



    inputFile.close(); // Close the file when done 

}



// Finds the frequency of a specific item 

int GroceryTracker::findFrequency(const string& item) const {

    auto it = itemFrequency.find(item); // Look for the item in the map 

    if (it != itemFrequency.end()) {

        return it->second; // If found, return the frequency 

    }
    else {

        return 0; // If not found, return 0 

    }

}



// Prints all items and their frequencies 

void GroceryTracker::printItemFrequencies() const {

    cout << "Item Frequencies:" << endl;

    for (const auto& entry : itemFrequency) {

        cout << entry.first << ": " << entry.second << endl;

    }

}



// Prints a histogram of item frequencies 

void GroceryTracker::printHistogram() const {

    cout << "Item Frequency Histogram:" << endl;

    for (const auto& entry : itemFrequency) {

        cout << entry.first << " ";

        for (int i = 0; i < entry.second; i++) {

            cout << "*"; // Print asterisks for the frequency count 

        }

        cout << endl;

    }

}



// Writes the frequency data to a file (frequency.dat) 

void GroceryTracker::writeFrequencyToFile() const {

    ofstream outFS("frequency.dat"); // Open frequency.dat for writing 



    if (!outFS.is_open()) {

        cout << "Could not open frequency.dat for writing!" << endl;

        return;

    }



    // Loop through frequency map and write to the file 

    for (const auto& pair : itemFrequency) {

        outFS << pair.first << " " << pair.second << endl; // Write item and frequency 

    }



    outFS.close(); // Close the file after writing 

    cout << "Frequency data written to frequency.dat" << endl;

}

