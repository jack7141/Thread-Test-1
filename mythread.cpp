#include "mythread.h"
using namespace cv;
using namespace std;
MyThread::MyThread()
{

}

void MyThread::run()
{
    VideoCapture camera(0);
    VideoCapture WebCamera(1);
    Mat frame;
    Mat WebFrame;

    while (Stop==false) {
        camera >> frame;
        QMutex mutex;
        bitwise_not(frame, WebFrame);
        mutex.lock();//Mutex를 사용하여 lock
        if ( this->Stop ) break;
        mutex.unlock();

        QImage qImag
        (frame.data,
         frame.cols,
         frame.rows,
         frame.step,
         QImage::Format::Format_RGB888);


        emit Display(qImag);
    }

   while (LStop==false) {
        WebCamera >> WebFrame;
        bitwise_not(WebFrame, frame);
        QMutex mutex;
        mutex.lock();
        if ( this->LStop ) break;
        mutex.unlock();
        QImage qImag2//Mat QImage로 바꿔준다.그리고 mainwindow에서 QPixmap으로 한번더 변환하는 과정을 거침
        (WebFrame.data,
         WebFrame.cols,
         WebFrame.rows,
         WebFrame.step,
         QImage::Format::Format_RGB888);
        emit WebDisplay(qImag2);
   }

}
