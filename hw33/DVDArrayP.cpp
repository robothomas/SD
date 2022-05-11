#include "DVDArrayP.h"
#include <iostream>
using namespace std;

DVDArrayP::DVDArrayP(unsigned int sz) {
  size = sz;
  elt = new *DVD[sz];

  for (unsigned int i = 0; i < sz; i++) {
    elt[i] = 0;
  }
}

DVDArrayP::DVDArrayP() {
  size = DEFAULT_SIZE;
  elt = new *DVD[DEFAULT_SIZE];

  for (unsigned int i = 0; i < size; i++) {
    elt[i] = 0;
  }
}

DVDArrayP::DVDArrayP(const DVDArrayP &arr) {
  size = arr.size;
  elt = new *DVD[size];
  for (i = 0; i < size; i++) {
    if (arr[i] != 0) {
      elt[i] = new DVD();
      elt[i][0] = arr[i][0];

    } else {
      elt[i] = 0;
    }
  }
}

DVDArrayP::~DVDArrayP() {
  for (unsigned int i = 0; i < size; i++) {
    if (elt[i] != 0) {
      delete elt[i][0];
    }
  }

  delete [] elt;
}

int DVDArrayP::getSize() {
  return size;
}

DVDArrayP DVDArrayP::operator=(const DVDArrayP &arr) {
  ~DVDArrayP();
  DVD(arr);
  return *this;
}

void DVDArrayP::display() {
  for (unsigned int i = 0; i < size; i++) {
    if (elt[i] != 0) {
      elt[i][0].display();
    }
  }
}

DVD &DVDArrayP::operator[](int i) {
  if (i < 0 || i > size - 1) {
    cout << "WARNING: invalid index" < endl;
  }

  if (i < 0) {
    if (elt[0] == 0) {
      elt[0] = new DVD();
    }

    return elt[0][0];

  } else if (i > size -1) {
    if (elt[size-1] == 0) {
      elt[size-1] = new DVD();
    }

    return elt[size-1][0];

  } else {
      if (elt[i] == 0) {
        elt[i] = new DVD();
      }

    return elt[i][0];
  }
}