#include "local.hpp"

using namespace std;

Local::Local() : business("") {}

Local::Local(const Local& c) : Property::Property(c), business(c.business) {}

Local::Local(const string& c) : Property(), business(c) {}

Local::Local(int cadastral,
             const Address& address,
             const Owner& owner,
             double groSup,
             double groCons,
             string business)
    : Property(cadastral, address, owner, groSup, groCons),
      business(business) {}

string Local::getBusiness() const {
  return business;
}

string Local::toString() const {
  return Property::toString() + ", " + business;
}

void Local::setBusiness(const string& c) {
  business = c;
}

Local& Local::operator=(const Local& c) {
  if (this != &c) {
    Property::operator=(c);
    business = c.business;
  }
  return *this;
}

bool Local::operator==(const Local& c) const {
  return getCatastral() == c.getCatastral();
}

bool Local::operator!=(const Local& c) const {
  return !(*this == c);
}

bool Local::operator<(const Local& c) const {
  return getCatastral() < c.getCatastral();
}

bool Local::operator<=(const Local& c) const {
  return *this < c or *this == c;
}

bool Local::operator>(const Local& c) const {
  return !(*this <= c);
}

bool Local::operator>=(const Local& c) const {
  return !(*this < c);
}

istream& operator>>(istream& is, Local& c) {
  string myStr;

  getline(is, myStr, '*');
  c.catastral = stod(myStr);

  is >> c.address;
  is >> c.owner;

  getline(is, myStr, '*');
  c.groSup = stod(myStr);

  getline(is, myStr, '*');
  c.groCons = stod(myStr);

  getline(is, myStr, '*');
  c.setBusiness(myStr);

  return is;
}

ostream& operator<<(ostream& os, const Local& c) {
  os << static_cast<const Property&>(c) << " * ";

  os << c.getBusiness();

  return os;
}