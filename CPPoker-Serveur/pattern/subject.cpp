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
    int i = m_observers.indexOf(obs);
    m_observers.remove(i);
}

void Subject::notify()
{
    for(Observer * obs : m_observers )
    {
        obs->update();
    }
}

