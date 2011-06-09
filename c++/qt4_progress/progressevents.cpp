#include "progressevents.hpp" 
#include "evtids.hpp"

namespace events{
namespace progress{

NumOperations::NumOperations(size_t operations) : 
    QEvent(Type(IdNumOperations)), 
    _operations(operations)
{
}

size_t NumOperations::operations() const 
{
    return _operations; 
}

void NumOperations::operations(size_t operations)
{
    _operations = operations; 
}


Step::Step() : 
    QEvent(Type(IdStep))
{
}

Completed::Completed() : 
    QEvent(Type(IdCompleted))
{
}

Canceled::Canceled() : 
    QEvent(Type(IdCanceled))
{
}

} // progress 
} // events
