#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <QVector>


class Subject
{
private:
    QVector<Observer*> m_observers;
public:
    Subject();
    void addObserver(Observer * obs);
    void remObserver(Observer * obs);
    void notify();
};

#endif // SUBJECT_H
