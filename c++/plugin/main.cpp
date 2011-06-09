//
// Use a dynamically loaded dll/so at runtime.
//

#include <dlfcn.h>
#include <cassert>
#include <iostream>
#include "DllBaseClass.hpp"

int main(int argc, char **argv)
{
    void* handle = dlopen("./libdllbaseclass.so", RTLD_LAZY);

    // create & destroy are function pointers
    // create is a pointer to a function that takes 0 parameters
    // and returns a DllBaseClass
    //
    // destroy is a pointer to a function that takes a DllBaseClass*
    // and returns void
    DllBaseClass* (*create)();
    void (*destroy)(DllBaseClass*);

    create = (DllBaseClass* (*)())dlsym(handle, "create_object");
    destroy = (void (*)(DllBaseClass*))dlsym(handle, "destroy_object");

    DllBaseClass* myClass = (DllBaseClass*)create();
    myClass->DoSomething();
    destroy( myClass );
}
