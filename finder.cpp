#include "reader.h"
#include "finder.h"
#include "restaurants.h"
#include <iostream>
#include <string>

// Overload operator<< for MyStruct
    ostream& operator<<(ostream& os, const restaurant& obj){
        os << "Name: " << obj.get_name() << ", " << obj.get_food_rating() << ", " << obj.get_address();
        return os;
    }

void find_restaurant_by_name(Reader& reader, std::string search){
    if (reader.name_map.find(search) != reader.name_map.end()) {
        restaurant found = reader.name_map[search];
        std::cout << "Found: " << found.get_name() << ", " << found.get_food_rating() << ", " << found.get_address() << std::endl;
    }
}
void find_restaurant_by_address(Reader& reader, std::string search){
    if (reader.address_map.find(search) != reader.address_map.end()) {
        restaurant found = reader.address_map[search];
        std::cout << "Found: " << found.get_name() << ", " << found.get_food_rating() << ", " << found.get_address() << std::endl;
    }
}

void find_restaurant_by_type(Reader& reader, std::string search, int no_of_restaurants){
    // Use equal_range to find all elements with the same key
    auto range = reader.type_map.equal_range(search);
    int c = 1;
    for (auto it = range.first; it != range.second && c<=no_of_restaurants; ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++c;
    }
}