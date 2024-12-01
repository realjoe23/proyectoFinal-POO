#include "address.hpp"

using namespace std;

Address::Address() : street(), number(), cp() {}

Address::Address(const Address& other)
    : street(other.street), number(other.number), cp(other.cp) {}

Address::Address(const string& s, int& n, int& c)
    : street(s), number(n), cp(c) {}

string Address::getStreet() const {
  return street;
}

int Address::getNumber() const {
  return number;
}

int Address::getCp() const {
  return cp;
}

string Address::toString() const {
  return street + ", " + to_string(number) + ", " + to_string(cp);
}

void Address::setStreet(const string& s) {
  street = s;
}

void Address::setNumber(const int& n) {
  number = n;
}

void Address::setCp(const int& c) {
  cp = c;
}

Address& Address::operator=(const Address& a) {
  if (this != &a) {
    street = a.street;
    number = a.number;
    cp = a.cp;
  }
  return *this;
}

bool Address::operator==(const Address& a) const {
  return toString() == a.toString();
}

bool Address::operator!=(const Address& a) const {
  return !(*this == a);
}

bool Address::operator<(const Address& a) const {
  return toString() < a.toString();
}

bool Address::operator<=(const Address& a) const {
  return *this < a || *this == a;
}

bool Address::operator>(const Address& a) const {
  return !(*this <= a);
}

bool Address::operator>=(const Address& a) const {
  return !(*this < a);
}

istream& operator>>(istream& is, Address& a) {
  string myStr;

  getline(is, a.street, '*');
  getline(is, myStr, '*');
  a.number = stoi(myStr);
  getline(is, myStr, '*');
  a.cp = stoi(myStr);

  return is;
}

ostream& operator<<(ostream& os, const Address& a) {
  os << a.street << "*" << a.number << "*" << a.cp;

  return os;
}
