#include "Menu.h"
using std::string;
using std::cout;
using std::endl;
using std::cin;

Menu::Menu() {
}

void Menu::showMenu(){
    int loop=1, cmd, comando;
    while(loop){
        cout << "Digite o que dejesa fazer: " << endl;
        cin >> comando;        
        if(comando == 1){
            cout << "1 - Adicionar no início\n"
                    "2 - Adicionar no fím\n"
                    "3 - Adicionar na posição\n" << endl;
            cin >> cmd;
            switch(cmd){
                case 1:
                    add(cmd);
                    break;
                case 2:
                    add(cmd);
                    break;
                case 3:
                    add(cmd);
                    break;
                default:
                    cout << "Operação inválida!" << endl;
            }
            
        }
        else if(comando == 2){
            cout << "1 - Remover do início\n"
                    "2 - Remover do fím\n"
                    "3 - Remover na posição\n" << endl;
            cin >> cmd;
            switch(cmd){
                case 1:
                    remove(cmd);
                    break;
                case 2:
                    remove(cmd);
                    break;
                case 3:
                    remove(cmd);
                    break;
                default:
                    cout << "Operação inválida!" << endl;
            }
        }
        else if(comando == 3)
            search();
        else if(comando == 4){
            seq.showList();  
            lin.showList();
        }
        else if(comando == 5){
            seq.exportTxt("export.txt");
            lin.exportTxt("export2.txt");
        }
        else if(comando == 6)
            importar();
        else if(comando == 0)
            loop = 0;
        else if(comando == 11){
            seq.insertBeg("Otávio", "6160886");
            seq.insertBeg("Jair", "459226");
            seq.insertEnd("Cláudia", "1545455");
            seq.insertIndex("Maria", "11111", 2);
        }
    }
}

void Menu::add(int operation){
    char name[30], rg[10]="";
    cout << "Digite o nome: " << endl;
    cin >> name;
    cout << "Digite o RG: " << endl;
    cin >> rg;
    switch(operation){
        case 1:
            seq.insertBeg(name, rg);
            lin.insertBeg(name, rg);
            break;
        case 2:
            seq.insertEnd(name, rg);
            lin.insertEnd(name, rg);
            break;
        case 3:
            int index;
            cout << "Digite a posição: " << endl;
            cin >> index;
            seq.insertIndex(name, rg, index);
            lin.insertIndex(name, rg, index);
            break;    
    }
}

void Menu::remove(int operation){
        switch(operation){
        case 1:
            seq.removeBeg();
            lin.removeBeg();
            break;
        case 2:
            seq.removeEnd();
            lin.removeEnd();
            break;
        case 3:
            int index;
            cout << "Digite a posição: " << endl;
            cin >> index;
            seq.removeIndex(index);
            lin.removeIndex(index);
            break;    
    }
}

void Menu::search(){
    char rg[20];
    cout << "Digite o RG que deseja procurar: " << endl;
    cin >> rg;
    seq.searchRg(rg);
    lin.searchRg(rg);
}

void Menu::importar(){
    char nome[20];
    cout << "Digite o nome do arquivo que deseja importar: " << endl;
    cin >> nome;
    seq.importTxt(nome);
    lin.importTxt(nome);
}

Menu::~Menu() {
}

