#include <fstream>
#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include "restaurants.h"
#include "reader.h"

using namespace std;

void Reader::read_record(string filename){
    
    // holds the header values
    vector<string> headers;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");
    // initialise variables
    string line, name, val;

    // Read the column names
    if(myFile.good())
    {
        // Extract the first line in the file
        getline(myFile, line);

        // Remove carriage return characters (if present)
        line.erase( remove(line.begin(), line.end(), '\r'), line.end() );
        // Create a stringstream from line
        stringstream ss(line);

        // Extract each column name
        while(getline(ss, name, ',')){
            // Check if the string starts with any whitespace characters
            if (!name.empty() && name[0] == ' ') {
                // Erase leading spaces
                name.erase(0, name.find_first_not_of(' '));
            }
            // Initialise the map with keys
            headers.push_back({name});
        }
    }

    // Read data, line by line
    while(getline(myFile, line))
    {
        // Remove carriage return characters (if present)
        line.erase( remove(line.begin(), line.end(), '\r'), line.end() );
        // Create a stringstream of the current line
        stringstream ss(line);
        string field;
        vector<string> row;
        
        // Keep track of the current column index
        int colIdx = 0;
        
        // initialise the restaurant class
        restaurant venue;
        string key;

        // 
        while(getline(ss,field,',')){
            
            // get the current header string
            key = headers[colIdx];
            // Check if the string starts with any whitespace characters
            if (!field.empty() && field[0] == ' ') {
                // Erase leading spaces
                field.erase(0, field.find_first_not_of(' '));
            }
            // add the value for that header to the restaurant class
            venue.add_value(key,field);
            
            // Increment the column index
            colIdx++;
        }
        // add venue to search maps
        name_map.insert({venue.get_name(),venue});
        type_map.insert({venue.get_type(),venue});
        food_rating_map.insert({venue.get_food_rating(), venue});
        service_rating_map.insert({venue.get_service_rating(), venue});
        address_map.insert({venue.get_address(),venue});
    }
    myFile.close();
}
