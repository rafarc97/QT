#ifndef TASKNUMBER_H
#define TASKNUMBER_H

#include <QRunnable>

class TaskNumber : public QRunnable {
public:
    TaskNumber(char id);
    ~TaskNumber();
protected:
    void run();
private:
    char mId;
};

#endif // TASKNUMBER_H
