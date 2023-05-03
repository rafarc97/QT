#include "tasknumber.h"
#include<QDebug>

TaskNumber::TaskNumber(char id)
{
    mId = id;
}

TaskNumber::~TaskNumber()
{
    qDebug() << "Task" << mId << "done.";
}

void TaskNumber::run(){
    for(int i = 0; i < 1000; i++){
        qDebug() << mId << ":" << i;
    }
}
