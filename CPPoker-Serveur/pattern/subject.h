#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <vector>


class Subject
{
private:
    std::vector<Observer*> m_observers;
public:
    Subject();
    void addObserver(Observer * obs);
    void notify();


};

#endif // SUBJECT_H
