#ifndef _PROGRESS_EVENTS_H
#define _PROGRESS_EVENTS_H

#include <qevent.h> 
#include "evtids.hpp" 

namespace events {
namespace progress {

class NumOperations : public QEvent
{
public: 
    NumOperations(size_t operations); 
    size_t operations() const; 
    void operations(size_t operations); 
private: 
    int _operations;     
};

class Step : public QEvent
{
public: 
    Step();
};

class Completed : public QEvent
{
public: 
    Completed();
};

class Canceled : public QEvent
{
public: 
    Canceled(); 
};

} //progress
} //events

#endif

