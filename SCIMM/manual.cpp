#include "manual.h"

int drag, select_flag;
bool callback = false;
Point ini, fim;
cv::Mat frameM, HSVM;
cv::Vec3b pixel;
int H[256], S[256], V[256];

char* janelasNome[2] = {"Selecão de Cores", "Threshold"};
Manual::Manual()
{
}

static void mouseHandler(int event, int x, int y, int flags, void *param) {
    if (event == CV_EVENT_LBUTTONDOWN && !drag && !select_flag) {
        /* left button clicked. ROI selection begins */
        ini = cv::Point(x, y);
        drag = 1;
    }
    if (event == CV_EVENT_MOUSEMOVE && drag && !select_flag) {
        /* mouse dragged. ROI being selected */
        cv::Mat img1 = frameM.clone();
        fim = cv::Point(x, y);
        cv::rectangle(img1, ini, fim, CV_RGB(255, 0, 0), 2, 5, 0);
        cv::imshow(janelasNome[0], img1);    }
    if (event == CV_EVENT_LBUTTONUP && drag && !select_flag) {
        cv::Mat img2 = frameM.clone();
        fim = cv::Point(x, y);
        cv::rectangle(img2, ini, fim, CV_RGB(255, 0, 0), 2, 5, 0);
        drag = 0;
        if (ini.y > fim.y || ini.x > fim.x) {
            std::cout << "Horientação errada para detecção de cor." << std::endl;
        } else {
            Manual::Calcular(ini, fim);
        }


    }
}


void Manual::Calcular(Point ini, Point fim){
    cv::cvtColor(frameM, HSVM, CV_RGB2HSV);
    for (int y = ini.y; y < fim.y; ++y) {
        for (int x = ini.x; x < fim.x; x++) {
            pixel = HSVM.at<cv::Vec3b>(y, x); // read current pixel
            H[pixel.val[0]]++;
            S[pixel.val[1]]++;
            V[pixel.val[2]]++;
        }
    }
}

void Manual::Iniciar(JanelaPrincipal *janela, int c){
    int CALIBRANDO_ATUAL;
        Mat src;
        FIM  =false;
        cv::VideoCapture camera(CAMERA);
        if (camera.isOpened()) {
            CALIBRANDO_ATUAL = janela->INDEX_CALIBRACAO;
            while (!janela->FINALIZADA || !FIM) {
                camera >> frame;
                if(janela->CALIBRADO[CALIBRANDO_ATUAL]){
                    coresCalibradas[CALIBRANDO_ATUAL] = janela->cor;
                }
                if(CALIBRANDO_ATUAL!=janela->INDEX_CALIBRACAO){
                    DeclararMatrizes();
                    CALIBRANDO_ATUAL = janela->INDEX_CALIBRACAO;
                }
                cv::setMouseCallback(janelasNome[0], mouseHandler, 0);
                cv::imshow(janelasNome[0], frame);
                if(janela->CALIBRAR){
                    janela->SetHSV(H,S,V);
                    janela->CALIBRAR = false;

                }
                key = cv::waitKey(5) & 255;
                if (FIM) {
                    break;
                }
            }

           camera.release();
            camera.release();
            camera.release();

            cv::destroyAllWindows();
            cv::destroyAllWindows();
            cv::destroyAllWindows();
            cv::destroyAllWindows();

            if(janela->FINALIZADA)
                SalvarArquivo();
    }
}

void Manual::DeclararMatrizes(){
    memset(H, 0, sizeof(H));
       memset(S, 0, sizeof(S));
   memset(V, 0, sizeof(V));
}