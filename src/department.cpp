#include "department.hpp"
using namespace std;

Department::Department() : innerN(0) {}

Department::Department(const Department& d) 
    : Property(d), innerN(d.innerN) {}

Department::Department(const int& d) 
    : Property(), innerN(d) {}

Department::Department(int catastral, const Address& address, const Owner& owner, double groSup, double groCons, int innerN)
    : Property(catastral, address, owner, groSup, groCons), innerN(innerN) {}

int Department::getInnerN() const {
    return innerN;
}

string Department::toString() const {
    return Property::toString() + ", Interior: " + to_string(innerN);
}

void Department::setInnerN(const int& d) {
    innerN = d;
}

Department& Department::operator=(const Department& d) {
    if (this != &d) {
        Property::operator=(d);
        innerN = d.innerN;
    }
    return *this;
}

bool Department::operator==(const Department& d) const {
    return getCatastral() == d.getCatastral();
}

bool Department::operator!=(const Department& d) const {
    return !(*this == d);
}

bool Department::operator<(const Department& d) const {
    return getCatastral() < d.getCatastral();
}

bool Department::operator<=(const Department& d) const {
    return *this < d || *this == d;
}

bool Department::operator>(const Department& d) const {
    return !(*this <= d);
}

bool Department::operator>=(const Department& d) const {
    return !(*this < d);
}

istream& operator>>(istream& is, Department& d) {
    string myStr;

    getline(is, myStr, '*');
    d.setCatastral(stoi(myStr));

    is >> d.address;

    is >> d.owner;

    getline(is, myStr, '*');
    d.setGroSup(stod(myStr));

    getline(is, myStr, '*');
    d.setGroCons(stod(myStr));

    getline(is, myStr, '*');
    d.setInnerN(stoi(myStr));

    return is;
}

ostream& operator<<(ostream& os, const Department& d) {
    os << static_cast<const Property&>(d) << " * Interior: " << d.getInnerN();
    return os;
}
