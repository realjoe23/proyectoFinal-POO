#include "property.hpp"
using namespace std;

Property::Property() : catastral(), address(), owner(), groSup(), groCons() {}

Property::Property(const Property& p)
    : catastral(p.catastral),
      address(p.address),
      owner(p.owner),
      groSup(p.groSup),
      groCons(p.groCons) {}

Property::Property(const int& c,
                   const Address& a,
                   const Owner& o,
                   const double& s,
                   const double& g)
    : catastral(c), address(a), owner(o), groSup(s), groCons(g) {}

int Property::getCatastral() const {
  return catastral;
}

Address Property::getAddress() const {
  return address;
}

Owner Property::getOwner() const {
  return owner;
}

double Property::getGroSup() const {
  return groSup;
}

double Property::getGroCons() const {
  return groCons;
}

string Property::toString() const {
  stringstream ss;

  ss << catastral << ", ";
  ss << address.toString() << ", ";
  ss << owner.toString() << ", ";
  ss << groSup << ", ";
  ss << groCons << ", ";

  return ss.str();
}

void Property::setCatastral(const int& c) {
  catastral = c;
}

void Property::setAddress(const Address& a) {
  address = a;
}

void Property::setOwner(const Owner& o) {
  owner = o;
}

void Property::setGroSup(const double& s) {
  groSup = s;
}

void Property::setGroCons(const double& c) {
  groCons = c;
}

Property& Property::operator=(const Property& p) {
  if (this != &p) {
    catastral = p.catastral;
    address = p.address;
    owner = p.owner;
    groSup = p.groSup;
    groCons = p.groCons;
  }
  return *this;
}

bool Property::operator==(const Property& p) const {
  return catastral == p.catastral && address == p.address && owner == p.owner &&
         groSup == p.groSup && groCons == p.groCons;
}

bool Property::operator!=(const Property& p) const {
  return !(*this == p);
}

bool Property::operator<(const Property& p) const {
  return catastral < p.catastral;
}

bool Property::operator<=(const Property& p) const {
  return *this < p || *this == p;
}

bool Property::operator>(const Property& p) const {
  return !(*this <= p);
}

bool Property::operator>=(const Property& p) const {
  return !(*this < p);
}

istream& operator>>(istream& is, Property& p) {
  string myStr;

  is >> p.catastral;
  is >> p.address;
  is >> p.owner;
  is >> p.groSup;
  is >> p.groCons;

  return is;
}

ostream& operator<<(ostream& os, const Property& p) {
  os << p.catastral << " * ";
  os << p.address.toString() << " * ";
  os << p.owner.toString() << " * ";
  os << p.groSup << " * ";
  os << p.groCons;

  return os;
}