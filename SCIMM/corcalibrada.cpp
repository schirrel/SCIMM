#include "corcalibrada.h"

CorCalibrada::CorCalibrada()
{

}

bool CorCalibrada::NaoZerada(){

    return (MAX[0]!=0 &&MAX[1]!=0 &&MAX[2]!=0 && MIN[0]!=0 &&MIN[1]!=0 &&MIN[2]!=0 );
}

void CorCalibrada::SetMax(int *max){

    for(int i=0; i < 3; i++){
        MAX[i]= max[i];
    }
}
void CorCalibrada::SetMin(int *min){
    for(int i=0; i < 3; i++){
        MIN[i]= min[i];
    }
}
