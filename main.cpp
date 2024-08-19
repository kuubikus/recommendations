#include "reader.h"
#include "finder.h"
#include <iostream>
#include <string>

Reader reader;

int main(){
    std::string find_method;

    // read the file
    reader.read_record("restaurants.csv");
    // Ask for user input
    std::cout << "Hello. Would you like to search by name, address or type ['name','address','type']?" << std::endl;
    std::cin >> find_method;  // Read an integer
    if (find_method=="name"){
        std::string search_name;
        std::cout << "What is the name of the restaurant?" << std::endl;
        std::cin >> search_name;
        find_restaurant_by_name(reader, search_name);
    }
    if (find_method=="address"){
        std::string search_name;
        std::cout << "What is the address of the restaurant?" << std::endl;
        std::cin >> search_name;
        find_restaurant_by_address(reader, search_name);
    }
    if (find_method=="type"){
        std::string search_name;
        int no_of_restaurants_to_display;
        std::cout << "What type of restaurant are you looking for?" << std::endl;
        std::cin >> search_name;
        std::cout << "How many restaurants to you want displayed? Press '0' for default" << std::endl;
        std::cin >> no_of_restaurants_to_display;
        if (no_of_restaurants_to_display == 0){
            no_of_restaurants_to_display = 2;
        }
        find_restaurant_by_type(reader, search_name,no_of_restaurants_to_display);
    }
};
