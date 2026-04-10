#include "DetachGetIOInThread.h"
#include "Modules.hpp"

DetachGetIOInThread::DetachGetIOInThread(QObject *parent) : QThread(parent)
{

}

DetachGetIOInThread::~DetachGetIOInThread()
{
    stopThread();
    wait(); // 等待线程安全退出
}

void DetachGetIOInThread::startThread()
{
    running = true;
    if (!isRunning()) {
        start(); // 启动线程
    }
}

void DetachGetIOInThread::stopThread()
{
    running = false; // 停止线程
}

void DetachGetIOInThread::process()
{
    
}

void DetachGetIOInThread::run()
{
    while (running) {
        QThread::msleep(1);

       // process();
    }
}
