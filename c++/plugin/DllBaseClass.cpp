//
// Simple dll/so base class for use in a plugin system where dlls are
// dynamically loaded at runtime as plugins to the system.
//
// This scheme uses the pimpl idiom for hiding the implementation class.
// The pointer to the implementation class should be a boost shared_ptr
// or auto_ptr if boost isn't available.
//

#include "DllBaseClass.hpp"
#include <iostream>
#include <cassert>
#include "Hiddenclass.hpp"

using std::cout;

extern "C" DllBaseClass* create_object()
{
  return new DllBaseClass;
}

extern "C" void destroy_object( DllBaseClass* object )
{
  delete object;
}

DllBaseClass::DllBaseClass()
{
    phc = new Hiddenclass();
}

DllBaseClass::~DllBaseClass()
{
    delete phc;
}

void DllBaseClass::DoSomething()
{
    assert(phc);
    cout << phc->DoSomething();
}
