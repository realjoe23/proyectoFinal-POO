#include "interface.hpp"

using namespace std;

void Interface::toContinue() {
    cout << "Presione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::promptOwner(Address& address, Owner& owner) {
    string street, curp, firstName, lastName;
    int number, cp;

    cout << "calle: ";
    cin.ignore();
    getline(cin, street);

    while (true) {
        cout << "numero de direccion: ";
        cin >> number;
        if (cin.fail() || number <= 0) {
            cout << "Por favor, ingresa un numero valido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    while (true) {
        cout << "Codigo Postal: ";
        cin >> cp;
        if (cin.fail() || cp <= 0) {
            cout << "Por favor, ingresa un codigo postal valido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    cout << "Curp: ";
    getline(cin, curp);

    cout << "apellido: ";
    getline(cin, lastName);

    cout << "nombre: ";
    getline(cin, firstName);

    address.setStreet(street);
    address.setNumber(number);
    address.setCp(cp);

    Name fullName;
    fullName.setFirst(firstName);
    fullName.setLast(lastName);

    owner.setCurp(curp);
    owner.setName(fullName);
    owner.setName(fullName);
}


Interface::Interface(Container<Building>& building, Container<House>& house, 
Container<Department>& department, Container<Local>& local) {
    buildingRef = &building;
    houseRef = &house;
    depaRef = &department;
    localRef = &local;
}

void Interface::mainMenu() {
    int option;
    do {
        system("cls");

        cout << "\n--- JCG REAL STATE ---" << endl;
        cout << "1. Edificios" << endl;
        cout << "2. Casas" << endl;
        cout << "3. Departamentos" << endl;
        cout << "4. Comercios" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Intente nuevamente.\n";
            toContinue();
            continue;
        }

        switch (option) {
            case 1:
                execute(*buildingRef, "Edificio");
                break;
            case 2:
                execute(*houseRef, "Casa");
                break;
            case 3:
                execute(*depaRef, "Departamento");
                break;
            case 4:
                execute(*localRef, "Comercios");
                break;
            case 5:
                cout << "Saliendo del Programa..." << endl;
                toContinue();
                break;
            default:
                cout << "Opcion invalida, intente de nuevo" << endl;
                toContinue();
        }
    } while (option != 5);
}



void Interface::typeMenu() {

    cout << "[A]ltas" << endl;
    cout << "[B]ajas" << endl;
    cout << "[S]how" << endl;
    cout << "[O]rder" << endl;
    cout << "[W]rite to Disk" << endl;
    cout << "[R]ead Disk" << endl;
    cout << "[E]xit" << endl << endl;
}

template <typename T>
void Interface::execute(Container<T>& registry, const string& typeName) {
    char option;
    do {
        system("cls");

        typeMenu();
        cin >> option;
        cin.ignore();
        option = toupper(option);

        switch (option) {
            case 'A':
                addData();
                break;
            case 'B':
                delData();
                break;
            case 'S':
                showData();
                break;
            case 'O':
                sortData();
                break;
            case 'W':
                writeDisk();
                break;
            case 'R':
                readDisk();
                break;
            case 'E':
                cout << "Regresando al menu principal" << endl;
                toContinue();
                break;
            default:
                cout << "Opcion invalida, intente de nuevo" << endl;
                toContinue();
        }
    } while (option != 'E');
}


void Interface::addData() {
    string typeName;

    cout << "Seleccione el tipo de inmueble por agregar:" << endl;
    cout << "1. Edificio" << endl;
    cout << "2. Casa" << endl;
    cout << "3. Departamento" << endl;
    cout << "4. Comercial" << endl;
    cout << "Opcion: ";
    int option;
    cin >> option;

    system("cls");

    Address address;
    Owner owner;

    if (cin.fail() || option < 1 || option > 4) {
        cout << "Opcion invalida." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        toContinue();
        return;
    }

    promptOwner(address, owner);

    int catastral;
    double groSup, groCons;

    while (true) {
        cout << "Dame la clave catastral: ";
        cin >> catastral;
        if (cin.fail() || catastral <= 0) {
            cout << "Por favor, ingresa una clave catastral valida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    while (true) {
        cout << "Dame la superficie del suelo (m2): ";
        cin >> groSup;
        if (cin.fail() || groSup <= 0) {
            cout << "Por favor, ingresa una superficie valida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    while (true) {
        cout << "Dame la superficie construida (m2): ";
        cin >> groCons;
        if (cin.fail() || groCons <= 0) {
            cout << "Por favor, ingresa una superficie valida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    switch (option) {
        case 1: { 
            typeName = "Edificio";
            int floors;

            while (true) {
                cout << "Dame la cantidad de pisos: ";
                cin >> floors;
                if (cin.fail() || floors <= 0) {
                    cout << "Por favor, ingresa un numero valido de pisos.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }

            Building newBuilding(catastral, address, owner, groSup, groCons, floors);
            buildingRef->add(newBuilding);
            cout << "Edificio agregado exitosamente." << endl;
            break;
        }
        case 2: {
            typeName = "Casa";
            int nRooms;

            while (true) {
                cout << "Dame la cantidad de habitaciones: ";
                cin >> nRooms;
                if (cin.fail() || nRooms <= 0) {
                    cout << "Por favor, ingresa un numero valido de habitaciones.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }

            House newHouse(catastral, address, owner, groSup, groCons, nRooms);
            houseRef->add(newHouse);
            cout << "Casa agregada exitosamente." << endl;
            break;
        }
        case 3: {
            typeName = "Departamento";
            int innerN;

            while (true) {
                cout << "Dame el numero interior: ";
                cin >> innerN;
                if (cin.fail() || innerN <= 0) {
                    cout << "Por favor, ingresa un numero valido de interior.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }

            Department newDepa(catastral, address, owner, groSup, groCons, innerN);
            depaRef->add(newDepa);
            cout << "Departamento agregado exitosamente." << endl;
            break;
        }
        case 4: {
            typeName = "Comercial";
            string business;

            cout << "Dame el giro comercial: ";
            cin.ignore();
            getline(cin, business);
            if (business.empty()) {
                business = "Sin especificar";
            }

            Local newComm(catastral, address, owner, groSup, groCons, business);
            localRef->add(newComm);
            cout << "Local comercial agregado exitosamente." << endl;
            break;
        }
        default:
            cout << "Opcion invalida." << endl;
            return;
    }

    toContinue();
}

void Interface::delData() {
    cout << "Seleccione el tipo de inmueble a eliminar:" << endl;
    cout << "1. Edificio" << endl;
    cout << "2. Casa" << endl;
    cout << "3. Departamento" << endl;
    cout << "4. Comercial" << endl;
    cout << "Opcion: ";
    
    int option;
    cin >> option;

    if (cin.fail() || option < 1 || option > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida." << endl;
        toContinue();
        return;
    }

    int catastralKey;

    cout << "Ingrese la clave catastral del inmueble a eliminar: ";
    while (!(cin >> catastralKey) || catastralKey <= 0) {
        cout << "Entrada invalida. Ingrese una clave catastral valida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (option) {
        case 1: {
            Building temp;
            temp.setCatastral(catastralKey);

            if (buildingRef->there(temp)) {
                buildingRef->del(temp);
                cout << "Edificio eliminada." << endl;
            } else {
                cout << "No se encontro un edificio con la clave catastral." << endl;
            }
            break;
        }
        case 2: {
            House temp;
            temp.setCatastral(catastralKey);

            if (houseRef->there(temp)) {
                houseRef->del(temp);
                cout << "Casa eliminada." << endl;
            } else {
                cout << "No se encontro una casa con la clave catastral." << endl;
            }
            break;
        }
        case 3: {
            Department temp;
            temp.setCatastral(catastralKey);

            if (depaRef->there(temp)) {
                depaRef->del(temp);
                cout << "Departamento eliminado." << endl;
            } else {
                cout << "No se encontro un departamento con la clave catastral." << endl;
            }
            break;
        }
        case 4: { 
            Local temp;
            temp.setCatastral(catastralKey);

            if (localRef->there(temp)) {
                localRef->del(temp);
                cout << "Local comercial eliminado." << endl;
            } else {
                cout << "No se encontro un local comercial con la clave catastral." << endl;
            }
            break;
        }
        default:
            cout << "Opcion invalida." << endl;
            break;
    }

    toContinue();
}




void Interface::showData() {

    cout << "\nLista de Inmuebles Actualizada" << endl;

    auto showCategory = [](const string& categoryName, auto* container) {
        cout << "\n" << categoryName << ":" << endl;
        if (container != nullptr) {
            string data = container->toString();
            if (!data.empty()) {
                cout << data << endl;
            } else {
                cout << "No hay datos disponibles para " << categoryName << "." << endl;
            }
        } else {
            cout << "Referencia no inicializada para " << categoryName << "." << endl;
        }
    };

    showCategory("Torres", buildingRef);
    showCategory("Casas", houseRef);
    showCategory("Departamentos", depaRef);
    showCategory("Comercios", localRef);

    cout << "\n------------------------------------------------------" << endl;

    toContinue();
}




void Interface::sortData() {
    system("cls"); 

    buildingRef->sortData();
    houseRef->sortData();
    depaRef->sortData();
    localRef->sortData();

    cout << "Registros ordenados con exito." << endl << endl;

    toContinue(); 
}


void Interface::writeDisk() {
    try {
        auto promptFileName = [](const string& typeName) -> string {
            string fileName;
            cout << "Ingrese el nombre del archivo para guardar los datos de " << typeName << ": ";
            getline(cin, fileName);
            if (fileName.empty()) {
                throw runtime_error("El nombre del archivo no puede estar vacio.");
            }
            return fileName;
        };

        buildingRef->writeDisk(promptFileName("edificios"));
        houseRef->writeDisk(promptFileName("casas"));
        depaRef->writeDisk(promptFileName("departamentos"));
        localRef->writeDisk(promptFileName("comercios"));

        cout << "Todos los datos han sido guardados en disco correctamente." << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void Interface::readDisk() {
    try {
        auto promptFileName = [](const string& typeName) -> string {
            string fileName;
            while (true) {
                cout << "Ingrese el nombre del archivo para cargar los datos de " << typeName << ": ";
                getline(cin, fileName);

                if (fileName.empty()) {
                    cerr << "El nombre del archivo no puede estar vacio. Intente de nuevo." << endl;
                    continue;
                }
                break; 
            }
            return fileName;
        };

        buildingRef->readDisk(promptFileName("edificios"));
        houseRef->readDisk(promptFileName("casas"));
        depaRef->readDisk(promptFileName("departamentos"));
        localRef->readDisk(promptFileName("comercios"));

        cout << "Todos los datos han sido importados desde disco correctamente." << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}





