#include "Sequential.h"
#include <cstddef>
#include "Element.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include<ctime> 
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;

Sequential::Sequential() {
    start = NULL;
    n_elements = 0;
}

void Sequential::insertBeg(char* name, char* rg){    
    int start_s=clock(), i, c=0, m=0;
    
    Element* new_array = new Element[n_elements+1];
    Element new_node;
    new_node.setName(name);
    new_node.setRg(rg);
    new_node.setPos(n_elements+1);
    m+=4;
    c++;
    if(n_elements == 0){        
        start = new_array;
        *start = new_node;
        m+=2;
    }
    else{        
        Element* aux=start;        
        start=new_array;
        *start = new_node;    
        m+=2;        
        for(i=1; i<=n_elements; i++){  
            start[i] = aux[i-1];
            start[i].setPos(i);
            m+=2;
        }
        //delete aux;
    }
    n_elements++;
    for(i=0; i<n_elements; i++){
        start[i].setPos(i+1);
        m++;
    }
    
    int stop_s=clock();  
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
}

void Sequential::insertEnd(char* name, char* rg){
    int start_s=clock(), i, c=0, m=0;
    
    Element* new_array = new Element[n_elements+1];    
    Element new_node;
    new_node.setName(name);
    new_node.setRg(rg);
    new_node.setPos(n_elements+1);
    Element* aux=start;
    start = new_array;
    start[n_elements] = new_node;
    m+=7;
    for(i=0; i<n_elements; i++){            
        start[i] = aux[i];
        start[i].setPos(i+1);
        m+=2;
    }
    n_elements++;
    delete[] aux;    
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
}

void Sequential::insertIndex(char* name, char* rg, int index){
    int start_s=clock(), c=0, m=0;
    
    c++;
    if(index>n_elements+1 || index <=0){
        cout << "Índice inexistente!" << endl;
    }
    else{
        index--;
        int i;
        Element* new_array = new Element[n_elements+1];    
        Element new_node;
        new_node.setName(name);
        new_node.setRg(rg);
        Element* aux=start;
        start = new_array;
        m+=5;
        for(i=0; i<index; i++){
            start[i] = aux[i];
            m++;
        }
        start[i] = new_node;
        start[i].setPos(i+1); 
        m+=2;
        for(i++; i<=n_elements; i++){
            start[i] = aux[i-1];
            start[i].setPos(i+1);
            m+=2;
        }
        n_elements++;
        delete[] aux;
        
        int stop_s=clock();    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
    }    
    
}

void Sequential::removeBeg(){
    int start_s=clock(), c=0, m=0;
    char name[30], rg[10];
    strcpy(name, start[0].getName());
    strcpy(rg, start[0].getRg());
    
    c++;
    if(n_elements == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
    int i;
        Element* new_array = new Element[n_elements-1];
        for(i=1; i<n_elements; i++){
            new_array[i-1] = start[i];
            new_array[i-1].setPos(i);
            m+=2;
        }
        start = new_array;
        n_elements--;
        //delete[] new_array;
    }
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
}

void Sequential::removeEnd(){
    int start_s=clock(), c=0, m=0;
    char name[30], rg[10];
    strcpy(name, start[n_elements-1].getName());
    strcpy(rg, start[n_elements-1].getRg());
    
    c++;
    if(n_elements == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
        int i;
        Element* new_array = new Element[n_elements-1];
        for(i=0; i<n_elements-1; i++){
            new_array[i] = start[i];
            m++;
        }
        start = new_array;
        n_elements--;
        //delete[] new_array;
    }
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
}

void Sequential::removeIndex(int index){
    int start_s=clock(), c=0, m=0;
    char name[30], rg[10];
    
    c+=2;
    if(n_elements == 0)
        cout << "Lista vazia!" << endl;
    else if(index > n_elements)     
        cout << "Posição inexistente!" << endl;
    else{
        int i;
        index--;
        Element* new_array = new Element[n_elements-1];
        for(i=0; i<index; i++){
            new_array[i] = start[i];
            new_array[i].setPos(i+1);
            m+=2;
        }
        strcpy(name, start[i].getName());
        strcpy(rg, start[i].getRg());
        for(i++; i<n_elements; i++){
            new_array[i-1] = start[i];
            new_array[i-1].setPos(i);
            m+=2;
        }
        start = new_array;
        n_elements--;
    }    
    int stop_s=clock();
    
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
}

