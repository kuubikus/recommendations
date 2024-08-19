#include "reader.h"
#include "finder.h"
#include <iostream>
#include <string>

Reader reader;

int main(){
    // read the file
    reader.read_record("restaurants.csv");
    // TODO Add search functionality with UI

    // Searching by name
    std::string search_name = "Esthers German Saloon";
    std::string search_address = "22 Teutonic Ave.";
    int no_of_restaurants_to_display = 2;
    find_restaurant_by_name(reader, search_name);
    find_restaurant_by_address(reader,search_address);
    find_restaurant_by_type(reader,"german",no_of_restaurants_to_display);
};
