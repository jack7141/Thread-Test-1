#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QPixmap>
#include <QMutex>
#include <QImage>
#include <opencv2/opencv.hpp>


class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run() override;
    bool Stop;
    bool LStop;

signals:
    void Display(QImage);
    void WebDisplay(QImage);
public slots:
};

#endif // MYTHREAD_H
