#include "scimm_cor.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;
SCIMM_COR::SCIMM_COR()
{
    memset(S_H, 0, sizeof(S_H));
    memset(S_S, 0, sizeof(S_S));
    memset(S_V, 0, sizeof(S_V));
    S_H[0] = 255;
    S_S[0] = 0;
    S_V[0] = 0;

    S_H[1] = 0;
    S_S[1] = 255;
    S_V[1] = 255;

}

void SCIMM_COR::SetMaxH(int h) {
    S_H[1]= h > S_H[1]?  h :  S_H[1];

}

void SCIMM_COR::SetMinH(int h) {
    S_H[1]= h < S_H[1]?  h :  S_H[1];

}


void SCIMM_COR::SetMaxS(int s) {
    S_S[1]= s > S_S[1]?  s :  S_S[1];

}

void SCIMM_COR::SetMinS(int s) {
    S_S[1]= s < S_S[1]?  s :  S_S[1];

}


void SCIMM_COR::SetMaxV(int v) {
    S_V[1]= v > S_V[1]?  v :  S_V[1];

}




void SCIMM_COR::SetMax(int *max){

    S_H[1]= max[0] > S_H[1]?  max[0] :  S_H[1];
    S_S[1]= max[1] > S_S[1]?  max[1] :  S_S[1];
    S_V[1]= max[2] > S_V[1]?  max[2] :  S_V[1];

}

void SCIMM_COR::SetMin(int *min){
    S_H[0]= min[0] < S_H[0]?  min[0] :  S_H[0];
    S_S[0]= min[1] < S_S[0]?  min[1] :  S_S[0];
    S_V[0]= min[2] < S_V[0]?  min[2] :  S_V[0];

}

void SCIMM_COR::SetMinMax(int *mi, int *ma){
    S_H[0]= mi[0] < S_H[0]?  mi[0] :  S_H[0];
    S_S[0]= mi[1] < S_S[0]?  mi[1] :  S_S[0];
    S_V[0]= mi[2] < S_V[0]?  mi[2] :  S_V[0];
    S_H[1]= ma[0] > S_H[1]?  ma[0] :  S_H[1];
    S_S[1]= ma[1] > S_S[1]?  ma[1] :  S_S[1];
    S_V[1]= ma[2] > S_V[1]?  ma[2] :  S_V[1];
}

void SCIMM_COR::SetMinMax(cv::Vec3b pixel){
    S_H[0]= pixel.val[0] < S_H[0]?  pixel.val[0] :  S_H[0];
    S_H[1]= pixel.val[0] > S_H[1]?  pixel.val[0] :  S_H[1];
}

void SCIMM_COR::SetMinMax2(cv::Vec3b pixel){
    S_H[0]= pixel.val[0] < S_H[0]?  pixel.val[0] :  S_H[0];
    S_S[0]= 100;
    S_V[0]= 100;
    S_H[1]= pixel.val[0] > S_H[1]?  pixel.val[0] :  S_H[1];
    S_S[1]= pixel.val[1] > S_S[1]?  pixel.val[1] :  S_S[1];
    S_V[1]= pixel.val[2] > S_V[1]?  pixel.val[2] :  S_V[1];


    if(S_S[0] ==  S_S[1]) {
        S_S[1] = 255;
    }
}

void SCIMM_COR::SetMinMax3(cv::Vec3b pixel){
    S_H[0]= pixel.val[0] < S_H[0]?  pixel.val[0] :  S_H[0];
    S_S[0]=  pixel.val[1] < S_S[0]?  pixel.val[1] :  S_S[0];
    S_V[0]= pixel.val[2] < S_V[0]?  pixel.val[2] :  S_V[0];
    S_H[1]= pixel.val[0] > S_H[1]?  pixel.val[0] :  S_H[1];
    S_S[1]= pixel.val[1] > S_S[1]?  pixel.val[1] :  S_S[1];
    S_V[1]= pixel.val[2] > S_V[1]?  pixel.val[2] :  S_V[1];


    if(S_S[0] ==  S_S[1]) {
        S_S[1] = 255;
    }
}

void SCIMM_COR::PRINT(){
    std::cout << "MIN: " << S_H[0] << " "<<S_S[0]<< " "<<S_V[0] <<std::endl;
    std::cout << "MAX: " << S_H[1] << " "<<S_S[1]<< " "<<S_V[1] <<std::endl;

}

void SCIMM_COR::PRINTV(){
    std::cout << "MIN: " <<S_V[0] <<std::endl;
    std::cout << "MAX: " <<S_V[1] <<std::endl;

}
