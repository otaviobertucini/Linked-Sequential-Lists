#ifndef ELEMENT_H
#define ELEMENT_H

class Element {
public:
    Element();
    ~Element();
    void setPos(int n);
    int getPos();
    void setName(char* name);
    char* getName();
    void setRg(char* rg);
    char* getRg();
private:
    char name[30];
    char rg[10];
    int position;
};

#endif /* ELEMENT_H */

