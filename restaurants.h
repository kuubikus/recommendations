#ifndef RESTAURANTS_H
#define RESTAURANTS_H


#include <string>
using namespace std;

class restaurant{
    private:
        std::string type, name, address;
        int food_rating, service_rating;
    public:
    void add_value(string key,string value);
    string get_name() const {return name;};
    string get_type() const {return type;};
    string get_address() const {return address;};
    int get_food_rating()const {return food_rating;};
    int get_service_rating() const {return service_rating;};
};

#endif