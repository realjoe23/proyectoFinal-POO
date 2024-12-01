#include "building.hpp"
#include "house.hpp"
#include "department.hpp"
#include "local.hpp"
#include "interface.hpp"
#include "container.hpp"

int main() {
    Container<Building> buildings;
    Container<House> houses;
    Container<Department> departments;
    Container<Local> locals;

    Interface ui(buildings, houses, departments, locals);
    ui.mainMenu();

    return 0;
}