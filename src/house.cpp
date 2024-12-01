#include "house.hpp"
using namespace std;

House::House() : nRooms(0) {}

House::House(const House& h) : Property::Property(h), nRooms(h.nRooms) {}

House::House(const int& n) : Property(), nRooms(n) {}

House::House(int catastral,
             const Address& address,
             const Owner& owner,
             double groSup,
             double groCons,
             int nRooms)
    : Property(catastral, address, owner, groSup, groCons), nRooms(nRooms) {}

int House::getnRooms() const {
  return nRooms;
}

string House::toString() const {
  return Property::toString() + ", " + to_string(nRooms);
}

void House::setnRooms(const int& n) {
  nRooms = n;
}

House& House::operator=(const House& h) {
  if (this != &h) {
    Property::operator=(h);
    nRooms = h.nRooms;
  }
  return *this;
}

bool House::operator==(const House& h) const {
  return getCatastral() == h.getCatastral() && nRooms == h.nRooms;
}

bool House::operator!=(const House& h) const {
  return !(*this == h);
}

bool House::operator<(const House& h) const {
  return getCatastral() == h.getCatastral() && nRooms == h.nRooms;
}

bool House::operator<=(const House& h) const {
  return *this < h or *this == h;
}

bool House::operator>(const House& h) const {
  return !(*this <= h);
}

bool House::operator>=(const House& h) const {
  return !(*this < h);
}

istream& operator>>(istream& is, House& h) {
  string myStr;

  getline(is, myStr, '*');
  h.catastral = stod(myStr);

  is >> h.address;
  is >> h.owner;

  getline(is, myStr, '*');
  h.groSup = stod(myStr);

  getline(is, myStr, '*');
  h.groCons = stod(myStr);

  getline(is, myStr, '*');
  h.setnRooms(stoi(myStr));

  return is;
}

ostream& operator<<(ostream& os, const House& h) {
  os << static_cast<const Property&>(h) << " * ";

  os << h.getnRooms();

  return os;
}
