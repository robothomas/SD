#include "DVD.h"
#include<iostream>
using namespace std;

// A helper function for copying char arrays. Doesn't work properly, but I left it here.
void copy(char *to, const char *from) {
  // making sure that any data associated with theis pointer is deleted before allocating new stuff
  delete [] to;

  int len = 0; // variable that stores the length of original array to create new array of same size

  for (len = 0; from[len] != 0; len++) {} // accumulates len up until it reaches null byte
  to = new char[len]; // allocates new char array of size len

  // copies all elements from original array into the new array
  for (int i = 0; i < len; i++) {
    to[i] = from[i];
  }
}

// constructor
DVD::DVD(int i, char *t, char *dir) {
  id = i;
  setTitle(t);
  setDirector(dir);
}

// default constructor
DVD::DVD() {
  id = 0;
  
  title = new char[50];
  title[0] = 0;

  director = new char[50];
  director[0] = 0;
}

// copy constructor
DVD::DVD(const DVD &d) {
  id = d.id; // nothing special needed here - just copy the int value
  setTitle(d.title);
  setDirector(d.director);
}

DVD::~DVD() {
  delete [] title;
  delete [] director;
}

int DVD::getId() {
  return id;
}

char *DVD::getTitle() {
  return title;
}

char *DVD::getDirector() {
  return director;
}

void DVD::display() {
  cerr << '[' << id << ". " << title << '/' << director << ']' << endl;
}

void DVD::setId(unsigned int i) {
  id = i;
}

void DVD::setTitle(const char *t) {
  // making sure that any data associated with theis pointer is deleted before allocating new stuff
  delete [] title;

  int len = 0; // variable that stores the length of original array to create new array of same size

  for (len = 0; t[len] != 0; len++) {} // accumulates len up until it reaches null byte
  title = new char[len]; // allocates new char array of size len

  // copies all elements from original array into the new array
  for (int i = 0; i < len; i++) {
    title[i] = t[i];
  }
}

void DVD::setDirector(const char *dir) {
  // making sure that any data associated with theis pointer is deleted before allocating new stuff
  delete [] director;

  int len = 0; // variable that stores the length of original array to create new array of same size

  for (len = 0; dir[len] != 0; len++) {} // accumulates len up until it reaches null byte
  director = new char[len]; // allocates new char array of size len

  // copies all elements from original array into the new array
  for (int i = 0; i < len; i++) {
    director[i] = dir[i];
  }
}

DVD DVD::operator=(const DVD &dvd) {
  id = dvd.id;
  setTitle(dvd.title);
  setDirector(dvd.director);

  return *this;
}
