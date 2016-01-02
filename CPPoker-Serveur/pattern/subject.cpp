#include "subject.h"

Subject::Subject()
{
}

void Subject::addObserver(Observer *obs)
{
    m_observers.push_back(obs);
}

void Subject::remObserver(Observer *obs)
{
    m_observers.removeOne(obs);
}

void Subject::notify()
{
    for(Observer * obs : m_observers )
    {
        obs->update();
    }
}

