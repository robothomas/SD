#include <iostream>
using namespace std;

class FileManipulator {
  protected:
    virtual void read(const char *mem) = 0;
    virtual void write(char *mem) = 0;
};

class Search : public FileManipulator {
  public:
    void read(const char *mem) {
      cout << "I can (sort of) read the search results!" << endl;
    }

    void write(char *mem) {
      cout << "I can definetly) write the search results!" << endl;
    }
};

class IdeaGenerator : public FileManipulator {
  public:
    void read(const char *mem) {
      cout << "I can (kind of) read the generator!" << endl;
    }

    void write(char *mem) {
      cout << "Who knows, maybe even I can write the generator!" << endl;
    }
};

int main() {
  char *mem = new char[10];
  Search search;
  IdeaGenerator idea;

  search.read(mem);
  idea.read(mem);

  search.write(mem);
  idea.write(mem);
}