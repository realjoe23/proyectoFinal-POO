#ifndef __OWNER_H__
#define __OWNER_H__

#include <string>
#include <iostream>
#include <sstream> 
#include "name.hpp"

class Owner {
private:
    std::string curp;
    Name name;

public:

    Owner();
    Owner(const Owner& o);
    Owner(const std::string& curp, const Name& name);

    std::string getCurp() const;
    Name getName() const;

    std::string toString() const;

    void setCurp(const std::string&);
    void setName(const Name&);

    Owner& operator=(const Owner&);

    bool operator==(const Owner&) const;
    bool operator!=(const Owner&) const; 
    bool operator<(const Owner&) const;
    bool operator<=(const Owner&) const;
    bool operator>(const Owner&) const;
    bool operator>=(const Owner&) const;

    friend std::ostream& operator<<(std::ostream&, const Owner&);
    friend std::istream& operator>>(std::istream&, Owner&);
};

#endif // __OWNER_H__
