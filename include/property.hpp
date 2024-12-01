#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <string>
#include <iostream>
#include <sstream>

#include "owner.hpp"
#include "address.hpp"

class Property{
protected:
    int catastral;
    Address address;
    Owner owner;
    double groSup;
    double groCons;

public:
    Property();

    Property(const Property&);

    Property(const int&, const Address&, const Owner&, const double&, const double&);

    int getCatastral() const;
    Address getAddress() const;
    Owner getOwner() const;
    double getGroSup() const;
    double getGroCons() const;

    std::string toString() const;

    void setCatastral(const int&);
    void setAddress(const Address&);
    void setOwner(const Owner&);
    void setGroSup(const double&);
    void setGroCons(const double&);

    Property& operator = (const Property&);

    bool operator==(const Property&) const;
    bool operator != (const Property&) const; 
    bool operator < (const Property&) const;
    bool operator <= (const Property&) const;
    bool operator > (const Property&) const;
    bool operator >= (const Property&) const;

    friend std::ostream& operator << (std::ostream&, const Property&);
    friend std::istream& operator >> (std::istream&, Property&);
};   

#endif // __PROPERTY_H__