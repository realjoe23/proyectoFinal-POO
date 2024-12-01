#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <cctype>
#include <iostream>
#include <limits>
#include <string>

#include "address.hpp"
#include "building.hpp"
#include "container.hpp"
#include "department.hpp"
#include "house.hpp"
#include "local.hpp"
#include "owner.hpp"

class Interface {
 private:
  Container<Building>* buildingRef;
  Container<House>* houseRef;
  Container<Department>* depaRef;
  Container<Local>* localRef;

  void toContinue();

  void typeMenu();

  void promptOwner(Address& address, Owner& owner);

  void addData();
  void delData();
  void sortData();
  void writeDisk();
  void readDisk();
  void showData();

  template <typename T>
  void execute(Container<T>&, const std::string&);

 public:
  Interface(Container<Building>&,
            Container<House>&,
            Container<Department>&,
            Container<Local>&);

  void mainMenu();
};

#endif  // __Interface_H__
