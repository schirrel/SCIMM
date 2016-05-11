#ifndef CORCALIBRADA_H
#define CORCALIBRADA_H


class CorCalibrada
{
public:
    CorCalibrada();
    CorCalibrada(int COR_INDEX, int MAX[3], int MIN[3]);
    bool NaoZerada();
    int COR_INDICE;
    int MIN[3];
    int MAX[3];
    void SetMin(int* min);
    void SetMax(int* max);

};

#endif // CORCALIBRADA_H
