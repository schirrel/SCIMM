#include "calibracaoautomatica.h"
#include "calibracaomanual.h"
#include "janelaprincipal.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "math.h"
#include <unistd.h>
#include "tdestudent.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#define PORCENTAGEM 1
using namespace cv;
RNG rng(12345);
bool fim;
CalibracaoAutomatica::CalibracaoAutomatica()
{

}

void CalibracaoAutomatica::Iniciar(JanelaPrincipal* janela){

      cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
    }
    int cont=0;

    while (!janela->INICIAR) {
        camera >> frame;
        cv::imshow("Imagem da Camera", frame);
        cvtColor(frame, src_gray, CV_BGR2GRAY);
        blur(src_gray, src_gray, Size(3, 3));
        thresh_callback(0, 0);
        if (cv::waitKey(30) >= 0) break;
    }

    cvDestroyAllWindows();
    janela->SetStatus(25, "Detectando Objetos");

    cvtColor(frame, src_gray, CV_BGR2GRAY);
    blur(src_gray, src_gray, Size(3, 3));
    //createTrackbar(" Canny thresh:", "janela", &thresh, 255, thresh_callback);
    thresh_callback(0, 0);
    sleep(1);
    insideRect = EliminarExcessos();
    janela->SetStatus(50, "Eliminando Objetos Indesejados");
    sleep(1);
    MetodoCalcular();
    janela->SetStatus(75, "Calculando Valores HSV");
    sleep(1);
    janela->SetText(cores.size() );
    janela->SetStatus(100, "Exibindo Objetos com Threshold");
    sleep(1);
    Mat Threshold;
    Mat res;
    while(1){
        camera >> frame;
        dilate(frame, frame, Mat(), Point(-1, -1), 2, 1, 1);

        cv::cvtColor(frame,HSV,cv::COLOR_RGB2HSV);
        cv::inRange(HSV,cv::Scalar(cores[janela->INDICE_OBJETO].MIN[0],cores[janela->INDICE_OBJETO].MIN[1],cores[janela->INDICE_OBJETO].MIN[2]),cv::Scalar( cores[janela->INDICE_OBJETO].MAX[0] , cores[janela->INDICE_OBJETO].MAX[1] , cores[janela->INDICE_OBJETO].MAX[2] ),Threshold);
        Mat res;
        if(janela->CALIBRADO){
            CorCalibrada cor;
            cor.SetMax(cores[janela->INDICE_OBJETO].MAX);
            cor.SetMin(cores[janela->INDICE_OBJETO].MIN);
            coresCalibradas[janela->INDICE_COR] = cor;
            janela->SALVAR = false;
        }
        bitwise_and(frame, frame, res, Threshold );
        cv::imshow("Limiar por Objeto", res);
        waitKey(30);
        if(janela->FINALIZADO || fim){
            cvDestroyAllWindows();
            cvDestroyAllWindows();
            camera.release();
            break;
        }
    }
    cvDestroyAllWindows();
    cvDestroyAllWindows();
    camera.release();
    SalvarArquivo();

}
void CalibracaoAutomatica::Fechar(){
    fim = true;

}
void CalibracaoAutomatica::thresh_callback(int, void *) {

    Mat canny_output;
     std::vector< std::vector<Point> > contours;
     std::vector<Vec4i> hierarchy;


    Canny(src_gray, canny_output, thresh, thresh * 2, 3);
    findContours(canny_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    //  vector<Moments> mu(contours.size());
    std:: vector<Point2f> center(contours.size());

    std:: vector<float> radius(contours.size());
    std:: vector< std::vector<Point> > contours_poly(contours.size());
    //for (int i = 0; i < contours.size(); i++) { mu[i] = moments(contours[i], false); }


    boundRect.clear();
    insideRect.clear();
    for (unsigned int i = 0; i < contours.size(); i++) {
        approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
        boundRect.push_back(boundingRect(Mat(contours_poly[i])));
        minEnclosingCircle((Mat) contours_poly[i], center[i], radius[i]);

    }

    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);

    Rect n;
    Point pTopRight, pBottomLeft;
    namedWindow("Contours", CV_WINDOW_AUTOSIZE);
    for (unsigned int i = 0; i < contours.size(); i++) {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
        n = boundRect.at(i);
        pTopRight = n.tl();
        pBottomLeft = n.br();
        //        pTopRight.x += 10;
        //        pTopRight.y += 10;
        //        pBottomLeft.x -= 10;
        //        pBottomLeft.y -= 10;
        //         ObterPorcentagem(pTopRight.x, 10);
        //        std::cout <<"Valor x À direita " << pTopRight.x <<", 10% = " << ObterPorcentagem(pTopRight.x, 10)<< std::endl;
        pTopRight.x += ObterPorcentagem(pTopRight.x, PORCENTAGEM);
        pTopRight.y += ObterPorcentagem(pTopRight.y, PORCENTAGEM);
        pBottomLeft.x -= ObterPorcentagem(pBottomLeft.x, PORCENTAGEM);
        pBottomLeft.y -= ObterPorcentagem(pBottomLeft.y,PORCENTAGEM);
        Rect rRect(pTopRight, pBottomLeft);
        if(rRect.area()>1){
            insideRect.push_back(rRect);
            rectangle(drawing, rRect, Scalar(0, 0, 255), 1, 8, 0);
        }
    }

    imshow("Contours", drawing);

}
bool CalibracaoAutomatica::CompararRectPorArea(Rect a, Rect b){
    return a.area() < b.area();

}
 std::vector<Rect> CalibracaoAutomatica::EliminarExcessos(){

    if(insideRect.size() > 29) {
        std::cout << "PROBLEMA, AMOSTRA MAIOR QUE 29" <<std::endl;

    }
    TdeStudent student;
    student.CalcularTdeStudent(insideRect);
    double* Limites =student.GetLimites();


    double L1=Limites[1], L2=Limites[0];
     std::vector<Rect> tamanhoEsperado;
    //sort(insideRect.begin(), insideRect.end(),CalibracaoAutomatica::EliminarExcessos);
    for(unsigned int i=0; i< insideRect.size(); i++){
        //        std::cout << insideRect.at(i).area() << std::endl;
        if(insideRect.at(i).area() >  L1 && insideRect.at(i).area() <  L2){
            tamanhoEsperado.push_back(insideRect.at(i));
        }
    }
    return tamanhoEsperado;
}
void CalibracaoAutomatica::MetodoCalcular() {
    cv::cvtColor(frame, HSV, CV_RGB2HSV);
    cv::Vec3b pixel;
    int H[257], S[257], V[257];
    int MIN[3], MAX[0];
    int k;
    for (unsigned int i = 0; i < insideRect.size(); i++) {
        memset(H, 0, sizeof(H));
        memset(S, 0, sizeof(S));
        memset(V, 0, sizeof(V));
        memset(MIN, 0, sizeof(MIN));
        memset(MAX, 0, sizeof(MAX));

        for (int y = insideRect.at(i).tl().y; y < insideRect.at(i).br().y; ++y) {
            for (int x = insideRect.at(i).tl().x; x < insideRect.at(i).br().x; x++) {
                pixel = HSV.at<cv::Vec3b>(y, x); // read current pixel
                H[pixel.val[0]]++;
                S[pixel.val[1]]++;
                V[pixel.val[2]]++;
            }
        }

        for (k = 0; k < 256; k++) {
            if (H[k] != 0) {
                break;
            }
        }
        MIN[0] = k;

        for (k = 255; k > MIN[0]; k--) {
            if (H[k] != 0) {
                break;
            }
        }
        MAX[0] = k;


        //Encontrar min e max S

        for (k = 0; k < 256; k++) {
            if (S[k] != 0) {
                break;
            }
        }
        MIN[1] = k;

        for (k = 255; k > MIN[1]; k--) {
            if (S[k] != 0) {
                break;
            }
        }
        MAX[1] = k;

        //Encontrar min e max V

        for (k = 0; k < 256; k++) {
            if (V[k] != 0) {
                break;
            }
        }
        MIN[2] = k;

        for (k = 255; k >MIN[2]; k--) {
            if (V[k] != 0) {
                break;
            }
        }
        MAX[2] = k;

        //Elimina tons de preto
        if(MIN[2] > 20 && MIN[1] > 20){
            CorCalibrada c;
            c.SetMax(MAX);
            c.SetMin(MIN);

            cores.push_back(c);
        }
    }

}
void CalibracaoAutomatica::SalvarArquivo(){

    //std::cout << "Salvando"<<std::endl;
    std::ofstream out;
    out.open("cores.arff");
    for(int i = 0; i < 8; i++){
        out << i << " : " << coresCalibradas[i].MIN[0] << "." << coresCalibradas[i].MIN[1]<< "."<< coresCalibradas[i].MIN[2] << std::endl;
        out << i << " : " << coresCalibradas[i].MAX[0] << "." << coresCalibradas[i].MAX[1]<< "."<< coresCalibradas[i].MAX[2] << std::endl;

    }
    out.close();
}
double CalibracaoAutomatica::ObterPorcentagem(int valor, int porcentagem){
    //    return (porcentagem * valor);
    double p = (porcentagem*valor)/100;
    return p;

}


static bool CompararPorArea(Rect a, Rect b){
    return a.area() < b.area();

}
