#include<iostream>
using namespace std;

// add your code for the DVD class here!
class DVD {
  private:
    int id; // identifcation number
    char *title = new char[0]; // title of movie
    char *director = new char[0]; // director of movie

    // A helper function for copying char arrays. Doesn't work properly, but I left it here.
    char *copy(char *to, const char *from) {
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

  public:
    // constructor
    DVD(int i, char *t, char *dir) {
      id = i;
      setTitle(t);
      setDirector(dir);
    }

    // default constructor
    DVD() {
      id = 0;
      
      title = new char[50];
      title[0] = 0;

      director = new char[50];
      director[0] = 0;
    }

    // copy constructor
    DVD(const DVD &d) {
      id = d.id; // nothing special needed here - just copy the int value
      setTitle(d.title);
      setDirector(d.director);
    }

    ~DVD() {
      delete [] title;
      delete [] director;
    }

    int getId() {
      return id;
    }

    char *getTitle() {
      return title;
    }

    char *getDirector() {
      return director;
    }

    void display() {
      cerr << '[' << id << ". " << title << '/' << director << ']' << endl;
    }

    void setId(unsigned int i) {
      id = i;
    }

    void setTitle(const char *t) {
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

    void setDirector(const char *dir) {
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

    DVD operator=(const DVD &dvd) {
      id = dvd.id;
      setTitle(dvd.title);
      setDirector(dvd.director);

      return *this;
    }
}; 

int main() {
  char str[] = "Gandhi";
  DVD d1(4, str, "Richard Attenborough");
  DVD d2;
  DVD d3(d1);
 
  cout << "After constructors:" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  str[0] = 'X';
  
  cout << "Test for dynamically allocated copies" << endl;
  
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  cout << d2.getId() << endl; // 0
  cout << d1.getTitle() << endl; // Gandhi
  cout << d1.getDirector() << endl; // Richard Attenborough
 
  d1.setId(2);
  d1.setTitle("Shadowlands");
  d2.setDirector("Ingmar Bergman");
 
  
  cout << "After state changes:" << endl;
  
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /Ingmar Bergman]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  d3 = d2;
  d2.setTitle("Wild Strawberries");
 
  
  cout << "After more state changes:" << endl;
  
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
  d3.display(); cout << endl; // [0.  /Ingmar Bergman]
  
}

