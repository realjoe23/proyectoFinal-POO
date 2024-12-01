#ifndef _HOUSE_H_
#define _HOUSE_H_

#include <string.h>
#include "property.hpp"
#include "owner.hpp"
#include "address.hpp"

class House: public Property{
private:
    int nRooms;

public:
    House();
    House(const House&);
    House(const int&);
    House(int catastral, const Address& address, const Owner& owner, 
    double groSup, double groCons, int nRooms);

    int getnRooms() const;

    std::string toString() const;

    void setnRooms(const int&);

    House& operator = (const House&);

    bool operator == (const House&) const;
    bool operator != (const House&) const; 
    bool operator < (const House&) const;
    bool operator <= (const House&) const;
    bool operator > (const House&) const;
    bool operator >= (const House&) const;

    friend std::ostream& operator << (std::ostream&, const House&);
    friend std::istream& operator >> (std::istream&, House&);
};

#endif // _HOUSE_H_