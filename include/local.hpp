#ifndef __LOCAL_H__
#define __LOCAL_H__

#include <string>
#include "property.hpp"
#include "owner.hpp"
#include "address.hpp"

class Local: public Property{
private:
    std::string business;

public:
    Local();
    Local(const Local&);
    Local(const std::string&);
    Local(int cadastral, const Address& address, const Owner& owner, 
    double groSup, double groCons, std::string business);

    std::string getBusiness() const;

    std::string toString() const;

    void setBusiness(const std::string&);

    Local& operator = (const Local&);

    bool operator==(const Local&) const;
    bool operator != (const Local&) const; 
    bool operator < (const Local&) const;
    bool operator <= (const Local&) const;
    bool operator > (const Local&) const;
    bool operator >= (const Local&) const;

    friend std::ostream& operator << (std::ostream&, const Local&);
    friend std::istream& operator >> (std::istream&, Local&);
};

#endif // __Local_H__