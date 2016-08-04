#ifndef SCIMM_COR_H
#define SCIMM_COR_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class SCIMM_COR
{
public:
    // 0 min 1 max
    int S_V[2];
    int S_H[2];
    int S_S[2];


    SCIMM_COR();
    void SetMinH(int h);
    void SetMaxH(int h);

    void SetMinS(int s);
    void SetMaxS(int s);

    void SetMinV(int v);
    void SetMaxV(int v);


    void SetMin(int* min);
    void SetMax(int* max);


    void SetMinMax(int* mi, int* ma);
     void SetMinMax(cv::Vec3b pixel);
    void PRINT();

};

#endif // SCIMM_COR_H
