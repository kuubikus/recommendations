#include "restaurants.h"
#include <string>
#include <iostream>

using namespace std;

void restaurant::add_value(string key,string value){
    if( key == "type" ){
        type = value;
    }
    if( key == "name" ){
        name = value;
    }
    if( key == "address" ){
        address = value;
    }
    if( key == "food_rating" ){
        food_rating = stoi(value);
    }
    if( key == "service_rating" ){
        service_rating = stoi(value);
    }
};

