//
// Simple class for use in developing a common scheme for building DLL and DSO
// versions of shared libraries while exporting only some of the symbols.
//
// This scheme uses the pimpl idiom for hiding the implementation class.
// The pointer to the implementation class should be a boost shared_ptr
// or auto_ptr if boost isn't available.
//

#include "Testclass.hpp"
#include "Hiddenclass.hpp"

Testclass::Testclass(int a, int b)
{
    phc = new Hiddenclass(a,b);
}

Testclass::~Testclass()
{
    delete phc;
}

int Testclass::multiply() const
{
    return phc->multiply();
}

int Testclass::divide() const
{
    return phc->divide();
}

int Testclass::add() const
{
    return phc->add();
}

int Testclass::subtract() const
{
    return phc->subtract();
}

