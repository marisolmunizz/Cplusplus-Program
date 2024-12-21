#ifndef GROCERYTRACKER_H 

#define GROCERYTRACKER_H 



#include <unordered_map> 

#include <string> 



class GroceryTracker {

public:

    // Constructor: Opens the input file and populates the frequency map 

    GroceryTracker(const std::string& inputFileName);



    // Finds the frequency of a specific item 

    int findFrequency(const std::string& item) const;



    // Prints all items and their frequencies 

    void printItemFrequencies() const;



    // Prints a histogram of item frequencies 

    void printHistogram() const;



    // Writes the frequency data to a file (frequency.dat) 

    void writeFrequencyToFile() const;



private:

    // Stores the frequency of each item 

    std::unordered_map<std::string, int> itemFrequency;

};



#endif 

