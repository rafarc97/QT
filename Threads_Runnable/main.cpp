#include <QCoreApplication>
#include <QThreadPool>
#include "tasknumber.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TaskNumber *x = new TaskNumber('x');
    TaskNumber *y = new TaskNumber('y');

    QThreadPool::globalInstance()->start(x,QThread::LowestPriority);
    QThreadPool::globalInstance()->start(y,QThread::HighestPriority);

    return a.exec();
}
