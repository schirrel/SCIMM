#ifndef TDESTUDENT_H
#define TDESTUDENT_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "math.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
class TdeStudent {

public:
    TdeStudent();
    void CalcularTdeStudent(std::vector<cv::Rect> rects);
    double* GetLimites();

    double LIMITES[2];
       std::vector<cv::Rect> RECTS;


private:
static int GL[43];
static double DIST[43];


double ObterPorcentagem(int valor, int porcentagem);
double Media();
double DesvioPadrao();
double EncontrarZ(int gl);
void DistribuicaoT(double media, double desvio, int numDados, int gl);
bool CompararRectPorArea(cv::Rect a, cv::Rect b);
  std::vector<cv::Rect> VetorFinal( std::vector<cv::Rect> insideRect);


};

#endif // TDESTUDENT_H
