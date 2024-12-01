#include "owner.hpp"

Owner::Owner() : curp(), name() {}

Owner::Owner(const Owner& o) : curp(o.curp), name(o.name) {}

Owner::Owner(const std::string& curp, const Name& name)
    : curp(curp), name(name) {}

std::string Owner::getCurp() const {
  return curp;
}

Name Owner::getName() const {
  return name;
}

std::string Owner::toString() const {
  std::ostringstream oss;
  oss << curp << " | " << name.toString();
  return oss.str();
}

void Owner::setCurp(const std::string& c) {
  curp = c;
}

void Owner::setName(const Name& n) {
  name = n;
}

Owner& Owner::operator=(const Owner& o) {
  if (this != &o) {
    curp = o.curp;
    name = o.name;
  }
  return *this;
}

bool Owner::operator==(const Owner& o) const {
  return curp == o.curp && name == o.name;
}

bool Owner::operator!=(const Owner& o) const {
  return !(*this == o);
}

bool Owner::operator<(const Owner& o) const {
  return curp < o.curp || (curp == o.curp && name < o.name);
}

bool Owner::operator<=(const Owner& o) const {
  return *this < o || *this == o;
}

bool Owner::operator>(const Owner& o) const {
  return !(*this <= o);
}

bool Owner::operator>=(const Owner& o) const {
  return !(*this < o);
}

std::istream& operator>>(std::istream& is, Owner& o) {
  std::string curp;
  Name name;

  if (is >> curp >> name) {
    o.curp = curp;
    o.name = name;
  } else {
    is.setstate(std::ios::failbit);
  }

  return is;
}

std::ostream& operator<<(std::ostream& os, const Owner& o) {
  os << o.curp << " | " << o.name.toString();
  return os;
}
