#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>

bool inSet(std::set<TYPE> a_set, TYPE to_find){
    //TODO: implement and change TYPE to the type you're using. 
    // this function takes in a set and a something to find in the set
    //return true if to_find is in the set, false otherwise
}

bool inMap(std::map<KEY_TYPE, VALUE_TYPE> cases, KEY_TYPE check){
    // TODO: implement and change KEY_TYPE and VALUE_TYPE to the type you're using. 
    // this function takes in a map and a something to find in the map
    // return true if to_find is in the map, false otherwise
}

int main(){
    //TODO: Specify what type of data your set will store
    std::set<TYPE> my_set; 
    //TODO: Specify what type of data your map will store: remember, they can be two differente or the same type.
    std::map<KEY_TYPE, VALUE_TYPE> cases;

    std::ifstream data;
    std::string line;

    //TODO: Replace with your CSV file name
    data.open("TODO: YOUR FILE HERE");
    while (std::getline(data, line)){
        // This is where you will implement your code for
        // insertion into maps and sets
    
    }

    data.close();

    //TODO: Test inMap() and inSet() by confirming that the values from your CSV are present 
    /* For example, if my set was storing countries, I could test by doing something like:

        if (!inSet(countries, "Guatemala")){
            std::cout << "Test Case 1: Failed" << std::endl;
            std::cout << "A country is missing from the countries set." << std::endl;
            return 1;
        }

        if (inSet(countries, "Rhode Island")){
            std::cout << "Test Case 2: Failed" << std::endl;
            std::cout << "A state/province was added to the the countries set." << std::endl;
            return 1;
        }

        (and so on and so forth with more tests and by testing map as well)

        std::cout << "All tests passed!" << std::endl;

    */

    //TODO: Use some of the built-in functions for std::set and std::map to answer questions about your data
}