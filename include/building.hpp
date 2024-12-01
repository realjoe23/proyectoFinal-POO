#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <string.h>
#include "property.hpp"
#include "owner.hpp"
#include "address.hpp"

class Building: public Property{
private:
    int floors;

public:
    Building();
    Building(const Building&);
    Building(const int&);
    Building(int catastral, const Address& address, const Owner& owner, 
    double groSup, double groCons, int floors);

    int getFloors() const;

    std::string toString() const;

    void setFloors(const int&);

    Building& operator = (const Building&);

    bool operator==(const Building&) const;
    bool operator != (const Building&) const; 
    bool operator < (const Building&) const;
    bool operator <= (const Building&) const;
    bool operator > (const Building&) const;
    bool operator >= (const Building&) const;

    friend std::ostream& operator << (std::ostream&, const Building&);
    friend std::istream& operator >> (std::istream&, Building&);
};

#endif // __Building_H__