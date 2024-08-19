#ifndef READER_H
#define READER_H

#include "restaurants.h"
#include <string>
#include <unordered_map>
#include <map>

class  Reader{
    public:
    // Initialise the unordered maps
    std::unordered_map<std::string, restaurant> name_map;      // Search by name
    std::multimap<std::string, restaurant> type_map;      // Search by type
    std::multimap<double, restaurant> food_rating_map;    // Search by rating
    std::multimap<double, restaurant> service_rating_map;    // Search by rating
    std::unordered_map<std::string, restaurant> address_map; // Search by address

    /* data */
    void read_record(std::string name);
};

#endif