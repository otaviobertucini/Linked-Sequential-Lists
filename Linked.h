#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <string.h>
#include <fstream>
#include <string>

class Linked {
public:
    Linked();
    ~Linked();
    void insertBeg(char* name, char* rg, long = 0, long = 0);
    void insertEnd(char* name, char* rg, long = 0, long = 0);
    void insertIndex(char* name, char* rg, int index);
    void removeBeg(long = 0, long = 0);
    void removeEnd(long = 0, long = 0);
    void removeIndex(int index);
    void searchRg(char* rg);
    void adjustPosition(Node* start, int amnt, long* m);
    void showList();
    void exportTxt(char* name);
    void importTxt(char* name);
    void printInfo(char* name, char* rg, long c, long m, 
         double time, char* action);
private:
    Node *first;
    Node *last;
    int n_nodes;
};

#endif /* LIST_H */

