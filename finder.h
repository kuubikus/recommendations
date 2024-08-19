#ifndef FINDER_H
#define FINDER_H

#include <string>

void find_restaurant_by_name(Reader& reader, std::string search);
void find_restaurant_by_address(Reader& reader, std::string search);
void find_restaurant_by_type(Reader& reader, std::string search, int no_of_restaurants);


#endif