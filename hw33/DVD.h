#ifndef __DVD_H__
#define __DVD_H__

class DVD {
  private:
    int id; // identifcation number
    char *title = new char[0]; // title of movie
    char *director = new char[0]; // director of movie

  public:
    // constructor
    DVD(int i, char *t, char *dir);

    // default constructor
    DVD();

    // copy constructor
    DVD(const DVD &d);

    ~DVD();

    int getId();

    char *getTitle();

    char *getDirector();
    
    void display();
    void setId(unsigned int i);

    void setTitle(const char *t);

    void setDirector(const char *dir);

    DVD operator=(const DVD &dvd);
}; 

#endif