void Sequential::searchRg(char* rg){
    int start_s=clock(), c=0, m=0, i, cmp;
    char name[30], rg_c[10];

    for(i=0; i<n_elements; i++){
        cmp = strcmp(start[i].getRg(), rg);
        m++;
        c++;
        if(cmp == 0){
            //showElement(start[i]);
            strcpy(name, start[i].getName());
            strcpy(rg_c, start[i].getRg());
            m+=2;
            int stop_s=clock();    
            printInfo(name, rg_c, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "encontrada");
            return;
        }
    }
    cout << "Elemento não encontrado!" << endl;
    int stop_s=clock();
    cout << "Tempo de execução: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000 << endl;
}

void Sequential::importTxt(char* file){
    int start_s=clock(), c=0, m=0, i, n_lines;
    string line;
    ifstream myfile (file);
    if (myfile.is_open()){
        n_lines = countLines(file);
        start = newArray(n_lines, &m);
        if(start == 0 || start == NULL)
            cout << "Erro!" << endl;            
        else{
            while ( getline (myfile,line)){
                for(i=0; line.size();i++){
                    c++;
                    if(line[i]==',')
                        break;
                }
                string name(line, 0, i);
                string rg(line, i+1, line.size()-1);            
                start[n_elements].setName((char *)name.c_str());
                start[n_elements].setRg((char *)rg.c_str());
                start[n_elements].setPos(n_elements+1);
                m+=5;
                n_elements++;
            }
        }            
        myfile.close();
        int stop_s=clock();
        cout << "---------------------------------------------------" << endl;
        cout << "Tempo de execução total (importar para sequencial): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else cout << "Não foi possível abrir o arquivo!" << endl;  
}

int Sequential::countLines(char* file){
    string line;
    int i=0;
    ifstream myfile (file);
    if (myfile.is_open()){
        while ( getline (myfile,line)){
            i++;
        }
        myfile.close();
    }
    else 
        cout << "Não foi possível abrir o arquivo!" << endl;
    return i;
}

Element* Sequential::newArray(int n, int* m){
    int i;
    Element* new_array = new Element[n_elements+n];
    if(new_array != 0 && new_array != NULL){
        for(i=0; i<n_elements; i++){
            new_array[i] = start[i];
            new_array[i].setPos(i+1);
            (*m)+=2;
        }
        return new_array;
    }
    return NULL;
}

void Sequential::exportTxt(char* name){
    int start_s=clock();
    int i;
    ofstream myfile(name);
    if(myfile.is_open()){
        for(i=0; i<n_elements; i++){
            myfile << start[i].getName();
            myfile << ",";
            myfile << start[i].getRg();
            myfile << "\n";
        }
        int stop_s=clock();
        cout << "---------------------------------------------------" << endl;
        cout << "Tempo de execução (exportar sequencial): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000  << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
        cout << "Não foi possível abrir o arquivo!" << endl;
}

void Sequential::showList(){
    int start_s=clock();
    
    cout << "---------------------------------------------------" << endl;
    if(n_elements == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
        int i;
        for(i=0; i<n_elements; i++){
            cout << "Nome: " << start[i].getName() << " RG: " <<
            start[i].getRg() << " Posição: "<< start[i].getPos() << endl;
        }
    }
    
    int stop_s=clock();    
    
    cout<<"Tempo de execução (mostrar lista sequencial): "<<(stop_s-start_s)
            /double(CLOCKS_PER_SEC)*1000 << endl;
    cout << "---------------------------------------------------" << endl;
}

void Sequential::showElement(Element element){
    cout << "Elemento encontrado!" << endl;
    cout << "Nome: " << element.getName() << endl;
    cout << "RG: " << element.getRg() << endl;
    cout << "Posição: " << element.getPos() << endl;
}

void Sequential::printInfo(char* name, char* rg, int c, int m, 
        double time, char* action){    
    cout << "---------------------------------------------------" << endl;
    cout << "Lista sequencial: " << endl;
    cout << "Pessoa " << name << " (" << rg <<") " << "Foi " << action << 
            " com sucesso!" << endl;
    cout << "Tempo de execução: " << time << endl;
    cout << "Comparações: " << c << endl;
    cout << "Cópias: " << m << endl;
    cout << "---------------------------------------------------" << endl;
}

Sequential::~Sequential() {
    delete [] start;
}

