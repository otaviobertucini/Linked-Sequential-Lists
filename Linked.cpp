#include "Linked.h"
#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::string;

Linked::Linked() {
    n_nodes = 0;
    first = NULL;
    last = NULL;
}

void Linked::insertBeg(char* name, char* rg, long print, long c){
    int start_s=clock();
    long m=0;
    
    Node *new_node = new Node;
    new_node->setName(name);
    new_node->setRg(rg);    
    c++;
    if (n_nodes == 0){        
        first = new_node;
        last = new_node;
        first->setPrev(NULL);
        first->setNext(NULL);  
        m+=7;
    }
    else if(n_nodes == 1){
        c++;
        first = new_node;
        first->setNext(last);
        last->setPrev(new_node);
    }
    else{        
        first->setPrev(new_node);
        new_node->setNext(first);
        first = new_node;
    }
    
    adjustPosition(first, 1, &m);
    n_nodes++;
    int stop_s=clock();  
    
    if(print == 0){
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
    }
}

void Linked::insertEnd(char* name, char* rg, long print, long c){
    int start_s=clock();
    long m=0;
    
    c++;
    if(n_nodes == 0){
        insertBeg(name, rg, 1, c);
    }
    else{
        Node *new_node = new Node;
        new_node->setName(name);
        new_node->setRg(rg);
        new_node->setPrev(last);
        last->setNext(new_node);
        last = new_node;
        last->setPos(n_nodes+1);
        n_nodes++;
        m+=6;
    }
    int stop_s=clock();  
    
    if(print == 0){
    printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
    }
}

void Linked::insertIndex(char* name, char* rg, int index){
    int start_s=clock();
    long c=0, m=0;
    
    c++;
    if(index > n_nodes+1){
        cout << "Índice inválido!" << endl;
    }
    else if(index == n_nodes+1){
        c++;
        insertEnd(name, rg, 0, c);
    }
    else{
        int i;
        Node *node=first;
        Node *new_node = new Node;
        new_node->setName(name);
        new_node->setRg(rg);
        index--;
        m+=4;
        for(i=1; i<index; i++){
            node = node->getNext();
            m++;
        }
        node->getNext()->setPrev(new_node);
        new_node->setNext(node->getNext());
        node->setNext(new_node);
        new_node->setPrev(node);   
        new_node->setPos(i);
        m+=5;
        adjustPosition(new_node, 1, &m);
        n_nodes++;
        int stop_s=clock();  
    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "adicionada");
    }    
        
}

void Linked::removeBeg(long c, long m){
    int start_s=clock();
    char *name, *rg;
    
    c++;
    if(n_nodes == 0)
        cout << "Não existe item para remover!" << endl;
    else{
        name = first->getName();
        rg = first->getRg();
        first = first->getNext();
        first->setPrev(NULL);
        m+=2;
        adjustPosition(first, -1, &m);
        n_nodes--;
        int stop_s=clock();  
    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
    }    
}

void Linked::removeEnd(long c, long m){
    int start_s=clock();
    char *name, *rg;
    
    c++;
    if(n_nodes == 0)
        cout << "Não existe item para remover!" << endl;
    else{
        name = last->getName();
        rg = last->getRg();
        last = last->getPrev();
        last->setNext(NULL); 
        m+=2;
        n_nodes--;
        int stop_s=clock();  
    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
    }    
}

