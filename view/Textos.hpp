//
// Created by rafael on 26/05/24.
//

#ifndef HELP_HPP
#define HELP_HPP
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Textos {
    public:
    static void exibirTexto(string arquivo){
        ifstream file(arquivo);
        string line;
        if(file.is_open()){
        while (getline(file, line)) {
            cout << line << endl;
            }
        }else{cout << "Falha na leitura do arquivo" << endl;}
        file.close();
    }
};



#endif //HELP_HPP
