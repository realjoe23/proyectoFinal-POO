#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#include <iostream>
#include <string>

class Address {
 private:
  std::string street;
  int number;
  int cp;

 public:
  Address();

  Address(const Address&);

  Address(const std::string&, int&, int&);

  std::string getStreet() const;
  int getNumber() const;
  int getCp() const;

  std::string toString() const;

  void setStreet(const std::string&);
  void setNumber(const int&);
  void setCp(const int&);

  Address& operator=(const Address&);

  bool operator==(const Address&) const;
  bool operator!=(const Address&) const;
  bool operator<(const Address&) const;
  bool operator<=(const Address&) const;
  bool operator>(const Address&) const;
  bool operator>=(const Address&) const;

  friend std::ostream& operator<<(std::ostream&, const Address&);
  friend std::istream& operator>>(std::istream&, Address&);
};

#endif  // __ADDRESS_H__