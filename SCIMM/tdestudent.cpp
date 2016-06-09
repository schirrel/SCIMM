#include "tdestudent.h"
int TdeStudent::GL[43] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,60,90,120,150,180,210,240,270,300,400,500,800,1000};
double TdeStudent::DIST[43] = {12.7062, 4.3027, 3.1824, 2.7764,
                               2.2281,2.2010,2.1788,2.1604,2.1448,2.1314,
                               2.1199, 2.1098,2.1009,2.0930,2.0860,2.0796,2.0739,
                               2.0687,2.0637,2.0595,2.0555,2.0518,2.0484,2.0452,2.0423,
                               2.0003,1.9867,1.9799,1.9759,1.9732,1.9713,1.9699,
                               1.9688,1.9679,1.9659,1.9647,1.9629,1.9623};


TdeStudent::TdeStudent(){}
double TdeStudent::ObterPorcentagem(int valor, int porcentagem){
    double p = (porcentagem*valor)/100;
    return p;

}

double TdeStudent::Media(){
    double soma=0;
    for(unsigned int i=0;i<RECTS.size(); i++){
        soma+=RECTS.at(i).area();
    }
    soma = soma/RECTS.size();
    return soma;

}

double TdeStudent::DesvioPadrao(){
    int media = Media();
    int dif;

    for(unsigned int i=0;i<RECTS.size(); i++){
        dif+=pow((RECTS.at(i).area() - media),2);
    }

return sqrt(dif/RECTS.size());;
}

double TdeStudent::EncontrarZ(int gl){
    for(unsigned int i = 0; i < ((sizeof(GL)/sizeof(*GL))); i++){
        if(GL[i]==gl){
            return DIST[i];
            break;
        }
    }
    return 0.0;
}

void TdeStudent::DistribuicaoT(double media, double desvio, int numDados, int gl){
   // std::cout<< " Media: " <<media << "\t desvio " << desvio << "\t numDados "<<numDados << "\t gl "<< gl << std::endl;


    double z = EncontrarZ(gl);
    if(z==0.0){
        LIMITES[0]=0;
        LIMITES[1]=0;
    }
    else {
        LIMITES[0]=media+(z*(desvio/sqrt(numDados)));
        LIMITES[1]=media-(z*(desvio/sqrt(numDados)));
    }


   // std::cout<< " Media: " <<media << "\t calc " << (z*(desvio/sqrt(numDados))) << std::endl;
}

void TdeStudent::CalcularTdeStudent( std::vector<cv::Rect> rects){

      RECTS = rects;
   //   std::cout << "Recs " << RECTS.size() << std::endl;
    double media = Media();
    double desvioPadrao = DesvioPadrao();
    int NumDados = RECTS.size();
    int GrausDeLiberdade = NumDados-1;
    DistribuicaoT(media,desvioPadrao,NumDados,GrausDeLiberdade);

}

double* TdeStudent::GetLimites(){
    return LIMITES;
}

 std::vector<cv::Rect> TdeStudent::VetorFinal( std::vector<cv::Rect> insideRect){
    if(insideRect.size() > 29) {
        std::cout << "PROBLEMA, AMOSTRA MAIOR QUE 29" <<std::endl;

    }

     std::vector<cv::Rect> tamanhoEsperado;
    //sort(insideRect.begin(), insideRect.end(),TdeStudent::CompararRectPorArea);
    for(unsigned int i=0; i< insideRect.size(); i++){
//        std::cout << insideRect.at(i).area() << std::endl;
        if(insideRect.at(i).area() >  LIMITES[1] && insideRect.at(i).area() <  LIMITES[0]){
            tamanhoEsperado.push_back(insideRect.at(i));
        }
    }
    return tamanhoEsperado;
}

bool TdeStudent::CompararRectPorArea(cv::Rect a, cv::Rect b){
    return a.area() < b.area();

}
