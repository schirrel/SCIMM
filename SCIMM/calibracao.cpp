
#include "calibracao.h"
#include <iostream>
#include <fstream>
Calibracao::Calibracao(){ }


void Calibracao::SalvarArquivo(){
    std::ofstream out;
    std::cout << " salvando " << std::endl;
    out.open("cores.arff");
    for(int i = 0; i < 8; i++){
        out << i << " : " << coresCalibradas[i].MIN[0] << "." << coresCalibradas[i].MIN[1]<< "."<< coresCalibradas[i].MIN[2] << std::endl;
        out << i << " : " << coresCalibradas[i].MAX[0] << "." << coresCalibradas[i].MAX[1]<< "."<< coresCalibradas[i].MAX[2] << std::endl;
    }
    out.close();
}


void Calibracao::Fechar(){
    FIM =true;
    cv::destroyAllWindows();

}
