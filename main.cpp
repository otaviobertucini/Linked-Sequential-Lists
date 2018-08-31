#include <cstdlib>
#include "Menu.h"
#include "Sequential.h"
#include "Linked.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace std;

/*Erros com a alocação de memória para 10M
 * Erro de valor com a contagem de comparações/cópias quando que remover um 
 * índice
 */

int main() {    
    int start_s=clock();
    
    Menu menu;
    menu.showMenu();
    
    /*//Teste de execução
    s.insertBeg("Otávio", "6160886");
    s.insertBeg("Jeff", "5484852");  
    s.insertBeg("Maria", "10241024");
    s.insertEnd("Cláudia", "1545455");
    s.insertIndex("Ezio", "11111", 4);     
    s.insertIndex("Luiz", "848448", 6);
    s.insertBeg("Jair", "459226");
    s.insertEnd("JP", "2184562");
    s.removeBeg();
    s.removeIndex(6);
    //s.removeEnd();
    //cout << "entrei" << endl;
    //s.removeIndex(2);
    //s.removeBeg();
    //s.removeEnd();
    //s.searchRg("6160886");
    s.showList();    
    s.exportTxt("export2.txt");*/
    
    
    int stop_s=clock();    
    /*cout<<"Tempo de execução total: " <<(stop_s-start_s)/double(CLOCKS_PER_SEC)
            *1000<<" milisegundos" << endl;*/ 
    return 0;
}

