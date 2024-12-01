#include "name.hpp"

using namespace std;

string Name::getLast() const {
    return this->last; 
}

string Name::getFirst() const{
    return this->first; 
}

string Name::toString() const {
    return this->last + ", " + this->first;
}

void Name::setLast(const string& l) {
    this->last = l;
}

void Name::setFirst(const string& f) {
    this->first = f;
}

Name::Name() : last(""), first("") {}

Name::Name(const Name& other) : last(other.last), first(other.first) {}

Name::Name(const string& l, const string& f) : last(l), first(f){}

Name& Name::operator = (const Name& other) {
    last = other.last;
    first = other.first;

    return *this;
}

bool Name::operator==(const Name& n) const {
    return toString() == n.toString();
}

bool Name::operator != (const Name& n) const {
    return !(*this == n);
}

bool Name::operator < (const Name& n) const {
    return toString() < n.toString();
}

bool Name::operator <= (const Name& n) const {
    return *this < n || *this == n; 
}

bool Name::operator > (const Name& n) const {
    return !(*this <= n);
}

bool Name::operator >= (const Name& n) const {
    return !(*this < n); 
}

ostream& operator << (ostream& os, const Name& n) {
    os << n.last << "*" << n.first;

    return os;
}

istream& operator >> (istream& is,  Name& n) {
    getline(is, n.last, '*');
    getline(is, n.first, '*');

    return is;
}