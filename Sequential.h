#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H
#include "Node.h"
#include "Element.h"
#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;

class Sequential {
public:
    Sequential();
    ~Sequential();
    void insertBeg(char* name, char* rg);
    void insertEnd(char* name, char* rg);
    void insertIndex(char* name, char* rg, int index);
    void removeBeg();
    void removeEnd();
    void removeIndex(int index);
    void searchRg(char* rg);
    void showList();
    void showElement(Element element);
    void importTxt(char* file);
    void exportTxt(char* file);
    int countLines(char* file);
    Element* newArray(int n, int* m);
    void printInfo(char* name, char* rg, int c, int m, 
         double time, char* action);
private:
    Element* start;
    int n_elements;
};

#endif /* SEQUENTIAL_H */

