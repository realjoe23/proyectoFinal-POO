#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

template <class T>
class Container {
 private:
  std::vector<T> data;

 public:
  Container();
  Container(const Container&);

  void add(const T&);
  void add(const Container&);
  void del(const T&);

  std::string toString() const;

  void sortData();
  void writeDisk(const std::string&);
  void readDisk(const std::string&);

  bool there(const T&);

  Container& operator=(const Container&);

  Container& operator+=(const T&);
  Container& operator+=(const Container&);

  Container operator+(const T&) const;
  Container operator+(const Container&) const;
};

template <class T>
Container<T>::Container() {}

template <class T>
Container<T>::Container(const Container<T>& c) : data(c.data) {}

template <class T>
void Container<T>::add(const T& e) {
  data.push_back(e);
}

template <class T>
void Container<T>::add(const Container<T>& e) {
  for (T i : e.data) {
    data.push_back(i);
  }
}

template <class T>
void Container<T>::del(const T& s) {
  typename std::vector<T>::iterator i;

  i = std::find(data.begin(), data.end(), s);

  if (i != data.end()) {
    data.erase(i);
  }
}

template <class T>
std::string Container<T>::toString() const {
  std::string re;

  for (T i : data) {
    re += i.toString() + "\n";
  }

  return re;
}

template <class T>
void Container<T>::sortData() {
  std::sort(data.begin(), data.end());
}

template <class T>
void Container<T>::writeDisk(const std::string& fileN) {
  std::ofstream myFile(fileN, std::ios_base::trunc);

  if (!myFile.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo para escribir.");
  }

  for (const T& item : data) {
    myFile << item;
  }

  myFile.close();
}

template <class T>
void Container<T>::readDisk(const std::string& fileN) {
  std::ifstream myFile(fileN);
  std::string myStr;
  T myData;

  if (!myFile.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo para leer.");
  }

  data.clear();

  while (std::getline(myFile, myStr)) {
    if (!myStr.empty()) {
      std::stringstream myStrStream(myStr);
      myStrStream >> myData;
      data.push_back(myData);
    }
  }

  myFile.close();
}

template <class T>
bool Container<T>::there(const T& e) {
  return std::find(data.begin(), data.end(), e) != data.end();
}

template <class T>
Container<T>& Container<T>::operator=(const Container<T>& c) {
  data = c.data;

  return *this;
}

template <class T>
Container<T> Container<T>::operator+(const Container<T>& e) const {
  data = e.data;

  return *this;
}

template <class T>
Container<T> Container<T>::operator+(const T& e) const {
  Container<T> result(*this);

  add(e);

  return result;
}

template <class T>
Container<T>& Container<T>::operator+=(const Container<T>& e) {
  add(e);

  return *this;
}

template <class T>
Container<T>& Container<T>::operator+=(const T& e) {
  add(e);

  return *this;
}

#endif  // __CONTAINER_H__