#ifndef __DEPARTMENT_HPP__
#define __DEPARTMENT_HPP__

#include <string>
#include <iostream>
#include "property.hpp" 

class Department : public Property {
private:
    int innerN; 

public:

    Department();
    Department(const Department& d);
    Department(const int& d); 
    Department(int catastral, const Address& address, const Owner& owner, double groSup, double groCons, int innerN);

    int getInnerN() const;

    std::string toString() const;

    void setInnerN(const int& d);

    Department& operator=(const Department& d);

    bool operator==(const Department&) const;
    bool operator!=(const Department&) const;
    bool operator<(const Department&) const;
    bool operator<=(const Department&) const;
    bool operator>(const Department&) const;
    bool operator>=(const Department&) const;

    friend std::istream& operator>>(std::istream&, Department&);
    friend std::ostream& operator<<(std::ostream&, const Department&);
};

#endif // __DEPARTMENT_HPP__
