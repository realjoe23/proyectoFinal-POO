#include "building.hpp"

using namespace std;

Building::Building(): floors(0) {}

Building::Building(const Building& t) : Property::Property(t), floors(t.floors) {}

Building::Building(const int& t) : Property(), floors(t) {}

Building::Building(int cadastral, const Address& address, const Owner& owner, double groSup, double groCons, int floors)
    : Property(cadastral, address, owner, groSup, groCons), floors(floors) {}
    
int Building::getFloors() const{
    return floors;
}

string Building::toString() const {
    return Property::toString() + ", " + to_string(floors);
}

void Building::setFloors(const int& t) {
    floors = t;
}

Building& Building::operator = (const Building& t) {
    if (this != &t) {
    Property::operator=(t);
    floors = t.floors;
  }
  return *this;
}

bool Building::operator==(const Building& t) const {
    return getCatastral() == t.getCatastral();
}

bool Building::operator != (const Building& t) const {
    return !(*this == t);
}

bool Building::operator < (const Building& t) const {
    return getCatastral() < t.getCatastral();
}

bool Building::operator <= (const Building& t) const {
    return *this < t or *this == t;
}

bool Building::operator > (const Building& t) const {
    return !(*this <= t);
}

bool Building::operator >= (const Building& t) const {
    return !(*this < t);
}

istream& operator >> (istream& is, Building& t) {
    string myStr;

    getline(is, myStr, '*');
    t.catastral = stod(myStr); 

    is >> t.address;
    is >> t.owner;

    getline(is, myStr, '*');
    t.groSup = stod(myStr);

    getline(is, myStr, '*');
    t.groCons = stod(myStr);

    getline(is, myStr, '*');
    t.setFloors(stoi(myStr));

    return is;    
}

ostream& operator << (ostream& os, const Building& t) {
    os << static_cast<const Property&>(t) << " * ";

    os << t.getFloors();

    return os;
}