void Linked::removeIndex(int index){
    int start_s=clock();
    long c=0, m=0;
    char *name, *rg;
    
    c++;
    if(n_nodes == 0 || index > n_nodes)
        cout << "Índice não pode ser removido!" << endl;
    else if(index == 1){
        c++;
        removeBeg(c, m);
    }
    else if(index == n_nodes){
        removeEnd(c, m);
        c++;
    }
    else{
        index--;
        int i;
        Node* node = first;
        for(i=1; i<index;i++){
            node = node->getNext();
            m++;
        }
        name = node->getNext()->getName();
        rg = node->getNext()->getRg();
        node->setNext(node->getNext()->getNext());
        node->getNext()->setPrev(node);
        m+=3;
        adjustPosition(node->getNext(), -1, &m);
        n_nodes--;
        int stop_s=clock();  
    
        printInfo(name, rg, c, m, (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000, "removida");
    }
}

void Linked::searchRg(char* rg){
    int start_s=clock(), c=0, m=0;
    
    c++;
    if(n_nodes == 0)
        cout << "Lista não tem elementos!" << endl;
    else{
        int cmp;
        Node* aux = first;
        while(aux != NULL){
            cmp = strcmp(aux->getRg(), rg);
            m++;
            c++;
            if(cmp == 0){
                int stop_s=clock();    
                printInfo(aux->getName(), aux->getRg(), c, m, (stop_s-start_s)
                /double(CLOCKS_PER_SEC)*1000, "encontrada");
                return;
            }
            aux = aux->getNext();
            m++;
        }
        cout << "Pessoa não encontrada!" << endl;
        int stop_s=clock();
        cout << "Tempo de execução: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000 << endl;
    }
}

void Linked::adjustPosition(Node* start, int amnt, long* m){
    while(start != NULL){
        start->sumPos(amnt);
        start = start->getNext();
        (*m)++;
    }
}

void Linked::showList(){
    Node *i=first;
    if(n_nodes == 0){
        cout << "Lista vazia!" << endl;
    }
    else{
        cout << "---------------------------------------------------" << endl;
        int start_s=clock();
        while(i != NULL){
            cout << "Nome: " << i->getName() << " RG: " << i->getRg() << 
                    " Posição: " << i->getPos() << endl;
            i = i->getNext();
        }
        cout << "Total de clientes registrados: " << n_nodes << endl;
        int stop_s=clock();
        cout << "Tempo de execução (mostrar lista encadeada): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
    }
}

void Linked::exportTxt(char* name){
    Node* aux = first;
    ofstream myfile(name);
    if(myfile.is_open()){
        cout << "---------------------------------------------------" << endl;
        int start_s=clock();
        while(aux != NULL){
            myfile << aux->getName();
            myfile << ",";
            myfile << aux->getRg();
            myfile << "\n";
            aux = aux->getNext();
        }
        int stop_s=clock();
        cout << "Tempo de execução (exportar lista): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
        myfile.close();
    }
    else
        cout << "Não foi possível abrir o arquivo!" << endl;    
}

void Linked::importTxt(char* name){
    string line;
    int i, c=0;    
    ifstream myfile(name);       
    if (myfile.is_open()){
        int start_s=clock();        
        while (getline(myfile,line)){
            for(i=0; line.size();i++){                
                if(line[i]==',')
                    break;
            }
            string name(line, 0, i);
            string rg(line, i+1, line.size()-1);
            insertEnd((char *)name.c_str(), (char *)rg.c_str(), 1); 
            c++;
            //11748443
            }   
        cout << "sai" << endl;
        myfile.close();
        int stop_s=clock();
        cout << "---------------------------------------------------" << endl;
        cout << "Tempo de execução total (exportar para encadeada): " << 
                (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        cout << "---------------------------------------------------" << endl;
        }         
    else
        cout << "Não foi possível abrir o arquivo!" << endl;
        
}

void Linked::printInfo(char* name, char* rg, long c, long m, 
         double time, char* action){    
    cout << "---------------------------------------------------" << endl;
    cout << "Lista encadeada: " << endl;
    cout << "Pessoa " << name << " (" << rg <<") " << "Foi " << action << 
            " com sucesso!" << endl;
    cout << "Tempo de execução: " << time << endl;
    cout << "Comparações: " << c << endl;
    cout << "Cópias: " << m << endl;
    cout << "---------------------------------------------------" << endl;
}

Linked::~Linked() {
    Node *aux, *aux2;
    aux = first;
    while(aux!= NULL){
        aux2 = aux->getNext();
        delete aux;
        aux = NULL;
        aux = aux2;
    }
}

